#include <iostream>
#include <string>
#include <vector>
#include <assert.h>

using namespace std;

class Hotel
{
protected:
	double przychody_z_pokojow;
	double utrzymanie_hotelu;
public:
	virtual double zlicz_finanse() = 0;
	virtual ~Hotel();
};

class Gosc
{
	const size_t ID = 0;
	string imie;
	string nazwisko;
	size_t pesel;
	size_t nr_tel;
	string data_pobytu;
	size_t nr_pokoju;
public:
	Gosc(string = "gosc", string = "gosc", size_t = 0, size_t = 0, string = "brak", size_t = 0);
	~Gosc();

	void setImie(string imie) { this->imie = imie; }
	void setNazwisko(string nazwisko) { this->nazwisko = nazwisko; }
	void setPesel(int pesel) { this->pesel = pesel; }
	void setNrTel(int nr_tel) { this->nr_tel = nr_tel; }
	void setDataPobytu(string data_pobytu) { this->data_pobytu = data_pobytu; }
	void setNrPokoju(int nr_pokoju) { this->nr_pokoju = nr_pokoju; }

	string getImie() { return imie; }
	string getNazwisko() { return this->nazwisko; }
	int getPesel() { return this->pesel; }
	int getNrTel() { return this->nr_tel; }
	string getDataPobytu() { return this->data_pobytu; }
	int getNrPokoju() { return this->nr_pokoju; }
	int getID() { return this->ID; }

	friend ostream& operator<<(ostream& COUT, Gosc& gosc);
	friend istream& operator>>(istream& CIN, Gosc& gosc);

	// DLA POJEDYNCZEGO GOSCIA //
	//void stworz(Gosc*& gosc);
	void inicjalizuj(Gosc*& gosc);
	void usun(Gosc*& gosc);
	//void dodaj(vector<Gosc>& v, Gosc*& gosc);

	// DLA TABLICY OBIEKTOW //
	//void stworz(Gosc*& gosc, const size_t rozmiar);
	void inicjalizuj(Gosc*& gosc, const size_t rozmiar);
	void usun(Gosc*& gosc, const size_t rozmiar);
	//void dodaj(vector<Gosc>& v, Gosc*& gosc, const size_t rozmiar);

	// DLA TABLICY WSKAZNIKOW //
	void stworz(Gosc**& gosc, const size_t rozmiar);
	void inicjalizuj(Gosc**& gosc, const size_t rozmiar);
	void usun(Gosc**& gosc, const size_t rozmiar);

	// OGOLNE //
	void wypisz(vector<Gosc>& v);
	void usun_goscia(vector<Gosc>& v);
};

class Pokoj : public Hotel
{
	size_t pokoj;
	string status;
	static double przychody_z_pokojow;

public:
	Pokoj(size_t = 0, string = "wolny");
	void zajmij_pokoj(Pokoj&);
	void wyswietl_pokoje();
	void zwolnij_pokoj();
	double getPrzychody() { return przychody_z_pokojow; }
	virtual double zlicz_finanse();
};

int aktualni_goscie(vector<Gosc>&);

class Finanse : public Hotel
{
	double utrzymanie_hotelu;

	class Pracownik
	{
		const size_t id = 0;
		string imie;
		string nazwisko;
		string stanowisko;
		double pensja;
	public:
		friend class Finanse;
		Pracownik(string = "pracownik", string = "pracownik", string = "brak", double = 0);
		string getImie() { return this->imie; }
		string getNazwisko() { return this->nazwisko; }
		string getStanowisko() { return this->stanowisko; }
		double getPensja() { return this->pensja; }
		void setImie(string imie) { this->imie = imie; }
		void setNazwisko(string nazwisko) { this->nazwisko = nazwisko; }
		void setStanowisko(string stanowisko) { this->stanowisko = stanowisko; }
		void setPensja(double pensja) { this->pensja = pensja; }
	};
	Pracownik** pracownik;
	size_t size = 10;
public:
	Finanse::Pracownik& operator[](size_t indeks);
	Finanse& operator=(const Finanse& prawaStrona);
	friend class Pracownik;
	Finanse(double = 0);
	Finanse(const Finanse&);
	~Finanse();
	double getUtrzymanieHotelu() { return this->utrzymanie_hotelu; }
	void setUtrzymanieHotelu(double utrzymanie_hotelu) { this->utrzymanie_hotelu = utrzymanie_hotelu; }
	void dodaj();
	void wyswietl();
	void usun_pracownika();
	void bilans();
	virtual double zlicz_finanse();
};

class Rezerwacje
{
	string imie;
	string nazwisko;
	size_t numer_telefonu;
	size_t numer_pokoju;
public:
	Rezerwacje(string = "imiê", string = "nazwisko" , size_t = 0, size_t numer_pokoju = 0);
	~Rezerwacje();
	void wprowadz_dane(Rezerwacje*&, size_t);
	void wyswietl(vector<Rezerwacje>&);
	void usun_z_tablicy(vector<Rezerwacje>&);
	void usun(Rezerwacje*&);
	string getImie() { return this->imie; };
	string getNazwisko() { return this->nazwisko; };
	size_t getNumerTel() { return this->numer_telefonu; };
	size_t getNumerPok() { return this->numer_telefonu; };
};

class Menu
{
	string potrawa;
public:
	string getPotrawa() { return this->potrawa; }
	void setPotrawa(string potrawa) { this->potrawa = potrawa; }
};