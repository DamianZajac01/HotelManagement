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
		cout << "=================MENU G£ÓWNE=================" << endl;
		cout << "Aktualni goœcie: " << aktualni_goscie(tablica_gosci) << endl;
		cout << "1. Dodaj pojedyñczego goœcia." << endl;
		cout << "2. Dodaj kilku goœci." << endl;
		cout << "3. Wyœwietl goœci." << endl;
		cout << "4. Usuñ ostatniego goœcia." << endl;
		cout << "5. Wyœwietl zajête pokoje." << endl;
		cout << "6. Menu finansów." << endl;
		cout << "7. Demonstracja polimorfizmu." << endl;
		cout << "8. Wyœwietl ostatnio wprowadzonego goœcia." << endl;
		cout << "9. Dokonaj rezerwacji." << endl;
		cout << "10. Wyœwietl wszystkie rezerwacje." << endl;
		cout << "11. Usuñ ostatni¹ rezerwacjê." << endl;
		cout << "12. Zamów œniadanie do pokoju." << endl;
		cout << "0. WyjdŸ z programu." << endl << endl;
		cout << "Co chcesz zrobiæ?: "; cin >> wybor;
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
			cout << "Ilu goœci wprowadziæ?: "; cin >> rozmiar;
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
			cout << "=================MENU FINANSÓW=================" << endl;
			cout << "1. Dodaj pracownika." << endl;
			cout << "2. Wyœwietl pracowników." << endl;
			cout << "3. Usuñ pracownika." << endl;
			cout << "4. Wyœwietl bilans finansów." << endl;
			cout << "Co chcesz zrobiæ?: "; cin >> wybor_finansow;
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
				cout << "To nie jest poprawny wybór!" << endl;
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
				cout << "Brak goœci." << endl;
			getchar(); getchar();
			break;
		}
		case 9:
		{
			size_t rozmiar;
			cout << "Ile rezerwacji wykonaæ?: ";
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
					cout << "Imiê: " << rez.getImie() << endl;
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
			cout << "WprowadŸ imiê: "; cin >> imie;
			cout << "Dostêpne potrawy: " << endl;
			cout << "1. Jajecznica" << endl;
			cout << "2. Sa³atka owocowa" << endl;
			cout << "3. Naleœniki" << endl;
			if (i == size-1)
				cout << "Lista zamówieñ jest pe³na.";
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
					potrawa = "Sa³atka owocowa";
					menu[i].setPotrawa(potrawa);
				}
				else
				{
					potrawa = "Naleœniki";
					menu[i].setPotrawa(potrawa);
				}
				i++;
				menuGosci.insert(pair<string, Menu*>(imie, menu));
			}
			cout << endl;
			cout << "Aktualne zamówienia œniadañ: " << endl;
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
			cout << "To nie jest poprawny wybór!" << endl;
			getchar(); getchar();
			break;
		}
		}
	} while (wybor != 0);

	return 0;
}