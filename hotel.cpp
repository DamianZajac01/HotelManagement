#include "hotel.h"
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

size_t indeks_pokoju;
size_t counter = 0;
Pokoj pokoj;
vector<Pokoj> tablica_pokoi;
double cena_za_pokoj = 500;
double Pokoj::przychody_z_pokojow = 0;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

// PRZIECIAZONE OPERATORY //
ostream& operator<<(ostream& COUT, Gosc& gosc)
{
	COUT << "Imiê: " << gosc.getImie() << endl;
	COUT << "Nazwisko: " << gosc.getNazwisko() << endl;
	COUT << "Pesel: " << gosc.getPesel() << endl;
	COUT << "Numer telefonu: " << gosc.getNrTel() << endl;
	COUT << "Data pobytu: " << gosc.getDataPobytu() << endl;
	COUT << "Numer pokoju: " << gosc.getNrPokoju() << endl;
	return COUT;
}
istream& operator>>(istream& CIN, Gosc& gosc)
{
	string nazwa;
	size_t liczba;
	cout << "WprowadŸ imiê: "; CIN >> nazwa; gosc.setImie(nazwa);
	cout << "WprowadŸ nazwisko: "; CIN >> nazwa; gosc.setNazwisko(nazwa);
	cout << "WprowadŸ pesel: "; CIN >> liczba; gosc.setPesel(liczba);
	cout << "WprowadŸ numer telefonu: "; CIN >> liczba; gosc.setNrTel(liczba);
	cout << "WprowadŸ datê pobytu: "; CIN >> nazwa; gosc.setDataPobytu(nazwa);
	cout << "WprowadŸ numer pokoju: "; CIN >> liczba; gosc.setNrPokoju(liczba);
	indeks_pokoju = gosc.nr_pokoju;
	pokoj.zajmij_pokoj(pokoj);
	return CIN;
}
Finanse& ::Finanse::operator=(const Finanse& prawaStrona)
{
	if (&prawaStrona == this)
		return *this;
	else
	{
		for (size_t i = 0; i < size; i++)
			delete pracownik[i];
		delete[] pracownik;
		pracownik = new Pracownik * [size];
		for (size_t i = 0; i < size; i++)
			pracownik[i] = new Pracownik;
		assert(pracownik != 0);
		for (int i = 0; i < size; i++)
		{
			pracownik[i]->setImie(prawaStrona.pracownik[i]->getImie());
			pracownik[i]->setNazwisko(prawaStrona.pracownik[i]->getNazwisko());
			pracownik[i]->setPensja(prawaStrona.pracownik[i]->getPensja());
			pracownik[i]->setStanowisko(prawaStrona.pracownik[i]->getStanowisko());
		}
		return *this;
	}
}
Finanse::Pracownik& Finanse::operator[](size_t indeks)
{
	return *pracownik[indeks];
}

Hotel::~Hotel() {}

// GOSC //
Gosc::Gosc(string imie, string nazwisko, size_t pesel, size_t nr_tel, string data_pobytu, size_t nr_pokoju)
{
	this->imie = imie;
	this->nazwisko = nazwisko;
	this->pesel = pesel;
	this->nr_tel = nr_tel;
	this->data_pobytu = data_pobytu;
	this->nr_pokoju = nr_pokoju;
}
Gosc::~Gosc()
{

}

// POJEDYNCZY GOSC //
//void Gosc::stworz(Gosc*& gosc)
//{
//	gosc = new Gosc;
//}
void Gosc::usun(Gosc*& gosc)
{
	delete gosc;
	gosc = nullptr;
}
void Gosc::inicjalizuj(Gosc*& gosc)
{
	cout << "------DODAWANIE GOŒCIA------" << endl;
	cout << "Podaj imiê: "; cin >> gosc->imie;
	cout << "Podaj nazwisko: "; cin >> gosc->nazwisko;
	cout << "Podaj pesel: "; cin >> gosc->pesel;
	cout << "Podaj numer telefonu: "; cin >> gosc->nr_tel;
	cout << "Podaj datê pobytu: "; cin >> gosc->data_pobytu;
	cout << "Podaj numer pokoju: "; cin >> gosc->nr_pokoju;
	indeks_pokoju = gosc->nr_pokoju;
	pokoj.zajmij_pokoj(pokoj);
}
//void Gosc::dodaj(vector<Gosc>& v, Gosc*& gosc)
//{
//	v.push_back(*gosc);
//}

