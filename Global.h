#pragma once

#include <iostream>

#include "../ManageUser/clsUser.h"

clsUser CurrentUser = clsUser::Find(" ", " ");

short EncrptedKey = 5;