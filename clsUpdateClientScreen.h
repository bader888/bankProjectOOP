#pragma once
#include "../Global/clsScreen.h"
#include "../lab/inputValidation.h"
#include "clsBankClients.h"

class clsUpdateClientScreen : protected clsScreen
{
private:
    static clsBankClient _ReadNewClient(string AccountNumber)
    {

        clsBankClient NewClient = clsBankClient::Find(AccountNumber);

        cout << endl;
        cout << "Enter First Name: ";
        NewClient.SetFirstName(clsInputValidate::ReadString());
        cout << endl;

        cout << "Enter Last Name: ";
        NewClient.SetLastName(clsInputValidate::ReadString());
        cout << endl;

        cout << "Enter Phone: ";
        NewClient.SetPhone(clsInputValidate::ReadString());
        cout << endl;

        cout << "Enter Email: ";
        NewClient.SetEmail(clsInputValidate::ReadString());
        cout << endl;

        cout << "Enter Pin Code: ";
        NewClient.SetPinCode(clsInputValidate::ReadString());
        cout << endl;

        cout << "Enter Account Balance: ";
        NewClient.SetAccountBalance(clsInputValidate::ReadFloatNumber());
        cout << endl;

        return NewClient;
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

public:
    static void ShowUpdateClientScreen()

    {
        if (!CheckAccessRights(clsUser::enMainMenuePermissions::pUpdateClients))
        {
            return; // this will exit the function and it will not continue
        }
        _DrawScreenHeader("Update Client Screen");

        cout << "Enter Account Number: ";

        string AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "The Client Not Exist , Try Another One: ";

            AccountNumber = clsInputValidate::ReadString();
        };

        clsBankClient Client = clsBankClient::Find(AccountNumber);

        _PrintClient(Client);

        cout << "Are You Sure You Want Upate This Client ? y/n: ";

        char Asnwer = clsInputValidate::ReadChar();

        if (Asnwer == 'y' || Asnwer == 'Y')
        {

            Client = _ReadNewClient(AccountNumber);

            clsBankClient::enSaveResults SaveResult;

            SaveResult = Client.Save();

            switch (SaveResult)
            {
            case clsBankClient::enSaveResults::svSucceeded:

                cout << "The Client Updated, successfully";
                break;

            case clsBankClient::enSaveResults::svFaildEmptyObject:

                cout << "The Client Updated, Faild";
                break;
            }
        }
    };
};