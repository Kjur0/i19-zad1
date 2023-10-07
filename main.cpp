#include "zads.h"

int main() {
	system("@echo off");
	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);
	int nr;
	wchar_t odp;
	system("cls");
init:
	wcout << L"Wprowadź nr zadania: ";
	wcin >> nr;
	switch (nr) {
		case 1:
			zad1();
			break;
		case 2:
			zad2();
			break;
		case 3:
			zad3();
			break;
		default:
			wcout << L"Nie ma takiego zadania" << endl;
			goto init;
			break;
	}
	system("cls");
	wcout << L"Czy chcesz zakończyć? (t/n): ";
	wcin >> odp;
	if (odp == 'n')
		goto init;
	return 0;
}