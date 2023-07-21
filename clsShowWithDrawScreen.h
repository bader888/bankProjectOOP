#pragma once
#include "../Global/clsScreen.h"
#include "../ManageClients/clsBankClients.h"
#include "../lab/inputValidation.h"

class clsShowWithDrawScreen : protected clsScreen
{
public:
    static void ShowWithDrawScreen()
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

        cout << "\nPlease enter WithDraw amount? ";

        float Amount = clsInputValidate::ReadFloatNumber();

        while (Amount > client.GetAccountBalance())
        {
            cout << "You Can't WithDraw This Amount, Try Another Amount:";

            Amount = clsInputValidate::ReadFloatNumber();
        }

        cout << "\nAre you sure you want to perform this transaction? y/n ";

        char Asnwer = clsInputValidate::ReadChar();

        if (Asnwer == 'y' || Asnwer == 'Y')
        {
            client.WithDraw(Amount);

            cout << "\nAmount WithDraw Successfully.\n";

            cout << "\nNew Balance Is: " << client.GetAccountBalance();
        };
    };
};
