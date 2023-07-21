#pragma once
#include "../Global/clsScreen.h"
#include "../lab/inputValidation.h"

class clsTransferLogScreen : protected clsScreen
{
    static void _PrintTransferLogRecord(clsBankClient::strTransferLog TransferLog)
    {
        cout << setw(8) << left << ""
             << "| " << left << setw(35) << TransferLog.DateAndTime;
        cout << "| " << left << setw(10) << TransferLog.Amount;
        cout << "| " << left << setw(10) << TransferLog.sAccountNumber;
        cout << "| " << left << setw(10) << TransferLog.dAccountNumber;
        cout << "| " << left << setw(10) << TransferLog.sAccountBalance;
        cout << "| " << left << setw(10) << TransferLog.dAccountBalance;
        cout << "| " << left << setw(10) << TransferLog.UserName;
        cout << setw(8) << left << "";
        cout << endl;
    }

public:
    static void ShowTransferLogScreen()
    {
        _DrawScreenHeader("Transfer Log Screen");

        vector<clsBankClient::strTransferLog> vTransferLog = clsBankClient::GetTransferLog();

        cout << setw(8) << left << ""
             << "\n\t_______________________________________________________";
        cout << "_________________________________________\n"
             << endl;

        cout << setw(8) << left << ""
             << "| " << left << setw(35) << "Date/Time";
        cout << "| " << left << setw(10) << "Amount";
        cout << "| " << left << setw(10) << "s.Account";
        cout << "| " << left << setw(10) << "d.Account";
        cout << "| " << left << setw(10) << "s.Balance";
        cout << "| " << left << setw(10) << "d.Balance";
        cout << "| " << left << setw(10) << "Username";

        cout << setw(8) << left << ""
             << "\n\t_______________________________________________________";
        cout << "_________________________________________\n"
             << endl;

        if (vTransferLog.size() == 0)
            cout << "\t\t\t\tNo Transfer Available In the System!";
        else

            for (clsBankClient::strTransferLog T : vTransferLog)
            {
                _PrintTransferLogRecord(T);
            }

        cout << setw(8) << left << ""
             << "\n\t_______________________________________________________";
        cout << "_________________________________________\n"
             << endl;
    }
};