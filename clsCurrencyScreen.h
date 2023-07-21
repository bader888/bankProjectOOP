#pragma once
#include "../Global/clsScreen.h"
#include "../Global/clsMainMenuScreen.h"
#include "clsCurrency.h"
#include "clsFindCurrency.h"
#include "clsUpdateCurrency.h"
#include "clsCalculateCurrency.h"
#include "clsListCurrencies.h"

class clsCurrencyScreen : protected clsScreen
{

private:
    static void _ListCurrencyScreen()
    {
        clsListCurrenciesScreen::ShowListCurrenciesScreen();
    };

    static void _FindCurrencyScreen()
    {
        clsFindCurrencyScreen::ShowFindCurrencyScreen();
    };

    static void _UpdateCurrencyScreen()
    {
        clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
    };

    static void _CalacuateCurrencyScreen()
    {
        clsCalculateCurrencyScreen::ShowCalculateCurrencyScreen();
    };

    enum enCurrencyOptions
    {
        CurrencyList = 1,
        FindCurrency = 2,
        UpdateCurrency = 3,
        CalculateCurrency = 4,
        MainMenu = 5,
    };
    static void _GoBackToMainMenue()
    {
        cout << "\n\nPress any key to go back to Main Menue...";

        system("pause>0");

        system("cls");

        ShowCurrencyScreen();
    }

    static void _PerformCurrencyOptions(enCurrencyOptions Option)
    {
        switch (Option)
        {
        case enCurrencyOptions::CurrencyList:
            system("cls");
            _ListCurrencyScreen();
            _GoBackToMainMenue();

            break;

        case enCurrencyOptions::FindCurrency:
            system("cls");
            _FindCurrencyScreen();
            _GoBackToMainMenue();

            break;

        case enCurrencyOptions::UpdateCurrency:
            system("cls");
            _UpdateCurrencyScreen();
            _GoBackToMainMenue();

            break;

        case enCurrencyOptions::CalculateCurrency:
            system("cls");
            _CalacuateCurrencyScreen();
            _GoBackToMainMenue();

            break;

        case enCurrencyOptions::MainMenu:

            break;
        }
    }

    static short _ReadCurrencyOptions()
    {
        short Option = 0;
        cout << setw(37) << left << ""
             << "Chose What Do You Want To Do [1-5]: ";

        Option = clsInputValidate::ReadShortNumberBetween(1, 5);

        return Option;
    };

public:
    static void
    ShowCurrencyScreen()
    {
        _DrawScreenHeader("Currency Screen");

        cout << setw(37) << left << ""
             << "===========================================\n";
        cout << setw(37) << left << ""
             << "\t\t Main Currency Screen\n";
        cout << setw(37) << left << ""
             << "===========================================\n";

        cout << setw(37) << left << ""
             << "\t[1] Show Currency List.\n";

        cout << setw(37) << left << ""
             << "\t[2] Find Currency.\n";

        cout << setw(37) << left << ""
             << "\t[3] Update Currency.\n";

        cout << setw(37) << left << ""
             << "\t[4] Calculate Currency.\n";

        cout << setw(37) << left << ""
             << "\t[5] Main Menu.\n";

        cout << setw(37) << left << ""
             << "===========================================\n";

        _PerformCurrencyOptions(enCurrencyOptions(_ReadCurrencyOptions()));
    }
};