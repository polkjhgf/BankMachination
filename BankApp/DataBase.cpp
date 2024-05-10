#include "DataBase.h"

namespace NSData {
/*
 * class users
 */
bool Users::Check(const User& _user)
{
    QSqlQuery query = QSqlQuery(*m_db);
    query.exec("SELECT * FROM Users WHERE Login = '" + _user.Login + "'");
    if (!query.first())
        return true;

    return false;
}

bool Users::Check(const QString& _login)
{
    QSqlQuery query = QSqlQuery(*m_db);
    query.exec("SELECT * FROM Users WHERE Login = '" + _login + "'");
    if (!query.first())
        return true;

    return false;
}

bool Users::Set(const User& _user)
{
    QSqlQuery query = QSqlQuery(*m_db);
    if (!query.exec("INSERT INTO Users(ID, Name, LastName, Login, Password, Balance, Rating) VALUES(" +
                    QString::number(getLastID() + 1) + ", " +
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

User Users::Get(int id)
{
    QSqlQuery query = QSqlQuery(*m_db);
    query.exec("SELECT * FROM Users WHERE ID = " + QString::number(id));
    return User(query.value(0).toString(),
                query.value(1).toString(),
                query.value(2).toString(),
                query.value(3).toString(),
                query.value(4).toDouble(),
                query.value(5).toFloat());
}

User Users::Get(const QString& _login)
{
    QSqlQuery query = QSqlQuery(*m_db);
    query.exec("SELECT * FROM Users WHERE Login = '" + _login + "'");
    query.first();
    return User(query.value(1).toString(),
                query.value(2).toString(),
                query.value(3).toString(),
                query.value(4).toString(),
                query.value(5).toDouble(),
                query.value(6).toFloat());
}

int Users::getLastID()
{
    QSqlQuery query = QSqlQuery(*m_db);
    query.exec("SELECT ID FROM Users ORDER BY ID");
    query.last();
    return query.value(0).toInt();
}

void Users::resetData(const User& _user)
{
    QSqlQuery query = QSqlQuery(*m_db);
    query.exec("UPDATE Users SET Rating = " + QString::number(_user.Rating) + "WHERE Login = '" + _user.Login + "'");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
 * class Credits
 */
bool Credits::Check(const Credit& _credit)
{
    QSqlQuery query = QSqlQuery(*m_db);
    query.exec("SELECT Active FROM Credits WHERE CustomerID = " + QString::number(_credit.CustomerID));

    QSqlQuery query1 = QSqlQuery(*m_db);
    query1.exec("SELECT Rating FROM Users WHERE ID = " + QString::number(_credit.CustomerID));

    if (query.first() || query.value(0).toInt() < 0.4)
        return false;

    return true;
}

bool Credits::Set(const Credit& _credit)
{
    QSqlQuery query = QSqlQuery(*m_db);
    if (!query.exec("INSERT INTO Credit(ContractID, CustomerID, Rate, Time, Amount, MonthPaid, Closed) VALUES(" +
                    QString::number(getLastID() + 1) + ", " +
                    QString::number(_credit.CustomerID) + ", " +
                    QString::number(_credit.Rate) + ", " +
                    QString::number(_credit.Amount) + ", " +
                    (_credit.MonthPaid ? "true" : "false") + ", " +
                    "false)"))
    {
        m_sError = query.lastError().text();
        return false;
    }

    resetData(_credit);
    return true;
}

Credit Credits::Get(int id)
{
    QSqlQuery query = QSqlQuery(*m_db);
    query.exec("SELECT * FROM Credits WHERE CustomerID = " + QString::number(id) + " and Closed = false");
    return Credit(query.value(0).toInt(),
                  query.value(1).toFloat(),
                  query.value(2).toFloat(),
                  query.value(3).toInt(),
                  query.value(4).toBool());
}

int Credits::getLastID()
{
    QSqlQuery query = QSqlQuery(*m_db);
    query.exec("SELECT ID FROM Credits ORDER BY ID");
    query.last();
    return query.value(0).toInt();
}

void Credits::resetData(const Credit& _credit)
{
    QSqlQuery query = QSqlQuery(*m_db);
    query.exec("UPDATE Bank SET Income = " + QString::number(_credit.Amount * _credit.Rate));
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
 * class Deposits
 */
bool Deposits::Check(const Deposit& _deposit)
{
    QSqlQuery query = QSqlQuery(*m_db);
    query.exec("SELECT * FROM Bank");
    if (query.value(1).toDouble() - query.value(2).toDouble() - _deposit.Rate * _deposit.Amount < 0)
        return false;

    return true;
}

bool Deposits::Set(const Deposit& _deposit)
{
    QSqlQuery query = QSqlQuery(*m_db);
    if (!query.exec("INSERT INTO Deposits(ContractID, CustomerID, Rate, Time, Amount, Closed) VALUES(" +
                    QString::number(getLastID() + 1) + ", " +
                    QString::number(_deposit.CustomerID) + ", " +
                    QString::number(_deposit.Rate) + ", " +
                    QString::number(_deposit.Time) + ", " +
                    QString::number(_deposit.Amount) + ", " +
                    "false)"))
    {
        m_sError = query.lastError().text();
        return false;
    }

    resetData(_deposit);
    return true;
}

Deposit Deposits::Get(int id)
{
    QSqlQuery query = QSqlQuery(*m_db);
    query.exec("SELECT * FROM Deposit WHERE CustomerID = " + QString::number(id) + " and Closed = false");
    return Deposit(query.value(0).toInt(),
                   query.value(1).toFloat(),
                   query.value(2).toFloat(),
                   query.value(3).toInt());
}

int Deposits::getLastID()
{
    QSqlQuery query = QSqlQuery(*m_db);
    query.exec("SELECT ID FROM Deposit ORDER BY ID");
    query.last();
    return query.value(0).toInt();
}

void Deposits::resetData(const Deposit& _deposit)
{
    QSqlQuery query = QSqlQuery(*m_db);
    query.exec("UPDATE Bank SET Consumption = " + QString::number(_deposit.Amount * _deposit.Rate));
}
}
