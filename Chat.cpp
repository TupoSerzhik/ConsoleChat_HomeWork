#include "Chat.h"
#include <iostream>

using namespace std;

Chat::Chat() : countUser(0), _UserData(new User[MAX_USERS]) {}

Chat::~Chat() {
    delete[] _UserData;
}

void Chat::ActiveChat()
{
    _MessegeData = new Message[MAX_MESSAGE];
    
}

void Chat::AddUser(const User& user) {
    if (countUser < MAX_USERS) {
        _UserData[countUser] = user;
        countUser++;
    }
    else {
        cout << "Достигнут лимит пользователей!" << endl;
    }
}

int Chat::GetCount() const {
    return countUser;
}

bool Chat::CheckPassword(const string& login, const string& password) const {
    for (int i = 0; i < countUser; ++i) {
        if (_UserData[i].GetLoginUser() == login && _UserData[i].GetPasswordUser() == password) {
            return true;
        }
    }
    return false;
}

bool Chat::IsLoginUnique(const string& login) const {
    for (int i = 0; i < countUser; ++i) {
        if (_UserData[i].GetLoginUser() == login) {
            return false; // Логин уже занят
        }
    }
    return true;
}

void Chat::ShowInfoUser(const string& login) const {
    for (int i = 0; i < countUser; ++i) {
        if (_UserData[i].GetLoginUser() == login) {
            cout << "Имя: " << _UserData[i].GetNameUser() << endl;
            cout << "Логин: " << _UserData[i].GetLoginUser() << endl;
            cout << "Пароль: " << _UserData[i].GetPasswordUser() << endl;
            return;
        }
    }
    cout << "Пользователь не найден." << endl;
}

void Chat::ShowAllUsers(string& login) const 
{
    int id = 1;
    if (countUser == 0) {
        cout << "Нет зарегистрированных пользователей." << endl;
        return;
    }
    for (int i = 0; i < countUser; ++i) 
    {
        
        if (_UserData[i].GetLoginUser() != login)
        {
            cout << "ID: " << id << endl;
            cout << "Имя: " << _UserData[i].GetNameUser() << endl;
            cout << "Логин: " << _UserData[i].GetLoginUser() << endl << endl;
            id++;

        }
    }
}

void Chat::AddMessage(Message message)
{
    if (countMessage < MAX_MESSAGE)
    {
        _MessegeData[countMessage] = message;
        countMessage++;
    }
}

string Chat::NameUserPoz(int poz)
{
    return _UserData[poz - 1].GetNameUser();
}

void Chat::SetStopSignal()
{
    StopSignal = countMessage;
}

int Chat::GetStop()
{
    return StopSignal;
}



void Chat::printDialog(string& login)
{
    
    for (int i = StopSignal; i < countMessage;i++)
    {
        cout << login << ": " << _MessegeData[i].GetMessage() << endl;
    }
}

void Chat::UsersName()
{
    for (int i = 0; i < countUser; i++)
    {
        cout << _UserData[i].GetNameUser() << ", ";
    }
}




