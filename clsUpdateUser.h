#pragma once
#include "../Global/clsScreen.h"
#include "clsUser.h"

class clsShowUpdateUserScreen : protected clsScreen
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

        return Permissions;
    }

    static clsUser _ReadUpdateUser(clsUser &User)
    {

        cout << "Enter First Name? ";
        User.SetFirstName(clsInputValidate::ReadString());
        cout << endl;

        cout << "Enter Last Name? ";
        User.SetLastName(clsInputValidate::ReadString());
        cout << endl;

        cout << "Enter Phone Number? ";
        User.SetPhone(clsInputValidate::ReadString());
        cout << endl;

        cout << "Enter Email? ";
        User.SetEmail(clsInputValidate::ReadString());
        cout << endl;

        cout << "Enter Password? ";
        User.SetPassword(clsInputValidate::ReadString());
        cout << endl;

        User.SetPermissions(_ReadPermissionsToSet());
        cout << endl;

        return User;
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
    static void ShowUpdateUserScreen()
    {
        system("cls");

        _DrawScreenHeader("Update User Screen");

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

        cout << "\nAre you sure you want to Update this User y/n? ";

        char Answer = 'n';

        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

            User1 = _ReadUpdateUser(User1);
            clsUser::enSaveResults SaveResult;

            SaveResult = User1.Save();

            switch (SaveResult)
            {
            case clsUser::enSaveResults::svSucceeded:
            {
                cout << "\nUser Updated Successfully :-)\n";

                _PrintUser(User1);

                break;
            }
            case clsUser::enSaveResults::svFaildEmptyObject:
            {
                cout << "\nError User was not Updated because it's Empty";
                break;
            }
            case clsUser::enSaveResults::svFaildUserExists:
            {
                cout << "\nError User was not Updated because UserName is used!\n";
                break;
            }
            }
        }
    }
};
