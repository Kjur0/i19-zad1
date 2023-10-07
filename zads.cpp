#include "zads.h"


void zad1() {
	vector<pytanie> pytania {
		{ L"Ile to 2+2?", { {L"4", true}, {L"5"}, {L"6"}, {L"10"} } },
		{ L"Kto jest prezydentem Polski? (2023)", { {L"Andrzej Duda", true}, {L"Rafa³ Trzaskowski"}, {L"Donald Tusk"}, {L"Jaros³aw Kaczyñski"} } },
		{ L"Ile lat trwa kadencja prezydenta Polski", { {L"5", true}, {L"10"}, {L"4"}, {L"3"} } },
		{ L"Co w informatyce oznacza skrót \"std\"", { {L"STanDard", true}, {L"Standart Text Data"}, {L"STandard Data"}, {L"Super Transfer of Data"} } },
		{ L"Co w informatyce oznacza skrót \"io\"", { {L"Input\\Output", true}, {L"In\\Out", true}, {L"Instant Output"}, {L"Input Of data"} } },
		{ L"Kto jest prezydentem Warszawy (2023)?", { {L"Rafa³ Trzaskowski", true}, {L"Andrzej Duda"}, {L"Donald Tusk"}, {L"Jaros³aw Kaczyñski"} } },
		{ L"Ile to \"szklanka\" w monemkulaturze kuchennej?", { {L"250ml", true}, {L"500ml"}, {L"75ml"}, {L"1l"} } },
		{ L"Ile bitów ma bajt?", { {L"8", true}, {L"16"}, {L"4"}, {L"2"} } },
		{ L"Jakie jest domyœlne kodowanie tekstu w Windows 10?", { {L"ANSI", true}, {L"UTF-16"}, {L"UTF-8"}, {L"ASCI"} } },
		{ L"Przez jak¹ liczbê nie mo¿na dzieliæ?", { {L"0", true}, {L"1"}, {L"20"}, {L"-1"} } }
	};

	int punkty = 0;
	random_shuffle(pytania.begin(), pytania.end());
	for (pytanie pyt : pytania) {
		system("cls");
		if (pytaj(pyt)) {
			wcout << L"Poprawna odpowiedŸ!!!\n";
			punkty++;
		} else
			wcout << L"B³êdna odpowiedŸ!!!\n";
		wcout << L"Aby kontynuoaæ naciœnij dowolny przycisk!";
		system("Pause>nul");
	}
	system("cls");
	wstring wynik;
	if (punkty <= pytania.size() * 0.4) wynik = RES_LOW;
	else if (punkty <= pytania.size() * 0.8) wynik = RES_MID;
	else wynik = RES_HIGH;
	wcout << wynik << L"\nAby kontynuowaæ naciœnij dowolny przycisk!";
	system("Pause>nul");
}

bool pytaj(pytanie pyt) {
	wcout << pyt.tresc << endl;
	random_shuffle(pyt.odpowiedzi.begin(), pyt.odpowiedzi.end());
	for (int i = 0; i < pyt.odpowiedzi.size(); i++)
		wcout << '\t' << (char)( 'a' + i ) << L") " << pyt.odpowiedzi[i].tresc << endl;
	wchar_t odp = NULL;
	do {
		if (odp != NULL)
			wcout << L"Taka odpowiedŸ nie istnieje\n";
		wcout << L"WprowadŸ odpowiedŸ: ";
		wcin >> odp;
	} while (odp < 'a' || odp >= ( 'a' + pyt.odpowiedzi.size() ));
	odp -= 'a';
	return pyt.odpowiedzi[odp].poprawna;
}


void zad2() {
	system("cls");
	wcout << L"UPS...\nZadania nie ma co modyfikowaæ...\nKliknij dowolny przycisk, aby uruchomiæ zadanie 1\n";
	system("Pause>nul");
	zad1();
}


void zad3() {
	bool loop = true, changed = false;
	int opt = 0, lastInstr = 5;
	vector<uczen> uczniowie {};
	wczytaj(&uczniowie);
	do {
		if (lastInstr >= 1 && lastInstr <= 5)
			system("cls");
		wcout << L"\t1.Dodaj ucznia\n\t2.Usuñ ucznia\n\t3.Poka¿ informacje ucznia\n\t4.Zapisz\n\t5.WyjdŸ\nWprowadŸ kod instrukcji: ";
		wcin >> opt;
		system("cls");
		switch (opt) {
			case 1:
				dodaj(&uczniowie, &changed);
				break;
			case 2:
				usun(&uczniowie, &changed);
				break;
			case 3:
				pokaz(&uczniowie);
				break;
			case 4:
				zapisz(&uczniowie, &changed);
				break;
			case 5:
				wyjdz(&uczniowie, changed, &loop);
				break;
			default:
				wcout << L"Nie ma takiej instrukcji\n";
				break;
		}
		lastInstr = opt;
	} while (loop);
}

