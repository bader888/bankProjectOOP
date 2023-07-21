#pragma once

#include <iostream>
#include "../Global/clsScreen.h"
#include <iomanip>
#include <fstream>
#include "clsUser.h"

class clsLoginRegisterScreen : protected clsScreen
{
private:
     static void _PrintLoginRegisterUserRecord(clsUser::strLoginRegisterUser loginRegisterUser)
     {
          cout << setw(8) << left << ""
               << "| " << left << setw(35) << loginRegisterUser.DateAndTime;
          cout << "| " << left << setw(20) << loginRegisterUser.UserName;
          cout << "| " << left << setw(20) << loginRegisterUser.PassWord;
          cout << "| " << left << setw(10) << loginRegisterUser.Permission;
          cout << setw(8) << left << "";
          cout << endl;
     }

public:
     static void ShowLoginRegisterScreen()
     {

          if (!CheckAccessRights(clsUser::enMainMenuePermissions::pListlogInRegisters))
          {
               return; // this will exit the function and it will not continue
          }

          vector<clsUser::strLoginRegisterUser> vloginRegisterUsers = clsUser::GetlogInRegisterUsers();

          _DrawScreenHeader("Login Register Screen");

          cout << setw(8) << left << ""
               << "\n\t_______________________________________________________";
          cout << "_________________________________________\n"
               << endl;

          cout << setw(8) << left << ""
               << "| " << left << setw(35) << "Date/Time";
          cout << "| " << left << setw(20) << "UserName";
          cout << "| " << left << setw(20) << "Password";
          cout << "| " << left << setw(10) << "Permissions";

          cout << setw(8) << left << ""
               << "\n\t_______________________________________________________";
          cout << "_________________________________________\n"
               << endl;

          if (vloginRegisterUsers.size() == 0)
               cout << "\t\t\t\tNo Logins Available In the System!";
          else

               for (clsUser::strLoginRegisterUser U : vloginRegisterUsers)
               {
                    _PrintLoginRegisterUserRecord(U);
               }

          cout << setw(8) << left << ""
               << "\n\t_______________________________________________________";
          cout << "_________________________________________\n"
               << endl;
     }
};
