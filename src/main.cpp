
#include <iostream>
#include "getcfname_main.h"
#include "MessageRegistration.h"

using namespace std;

Registrator msreg_g;

int main(int argc, char* argv[])
{

    msreg_g.AddMessage("sdfsdfsdf",MessageState::Info);
    cout << "Тестовая строка" << endl;

	return 0;
}
