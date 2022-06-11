#include "hotel.h"
#include <iostream>
#include <windows.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;
#define pass (void)0

template<typename T>
void stworz(T*& t, const size_t size)
{
	if (size == 0)
		t = new T;
	else
		t = new T[size];
}

template<typename T>
void usun(T*& t, const size_t size)
{
	if (size == 0)
	{
		delete t;
		t = nullptr;
	}
	else
	{
		delete[] t;
		t = nullptr;
	}
}

template<typename T>
void dodaj(vector<T>& v, T*& t, const size_t size)
{
	if (size == 0)
		v.push_back(*t);
	else
		for (size_t i = 0; i < size; i++)
			v.push_back(*(t + i));
}

int main()
{
	setlocale(LC_CTYPE, "Polish");
	Gosc* gosc = nullptr;
	Rezerwacje* rezerwacje = nullptr;
	Pokoj pokoj;
	vector<Gosc> tablica_gosci;
	vector<Rezerwacje> tablica_rezerwacji;
	Finanse finanse;
	int wybor;
	Hotel* hotel;
	size_t size = 10;
	size_t i = 0;
	Menu* menu = new Menu[size];
	map<string, Menu*> menuGosci;

	do
	{
		system("cls");
		cout << "=================MENU G��WNE=================" << endl;
		cout << "Aktualni go�cie: " << aktualni_goscie(tablica_gosci) << endl;
		cout << "1. Dodaj pojedy�czego go�cia." << endl;
		cout << "2. Dodaj kilku go�ci." << endl;
		cout << "3. Wy�wietl go�ci." << endl;
		cout << "4. Usu� ostatniego go�cia." << endl;
		cout << "5. Wy�wietl zaj�te pokoje." << endl;
		cout << "6. Menu finans�w." << endl;
		cout << "7. Demonstracja polimorfizmu." << endl;
		cout << "8. Wy�wietl ostatnio wprowadzonego go�cia." << endl;
		cout << "9. Dokonaj rezerwacji." << endl;
		cout << "10. Wy�wietl wszystkie rezerwacje." << endl;
		cout << "11. Usu� ostatni� rezerwacj�." << endl;
		cout << "12. Zam�w �niadanie do pokoju." << endl;
		cout << "0. Wyjd� z programu." << endl << endl;
		cout << "Co chcesz zrobi�?: "; cin >> wybor;
		system("cls");
		switch (wybor)
		{
		case 1:
		{
			int rozmiar = 0;
			stworz(gosc, rozmiar);
			cin >> *gosc;
			//gosc->inicjalizuj(gosc);
			dodaj(tablica_gosci, gosc, rozmiar);
			//gosc->usun(gosc);
			getchar(); getchar();
			break;
		}
		case 2:
		{
			int rozmiar;
			cout << "Ilu go�ci wprowadzi�?: "; cin >> rozmiar;
			stworz(gosc, rozmiar);
			gosc->inicjalizuj(gosc, rozmiar);
			dodaj(tablica_gosci, gosc, rozmiar);
			//gosc->usun(gosc, rozmiar);
			usun(gosc, rozmiar);
			getchar(); getchar();
			break;
		}
		case 3: gosc->wypisz(tablica_gosci); getchar(); getchar(); break;
		case 4: gosc->usun_goscia(tablica_gosci); getchar(); getchar(); break;
		case 5: pokoj.wyswietl_pokoje(); getchar(); getchar(); break;
		case 6:
		{
			int wybor_finansow;
			cout << "=================MENU FINANS�W=================" << endl;
			cout << "1. Dodaj pracownika." << endl;
			cout << "2. Wy�wietl pracownik�w." << endl;
			cout << "3. Usu� pracownika." << endl;
			cout << "4. Wy�wietl bilans finans�w." << endl;
			cout << "Co chcesz zrobi�?: "; cin >> wybor_finansow;
			system("cls");
			switch (wybor_finansow)
			{
			case 1:
			{
				finanse.dodaj();
				hotel = &finanse;
				hotel->zlicz_finanse();
				getchar(); getchar();
				break;
			}
			case 2: finanse.wyswietl(); getchar(); getchar(); break;
			case 3: finanse.usun_pracownika(); getchar(); getchar(); break;
			case 4:
			{
				if (tablica_gosci.empty())
					pass;
				else
				{
					hotel = &pokoj;
					hotel->zlicz_finanse();
				}
				finanse.bilans();
				getchar(); getchar();
				break;
			}
			case 0: break;
			default:
			{
				cout << "To nie jest poprawny wyb�r!" << endl;
				getchar(); getchar();
				break;
			}
			}
			break;
		}
		case 7:
		{
			vector<Hotel*> hotel = { &pokoj, &finanse };
			for (size_t i = 0; i < 2; i++)
				cout << hotel[i]->zlicz_finanse() << endl;
			getchar(); getchar();
			break;
		}
		case 8:
		{
			if (gosc != nullptr)
				cout << *gosc << endl;
			else if (gosc == nullptr && aktualni_goscie(tablica_gosci) != 0)
				cout << tablica_gosci[aktualni_goscie(tablica_gosci) - 1] << endl;
			else
				cout << "Brak go�ci." << endl;
			getchar(); getchar();
			break;
		}
		case 9:
		{
			size_t rozmiar;
			cout << "Ile rezerwacji wykona�?: ";
			cin >> rozmiar;
			stworz(rezerwacje, rozmiar);
			rezerwacje->wprowadz_dane(rezerwacje, rozmiar);
			dodaj(tablica_rezerwacji, rezerwacje, rozmiar);
			usun(rezerwacje, rozmiar);
			getchar(); getchar();
			break;
		}
		case 10:
		{
			//rezerwacje->wyswietl(tablica_rezerwacji);
			if (tablica_rezerwacji.empty())
				cout << "Brak rezerwacji." << endl;
			else
				for_each(tablica_rezerwacji.begin(), tablica_rezerwacji.end(), [](Rezerwacje rez){
					cout << "Imi�: " << rez.getImie() << endl;
					cout << "Nazwisko: " << rez.getNazwisko() << endl;
					cout << "Numer telefonu: " << rez.getNumerTel() << endl;
					cout << "Numer pokoju: " << rez.getNumerPok() << endl << endl;
					});
			getchar(); getchar();
			break;
		}
		case 11:
		{
			rezerwacje->usun_z_tablicy(tablica_rezerwacji);
			getchar(); getchar();
			break;
		}
		case 12:
		{	
			string imie;
			size_t wybor_potrawy;
			string potrawa;
			cout << "Wprowad� imi�: "; cin >> imie;
			cout << "Dost�pne potrawy: " << endl;
			cout << "1. Jajecznica" << endl;
			cout << "2. Sa�atka owocowa" << endl;
			cout << "3. Nale�niki" << endl;
			if (i == size-1)
				cout << "Lista zam�wie� jest pe�na.";
			else
			{
				cin >> wybor_potrawy;
				if (wybor_potrawy == 1)
				{
					potrawa = "Jajecznica";
					menu[i].setPotrawa(potrawa);
				}
				else if (wybor_potrawy == 2)
				{
					potrawa = "Sa�atka owocowa";
					menu[i].setPotrawa(potrawa);
				}
				else
				{
					potrawa = "Nale�niki";
					menu[i].setPotrawa(potrawa);
				}
				i++;
				menuGosci.insert(pair<string, Menu*>(imie, menu));
			}
			cout << endl;
			cout << "Aktualne zam�wienia �niada�: " << endl;
			size_t j = 0;
			for (auto pair : menuGosci)
			{
				cout << pair.first << " - " << (pair.second + j)->getPotrawa() << endl;
				j++;
			}

			getchar(); getchar();
			break;
		}
		case 0: break;
		default:
		{
			cout << "To nie jest poprawny wyb�r!" << endl;
			getchar(); getchar();
			break;
		}
		}
	} while (wybor != 0);

	return 0;
}