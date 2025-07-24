#include "User.h"

User::User(string nameUser, string loginUser, string passwordUser)
    : _nameUser(nameUser), _loginUser(loginUser), _passwordUser(passwordUser)
{
}

string User::GetNameUser() const {
    return _nameUser;
}

string User::GetLoginUser() const {
    return _loginUser;
}

string User::GetPasswordUser() const {
    return _passwordUser;
}

ostream& operator<<(ostream& os, const User& user) {
    os << "Имя: " << user._nameUser << endl;
    os << "Логин: " << user._loginUser << endl;
    os << "Пароль: " << user._passwordUser << endl;
    return os;
}