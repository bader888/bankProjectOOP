#pragma once
#include "../Global/clsScreen.h"
#include "clsBankClients.h"
#include "../lab/inputValidation.h"

class clsDeleteClientScreen : protected clsScreen
{

private:
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

public:
    static void ShowDeleteClientScreen()
    {
        if (!CheckAccessRights(clsUser::enMainMenuePermissions::pDeleteClient))
        {
            return; // this will exit the function and it will not continue
        }

        _DrawScreenHeader("Delete Client Screen");

        cout << "Enter Account Number: ";

        string AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "The Client Not Exist , Try Another One: ";

            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);

        _PrintClient(Client);

        cout << "Are your sure you want delete this Client? y/n: ";
        char Asnwer = clsInputValidate::ReadChar();
        if (Asnwer == 'y' || Asnwer == 'Y')
        {

            if (Client.Delete())
            {

                cout << "The Client Deleted, successfully";
            }
            else
            {
                cout << "The Client Deleted, Faild";
            }
        }
    }
};