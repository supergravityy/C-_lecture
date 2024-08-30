#include "UI.h"
#include "List.h"

int main()
{
	List db;
	UI ui(db);
	ui.UIrun();

	return 0;
}