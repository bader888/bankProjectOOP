#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include "../Global/clsPersone.h"
#include "../Global/Global.h"
#include "../lab/stringLab.h"
#include "../lab/inputValidation.h"

class clsBankClient : public clsPerson
{
private:
    enum enMode
    {
        EmptyMode = 0,
        UpdateMode = 1,
        AddNewClient = 2,
    };
    enMode _Mode;
    string _AccountNumber;
    string _PinCode;
    float _AccountBalance;
    bool _MarkForDelete = false;
    string _PreperTransferRecord(string Seperator, clsBankClient Destination, float Amount, string UserName)
    {
        string TransferLog = "";

        TransferLog += clsDate::GetSystemDateTime() + Seperator;
        TransferLog += this->AccountNumber() + Seperator;
        TransferLog += Destination.AccountNumber() + Seperator;

        TransferLog += to_string(Amount) + Seperator;

        TransferLog += to_string(this->GetAccountBalance()) + Seperator;
        TransferLog += to_string(Destination.GetAccountBalance()) + Seperator;

        TransferLog += UserName;

        return TransferLog;
    }

    void _RegisterTransferLog(clsBankClient Destination, float Amount, string UserName)
    {

        string stDataLine;

        stDataLine = _PreperTransferRecord("#//#", Destination, Amount, UserName);

        fstream MyFile;

        MyFile.open("TransferLog.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }
    }
    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient(enMode::EmptyMode, " ", " ", " ", " ", " ", " ", 110);
    }

    static clsBankClient _ConvertLinetoClientObject(string Line)
    {
        vector<string> vClient = clsString::Split(Line, "#//#");

        return clsBankClient(
            enMode::UpdateMode,
            vClient[0],
            vClient[1],
            vClient[2],
            vClient[3],
            vClient[4],
            vClient[5],
            stod(vClient[6]));
    }

    string _ConvertClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
    {

        string stClientRecord = "";

        stClientRecord += Client.GetFirstName() + Seperator;
        stClientRecord += Client.GetLastName() + Seperator;
        stClientRecord += Client.GetEmail() + Seperator;
        stClientRecord += Client.GetPhone() + Seperator;
        stClientRecord += Client.AccountNumber() + Seperator;
        stClientRecord += Client.GetPinCode() + Seperator;
        stClientRecord += to_string(Client.GetAccountBalance());

        return stClientRecord;
    }

    vector<clsBankClient> _SaveCleintsDataToFile(vector<clsBankClient> vClients)
    {

        fstream MyFile;

        MyFile.open("Clients.txt", ios::out); // overwrite

        string DataLine;

        if (MyFile.is_open())
        {
            for (clsBankClient C : vClients)
            {
                if (C.MarkedForDeleted() == false)
                {
                    // we only write records that are not marked for delete.
                    DataLine = _ConvertClientObjectToLine(C);
                    MyFile << DataLine << endl;
                }
            }

            MyFile.close();
        }

        return vClients;
    }

    static vector<clsBankClient> _LoadCleintsDataFromFile()
    {

        vector<clsBankClient> vClients;

        fstream MyFile;
        MyFile.open("Clients.txt", ios::in); // read Mode

        if (MyFile.is_open())
        {

            string Line;

            while (getline(MyFile, Line))
            {

                clsBankClient Client = _ConvertLinetoClientObject(Line);

                vClients.push_back(Client);
            }

            MyFile.close();
        }

        return vClients;
    }

    void _Update()
    {
        vector<clsBankClient> Vclients = _LoadCleintsDataFromFile();

        for (clsBankClient &C : Vclients)
        {
            if (C.AccountNumber() == AccountNumber())
            {
                C = *this;

                break;
            }
        }

        _SaveCleintsDataToFile(Vclients);
    }

    void _Add()
    {
        _AddDataLineToFile(_ConvertClientObjectToLine(*this, "#//#"));
    }

    void _AddDataLineToFile(string stDataLine)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }
    }

