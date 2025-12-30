
#include <iostream>
#include "getcfname_main.h"
#include "Messenger.h"
#include "MessageRegistration.h"

using namespace std;

Registrator msreg_g;

int main(int argc, char* argv[])
{
    msreg_g.AddMessageRegistrator(&mess);
    
	if(argc <= 1)
	{
        msreg_g.AddDetailedMessage("getcfname: Определение имени и версии конфигурации файловых баз *.1cd и файлов конфигураций *.cf\n(c)awa    2012-2016\n(c)fishca 2017-2025\n\nИспользование:\ngetcfname.exe <1CD-file>\ngetcfname.exe <CF-file>", MessageState::Info, nullptr);
		return 2;
	}

	if(argc > 2)
	{
        msreg_g.AddDetailedMessage("Слишком много параметров\n\nИспользование:\ngetcfname.exe <1CD-file>\ngetcfname.exe <CF-file>", MessageState::Info, nullptr);
		return 2;
	}

    string filename = argv[1];
    msreg_g.AddDetailedMessage(filename, MessageState::Info, nullptr);
	//return 0;
}
