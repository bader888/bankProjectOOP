#pragma once
#include "../Global/clsScreen.h"
#include "../lab/inputValidation.h"
#include "../Global/clsMainMenuScreen.h"
#include "clsShowDepositScreen.h"
#include "clsShowWithDrawScreen.h"
#include "clsShowTotalBalances.h"
#include "clsTransferScreen.h"
#include "clsTransferlogScreen.h"

class clsTracnactionScreen : protected clsScreen
{
private:
    enum enTransactionsMenueOptions
    {
        eDeposit = 1,
        eWithdraw = 2,
        eShowTotalBalance = 3,
        eTransfer = 4,
        eTransferLog = 5,
        eShowMainMenue = 6
    };

    static void _ShowDepositScreen()
    {
        clsShowDepositScreen::ShowDepositeScreen();
    }

    static void _ShowWithDrawScreen()
    {
        clsShowWithDrawScreen::ShowWithDrawScreen();
    }

    static void _ShowTotalBalancesScreen()
    {
        clsTotalBalancesScreen::ShowTotalBalances();
    }

    static void _ShowTransferScreen()
    {
        clsTransferScreen::ShowTransferScreen();
    }

    static void _ShowTransferLogScreen()
    {
        clsTransferLogScreen::ShowTransferLogScreen();
    }

    static void _GoBackToTransactionsMenue()
    {
        cout << "\n\nPress any key to go back to Transactions Menue...";
        system("pause>0");
        ShowTransactionsMenueScreen();
    }

    static short _ReadTransactionsMenueOption()
    {
        cout << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 6);

        return Choice;
    }

    static void _PerfromTranactionsMenueOption(enTransactionsMenueOptions TransactionMenueOption)
    {
        switch (TransactionMenueOption)
        {
        case enTransactionsMenueOptions::eDeposit:
        {
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eWithdraw:
        {
            system("cls");
            _ShowWithDrawScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eShowTotalBalance:
        {
            system("cls");
            _ShowTotalBalancesScreen();
            _GoBackToTransactionsMenue();

            break;
        }
        case enTransactionsMenueOptions::eTransferLog:
        {
            system("cls");
            _ShowTransferLogScreen();
            _GoBackToTransactionsMenue();

            break;
        }
        case enTransactionsMenueOptions::eTransfer:
        {
            system("cls");
            _ShowTransferScreen();
            _GoBackToTransactionsMenue();

            break;
        }

        case enTransactionsMenueOptions::eShowMainMenue:
        {
            // clsMainMenuScreen::ShowMainMenue();
        }
        }
    }

public:
    static void ShowTransactionsMenueScreen()
    {
        if (!CheckAccessRights(clsUser::enMainMenuePermissions::pTranactions))
        {
            return; // this will exit the function and it will not continue
        }

        system("cls");

        _DrawScreenHeader("Transaction Screen");
        cout << setw(37) << left << ""
             << "===========================================\n";
        cout << setw(37) << left << ""
             << "\t\tTransaction Menue Screen\n";
        cout << setw(37) << left << ""
             << "===========================================\n";
        cout << setw(37) << left << ""
             << "\t[1] Show Deposite Screen.\n";

        cout << setw(37) << left << ""
             << "\t[2] Show Withdraw Screen.\n";

        cout << setw(37) << left << ""
             << "\t[3] Show Total Balance Screen.\n";

        cout << setw(37) << left << ""
             << "\t[4] Transfer Screen.\n";

        cout << setw(37) << left << ""
             << "\t[5] Transgfer Log Screen.\n";

        cout << setw(37) << left << ""
             << "\t[5] Show Main Menu Screen.\n";

        cout << setw(37) << left << ""
             << "===========================================\n";

        _PerfromTranactionsMenueOption(enTransactionsMenueOptions(_ReadTransactionsMenueOption()));
    };
};