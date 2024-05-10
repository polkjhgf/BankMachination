#ifndef DATABASE_H
#define DATABASE_H

#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

namespace NSData {
template <typename T>
class DataBase
{
public:
    DataBase(QSqlDatabase *_db = nullptr) : m_db(_db) {}
    ~DataBase() {}

    virtual bool Check(const T& _data) = 0;

    virtual bool Set(const T& _data) = 0;

    virtual T Get(int id) = 0;

    QString getError() { return m_sError; }
protected:
    virtual int getLastID() = 0;
    virtual void resetData(const T& _data) = 0;

protected:
    QSqlDatabase *m_db;
    QString m_sError;
};

struct User
{
    User(const QString& _name,
         const QString& _lastname,
         const QString& _login,
         const QString& _password,
         double _balance) : Name(_name), LastName(_lastname), Login(_login), Password(_password), Balance(_balance), Rating(0.5f) {}
    User(int _id,
         const QString& _name,
         const QString& _lastname,
         const QString& _login,
         const QString& _password,
         double _balance,
         float _rating) : ID(_id), Name(_name), LastName(_lastname), Login(_login), Password(_password), Balance(_balance), Rating(_rating) {}
    ~User() {}

    int ID;
    QString Name;
    QString LastName;
    QString Login;
    QString Password;
    double Balance;
    float Rating;
};

class Users : public DataBase<User>
{
public:
    Users(QSqlDatabase *_db = nullptr) : DataBase(_db) {}
    bool Check(const User& _user) override;
    bool Check(const QString& _login);

    bool Set(const User& _user) override;

    User Get(int id) override;
    User Get(const QString& _login);

protected:
    int getLastID() override;
    void resetData(const User& _user) override;
};

struct Credit
{
    Credit(int _customerid,
           float _rate,
           float _time,
           int _amount) : CustomerID(_customerid), Rate(_rate), Time(_time), Amount(_amount), MonthPaid(false) {}
    Credit(int _customerid,
           float _rate,
           float _time,
           int _amount,
           bool _monthpaid) : CustomerID(_customerid), Rate(_rate), Time(_time), Amount(_amount), MonthPaid(_monthpaid) {}
    ~Credit() {}

    int CustomerID;
    float Rate;
    float Time;
    int Amount;
    bool MonthPaid;
};

class Credits : public DataBase<Credit>
{
public:
    Credits(QSqlDatabase *_db = nullptr) : DataBase(_db) {}

    bool Check(const Credit& _credit) override;

    bool Set(const Credit& _credit) override;

    Credit Get(int id) override;

protected:
    int getLastID() override;
    void resetData(const Credit& _credit) override;
};

struct Deposit
{
    Deposit(int _customerid,
            float _rate,
            float _time,
            int _amount) : CustomerID(_customerid), Rate(_rate), Time(_time), Amount(_amount) {}
    ~Deposit() {}

    int CustomerID;
    float Rate;
    float Time;
    int Amount;
};

class Deposits : public DataBase<Deposit>
{
public:
    Deposits(QSqlDatabase *_db = nullptr) : DataBase(_db) {}

    bool Check(const Deposit& _deposit) override;

    bool Set(const Deposit& _deposit) override;

    Deposit Get(int id) override;

protected:
    int getLastID() override;
    void resetData(const Deposit& _deposit) override;
};
}

#endif // DATABASE_H
