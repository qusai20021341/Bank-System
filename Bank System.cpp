#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include<iomanip>
#include "clsMainScreen.h"
#include "clsLoginScreen.h"
#include<vector>
#include "Global.h"
using namespace std;
int main()
{
	while (true)
	{
		if (!clsLoginScreen::ShowLoginScreen())
		{
			break;
		}
	}
	return 0;
}


