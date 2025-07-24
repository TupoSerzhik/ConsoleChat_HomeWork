#pragma once
#include <iostream>
#include <string>

using namespace std;

class User
{
private:
    string _nameUser;
    string _loginUser;
    string _passwordUser;

public:
    User() = default;
    User(string nameUser, string loginUser, string passwordUser);

    string GetNameUser() const;
    string GetLoginUser() const;
    string GetPasswordUser() const;

    friend ostream& operator<<(ostream& os, const User& user);

    ~User() = default;
};