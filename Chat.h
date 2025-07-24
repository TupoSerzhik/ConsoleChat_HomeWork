#pragma once
#include "User.h"
#include "Message.h"

class Chat {
private:
    static const int MAX_MESSAGE = 100000;
    static const int MAX_USERS = 100;
    int countMessage;
    int countUser;
    User* _UserData;
    Message* _MessegeData;
    int StopSignal;
public:
    Chat();
    ~Chat();

    void ActiveChat();
    void AddUser(const User& user);
    int GetCount() const;
    bool CheckPassword(const string& login, const string& password) const;
    bool IsLoginUnique(const string& login) const;
    void ShowInfoUser(const string& login) const;
    void ShowAllUsers(string& login) const;
    void AddMessage(Message message); // 3 - общий чат    2 - личный чат 
    string NameUserPoz(int poz);
   
    void SetStopSignal();
    int GetStop();

    void printDialog(string& login);
 
    void UsersName();
};