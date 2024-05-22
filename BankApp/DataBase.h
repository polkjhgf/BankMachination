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

    void SetDate()
    {
        QSqlQuery query = QSqlQuery(*m_db);
        query.exec("SELECT CURRENT_DATE");
        query.first();
        CurrentDate = query.value(0).toString();
    }

    QString GetDate() const
    {
        return CurrentDate;
    }

    virtual bool Check(const T& _data) = 0;

    virtual bool Set(const T& _data) = 0;

    virtual T Get(int id) = 0;

    virtual void resetData(const T& _data) = 0;

    QString getError() { return m_sError; }
protected:
    virtual int getLastID() = 0;

protected:
    QString CurrentDate;
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

    void resetData(const User& _user) override;

protected:
    int getLastID() override;
};

struct Credit
{
    Credit(int _customerid,
           float _rate,
           float _time,
           int _amount) : CustomerID(_customerid), Rate(_rate), Time(_time), Amount(_amount), MonthPaid(0), ContractDate("") {}
    Credit(int _customerid,
           float _rate,
           float _time,
           int _amount,
           int _monthpaid,
           QString _contractdate) : CustomerID(_customerid), Rate(_rate), Time(_time), Amount(_amount), MonthPaid(_monthpaid), ContractDate(_contractdate) {}
    Credit(int _customerid) : CustomerID(_customerid) {}
    ~Credit() {}

    int CustomerID;
    float Rate;
    float Time;
    int Amount;
    int MonthPaid;
    QString ContractDate;
};

class Credits : public DataBase<Credit>
{
public:
    Credits(QSqlDatabase *_db = nullptr) : DataBase(_db) {}

    bool Check(const Credit& _credit) override;

    bool Set(const Credit& _credit) override;

    Credit Get(int id) override;

    void resetData(const Credit& _credit) override;

    void Close(const Credit& _credit);

protected:
    int getLastID() override;
    void resetIncome(const Credit& _credit, bool closed);
};

struct Deposit
{
    Deposit(int _customerid,
            float _rate,
            float _time,
            int _amount) : CustomerID(_customerid), Rate(_rate), Time(_time), Amount(_amount), ContractDate(""), MonthPaid(0) {}
    Deposit(int _customerid,
            float _rate,
            float _time,
            int _amount,
            QString _contractdate,
            int _monthpaid) : CustomerID(_customerid), Rate(_rate), Time(_time), Amount(_amount), ContractDate(_contractdate), MonthPaid(_monthpaid) {}
    Deposit(int _customerid) : CustomerID(_customerid) {}
    ~Deposit() {}

    int CustomerID;
    float Rate;
    float Time;
    int Amount;
    QString ContractDate;
    int MonthPaid;
};

class Deposits : public DataBase<Deposit>
{
public:
    Deposits(QSqlDatabase *_db = nullptr) : DataBase(_db) {}

    bool Check(const Deposit& _deposit) override;

    bool Set(const Deposit& _deposit) override;

    Deposit Get(int id) override;

    void resetData(const Deposit& _deposit) override;

    void Close(const Deposit& _deposit);

protected:
    int getLastID() override;
    void resetConsumption(const Deposit& _deposit, bool closed);
};
}

#endif // DATABASE_H
