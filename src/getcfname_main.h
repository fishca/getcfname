//---------------------------------------------------------------------------

#ifndef getcfname_mainH
#define getcfname_mainH
//---------------------------------------------------------------------------
#include <iostream>

#include "Class_1CD.h"
#include "MessageRegistration.h"
#include "Parse_tree.h"

//---------------------------------------------------------------------------
class Messager : public MessageRegistrator
{
public:
	bool has_error;
	Messager();
	virtual void AddMessage(const std::string& message, const MessageState mstate, TStringList* param = NULL);
	virtual void Status(const std::string& message);
};

#endif

