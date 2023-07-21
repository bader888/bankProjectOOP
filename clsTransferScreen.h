#include "../Global/clsScreen.h"
#include "../ManageClients/clsBankClients.h"
#include "../lab/inputValidation.h"

class clsTransferScreen : protected clsScreen
{
    static string _ReadAccountNumber()
    {
        string AccountNumber = "";
        // Usage of std::ws will extract allthe whitespace character
        getline(cin >> ws, AccountNumber);

        clsBankClient client = clsBankClient::Find(AccountNumber);

        while (client.IsEmpty())
        {
            cout << "The Client not found, try another one: ";
            AccountNumber = clsInputValidate::ReadString();
            client = clsBankClient::Find(AccountNumber);
        }

        return AccountNumber;
    }

    static float _ReadAmount(clsBankClient SourceClient)
    {
        float Amount = 0;

        cin >> Amount;

        while (Amount > SourceClient.GetAccountBalance())
        {
            cout << "The Amount biggest than Account balance, try another Amount: ";
            Amount = clsInputValidate::ReadFloatNumber();
        }

        return Amount;
    }

    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nInfo:";
        cout << "\n___________________";
        cout << "\nFull Name   : " << Client.GetFullName();
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nBalance     : " << Client.GetAccountBalance();
        cout << "\n___________________\n";
    }

public:
    static void ShowTransferScreen()
    {
        _DrawScreenHeader("Transfer Screen");

        cout << "\nEnter Account Number of Client you want transfer from: ";
        clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber());
        _PrintClient(SourceClient);

        cout << "\nEnter Account Number of Client you want transfer To: ";
        clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber());
        _PrintClient(DestinationClient);

        cout << "\nEnter Amount of money you want transfer from [" << SourceClient.GetFullName() << "] to [" << DestinationClient.GetFullName() << "]";
        float Amount = _ReadAmount(SourceClient);

        cout << "\nAre you sure you want to perform this operation? y/n? ";
        char Answer = 'n';
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            if (SourceClient.Transfer(Amount, DestinationClient, CurrentUser.GetUserName()))
            {
                cout << "\nThe Transfer done successfully";
            }
            else
            {
                cout << "\nThe transfer Faild ;(";
            }

            _PrintClient(SourceClient);
            _PrintClient(DestinationClient);
        }
    }
};