public:
    clsBankClient(
        enMode Mode,
        string FirstName,
        string LastName,
        string Email,
        string Phone,
        string AccountNumber,
        string PinCode,
        float AccountBalance)
        : clsPerson(FirstName, LastName, Email, Phone)
    {
        _Mode = Mode;
        _AccountNumber = AccountNumber;
        _PinCode = PinCode;
        _AccountBalance = AccountBalance;
    }

    struct strTransferLog
    {
        string DateAndTime;
        string Amount;
        string sAccountNumber;
        string dAccountNumber;
        string sAccountBalance;
        string dAccountBalance;
        string UserName;
    };
    static strTransferLog _ConvertTransferLineToObjects(string Line)
    {

        vector<string> vTransferlog = clsString::Split(Line, "#//#");

        strTransferLog Transferlog;

        Transferlog.DateAndTime = vTransferlog[0];
        Transferlog.Amount = vTransferlog[1];
        Transferlog.sAccountNumber = vTransferlog[2];
        Transferlog.dAccountNumber = vTransferlog[3];
        Transferlog.sAccountBalance = vTransferlog[4];
        Transferlog.dAccountBalance = vTransferlog[5];
        Transferlog.UserName = vTransferlog[6];

        return Transferlog;
    };

    string AccountNumber()
    {
        return _AccountNumber;
    }

    void SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }

    string GetPinCode()
    {
        return _PinCode;
    }

    void SetAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }

    float GetAccountBalance()
    {
        return _AccountBalance;
    }

    bool MarkedForDeleted()
    {
        return _MarkForDelete;
    }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    static clsBankClient Find(string AccountNumber)
    {

        fstream MyFile;
        MyFile.open("Clients.txt", ios::in); // read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);

                if (Client.AccountNumber() == AccountNumber)
                {
                    MyFile.close();

                    return Client;
                }
            }

            MyFile.close();
        }

        return _GetEmptyClientObject();
    }

    static clsBankClient Find(string AccountNumber, string PinCode)
    {

        fstream MyFile;
        MyFile.open("Clients.txt", ios::in); // read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.AccountNumber() == AccountNumber && Client.GetPinCode() == PinCode)
                {
                    MyFile.close();

                    return Client;
                }
            }

            MyFile.close();
        }

        return _GetEmptyClientObject();
    }

    static bool IsClientExist(string AccountNumber)
    {
        clsBankClient Client = clsBankClient::Find(AccountNumber);

        return (!Client.IsEmpty());
    }

    static clsBankClient GetAddNewClientObject(string AccountNumber)
    {
        return clsBankClient(enMode::AddNewClient, " ", " ", " ", " ", AccountNumber, " ", 0);
    }

    enum enSaveResults
    {
        svFaildEmptyObject = 0,
        svSucceeded = 1,
        svFaildAccountNumberExist = 3
    };

    enSaveResults Save()
    {

        switch (_Mode)
        {

        case enMode::EmptyMode:

            return enSaveResults::svFaildEmptyObject;

            break;

        case enMode::UpdateMode:

            _Update();

            return enSaveResults::svSucceeded;

            break;

        case enMode::AddNewClient:

            if (clsBankClient::IsClientExist(_AccountNumber))
            {
                return enSaveResults::svFaildAccountNumberExist;
            }
            else
            {
                _Add();

                _Mode = enMode::UpdateMode;

                return enSaveResults::svSucceeded;
            }
            break;
        }
    }

    bool Delete()
    {
        vector<clsBankClient> _vClients;
        _vClients = _LoadCleintsDataFromFile();

        for (clsBankClient &C : _vClients)
        {
            if (C.AccountNumber() == _AccountNumber)
            {
                C._MarkForDelete = true;
                break;
            }
        }
        _SaveCleintsDataToFile(_vClients);

        *this = _GetEmptyClientObject();

        return true;
    }

    void Deposit(float Amount)
    {
        _AccountBalance += Amount;

        Save();
    }

    void WithDraw(float Amount)
    {
        if (Amount > _AccountBalance)
        {
            cout << "You Can't WithDraw This Amount, Try Another Amount:";
        }
        else
        {
            _AccountBalance -= Amount;

            Save();
        };
    }

    static double GetTotalBalances()
    {
        vector<clsBankClient> vClients = _LoadCleintsDataFromFile();

        double ToatalBalance = 0;

        for (clsBankClient C : vClients)
        {
            ToatalBalance += C.GetAccountBalance();
        }

        return ToatalBalance;
    }

    static vector<clsBankClient> GetClientsList()
    {
        return _LoadCleintsDataFromFile();
    }

    bool Transfer(float Amount, clsBankClient &DestinationClient, string UserName)
    {
        if (Amount > this->GetAccountBalance())
        {
            return false;
        }

        this->WithDraw(Amount);

        DestinationClient.Deposit(Amount);

        _RegisterTransferLog(DestinationClient, Amount, UserName);
        return true;
    }

    static vector<strTransferLog> GetTransferLog()
    {

        fstream MyFile;

        vector<strTransferLog> vloginRegistersUsers;

        MyFile.open("TransferLog.txt", ios::in); // read Mode

        if (MyFile.is_open())
        {
            string Line;

            while (getline(MyFile, Line))
            {
                strTransferLog loginRegisterUser = _ConvertTransferLineToObjects(Line);

                vloginRegistersUsers.push_back(loginRegisterUser);
            }

            MyFile.close();
        }

        return vloginRegistersUsers;
    }
};