void wczytaj(vector<uczen> * p) {
	wifstream plik("uczniowie.csv");
	wstring linia;
	while (getline(plik, linia)) {
		uczen u;
		u.id = stoi(linia.substr(0, linia.find(',')));
		linia = linia.substr(linia.find(',') + 1);
		u.nazwisko = linia.substr(0, linia.find(','));
		linia = linia.substr(linia.find(',') + 1);
		u.imie = linia.substr(0, linia.find(','));
		linia = linia.substr(linia.find(',') + 1);
		u.nr = stoi(linia.substr(0, linia.find(',')));
		linia = linia.substr(linia.find(',') + 1);
		u.klasa = linia;
		p->push_back(u);
	}
	plik.close();
}
void dodaj(vector<uczen> * p, bool * changed) {
	vector<uczen> table = *p;
	uczen u;
	int id = ( table.size() + 1 ), nr;
	wstring nazwisko, imie, klasa;
	wcout << L"ID: " << id << endl;
	wcout << L"Imiê: ";
	wcin >> imie;
	wcout << L"Nazwisko: ";
	wcin >> nazwisko;
	wcout << L"Numer w dzienniku: ";
	wcin >> nr;
	wcout << L"Klasa: ";
	wcin >> klasa;
	u.id = id;
	u.imie = imie;
	u.nazwisko = nazwisko;
	u.nr = nr;
	u.klasa = klasa;
	p->push_back(u);
	*changed = true;
	wcout << L"Dodano!\nAby kontynuoaæ naciœnij dowolny przycisk!";
	system("Pause>nul");
}

void usun(vector<uczen> * p, bool * changed) {
	vector<uczen> table = *p;
	int id;
	bool exists = false;
	wcout << L"Podaj ID ucznia: ";
	wcin >> id;
	p->erase(p->begin(), p->end());
	for (uczen u : table) {
		if (u.id != id) {
			p->push_back(u);
		} else {
			exists = true;
			*changed = true;
		}
	}
	if (exists)
		wcout << L"Usuniêto!\n";
	else
		wcout << L"Nie znaleziono ucznia o takim ID\n";
	wcout << L"Aby kontynuoaæ naciœnij dowolny przycisk!";
	system("Pause>nul");
}

void pokaz(vector<uczen> * p) {
	vector<uczen> table = *p;
	int id;
	wcout << L"Podaj ID ucznia: ";
	wcin >> id;
	for (uczen u : table) {
		if (u.id == id) {
			wcout << L"ID: " << u.id << endl;
			wcout << L"Imiê: " << u.imie << endl;
			wcout << L"Nazwisko: " << u.nazwisko << endl;
			wcout << L"Numer w dzienniku: " << u.nr << endl;
			wcout << L"Klasa: " << u.klasa << endl;
			wcout << L"Aby kontynuoaæ naciœnij dowolny przycisk!";
			system("Pause>nul");
			return;
		}
	}
	wcout << L"Nie znaleziono ucznia o takim ID\nAby kontynuoaæ naciœnij dowolny przycisk!";
	system("Pause>nul");
}

void zapisz(vector<uczen> * p, bool * changed = NULL) {
	vector<uczen> table = *p;
	wofstream plik("uczniowie.csv");
	for (uczen u : table) {
		plik << u.id << L"," << u.nazwisko << L"," << u.imie << L"," << u.nr << L"," << u.klasa;
	}
	plik.close();
	if (changed != NULL)
		*changed = false;
	wcout << L"Zapisano!\nAby kontynuoaæ naciœnij dowolny przycisk!";
	system("Pause>nul");
}

void wyjdz(vector<uczen> * p, bool changed, bool * loop) {
	vector<uczen> table = *p;
	if (changed) {
		wcout << L"Masz niezapisane zmiany!!!\nCzy chcesz zapisaæ? (t/n): ";
		wchar_t odp;
		wcin >> odp;
		if (odp == 't')
			zapisz(&table);
	}
	*loop = false;
}