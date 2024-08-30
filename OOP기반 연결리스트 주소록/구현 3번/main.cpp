#include "UI.h"
#include "ListEx.h"
#include "UserData.h"


int main()
{
	ListEx db(new UserData("Dummy", "Head"));
	UI ui(db);
	ui.runUI();
}