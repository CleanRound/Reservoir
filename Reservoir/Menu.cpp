#include"Reservoir.h"


int countreservoir = 4;

int countrountry = 1;

int number = 1;

Reservoir* vodoem = new Reservoir[countreservoir]
{
	{number++, 2201, "Blue Lake", 0.72, 0.45, 50, "lake", "Bugskiy Gard. Myhiya. Mykolayivs'ka oblast"},
	{number++, 3301, "Dnieper Reservoir", 3.5, 170, 8, "reservoir","Zaporiz'ka and Dnipropetrovs'ka oblast"},
	{number++, 4421, "Azov Sea", 20, 180, 7.4, "sea", "Khersons'ka, Zaporiz'ka and Donets'ka oblast"},
	{number++, 4478, "Black Sea", 100, 310, 25, "sea", "Khersons'ka, Mykolayivs'ka and Odes'ka oblast"}
};

Country* cname = new Country[countrountry]
{
	{countrountry++, "Ukraine"},
};

//-----------------------------------------------------------------------------------------------
string* MenuItems()
{
	string* item = new string[7];
	item[0] = "1. List of Reservoirs";
	item[1] = "2. Adding a Reservoir. Deleting a Reservoir";
	item[2] = "3. Calculation of Reservoir Volume";
	item[3] = "4. Determination of water surface area";
	item[4] = "5. Checking the type of a reservoir";
	item[5] = "6. Compare water surface areas";
	item[6] = "7. Exit the program";

	return item;
}
//-----------------------------------------------------------------------------------------------
void gotoxy(int xpos, int ypos)
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = xpos; scrn.Y = ypos;
	SetConsoleCursorPosition(hOuput, scrn);
}
//-----------------------------------------------------------------------------------------------
void MenuFun1()
{
	system("cls");

	gotoxy(1, 6);
	cout << "List of Reservoirs\n\n";
	gotoxy(20, 6);
	cname->Show_Country();

	gotoxy(1, 7);
	cout << "+-------+----------------------------+------------+------------+------------+-----------------+-------------------------------------------------+\n";
	gotoxy(1, 8);
	cout << "|Code   | Name                       | Width, km  | Length, km | Depth, m   | Type            | Additional information                          |\n";
	gotoxy(1, 9);
	cout << "+-------+----------------------------+------------+------------+------------+-----------------+-------------------------------------------------+\n";

	for (size_t i = 0; i < countreservoir; i++)
	{
		gotoxy(1, 10 + i);
		vodoem[i].Show_Reservoir();

	}
	cout << " +-------+----------------------------+------------+------------+------------+-----------------+-------------------------------------------------+\n";

	_getch();
	system("cls");
}
void MenuFun2()
{
	system("cls");
	gotoxy(0, 5);
	cout << "Country: \n";
	gotoxy(9, 5);
	cname->Show_Country();
	cout << endl;
	gotoxy(0, 6);

	int choose;
	cout << "1. Adding a reservoir" << endl;
	cout << "2. Deleting a reservoir" << endl;
	cout << "3. Exit" << endl;
	cout << "Enter a number of the menu: ";
	cin >> choose;
	cout << endl << endl;
	if (choose == 1)
		vodoem->AddReservoir(vodoem, &countreservoir, &number);

	if (choose == 2)
		vodoem->DeleteReservoir(vodoem, &countreservoir, &number);

	if (choose > 2)
		cout << "Exiting..." << endl;

	_getch();
	system("cls");
}
void MenuFun3()
{
	system("cls");
	int _code;
	int idarray = NULL;
	int check = 0;

	gotoxy(0, 9);
	cout << "Calculation of Reservoir Volume\n";
	cout << "Enter the cadastral number of the reservoir: ";
	cin >> _code;
	vodoem->SearchVolume(vodoem, countreservoir, _code, &idarray, &check);

	if (check)
	{
		cout << "Volume of the reservoir ";
		vodoem[idarray].Show_One_Reservoir();
		cout << " = " << vodoem[idarray].Getvolume() << " km3";
	}

	else
		cout << "Nothing has been found by a request...";

	_getch();
	system("cls");
}
void MenuFun4()
{
	system("cls");
	int _code;
	int idarray = NULL;
	int check = 0;

	gotoxy(0, 9);
	cout << "Determination of a water surface area\n";
	cout << "Enter the cadastral number of a reservoir: ";
	cin >> _code;
	vodoem->SearchArea(vodoem, countreservoir, _code, &idarray, &check);

	if (check)
	{
		cout << "Area of a reservoir ";
		vodoem[idarray].Show_One_Reservoir();
		cout << " = " << vodoem[idarray].Getarea() << " km.";
	}

	else
		cout << "Nothing has been found by a request...";

	_getch();
	system("cls");
}
void MenuFun5()
{
	system("cls");

	bool checktip = 0;
	int code1;
	int code2;
	int idarray1 = NULL;
	int idarray2 = NULL;
	int checkcode1 = 0;
	int checkcode2 = 0;

	gotoxy(0, 9);
	cout << "Checking whether reservoires belong to the same type\n";
	cout << "Enter the cadastral number of a first reservoir: ";
	cin >> code1;
	cout << "Enter the cadastral number of a second reservoir: ";
	cin >> code2;


	for (size_t k = 0; k < countreservoir; k++)
	{
		if (vodoem[k].Getcode() == code1)
		{
			checkcode1++;
		}
	}

	if (checkcode1)
	{
		cout << "First reservoir has been found in a base\n";
	}

	else
	{
		cout << "First reservoir hasn't been found in a base\n";
	}

	for (size_t k = 0; k < countreservoir; k++)
	{
		if (vodoem[k].Getcode() == code2)
		{
			checkcode2++;
		}
	}

	if (checkcode2)
	{
		cout << "Second reservoir has been found in a base\n";
	}

	else
	{
		cout << "Second reservoir hasn't been found in a base\n";
	}

	if (checkcode1 && checkcode2)
	{
		cout << "Both reservoires have been found in a base\n";
		cout << "Starting to compare types of reservoires\n\n";

		checktip = vodoem->CheckTip(vodoem, countreservoir, code1, code2, &idarray1, &idarray2);

		if (checktip)
		{
			cout << "Reservoires ";
			vodoem[idarray1].Show_One_Reservoir();
			cout << " and ";
			vodoem[idarray2].Show_One_Reservoir();
			cout << " have a common type - ";
			vodoem[idarray1].Show_Tip();
		}

		else
		{
			cout << "Reservoires have different types\n";
			vodoem[idarray1].Show_One_Reservoir();
			cout << " type - ";
			vodoem[idarray1].Show_Tip();
			cout << endl;
			vodoem[idarray2].Show_One_Reservoir();
			cout << " type - ";
			vodoem[idarray2].Show_Tip();
		}
	}

	else
	{
		cout << "Enter the right data and repeat your request...\n";
	}



	_getch();
	system("cls");
}
//-----------------------------------------------------------------------------------------------
void MenuFun6()
{
	system("cls");
	gotoxy(0, 9);
	cout << "Comparisons of the water surface area of reservoires of the same type\n";
	vodoem->AutoSearchArea(vodoem, countreservoir);
	cout << "The automatic area update for all reservoires completed\n";
	cin.ignore();
	char charsearch[30] = "";
	cout << "Enter the type of a reservoir for comparison: ";
	cin.getline(charsearch, 30);

	vodoem->SearchAreaTip(vodoem, charsearch, countreservoir);

	_getch();
	system("cls");
}
//-----------------------------------------------------------------------------------------------
void ExitOption()
{
	gotoxy(35, 15);
	delete[]vodoem;
	delete[]cname;
	cout << "Exiting..." << endl;
	_getch();
	exit(0);
}
//-----------------------------------------------------------------------------------------------
void ChangeCursorStatus(bool Visible)
{
	CONSOLE_CURSOR_INFO* c = new CONSOLE_CURSOR_INFO;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	if (Visible)
	{
		c->bVisible = TRUE;
		c->dwSize = 0;
	}
	else
	{
		c->bVisible = FALSE;
		c->dwSize = 1;
	}

	SetConsoleCursorInfo(h, c);
}
//-----------------------------------------------------------------------------------------------
