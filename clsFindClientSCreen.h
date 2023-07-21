#include "../Global/clsScreen.h"
#include "clsBankClients.h"

class clsFindClientScreen : protected clsScreen
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
    static void ShowFindClientScreen()

    {
        if (!CheckAccessRights(clsUser::enMainMenuePermissions::pFindClient))
        {
            return; // this will exit the function and it will not continue
        }
        _DrawScreenHeader("Find Client Screen");

        cout << "Enter Account Number: ";

        string AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "The Client Not Exist , Try Another One: ";

            AccountNumber = clsInputValidate::ReadString();
        };

        clsBankClient Client = clsBankClient::Find(AccountNumber);

        if (!Client.IsEmpty())
        {
            cout << "Client Found ;) ";
        }
        else
        {
            cout << "Client not Found ;(";
        }

        _PrintClient(Client);
    }
};
