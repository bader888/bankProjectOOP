#pragma once
#include "../Global/clsScreen.h"
#include "../ManageClients/clsAllClientsScreen.h"
#include "../ManageClients/clsAddNewClientScreen.h"
#include "../ManageClients/clsDeleteClientScreen.h"
#include "../ManageClients/clsUpdateClientScreen.h"
#include "../ManageClients/clsFindClientSCreen.h"
#include "../TransaCtion/clsTransActionScreen.h"
#include "../ManageUser/clsManageUserScreen.h"
#include "../ManageUser/clsLoginRegister.h"
#include "../Currancy/clsCurrencyScreen.h"
#include "Global.h"

class clsMainMenuScreen : public clsScreen
{
private:
    enum enMainMenueOptions
    {
        eListClients = 1,
        eAddNewClient = 2,
        eDeleteClient = 3,
        eUpdateClient = 4,
        eFindClient = 5,
        eShowTransactionsMenue = 6,
        eManageUsers = 7,
        eloginRegister = 8,
        eCurrency = 9,
        eExit = 10
    };

    static void _GoBackToMainMenue()
    {
        cout << "\n\nPress any key to go back to Main Menue...";

        system("pause>0");

        system("cls");

        ShowMainMenue();
    }

    static void _ShowAllClientsScreen()
    {

        clsClientListScreen::ShowClientsList();
    }

    static void _ShowAddNewClientsScreen()
    {
        clsAddNewClientScreen::ShowAddNewClientsScreen();
    }

    static void _ShowDeleteClientScreen()
    {
        clsDeleteClientScreen::ShowDeleteClientScreen();
    }

    static void _ShowUpdateClientScreen()
    {
        clsUpdateClientScreen::ShowUpdateClientScreen();
    }

    static void _ShowFindClientScreen()
    {
        clsFindClientScreen::ShowFindClientScreen();
    }

    static void _ShowTransactionsMenue()
    {
        clsTracnactionScreen::ShowTransactionsMenueScreen();
    }

    static void _ShowManageUsersMenue()
    {
        clsManageUsersScreen::ShowManageUsersMenue();
    }

    static void _ShowLogInRegisterScreen()
    {
        clsLoginRegisterScreen::ShowLoginRegisterScreen();
    }

    static void _ShowCurrencyScreen()
    {
        clsCurrencyScreen::ShowCurrencyScreen();
    }

    static void _LogOut()
    {
        CurrentUser = clsUser::Find(" ", " ");

        //    than go back to main menu
    }

    static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
    {
        switch (MainMenueOption)
        {
        case enMainMenueOptions::eListClients:

            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eAddNewClient:
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eDeleteClient:
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eUpdateClient:
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eFindClient:
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eShowTransactionsMenue:
            system("cls");
            _ShowTransactionsMenue();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eManageUsers:
            system("cls");
            _ShowManageUsersMenue();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eloginRegister:
            system("cls");
            _ShowLogInRegisterScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eCurrency:
            system("cls");
            _ShowCurrencyScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eExit:
            system("cls");
            _LogOut();
            break;
        }
    }

    static short _ReadMainMenueOption()
    {
        cout << setw(37) << left << ""
             << "Choose what do you want to do? [1 to 10]?? ";
        short Choice = 0;

        Choice = clsInputValidate::ReadShortNumberBetween(1, 10);

        return Choice;
    }

public:
    static void ShowMainMenue()
    {
        system("cls");

        _DrawScreenHeader("\tMain Screen");
        cout << setw(37) << left << ""
             << "===========================================\n";
        cout << setw(37) << left << ""
             << "\t\t Main Menue Screen\n";
        cout << setw(37) << left << ""
             << "===========================================\n";

        cout << setw(37) << left << ""
             << "\t[1] Show Client List.\n";

        cout << setw(37) << left << ""
             << "\t[2] Add New Client.\n";

        cout << setw(37) << left << ""
             << "\t[3] Delete Client.\n";

        cout << setw(37) << left << ""
             << "\t[4] Update Client Info.\n";

        cout << setw(37) << left << ""
             << "\t[5] Find Client.\n";

        cout << setw(37) << left << ""
             << "\t[6] Transactions.\n";

        cout << setw(37) << left << ""
             << "\t[7] Manage Users.\n";

        cout << setw(37) << left << ""
             << "\t[8] LogIn Regester.\n";

        cout << setw(37) << left << ""
             << "\t[9] Currency.\n";

        cout << setw(37) << left << ""
             << "\t[10] Logout.\n";

        cout << setw(37) << left << ""
             << "===========================================\n";

        _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
    }
};