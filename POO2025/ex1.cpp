#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Restaurant {
public:
    string nume;
    string adresa;
    int rating;

    int nrSpecialitati;
    string* specialitati;

    const int id;

    static int nrRestaurante;
    static int nextId;

    Restaurant() : id(nextId++) {
        nume = "";
        adresa = "";
        rating = 0;

        nrSpecialitati = 0;
        specialitati = nullptr;

        nrRestaurante++;
    }

    Restaurant(string nume) : id(nextId++) {
        this->nume = nume;
        adresa = "";
        rating = 0;

        nrSpecialitati = 0;
        specialitati = nullptr;

        nrRestaurante++;
    }

    Restaurant(string nume, string adresa, int rating, int nrSpecialitati, string* specialitati) : id(nextId++) {
        this->nume = nume;
        this->adresa = adresa;
        this->rating = rating;

        this->nrSpecialitati = nrSpecialitati;
        if (nrSpecialitati > 0 && specialitati != nullptr) {
            this->specialitati = new string[nrSpecialitati];
            for (int i = 0; i < nrSpecialitati; i++) this->specialitati[i] = specialitati[i];
        }
        else {
            this->specialitati = nullptr;
            this->nrSpecialitati = 0;
        }

        nrRestaurante++;
    }

    Restaurant(const Restaurant& r) : id(nextId++) {
        nume = r.nume;
        adresa = r.adresa;
        rating = r.rating;

        nrSpecialitati = r.nrSpecialitati;
        if (nrSpecialitati > 0 && r.specialitati != nullptr) {
            specialitati = new string[nrSpecialitati];
            for (int i = 0; i < nrSpecialitati; i++) specialitati[i] = r.specialitati[i];
        }
        else {
            specialitati = nullptr;
            nrSpecialitati = 0;
        }

        nrRestaurante++;
    }

    Restaurant& operator=(const Restaurant& r) {
        if (this != &r) {
            nume = r.nume;
            adresa = r.adresa;
            rating = r.rating;

            if (specialitati) delete[] specialitati;

            nrSpecialitati = r.nrSpecialitati;
            if (nrSpecialitati > 0 && r.specialitati != nullptr) {
                specialitati = new string[nrSpecialitati];
                for (int i = 0; i < nrSpecialitati; i++) specialitati[i] = r.specialitati[i];
            }
            else {
                specialitati = nullptr;
                nrSpecialitati = 0;
            }
        }
        return *this;
    }

    ~Restaurant() {
        if (specialitati) delete[] specialitati;
        nrRestaurante--;
    }

    static double ratingMediu(const Restaurant* v, int n) {
        if (!v || n <= 0) return 0.0;
        double s = 0;
        for (int i = 0; i < n; i++) s += v[i].rating;
        return s / n;
    }
};

int Restaurant::nrRestaurante = 0;
int Restaurant::nextId = 1;

class Meniu {
public:
    string denumire;

    int nrProduse;
    double* preturi;

    const string tip;

    static int nrMeniuri;
    static double TVA;

    Meniu() : tip("Standard") {
        denumire = "";
        nrProduse = 0;
        preturi = nullptr;

        nrMeniuri++;
    }

    Meniu(string denumire, string tip) : tip(tip) {
        this->denumire = denumire;
        nrProduse = 0;
        preturi = nullptr;

        nrMeniuri++;
    }

    Meniu(string denumire, string tip, int nrProduse, double* preturi) : tip(tip) {
        this->denumire = denumire;

        this->nrProduse = nrProduse;
        if (nrProduse > 0 && preturi != nullptr) {
            this->preturi = new double[nrProduse];
            for (int i = 0; i < nrProduse; i++) this->preturi[i] = preturi[i];
        }
        else {
            this->preturi = nullptr;
            this->nrProduse = 0;
        }

        nrMeniuri++;
    }

    Meniu(const Meniu& m) : tip(m.tip) {
        denumire = m.denumire;

        nrProduse = m.nrProduse;
        if (nrProduse > 0 && m.preturi != nullptr) {
            preturi = new double[nrProduse];
            for (int i = 0; i < nrProduse; i++) preturi[i] = m.preturi[i];
        }
        else {
            preturi = nullptr;
            nrProduse = 0;
        }

        nrMeniuri++;
    }

