#include <iostream>

using namespace std;

class Pojazd
{
protected:

    string marka,model,nr_rej,kolor;
    float pojemnosc;
    long long int vin;

public:

Pojazd(string ma="nie podano", string mo="nie podano", string r="nie podano", string k="nie podano", float p=0, long long int v=0)
    {
        marka=ma;
        model=mo;
        nr_rej=r;
        kolor=k;
        pojemnosc=p;
        vin=v;
    }

    void wczytaj()
    {
        cout<<"Podaj dane pojazdu: "<<endl;
        cout<<"Podaj marke: ";
        cin>>marka;
        cout<<"Podaj model: ";
        cin>>model;
        cout<<"Podaj numer rejestracyjny: ";
        cin>>nr_rej;
        cout<<"Podaj kolor: ";
        cin>>kolor;
        cout<<"Podaj pojemnosc silnika: ";
        cin>>pojemnosc;
        cout<<"Podaj numer nadwozia (nr VIN): ";
        cin>>vin;
    }

    void pokaz()
    {
        cout<<"Dane pojazdu:"<<endl;
        cout<<"Marka: "<<marka<<endl;
        cout<<"Model: "<<model<<endl;
        cout<<"Numer rejestracyjny: "<<nr_rej<<endl;
        cout<<"Kolor: "<<kolor<<endl;
        cout<<"Pojemnosc silnika: "<<pojemnosc<<endl;
        cout<<"Numer nadwozia VIN: "<<vin<<endl;

    }

};

class Osobowe:public Pojazd
{
protected:
    string nadwozie;
    int ile_osob; //ilosc miejsc siedzacych w samocgodzie

public:
Osobowe(string ma="nie podano", string mo="nie podano", string r="nie podano", string k="nie podano", float p=1.1, long long int v=123456789, string n="nie podano", int l=4):Pojazd(ma,mo,r,k,p,v)
{

nadwozie=n;
ile_osob=l;

}

    void wczytaj()
    {
        Pojazd::wczytaj();
        cout<<"Podaj typ nadwozia auta osobowego: ";
        cin>>nadwozie;
        cout<<"Podaj liczbe siedzen w aucie: ";
        cin>>ile_osob;
        while(ile_osob<2 || ile_osob>4)
        {
            cout<<"Niepoprawna liczba siedzen. Auto osobowe ma przynajmniej 2 siedzenia. Maksymalna liczba siedzen dla auta osobowego to 4."<<endl<<"Podaj ponownie poprawna liczbe siedzen: ";
            cin>>ile_osob;
        }
    }

    void pokaz()
    {
        Pojazd::pokaz();
        cout<<"Nadwozie: "<<nadwozie<<endl;
        cout<<"Liczba siedzen w aucie: "<<ile_osob<<endl;
    }


};

class Ciezarowe:public Pojazd
{
protected:
    float ladownosc;
    int ile_osi;

public:
Ciezarowe(string ma="nie podano", string mo="nie podano", string r="nie podano", string k="nie podano", float p=1.1, long long int v=123456789, float l=20, int o=2):Pojazd(ma,mo,r,k,p,v)
{

	ladownosc=l;
	ile_osi=o;

}

    void wczytaj()
    {
        Pojazd::wczytaj();
        cout<<"Podaj ladownosc ciezarowki: "<<endl;
        cin>>ladownosc;
         while(ladownosc<20 || ladownosc>45)
        {
            cout<<"Niepoprawna ladownosc. Ciezarowka musi miec przynajmniej 20 ton ladownosci. Max ladownosc wynosi 45 ton"<<endl<<"Podaj ponownie poprawna ladownosc: ";
            cin>>ladownosc;
        }
        cout<<"Podaj liczbe osi ciezarowki: "<<endl;
        cin>>ile_osi;
         while(ile_osi<3 || ile_osi>5)
        {
            cout<<"Niepoprawna ilosc osi. Ciezarowka musi miec przynajmniej 3 osie i nie moze miec ich wiecej niz 5"<<endl<<"Podaj ponownie poprawna liczbe osi: ";
            cin>>ile_osi;
        }
    }

