#include "../Global/clsScreen.h"
#include "../Core/clsCurrency.h"

class clsListCurrenciesScreen : protected clsScreen
{
     static void PrintCurrencyRecordLine(clsCurrency Currency)
     {

          cout << setw(8) << left << ""
               << "| " << setw(25) << left << Currency.Country();
          cout << "| " << setw(20) << left << Currency.CurrencyCode();
          cout << "| " << setw(25) << left << Currency.CurrencyName();
          cout << "| " << setw(15) << left << Currency.Rate();
     }

public:
     static void ShowListCurrenciesScreen()
     {
          _DrawScreenHeader("List Currency Screen");

          vector<clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();

          cout << setw(8) << left << ""
               << "\n\t_______________________________________________________";
          cout << "_________________________________________\n"
               << endl;

          cout << setw(8) << left << ""
               << "| " << left << setw(15) << "Country";
          cout << "| " << left << setw(20) << "Code";
          cout << "| " << left << setw(12) << "Name";
          cout << "| " << left << setw(20) << "Rate";
          cout << setw(8) << left << ""
               << "\n\t_______________________________________________________";
          cout << "_________________________________________\n"
               << endl;

          if (vCurrencies.size() == 0)
               cout << "\t\t\t\tNo Clients Available In the System!";
          else

               for (clsCurrency Currency : vCurrencies)
               {

                    PrintCurrencyRecordLine(Currency);
                    cout << endl;
               }

          cout << setw(8) << left << ""
               << "\n\t_______________________________________________________";
          cout << "_________________________________________\n"
               << endl;
     };
};