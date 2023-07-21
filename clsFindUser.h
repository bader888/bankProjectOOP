#pragma once
#include "../Global/clsScreen.h"
#include "clsUser.h"

class clsFindUserScreen : protected clsScreen
{
private:
    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.GetFirstName();
        cout << "\nLastName    : " << User.GetLastName();
        cout << "\nFull Name   : " << User.GetFullName();
        cout << "\nEmail       : " << User.GetEmail();
        cout << "\nPhone       : " << User.GetPhone();
        cout << "\nUser Name   : " << User.GetUserName();
        cout << "\nPassword    : " << User.GetPassword();
        cout << "\nPermissions : " << User.GetPermissions();
        cout << "\n___________________\n";
    }

public:
    static void ShowFindUserScreen()
    {

        system("cls");

        _DrawScreenHeader("Find User Screen");

        string UserName = "";

        cout << "\nPlease Enter UserName: ";

        UserName = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUser is not found, choose another one: ";

            UserName = clsInputValidate::ReadString();
        };

        clsUser User1 = clsUser::Find(UserName);

        _PrintUser(User1);
    }
};