#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include "../lab/stringLab.h"
#include "../lab/inputValidation.h"
#include "../lab/DataLab.h"
#include "../ManageUser/clsUser.h"
#include "../ManageClients/clsBankClients.h"
#include "clsPersone.h"
#include "Global.h"

class clsScreen
{
    static void _DrawDateAndUserName()
    {

        string strDate = clsDate::DateToString(clsDate::GetSystemDate());

        string CuurentUserName = CurrentUser.GetUserName();

        cout << setw(37) << left << ""
             << "\t\t"
             << "User Name: " << CuurentUserName << "\n";

        cout << setw(37) << left << ""
             << "\t\t"
             << "Date: " << strDate << "\n";
    }

public:
    static void
    _DrawScreenHeader(const std::string &Title, const string subTitle = " ")
    {
        system("cls");

        cout << setw(37) << left << ""
             << "===========================================\n";
        cout << setw(37) << left << ""
             << "\t\t" << Title << "\n";
        if (subTitle != " ")
        {
            cout << setw(37) << left << ""
                 << "\t\t" << subTitle << "\n";
        }
        cout << setw(37) << left << ""
             << "===========================================\n";

        _DrawDateAndUserName();
    }

    static bool CheckAccessRights(clsUser::enMainMenuePermissions Permission)
    {

        if (!CurrentUser.CheckAccessPermission(Permission))
        {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        }
        else
        {
            return true;
        }
    }

    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nInfo:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.GetFirstName();
        cout << "\nLastName    : " << Client.GetLastName();
        cout << "\nFull Name   : " << Client.GetFullName();
        cout << "\nEmail       : " << Client.GetEmail();
        cout << "\nPhone       : " << Client.GetPhone();
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.GetPinCode();
        cout << "\nBalance     : " << Client.GetAccountBalance();
        cout << "\n___________________\n";
    }
};