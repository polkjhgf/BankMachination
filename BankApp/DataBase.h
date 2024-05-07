#ifndef DATABASE_H
#define DATABASE_H

#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

namespace NSData {
struct User
{
    User(const QString& _name,
         const QString& _lastname,
         const QString& _login,
         const QString& _password) : Name(_name), LastName(_lastname), Login(_login), Password(_password), Rating(0.5f) {}
    User(const QString& _name,
         const QString& _lastname,
         const QString& _login,
         const QString& _password,
         float _rating) : Name(_name), LastName(_lastname), Login(_login), Password(_password), Rating(_rating) {}
    ~User() {}

    QString Name;
    QString LastName;
    QString Login;
    QString Password;
    float Rating;
};

class DataBase
{
public:
    DataBase();
    ~DataBase();

    void Connect();
    void Disconnect();

    bool CheckConnection();
    bool CheckLogin(const QString& _login);

    void resetUsersRating(const User& _user, float _newrating);

    bool setUser(const User& _user);

    User getUser(int id) const;
    User getUser(const QString& _login) const;
    QString getError() const;
    int getLastId() const;
private:
    QSqlDatabase m_db;
    QString m_sError;
};
}

#endif // DATABASE_H