    Meniu& operator=(const Meniu& m) {
        if (this != &m) {
            denumire = m.denumire;

            if (preturi) delete[] preturi;

            nrProduse = m.nrProduse;
            if (nrProduse > 0 && m.preturi != nullptr) {
                preturi = new double[nrProduse];
                for (int i = 0; i < nrProduse; i++) preturi[i] = m.preturi[i];
            }
            else {
                preturi = nullptr;
                nrProduse = 0;
            }
        }
        return *this;
    }

    ~Meniu() {
        if (preturi) delete[] preturi;
        nrMeniuri--;
    }

    static double totalCuTVA(const Meniu& m) {
        double s = 0;
        for (int i = 0; i < m.nrProduse; i++) s += m.preturi[i];
        return s * (1.0 + TVA);
    }
};

int Meniu::nrMeniuri = 0;
double Meniu::TVA = 0.19;

class Angajat {
public:
    string nume;
    int varsta;
    double salariu;

    char* functie;

    const int id;

    static int nrAngajati;
    static int nextId;

    Angajat() : id(nextId++) {
        nume = "";
        varsta = 0;
        salariu = 0;

        functie = new char[1];
        functie[0] = '\0';

        nrAngajati++;
    }

    Angajat(string nume, const char* functie) : id(nextId++) {
        this->nume = nume;
        varsta = 0;
        salariu = 0;

        if (functie) {
            this->functie = new char[strlen(functie) + 1];
            strcpy(this->functie, functie);
        }
        else {
            this->functie = new char[1];
            this->functie[0] = '\0';
        }

        nrAngajati++;
    }

    Angajat(string nume, int varsta, double salariu, const char* functie) : id(nextId++) {
        this->nume = nume;
        this->varsta = varsta;
        this->salariu = salariu;

        if (functie) {
            this->functie = new char[strlen(functie) + 1];
            strcpy(this->functie, functie);
        }
        else {
            this->functie = new char[1];
            this->functie[0] = '\0';
        }

        nrAngajati++;
    }

    Angajat(const Angajat& a) : id(nextId++) {
        nume = a.nume;
        varsta = a.varsta;
        salariu = a.salariu;

        if (a.functie) {
            functie = new char[strlen(a.functie) + 1];
            strcpy(functie, a.functie);
        }
        else {
            functie = new char[1];
            functie[0] = '\0';
        }

        nrAngajati++;
    }

    Angajat& operator=(const Angajat& a) {
        if (this != &a) {
            nume = a.nume;
            varsta = a.varsta;
            salariu = a.salariu;

            if (functie) delete[] functie;

            if (a.functie) {
                functie = new char[strlen(a.functie) + 1];
                strcpy(functie, a.functie);
            }
            else {
                functie = new char[1];
                functie[0] = '\0';
            }
        }
        return *this;
    }

    ~Angajat() {
        if (functie) delete[] functie;
        nrAngajati--;
    }

    static double salariuMediu(const Angajat* v, int n) {
        if (!v || n <= 0) return 0.0;
        double s = 0;
        for (int i = 0; i < n; i++) s += v[i].salariu;
        return s / n;
    }
};

int Angajat::nrAngajati = 0;
int Angajat::nextId = 1;

int main() {
    string sp[] = { "Paste", "Pizza" };
    Restaurant r1("La Mama", "Strada Florilor 10", 5, 2, sp);
    Restaurant r2;

    double p[] = { 25.5, 18.0, 30.0 };
    Meniu m1("Meniu pranz", "Italian", 3, p);

    Angajat a1("Ion", 30, 4500, "Bucatar");
    Angajat a2("Ana", "Ospatar");

    Restaurant vR[] = { r1, Restaurant("X", "Y", 4, 0, nullptr) };
    cout << "Rating mediu: " << Restaurant::ratingMediu(vR, 2) << "\n";

    cout << "Total meniu cu TVA: " << Meniu::totalCuTVA(m1) << "\n";

    Angajat vA[] = { a1, Angajat("Mihai", 25, 3500, "Ajutor bucatar") };
    cout << "Salariu mediu: " << Angajat::salariuMediu(vA, 2) << "\n";

    cout << "Restaurante active: " << Restaurant::nrRestaurante << "\n";
    cout << "Meniuri active: " << Meniu::nrMeniuri << "\n";
    cout << "Angajati activi: " << Angajat::nrAngajati << "\n";

    return 0;
}