// TABLICA GOSCI //
//void Gosc::stworz(Gosc*& gosc, const size_t rozmiar)
//{
//	gosc = new Gosc[rozmiar];
//}
void Gosc::usun(Gosc*& gosc, const size_t rozmiar)
{
	delete[] gosc;
	gosc = nullptr;
}
void Gosc::inicjalizuj(Gosc*& gosc, const size_t rozmiar)
{
	cout << "------DODAWANIE GOŒCI------" << endl;
	for (int i = 0; i < rozmiar; i++)
	{
		cout << "Podaj imiê: "; cin >> (gosc + i)->imie;
		cout << "Podaj nazwisko: "; cin >> (gosc + i)->nazwisko;
		cout << "Podaj pesel: "; cin >> (gosc + i)->pesel;
		cout << "Podaj numer telefonu: "; cin >> (gosc + i)->nr_tel;
		cout << "Podaj datê pobytu: "; cin >> (gosc + i)->data_pobytu;
		cout << "Podaj numer pokoju: "; cin >> (gosc + i)->nr_pokoju;
		cout << "---------------------------------------" << endl;
		indeks_pokoju = (gosc + i)->nr_pokoju;
		pokoj.zajmij_pokoj(pokoj);
	}
}
//void Gosc::dodaj(vector<Gosc>& v, Gosc*& gosc, const size_t rozmiar)
//{
//	for (int i = 0; i < rozmiar; i++)
//		v.push_back(*(gosc + i));
//}

// TABLICA WSKAZNIKOW //
void Gosc::stworz(Gosc**& gosc, const size_t rozmiar)
{
	gosc = new Gosc * [rozmiar];
	for (int i = 0; i < rozmiar; i++)
		gosc[i] = new Gosc;
}
void Gosc::usun(Gosc**& gosc, const size_t rozmiar)
{
	for (int i = 0; i < rozmiar; i++)
		delete gosc[i];
	delete[] gosc;
	gosc = nullptr;
}
void Gosc::inicjalizuj(Gosc**& gosc, const size_t rozmiar)
{
	for (int i = 0; i < rozmiar; i++)
	{
		cout << "Podaj imiê: "; cin >> (*(gosc + i))->imie;
		cout << "Podaj nazwisko: "; cin >> (*(gosc + i))->nazwisko;
		cout << "Podaj pesel: "; cin >> (*(gosc + i))->pesel;
		cout << "Podaj numer telefonu: "; cin >> (*(gosc + i))->nr_tel;
		cout << "Podaj datê pobytu: "; cin >> (*(gosc + i))->data_pobytu;
		cout << "Podaj numer pokoju: "; cin >> (*(gosc + i))->nr_pokoju;
	}
}

// OGOLNE GOSC //
void Gosc::wypisz(vector<Gosc>& v)
{
	if (v.empty())
		cout << "Brak goœci w systemie." << endl;
	else
		for (int i = 0; i < v.size(); i++)
		{
			cout << "------WYŒWIETLANIE GOŒÆI------" << endl;
			cout << "---------------------------------------" << endl;
			cout << "ID: " << v[i].ID + (i + 1) << endl;
			cout << "Imiê: " << v[i].imie << endl;
			cout << "Nazwisko: " << v[i].nazwisko << endl;
			cout << "Pesel: " << v[i].pesel << endl;
			cout << "Numer telefonu: " << v[i].nr_tel << endl;
			cout << "Data pobytu: " << v[i].data_pobytu << endl;
			cout << "Numer pokoju: " << v[i].nr_pokoju << endl;
			cout << "---------------------------------------" << endl;
		}
}
void Gosc::usun_goscia(vector<Gosc>& v)
{
	if (v.empty())
	{
		cout << "Brak goœci w systemie!" << endl;
		return;
	}
	else
	{
		v.pop_back();
		pokoj.zwolnij_pokoj();
		cout << "Pomyœlnie usuniêto goœcia." << endl;
	}
}

