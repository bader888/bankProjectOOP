#include <iostream>
#include "Global/clsPersone.h"
#include "ManageClients/clsBankClients.h"
#include "lab/inputValidation.h"
#include "lab/utilLab.h"
#include "LogIn/clsLogIn.h"

int main()
{

    while (true)
    {

        if (!clsLogInScreen::ShowLoginScreen())
        {
            break;
        }
    }

    return 0;
}