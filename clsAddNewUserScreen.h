#pragma once
#include "../Global/clsScreen.h"
#include "../lab/inputValidation.h"
#include "clsUser.h"

class clsAddNewUserScreen : protected clsScreen
{
private:
    static int _ReadPermissionsToSet()
    {

        int Permissions = 0;
        char Answer = 'n';

        cout << "\nDo you want to give full access? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            return -1;
        }

        cout << "\nDo you want to give access to : \n ";

        cout << "\nShow Client List? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {

            Permissions += clsUser::enMainMenuePermissions::pListClients;
        }

        cout << "\nAdd New Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enMainMenuePermissions::pAddNewClient;
        }

        cout << "\nDelete Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enMainMenuePermissions::pDeleteClient;
        }

        cout << "\nUpdate Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enMainMenuePermissions::pUpdateClients;
        }

        cout << "\nFind Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enMainMenuePermissions::pFindClient;
        }

        cout << "\nTransactions? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enMainMenuePermissions::pTranactions;
        }

        cout << "\nManage Users? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enMainMenuePermissions::pManageUsers;
        }

        cout << "\nShow login Register? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enMainMenuePermissions::pListlogInRegisters;
        }

        return Permissions;
    }

    static clsUser _ReadNewUser(string UserName)
    {

        clsUser NewUser = clsUser::GetAddNewUserObject(UserName);

        cout << "Enter First Name? ";
        NewUser.SetFirstName(clsInputValidate::ReadString());
        cout << endl;

        cout << "Enter Last Name? ";
        NewUser.SetLastName(clsInputValidate::ReadString());
        cout << endl;

        cout << "Enter Phone Number? ";
        NewUser.SetPhone(clsInputValidate::ReadString());
        cout << endl;

        cout << "Enter Email? ";
        NewUser.SetEmail(clsInputValidate::ReadString());
        cout << endl;

        cout << "Enter Password? ";
        NewUser.SetPassword(clsInputValidate::ReadString());
        cout << endl;

        NewUser.SetPermissions(_ReadPermissionsToSet());
        cout << endl;

        return NewUser;
    }

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
    static void ShowAddNewUserScreen()
    {
        system("cls");

        _DrawScreenHeader("Add New User Screen");

        cout << "Enter User Name: ";

        string UserName = clsInputValidate::ReadString();

        while (clsUser::IsUserExist(UserName))
        {

            cout << "\nUser with [" << UserName << "] already exists, Enter another Username? ";

            UserName = clsInputValidate::ReadString();
        }

        clsUser NewUser = _ReadNewUser(UserName);

        clsUser::enSaveResults SaveResult;

        SaveResult = NewUser.Save();

        switch (SaveResult)
        {
        case clsUser::enSaveResults::svSucceeded:
        {
            cout << "\nUser Addeded Successfully :-)\n";

            _PrintUser(NewUser);

            break;
        }
        case clsUser::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError User was not saved because it's Empty";
            break;
        }
        case clsUser::enSaveResults::svFaildUserExists:
        {
            cout << "\nError User was not saved because UserName is used!\n";
            break;
        }
        }
    }
};