// POKOJ //
Pokoj::Pokoj(size_t pokoj, string status)
{
	this->pokoj = pokoj;
	this->status = status;
}
void Pokoj::zajmij_pokoj(Pokoj& pokoj_do_zajecia)
{
	pokoj_do_zajecia.pokoj = indeks_pokoju;
	pokoj_do_zajecia.status = "zajety";
	tablica_pokoi.push_back(pokoj_do_zajecia);
}
void Pokoj::wyswietl_pokoje()
{
	for (int i = 0; i < tablica_pokoi.size(); i++)
	{
		cout << "------WYŒWIETLANIE POKOJÓW------" << endl;
		cout << "---------------------------------------" << endl;
		cout << "Pokój nr: " << tablica_pokoi[i].pokoj << endl;
		SetConsoleTextAttribute(h, 4);
		cout << "Status: " << tablica_pokoi[i].status << endl;
		SetConsoleTextAttribute(h, 7);
		cout << "---------------------------------------" << endl;
	}
}
void Pokoj::zwolnij_pokoj()
{
	if (tablica_pokoi.empty())
		return;
	tablica_pokoi.pop_back();
}
double Pokoj::zlicz_finanse()
{
	przychody_z_pokojow = 0;
	for (size_t i = 0; i < tablica_pokoi.size(); i++)
		przychody_z_pokojow += cena_za_pokoj;
	return przychody_z_pokojow;
}

// FINANSE //
Finanse::Finanse(double utrzymanie_hotelu)
{
	pracownik = new Pracownik * [size];
	for (size_t i = 0; i < size; i++)
		pracownik[i] = new Pracownik;
	this->utrzymanie_hotelu = utrzymanie_hotelu;
}
Finanse::Finanse(const Finanse& obj)
{
	pracownik = new Pracownik * [size];
	for (size_t i = 0; i < size; i++)
		pracownik[i] = new Pracownik;

	for (size_t i = 0; i < size; i++)
	{
		pracownik[i]->setImie(obj.pracownik[i]->getImie());
		pracownik[i]->setNazwisko(obj.pracownik[i]->getNazwisko());
		pracownik[i]->setPensja(obj.pracownik[i]->getPensja());
		pracownik[i]->setStanowisko(obj.pracownik[i]->getStanowisko());
	}
}
Finanse::~Finanse()
{
	for (size_t i = 0; i < size; i++)
		delete pracownik[i];
	delete[] pracownik;
	pracownik = nullptr;
}
void Finanse::dodaj()
{
	for (int i = counter; i <= counter; i++)
	{
		cout << "Podaj imiê: "; cin >> (*pracownik[i]).imie;
		cout << "Podaj nazwisko: "; cin >> pracownik[i]->nazwisko;
		cout << "Podaj stanowisko: "; cin >> pracownik[i]->stanowisko;
		cout << "Podaj pensje: "; cin >> pracownik[i]->pensja;
		//pensje_pracownikow += pracownik[i]->pensja;
	}
}
void Finanse::wyswietl()
{
	if (counter == 0)
	{
		cout << "Brak pracowników w systemie." << endl;
		return;
	}
	else
	{
		for (int i = 0; i < counter; i++)
		{
			cout << "ID: " << pracownik[i]->id + (i + 1) << endl;
			cout << "Imiê: " << pracownik[i]->imie << endl;
			cout << "Nazwisko: " << pracownik[i]->nazwisko << endl;
			cout << "Stanowisko: " << pracownik[i]->stanowisko << endl;
			cout << "Pensja: " << pracownik[i]->pensja << endl;
		}
	}
}
void Finanse::usun_pracownika()
{
	if (counter == 0)
	{
		cout << "Brak pracowników do usuniêcia." << endl;
		return;
	}
	else
	{
		counter--;
		cout << "Pomyœlnie usuniêto pracownika." << endl;
	}
}
void Finanse::bilans()
{
	cout << "------DZIENNE DOCHODY------" << endl;
	cout << "Dochód z pokojów: "; SetConsoleTextAttribute(h, 2); cout << pokoj.getPrzychody() << "z³" << endl; SetConsoleTextAttribute(h, 7);
	cout << "£¹czne miesiêczne utrzymanie pracowników: "; SetConsoleTextAttribute(h, 4); cout << utrzymanie_hotelu << "z³" << endl; SetConsoleTextAttribute(h, 7);
	cout << "£¹czne dzienne utrzymanie pracowników: "; SetConsoleTextAttribute(h, 4); cout << utrzymanie_hotelu / 30 << "z³" << endl; SetConsoleTextAttribute(h, 7);
	cout << "---------------------------------------------------------" << endl;
	cout << "£¥CZNY BILANS PRZYCHODÓW (dziennych): "; SetConsoleTextAttribute(h, 14); cout << pokoj.getPrzychody() - utrzymanie_hotelu / 30 << endl; SetConsoleTextAttribute(h, 7);
}
double Finanse::zlicz_finanse()
{
	for (int i = counter; i <= counter; i++)
		utrzymanie_hotelu += pracownik[i]->pensja;
	counter++;
	return utrzymanie_hotelu;
}

