#ifndef DATABASE_H
#define DATABASE_H

#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

namespace NSData {
class User
{
public:
    User(const QString& _name,
         const QString& _lastname,
         const QString& _login,
         const QString& _password) : m_oName(_name), m_oLastName(_lastname), m_oLogin(_login), m_oPassword(_password), m_oRating(0.5f) {}
    User(const QString& _name,
         const QString& _lastname,
         const QString& _login,
         const QString& _password,
         float _rating) : m_oName(_name), m_oLastName(_lastname), m_oLogin(_login), m_oPassword(_password), m_oRating(_rating) {}
    ~User() {}

    void setName(const QString& _name);
    void setLastName(const QString& _lastname);
    void setLogin(const QString& _login);
    void setPassword(const QString& _password);
    void setRating(float _rating);

    QString getName() const;
    QString getLastName() const;
    QString getLogin() const;
    QString getPassword() const;
    float getRating() const;

private:
    QString m_oName;
    QString m_oLastName;
    QString m_oLogin;
    QString m_oPassword;
    float m_oRating;
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
