#pragma once
#include "../Global/clsScreen.h"
#include "../ManageUser/clsUser.h"
#include "../lab/inputValidation.h"
#include "../Global/clsMainMenuScreen.h"
#include "../Global/Global.h"
class clsLogInScreen : protected clsScreen
{
private:
    static bool _LogIn()
    {
        bool LogInFaild = false;

        short FaildLogInCoun = 0;

        string UserName, PassWord;

        do
        {

            if (LogInFaild)
            {

                FaildLogInCoun++;

                cout << "\nInvalid UserName/passWord ";

                cout << "\nYou Have " << (3 - FaildLogInCoun) << " Trails To Log In: \n";
            }

            if (FaildLogInCoun == 3)
            {
                return false;
            }

            cout << "\nEnter UserName: ";
            UserName = clsInputValidate::ReadString();

            cout << "\nEnter PassWord: ";
            PassWord = clsInputValidate::ReadString();

            CurrentUser = clsUser::Find(UserName, PassWord);

            LogInFaild = CurrentUser.IsEmpty();

        } while (LogInFaild);

        CurrentUser.RegisterLogin();

        clsMainMenuScreen::ShowMainMenue();
    }

public:
    static bool ShowLoginScreen()
    {
        system("cls");

        _DrawScreenHeader("Log IN Screen");

        return _LogIn();
    }
};