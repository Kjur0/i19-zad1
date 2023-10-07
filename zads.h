#pragma once

#include <iostream>
#include <fstream>
#include <io.h>
#include <fcntl.h>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void zad1();

#define RES_LOW L"spróbuj ponownie"
#define RES_MID L"ca³kiem nieŸle"
#define RES_HIGH L"Wspaniale!"

struct odpowiedz {
	wstring tresc;
	bool poprawna = false;
};

struct pytanie {
	wstring tresc;
	vector<odpowiedz> odpowiedzi;
};

bool pytaj(pytanie pyt);


void zad2();


void zad3();

struct uczen {
	int id;
	wstring nazwisko;
	wstring imie;
	int nr;
	wstring klasa;
};

void wczytaj(vector<uczen> * p);
void dodaj(vector<uczen> * p, bool * changed);
void usun(vector<uczen> * p, bool * changed);
void pokaz(vector<uczen> * p);
void zapisz(vector<uczen> * p, bool * changed);
void wyjdz(vector<uczen> * p, bool changed, bool * loop);