// PRACOWNIK //
Finanse::Pracownik::Pracownik(string imie, string nazwisko, string stanowisko, double pensja)
{
	this->imie = imie;
	this->nazwisko = nazwisko;
	this->stanowisko = stanowisko;
	this->pensja = pensja;
}

// REZERWACJE //
Rezerwacje::Rezerwacje(string imie, string nazwisko, size_t numer_telefonu, size_t numer_pokoju)
{
	this->imie = imie;
	this->nazwisko = nazwisko;
	this->numer_telefonu = numer_telefonu;
	this->numer_pokoju = numer_pokoju;
}
Rezerwacje::~Rezerwacje() {}
void Rezerwacje::wprowadz_dane(Rezerwacje*& rezerwacja, size_t rozmiar)
{
	for (size_t i = 0; i < rozmiar; i++)
	{
		cout << "--------------USTAWIANIE REZERWACJI--------------" << endl;
		cout << "WprowadŸ imiê: "; cin >> (rezerwacja + i)->imie;
		cout << "WprowadŸ nazwisko: "; cin >> (rezerwacja + i)->nazwisko;
		cout << "WprowadŸ numer telefonu: "; cin >> (rezerwacja + i)->numer_telefonu;
		cout << "Który pokój zarezerwowaæ?: "; cin >> (rezerwacja + i)->numer_pokoju;
	}
}
//void Rezerwacje::wyswietl(vector<Rezerwacje>& v)
//{
//	if (v.empty())
//		cout << "Brak rezerwacji." << endl;
//	else
//		for (int i = 0; i < v.size(); i++)
//		{
//			cout << "--------WYŒWIETLANIE REZERWACJI--------" << endl;
//			cout << "---------------------------------------" << endl;
//			cout << "Imiê: " << v[i].imie << endl;
//			cout << "Nazwisko: " << v[i].nazwisko << endl;
//			cout << "Numer telefonu: " << v[i].numer_telefonu << endl;
//			cout << "Numer pokoju: " << v[i].numer_pokoju << endl;
//			cout << "---------------------------------------" << endl;
//		}
//}
void Rezerwacje::usun_z_tablicy(vector<Rezerwacje>& v)
{
	if (v.empty())
	{
		cout << "Brak rezerwacji." << endl;
		return;
	}
	else
	{
		v.pop_back();
		cout << "Pomyœlnie anulowano ostatni¹ rezerwacjê." << endl;
	}
}
void Rezerwacje::usun(Rezerwacje*& rezerwacja)
{
	delete rezerwacja;
	rezerwacja = nullptr;
}

// OGOLNE //
int aktualni_goscie(vector<Gosc>& v)
{
	int zliczeni_goscie = 0;
	for (int i = 0; i < v.size(); i++)
	{
		zliczeni_goscie++;
	}
	return zliczeni_goscie;
}