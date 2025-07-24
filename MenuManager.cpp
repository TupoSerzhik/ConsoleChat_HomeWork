#include "MenuManager.h"
#include "Chat.h"
#include "User.h"
#include <iostream>
#include <string>
#include "Message.h"
using namespace std;

// Глобальные переменные (для простоты)

Chat localChat;
bool ReplayChat = true;
bool ReplayLocalChat = true;
bool onDialog = true;
void StartMenu() {
    char user_choice;

    // Предзагрузка тестовых пользователей
    localChat.AddUser(User("Василий", "Vasya1975", "Vor777"));
    localChat.AddUser(User("Игнатий", "Lol228", "12345"));
    localChat.AddUser(User("Лёха", "Smotryashiy", "ZonaNePrigovor"));

    while (ReplayChat) {
        string send = "";
        cout << "-=-=-=-=-=-=-=-=- Вы попали в главное меню -=-=-=-=-=-=-=-=-" << endl;
        cout << "1 - Зарегистрироваться" << endl;
        cout << "2 - Войти в аккаунт" << endl;
        cout << "3 - Закрыть" << endl << "=> ";

        cin >> user_choice;
        system("cls"); // или "clear" на Linux/Mac

        switch (user_choice) {
        case '1': {
            string name, login, password;
            cout << "-=-=-=-=-=-=-=-=- Регистрация -=-=-=-=-=-=-=-=-" << endl;
            cout << "Чтобы выйти, введите '!'" << endl;

            cout << "Введите имя: ";
            cin >> name;
            if (name == "!") { system("cls"); break; }

            cout << "Введите логин: ";
            cin >> login;
            if (login == "!") { system("cls"); break; }

            if (!localChat.IsLoginUnique(login)) {
                cout << "Ошибка: логин уже занят!" << endl;
                cout << "Нажмите любую клавишу для продолжения..." << endl;
                cin.ignore();
                cin.get();
                system("cls");
                break;
            }

            cout << "Введите пароль: ";
            cin >> password;
            if (password == "!") { system("cls"); break; }

            localChat.AddUser(User(name, login, password));
            cout << "Регистрация успешна!" << endl;
            cout << "Нажмите любую клавишу для продолжения..." << endl;
            cin.ignore();
            cin.get();
            system("cls");
            break;
        }
        case '2': {
            string login, password;
            cout << "-=-=-=-=-=-=-=-=- Вход в аккаунт -=-=-=-=-=-=-=-=-" << endl;
            cout << "Чтобы выйти, введите '!'" << endl;

            cout << "Введите логин: ";
            cin >> login;
            if (login == "!") { system("cls"); break; }

            cout << "Введите пароль: ";
            cin >> password;
            if (password == "!") { system("cls"); break; }

            if (localChat.CheckPassword(login, password)) {
                cout << "Вы успешно вошли!" << endl;
                cout << "Нажмите любую клавишу для продолжения..." << endl;
                cin.ignore();
                cin.get();
                system("cls");

                char localChoice;
                localChat.ActiveChat();
                while (ReplayLocalChat) {
            
                    cout << "Меню пользователя:" << endl;
                    cout << "1 - Посмотреть информацию" << endl;
                    cout << "2 - Отправить личное сообщение" << endl;
                    cout << "3 - Отправить общее сообщение (заглушка)" << endl;
                    cout << "4 - Выйти" << endl << "=> ";
                    cin >> localChoice;
                    system("cls");
                    string user_message;
                    Message message(user_message);
                    switch (localChoice) {
                    case '1':
                        localChat.ShowInfoUser(login);
                        cout << "\nНажмите любую клавишу для возврата..." << endl;
                        cin.ignore();
                        cin.get();
                        system("cls");
                        break;

                    case '2':
                        
                        int choiseDialog;
                        cout << "Выберете номер участника \nс кем хотите войти в диолог" << endl << endl;
                        localChat.ShowAllUsers(login);
                        cout << endl << endl << "=>  ";
                        cin >> choiseDialog;
                        if (choiseDialog < localChat.GetCount());
                        system("cls");
                        
                        while (onDialog)
                        {   
                           
                            cout << "      | Диалог с " << localChat.NameUserPoz(choiseDialog) << "|";
                            cout << endl << "Чтобы выйти из диалога введите !" << endl << endl;
                            localChat.printDialog(login);
                            cout <<endl <<  "=>  ";
                            cin >> user_message;
                            
                            if (user_message == "!")
                            {
                                localChat.SetStopSignal();
                                system("cls");
                                break;
                            }
                            system("cls");
                            localChat.AddMessage(user_message);
                        }

                       
                        system("cls");
                        
                        break;
                        
                    case '3':
                        cout << "Общий чат" << endl << endl;
                        while (onDialog)
                        {

                            cout << "      | Диалог с "; localChat.UsersName();cout << "|";
                            cout << endl << "Чтобы выйти из диалога введите !" << endl << endl;
                            localChat.printDialog(login);
                            cout << endl << "=>  ";
                            cin >> user_message;

                            if (user_message == "!")
                            {
                                localChat.SetStopSignal();
                                system("cls");
                                break;
                            }
                            system("cls");
                            localChat.AddMessage(user_message);
                        }

                       
                        system("cls");
                        break;
                    case '4':
                        ReplayLocalChat = false;
                        system("cls");
                        break;
                    default:
                        cout << "Неверный выбор!" << endl;
                        cin.ignore();
                        cin.get();
                        system("cls");
                        break;
                    }
                }
                ReplayLocalChat = true; // Сброс для следующего входа
            }
            else {
                cout << "Неверный логин или пароль!" << endl;
                cout << "Нажмите любую клавишу для продолжения..." << endl;
                cin.ignore();
                cin.get();
                system("cls");
            }
            break;
        }
        case '3':
            ReplayChat = false;
            break;
        default:
            cout << "Неверный выбор! Попробуйте снова." << endl;
            cout << "Нажмите любую клавишу для продолжения..." << endl;
            cin.ignore();
            cin.get();
            system("cls");
            break;
        }
    }
}