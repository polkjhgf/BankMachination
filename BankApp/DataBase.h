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
         const QString& _password,
         double _balance) : Name(_name), LastName(_lastname), Login(_login), Password(_password), Balance(_balance), Rating(0.5f) {}
    User(const QString& _name,
         const QString& _lastname,
         const QString& _login,
         const QString& _password,
         double _balance,
         float _rating) : Name(_name), LastName(_lastname), Login(_login), Password(_password), Balance(_balance), Rating(_rating) {}
    ~User() {}

    QString Name;
    QString LastName;
    QString Login;
    QString Password;
    double Balance;
    float Rating;
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

class DataBase
{
public:
    DataBase();
    ~DataBase();

    void Connect();
    void Disconnect();

    bool CheckConnection();
    bool CheckLogin(const QString& _login);
    bool CheckDeposit(const Deposit& _deposite);
    bool CheckCredit(const Credit& _credit);

    void resetUsersRating(const User& _user, float _newrating);

    bool setUser(const User& _user);
    bool setCredit(const Credit& _credit);
    bool setDeposit(const Deposit& _deposite);

    Credit getCredit(int id) const;
    Deposit getDeposite(int id) const;
    User getUser(int id) const;
    User getUser(const QString& _login) const;
    QString getError() const;
    int getLastId() const;
    int getLastIDCredit() const;
    int getLastIDDeposit() const;

protected:
    void ResetIncome(const Credit& _credit);
    void ResetConsumption(const Deposit& _deposit);

private:
    QSqlDatabase m_db;
    QString m_sError;
};
}

#endif // DATABASE_H
