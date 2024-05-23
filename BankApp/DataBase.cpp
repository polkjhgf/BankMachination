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
    return User(query.value(0).toInt(),
                query.value(1).toString(),
                query.value(2).toString(),
                query.value(3).toString(),
                query.value(4).toString(),
                query.value(5).toDouble(),
                query.value(6).toFloat());
}

User Users::Get(const QString& _login)
{
    QSqlQuery query = QSqlQuery(*m_db);
    query.exec("SELECT * FROM Users WHERE Login = '" + _login + "'");
    query.first();
    return User(query.value(0).toInt(),
                query.value(1).toString(),
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
    query.exec("UPDATE Users SET Rating = " + QString::number(_user.Rating) + ", Balance = " + QString::number(_user.Balance) + " WHERE Login = '" + _user.Login + "'");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
 * class Credits
 */
bool Credits::Check(const Credit& _credit)
{
    QSqlQuery query = QSqlQuery(*m_db);
    query.exec("SELECT * FROM Credits WHERE CustomerID = " + QString::number(_credit.CustomerID) + " and Closed = false");

    QSqlQuery query1 = QSqlQuery(*m_db);
    query1.exec("SELECT Rating FROM Users WHERE ID = " + QString::number(_credit.CustomerID));
    query1.first();

    QSqlQuery query2 = QSqlQuery(*m_db);
    query2.exec("SELECT Amount FROM Bank");
    query2.first();

    if (query.first() || query1.value(0).toInt() < 0.3 || query2.value(0).toInt() <= _credit.Amount)
        return false;

    return true;
}

bool Credits::Set(const Credit& _credit)
{
    QSqlQuery query = QSqlQuery(*m_db);
    if (!query.exec("INSERT INTO Credits(contractid, customerid, rate, time, amount, closed, monthpaid, contractdate, allamount) VALUES(" +
                    QString::number(getLastID() + 1) + ", " +
                    QString::number(_credit.CustomerID) + ", " +
                    QString::number(_credit.Rate) + ", " +
                    QString::number(_credit.Time) + ", " +
                    QString::number(_credit.Amount) + ", false, 0, " +
                    "'" + CurrentDate + "', " +
                    QString::number(_credit.AllAmount) + ")"))
    {
        m_sError = query.lastError().text();
        return false;
    }

    resetIncome(_credit, false, true);
    return true;
}

Credit Credits::Get(int id)
{
    QSqlQuery query = QSqlQuery(*m_db);
    query.exec("SELECT * FROM Credits WHERE CustomerID = " + QString::number(id) + " and Closed = false");
    if (!query.first()) return Credit(0);
    return Credit(query.value(1).toInt(),
                  query.value(2).toFloat(),
                  query.value(3).toInt(),
                  query.value(4).toFloat(),
                  query.value(6).toInt(),
                  query.value(7).toString(),
                  query.value(8).toInt());
}

int Credits::getLastID()
{
    QSqlQuery query = QSqlQuery(*m_db);
    query.exec("SELECT ContractID FROM Credits ORDER BY ContractID");
    if (!query.last()) return 0;
    return query.value(0).toInt();
}

void Credits::resetData(const Credit& _credit)
{
    QSqlQuery query = QSqlQuery(*m_db);
    query.exec("UPDATE Credits SET Time = " +
               QString::number(_credit.Time) +
               ", Amount = " +
               QString::number(_credit.Amount) +
               ", MonthPaid = " +
               QString::number(_credit.MonthPaid) +
               " WHERE CustomerID = " +
               QString::number(_credit.CustomerID) +
               " and Closed = false");
    resetIncome(_credit, false, false);
}

void Credits::Close(const Credit& _credit)
{
    QSqlQuery query = QSqlQuery(*m_db);
    query.exec("UPDATE credits SET closed = true, monthpaid = " + QString::number(_credit.MonthPaid) + " WHERE customerid = " + QString::number(_credit.CustomerID) + " and closed = false");
    resetIncome(_credit, true, false);
}

void Credits::resetIncome(const Credit& _credit, bool closed, bool set)
{
    if (closed)
    {
        QSqlQuery query = QSqlQuery(*m_db);
        query.exec("UPDATE Bank SET Income = Income - " + QString::number(_credit.AllAmount * _credit.Rate / 1200) + ", Amount = Amount + " + QString::number(_credit.Amount));
    }
    else if (set)
    {
        QSqlQuery query = QSqlQuery(*m_db);
        query.exec("UPDATE Bank SET Income = Income + " + QString::number(_credit.AllAmount * _credit.Rate / 1200) + ", Amount = Amount - " + QString::number(_credit.Amount));
    }
    else
    {
        QSqlQuery query = QSqlQuery(*m_db);
        query.exec("UPDATE Bank SET Amount = Amount + " + QString::number(_credit.Amount / (_credit.Time - _credit.MonthPaid) + _credit.Amount * _credit.Rate / 1200));
    }

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
 * class Deposits
 */
bool Deposits::Check(const Deposit& _deposit)
{
    QSqlQuery query = QSqlQuery(*m_db);
    query.exec("SELECT * FROM Bank");
    query.first();
    if (query.value(1).toDouble() - query.value(2).toDouble() - _deposit.Rate * _deposit.Amount / 1200 < 0)
        return false;

    QSqlQuery query1 = QSqlQuery(*m_db);
    query1.exec("SELECT * FROM Deposits WHERE CustomerID = " + QString::number(_deposit.CustomerID) + " and Closed = false");
    if (query1.first())
        return false;

    return true;
}

bool Deposits::Set(const Deposit& _deposit)
{
    QSqlQuery query = QSqlQuery(*m_db);
    if (!query.exec("INSERT INTO Deposits(ContractID, CustomerID, Rate, Time, Amount, Closed, ContractDate, MonthPaid) VALUES(" +
                    QString::number(getLastID() + 1) + ", " +
                    QString::number(_deposit.CustomerID) + ", " +
                    QString::number(_deposit.Rate) + ", " +
                    QString::number(_deposit.Time) + ", " +
                    QString::number(_deposit.Amount) + ", false, " +
                    "'" + CurrentDate + "', " +
                    QString::number(_deposit.MonthPaid) + ")"))
    {
        m_sError = query.lastError().text();
        return false;
    }

    resetConsumption(_deposit, false);
    return true;
}

Deposit Deposits::Get(int id)
{
    QSqlQuery query = QSqlQuery(*m_db);
    query.exec("SELECT * FROM Deposits WHERE CustomerID = " + QString::number(id) + " and Closed = false");
    if (!query.first()) return Deposit(0);
    return Deposit(query.value(1).toInt(),
                   query.value(2).toFloat(),
                   query.value(3).toFloat(),
                   query.value(4).toFloat(),
                   query.value(6).toString(),
                   query.value(7).toInt());
}

int Deposits::getLastID()
{
    QSqlQuery query = QSqlQuery(*m_db);
    query.exec("SELECT ContractID FROM Deposits ORDER BY ContractID");
    if (!query.last()) return 0;
    return query.value(0).toInt();
}

void Deposits::resetData(const Deposit& _deposit)
{
    QSqlQuery query1 = QSqlQuery(*m_db);
    query1.exec("SELECT * FROM Deposits WHERE CustomerID = " + QString::number(_deposit.CustomerID) + " and Closed = false");
    query1.first();
    Deposit olddeposit(query1.value(1).toInt(), query1.value(2).toFloat(), query1.value(3).toFloat(), query1.value(4).toInt());
    resetConsumption(olddeposit, true);

    QSqlQuery query = QSqlQuery(*m_db);
    query.exec("UPDATE Deposits SET Amount = " +
               QString::number(_deposit.Amount) +
               ",  monthpaid = " +
               QString::number(_deposit.MonthPaid) +
               " WHERE CustomerID = " +
               QString::number(_deposit.CustomerID) +
               " and Closed = false");
    resetConsumption(_deposit, false);
}

void Deposits::Close(const Deposit& _deposit)
{
    QSqlQuery query = QSqlQuery(*m_db);
    query.exec("UPDATE Deposits SET Closed = true WHERE CustomerID = " + QString::number(_deposit.CustomerID) + " and Closed = false");
    resetConsumption(_deposit, true);
}

void Deposits::resetConsumption(const Deposit& _deposit, bool closed)
{
    if (closed)
    {
        QSqlQuery query = QSqlQuery(*m_db);
        query.exec("UPDATE Bank SET Consumption = Consumption - " + QString::number(_deposit.Amount * _deposit.Rate / 1200) + ", Amount = Amount - " + QString::number(_deposit.Amount));
    }
    else
    {
        QSqlQuery query = QSqlQuery(*m_db);
        query.exec("UPDATE Bank SET Consumption = Consumption + " + QString::number(_deposit.Amount * _deposit.Rate / 1200) + ", Amount = Amount + " + QString::number(_deposit.Amount));
    }
}
}
