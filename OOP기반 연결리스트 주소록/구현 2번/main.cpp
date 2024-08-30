#include "UI.h"
#include "List.h"
#include "UserData.h"

int main()
{
	List db(new UserData);
	UI ui(db);
	ui.runUI();
}