    void pokaz()
    {
        Pojazd::pokaz();
        cout<<"Ladownosc: "<<ladownosc<<" ton"<<endl;
        cout<<"Liczba osi: "<<ile_osi<<endl;
    }


};

class Kamaz:public Ciezarowe
{

public:
Kamaz(string ma="Kamaz", string mo="T130", string r="nie podano", string k="nie podano", float p=5.3, long long int v=123456789, float l=28, int o=3):Ciezarowe(ma,mo,r,k,p,v,l,o)
{

}

    void wczytaj()
    {
        cout<<"Podaj dane szczegolowe ciezarowki Kamaz:"<<endl;
        cout<<"Podaj numer rejestracyjny: ";
        cin>>nr_rej;
        cout<<"Podaj kolor: ";
        cin>>kolor;
        cout<<"Podaj numer nadwozia (nr VIN): ";
        cin>>vin;

    }

    void pokaz()
    {
        Ciezarowe::pokaz();

    }


};

class Maluch:public Osobowe
{

int r_prod;

public:
Maluch(string ma="Fiat", string mo="126P", string r="nie podano", string k="nie podano", float p=0.6, long long int v=123456789, int rp=1972):Osobowe(ma,mo,r,k,p,v)
{
 r_prod=rp;
}

    void wczytaj()
    {
        cout<<"Podaj dane szczegolowe Malucha:"<<endl;
        cout<<"Podaj numer rejestracyjny: ";
        cin>>nr_rej;
        cout<<"Podaj kolor: ";
        cin>>kolor;
        cout<<"Podaj numer nadwozia (nr VIN): ";
        cin>>vin;
		cout<<"Podaj pojemnosc silnika: ";
        cin>>pojemnosc;
		cout<<"Podaj rok produkcji: ";
        cin>>r_prod;
        while(r_prod<1972 || r_prod>2000)
        {
            cout<<"Nieprawidlowy rok produkcji. Maluch byl produkowany w latach 1972 - 2000"<<endl<<"Podaj ponownie poprawna date produkcji: ";
            cin>>r_prod;

        }
    }

    void pokaz()
    {
        Pojazd::pokaz();
        cout<<"Rok produkcji: "<<r_prod<<endl;

    }


};

class Wlasciciel:public Maluch
{

private:

    string imie,nazwisko,miejscowosc;
    int wiek;

public:

    Wlasciciel(string i="N/N", string n="N/N", string m="N/N", int w=18)
    {
        imie=i;
        nazwisko=n;
        miejscowosc=m;
        wiek=w;
    }

    void generuj()
    {
        cout<<"Podaj dane wlasciciela auta"<<endl;
        cout<<"Imie: ";
        cin>>imie;
        cout<<"Nazwisko: ";
        cin>>nazwisko;
        cout<<"Miejscowosc pochodzenia: ";
        cin>>miejscowosc;
        cout<<"Wiek: ";
        cin>>wiek;
        while(wiek<18)
        {
            cout<<"W Polsce osoba niepelnoletnia nie moze byc posiadaczem samochodu!"<<endl<<"Podaj wiek doroslego posiadacza auta! "<<endl;
            cin>>wiek;
        }
    }

    void jezdzi()
    {
        cout<<"Dane posiadacza auta:"<<endl<<endl<<"Wlasciciel: "<<imie<<" "<<nazwisko<<" z miejscowosci: "<<miejscowosc<<" w wieku: "<<wiek<<" posiada auto o ponizszych danych: "<<endl;
    }
};
int main()
{

    Maluch m1;
    m1.wczytaj();
    Wlasciciel w1;
    w1.generuj();
    w1.jezdzi();
    m1.pokaz();
    cout<<"__________________"<<endl;
    Kamaz k1;
    k1.wczytaj();
    Wlasciciel w2;
    w2.generuj();
    w2.jezdzi();
    k1.pokaz();


    return 0;
}
