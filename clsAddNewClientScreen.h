#pragma Once
#include "../Global/clsScreen.h"
#include "clsBankClients.h"
#include "../lab/inputValidation.h"
class clsAddNewClientScreen : protected clsScreen
{

private:
    static clsBankClient _ReadNewClient(string AccountNumber)
    {

        clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

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
    static void ShowAddNewClientsScreen()
    {
        if (!CheckAccessRights(clsUser::enMainMenuePermissions::pAddNewClient))
        {
            return; // this will exit the function and it will not continue
        }
        _DrawScreenHeader("Add New Clients Screen");

        cout << "Enter Account Number: ";

        string AccountNumber = clsInputValidate::ReadString();

        while (clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "The Client Exist , Try Another One: ";

            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient NewClient = _ReadNewClient(AccountNumber);

        cout << "Are you sure you want Add this client? y/n ?";

        char Answer = clsInputValidate::ReadChar();

        clsBankClient::enSaveResults SaveResult;

        SaveResult = NewClient.Save();

        switch (SaveResult)
        {
        case clsBankClient::enSaveResults::svSucceeded:

            cout << "\nAccount Addeded Successfully :-)\n";

            _PrintClient(NewClient);

            break;

        case clsBankClient::enSaveResults::svFaildEmptyObject:

            cout << "\nError account was not saved because it's Empty";
            break;

        case clsBankClient::enSaveResults::svFaildAccountNumberExist:

            cout << "\nError account was not saved because account number is used!\n";

            break;
        }
    }
};