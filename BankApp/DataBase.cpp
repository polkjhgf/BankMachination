#include "DataBase.h"

namespace NSData {
DataBase::DataBase()
{
    Connect();
}

DataBase::~DataBase()
{
    Disconnect();
}

void DataBase::Connect()
{
    m_db = QSqlDatabase::addDatabase("QPSQL");
    m_db.setDatabaseName("postgres");
    m_db.setUserName("postgres");
    m_db.setPassword("12345678");
}

void DataBase::Disconnect()
{
    m_db.close();
    m_db.~QSqlDatabase();
}

bool DataBase::CheckConnection()
{
    if (m_db.open())
        return true;

    m_sError = m_db.lastError().text();
    return false;
}

bool DataBase::CheckLogin(const QString& _login)
{
    QSqlQuery query = QSqlQuery(m_db);
    query.exec("SELECT * FROM Users WHERE Login = '" + _login + "'");
    if (!query.first())
        return true;

    m_sError = "This Login already used!";
    return false;
}

bool DataBase::CheckCredit(const Credit& _credit)
{
    User user = getUser(_credit.CustomerID);
    QSqlQuery query = QSqlQuery(m_db);
    query.exec("SELECT Active FROM Credits WHERE CustomerID = " + QString::number(_credit.CustomerID));

    if (query.first() || user.Rating < 0.4)
        return false;

    setCredit(_credit);
    return true;
}

bool DataBase::CheckDeposit(const Deposit& _deposit)
{
    QSqlQuery query = QSqlQuery(m_db);
    query.exec("SELECT * FROM Bank");
    if (query.value(1).toDouble() - query.value(2).toDouble() - _deposit.Rate * _deposit.Amount < 0)
        return false;

    return true;
}

void DataBase::resetUsersRating(const User& _user, float _newrating)
{
    QSqlQuery query = QSqlQuery(m_db);
    query.exec("UPDATE Users SET Rating = " + QString::number(_newrating) + "WHERE Login = '" + _user.Login + "'");
}

void DataBase::ResetIncome(const Credit& _credit)
{
    QSqlQuery query = QSqlQuery(m_db);
    query.exec("UPDATE Bank SET Income = " + QString::number(_credit.Amount * _credit.Rate));
}

void DataBase::ResetConsumption(const Deposit& _deposit)
{
    QSqlQuery query = QSqlQuery(m_db);
    query.exec("UPDATE Bank SET Consumption = " + QString::number(_deposit.Amount * _deposit.Rate));
}

bool DataBase::setUser(const User& _user)
{    
    QSqlQuery query = QSqlQuery(m_db);
    if (!query.exec("INSERT INTO Users(ID, Name, LastName, Login, Password, Rating) VALUES(" +
                    QString::number(getLastId() + 1) + ", " +
                    "'" + _user.Name + "', " +
                    "'" + _user.LastName + "', " +
                    "'" + _user.Login + "', " +
                    "'" + _user.Password + "', " +
                    QString::number(_user.Balance) + ", " +
                    QString::number(_user.Rating) + ")"))
    {
        m_sError = query.lastError().text();
        return false;
    }

    return true;
}

bool DataBase::setCredit(const Credit& _credit)
{
    QSqlQuery query = QSqlQuery(m_db);
    if (!query.exec("INSERT INTO Credit(ContractID, CustomerID, Rate, Time, Amount, MonthPaid, Closed) VALUES(" +
                    QString::number(getLastIDCredit() + 1) + ", " +
                    QString::number(_credit.CustomerID) + ", " +
                    QString::number(_credit.Rate) + ", " +
                    QString::number(_credit.Amount) + ", " +
                    (_credit.MonthPaid ? "true" : "false") + ", " +
                    "false)"))
    {
        m_sError = query.lastError().text();
        return false;
    }

    ResetIncome(_credit);
    return true;
}

bool DataBase::setDeposit(const Deposit& _deposit)
{
    QSqlQuery query = QSqlQuery(m_db);
    if (!query.exec("INSERT INTO Deposits(ContractID, CustomerID, Rate, Time, Amount, Closed) VALUES(" +
                    QString::number(getLastIDDeposit() + 1) + ", " +
                    QString::number(_deposit.CustomerID) + ", " +
                    QString::number(_deposit.Rate) + ", " +
                    QString::number(_deposit.Time) + ", " +
                    QString::number(_deposit.Amount) + ", " +
                    "false)"))
    {
        m_sError = query.lastError().text();
        return false;
    }

    ResetConsumption(_deposit);
    return true;
}

User DataBase::getUser(int id) const
{
    QSqlQuery query = QSqlQuery(m_db);
    query.exec("SELECT * FROM Users WHERE ID = " + QString::number(id));
    return User(query.value(0).toString(),
                query.value(1).toString(),
                query.value(2).toString(),
                query.value(3).toString(),
                query.value(4).toDouble(),
                query.value(5).toFloat());
}

User DataBase::getUser(const QString& _login) const
{
    QSqlQuery query = QSqlQuery(m_db);
    query.exec("SELECT * FROM Users WHERE Login = '" + _login + "'");
    return User(query.value(0).toString(),
                query.value(1).toString(),
                query.value(2).toString(),
                query.value(3).toString(),
                query.value(4).toDouble(),
                query.value(5).toFloat());
}

Credit DataBase::getCredit(int id) const
{
    QSqlQuery query = QSqlQuery(m_db);
    query.exec("SELECT * FROM Credits WHERE CustomerID = " + QString::number(id) + " and Closed = false");
    return Credit(query.value(0).toInt(),
                  query.value(1).toFloat(),
                  query.value(2).toFloat(),
                  query.value(3).toInt(),
                  query.value(4).toBool());
}

Deposit DataBase::getDeposite(int id) const
{
    QSqlQuery query = QSqlQuery(m_db);
    query.exec("SELECT * FROM Deposit WHERE CustomerID = " + QString::number(id) + " and Closed = false");
    return Deposit(query.value(0).toInt(),
                  query.value(1).toFloat(),
                  query.value(2).toFloat(),
                  query.value(3).toInt());
}

QString DataBase::getError() const
{
    return m_sError;
}

int DataBase::getLastId() const
{
    QSqlQuery query = QSqlQuery(m_db);
    query.exec("SELECT ID FROM Users ORDER BY ID");
    query.last();
    return query.value(0).toInt();
}

int DataBase::getLastIDCredit() const
{
    QSqlQuery query = QSqlQuery(m_db);
    query.exec("SELECT ID FROM Credits ORDER BY ID");
    query.last();
    return query.value(0).toInt();
}

int DataBase::getLastIDDeposit() const
{
    QSqlQuery query = QSqlQuery(m_db);
    query.exec("SELECT ID FROM Deposit ORDER BY ID");
    query.last();
    return query.value(0).toInt();
}
}
