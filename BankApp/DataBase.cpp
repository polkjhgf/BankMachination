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

void DataBase::resetUsersRating(const User& _user, float _newrating)
{
    QSqlQuery query = QSqlQuery(m_db);
    query.exec("UPDATE Users SET Rating = " + QString::number(_newrating) + "WHERE Login = '" + _user.Login + "'");
}

bool DataBase::setUser(const User& _user)
{    
    QSqlQuery query = QSqlQuery(m_db);
    if (!query.exec("INSERT INTO Users(ID, Name, LastName, Login, Password, Rating) VALUES(" +
                    QString::number(getLastId() + 1) + ", "+
                    "'" + _user.Name + "', " +
                    "'" + _user.LastName + "', " +
                    "'" + _user.Login + "', " +
                    "'" + _user.Password + "', " +
                    QString::number(_user.Rating) + ")"))
    {
        m_sError = query.lastError().text();
        return false;
    }

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
                query.value(4).toFloat());
}

User DataBase::getUser(const QString& _login) const
{
    QSqlQuery query = QSqlQuery(m_db);
    query.exec("SELECT * FROM Users WHERE Login = '" + _login + "'");
    return User(query.value(0).toString(),
                query.value(1).toString(),
                query.value(2).toString(),
                query.value(3).toString(),
                query.value(4).toFloat());
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
}
