#pragma once
#include "../Global/clsScreen.h"
#include "../ManageClients/clsBankClients.h"

class clsShowDepositScreen : protected clsScreen
{
public:
    static void ShowDepositeScreen()
    {
        system("cls");

        _DrawScreenHeader("Deposite Screen");

        cout << "Enter Account Number: ";

        string AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nClient with [" << AccountNumber << "] does not exist.\n";

            AccountNumber = clsInputValidate::ReadString();
        };

        clsBankClient client = client.Find(AccountNumber);

        clsScreen::_PrintClient(client);

        cout << "\nPlease enter deposit amount? ";

        float Amount = clsInputValidate::ReadFloatNumber();

        cout << "\nAre you sure you want to perform this transaction? y/n ";

        char Asnwer = clsInputValidate::ReadChar();

        if (Asnwer == 'y' || Asnwer == 'Y')
        {
            client.Deposit(Amount);

            cout << "\nAmount Deposited Successfully.\n";

            cout << "\nNew Balance Is: " << client.GetAccountBalance();
        };
    };
};