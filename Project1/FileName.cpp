#include<iostream>
#include<string>

using namespace std;

class Casa {
private: 
    bool cuEtaj;
    float amprentaSol;
    int nrCamere;
    
    bool* camereLaEtaj;
public:
    // constructor implicit
    Casa() {
        this->cuEtaj = false;
        this->amprentaSol = 0;
        this->nrCamere = 0;
        this->camereLaEtaj = nullptr;
    }

    // constructor cu parametri
    Casa(bool cuEtaj, float amprentaSol, int nrCamere, const bool* valori) {
        this->cuEtaj = cuEtaj;
        this->amprentaSol = amprentaSol;
        this->nrCamere = nrCamere;

        if (nrCamere > 0 && valori != nullptr) {
            this->camereLaEtaj = new bool[nrCamere];
            for (int i = 0; i < nrCamere; i++) {
                this->camereLaEtaj[i] = valori[i];
            }
        }
        else {
            this->camereLaEtaj = nullptr;
        }
    }

    // constructor de copiere (deep copy)
    Casa(const Casa& other) {
        this->cuEtaj = other.cuEtaj;
        this->amprentaSol = other.amprentaSol;
        this->nrCamere = other.nrCamere;

        if (this->nrCamere > 0 && other.camereLaEtaj != nullptr) {
            this->camereLaEtaj = new bool[this->nrCamere];
            for (int i = 0; i < this->nrCamere; i++) {
                this->camereLaEtaj[i] = other.camereLaEtaj[i];
            }
        }
        else {
            this->camereLaEtaj = nullptr;
        }
    }

    // operator=
    Casa& operator=(const Casa& other) {
        if (this != &other) {
            // eliber?m ce aveam deja
            if (this->camereLaEtaj != nullptr) {
                delete[] this->camereLaEtaj;
            }

            // copiem membrii simpli
            this->cuEtaj = other.cuEtaj;
            this->amprentaSol = other.amprentaSol;
            this->nrCamere = other.nrCamere;

            // copiem vectorul dinamic
            if (this->nrCamere > 0 && other.camereLaEtaj != nullptr) {
                this->camereLaEtaj = new bool[this->nrCamere];
                for (int i = 0; i < this->nrCamere; i++) {
                    this->camereLaEtaj[i] = other.camereLaEtaj[i];
                }
            }
            else {
                this->camereLaEtaj = nullptr;
            }
        }
        return *this;
    }

    // destructor
    ~Casa() {
        if (this->camereLaEtaj != nullptr) {
            delete[] this->camereLaEtaj;
        }
    }

    // getteri simpli
    int getNrCamere() const {
        return this->nrCamere;
    }

    float getAmprentaSol() const {
        return this->amprentaSol;
    }

    // operator << pentru afisare
    friend ostream& operator<<(ostream& out, const Casa& c) {
        out << "Cu etaj: " << c.cuEtaj << "\n";
        out << "Amprenta sol: " << c.amprentaSol << "\n";
        out << "Numar camere: " << c.nrCamere << "\n";
        out << "Camere la etaj: ";
        for (int i = 0; i < c.nrCamere; i++) {
            out << c.camereLaEtaj[i] << " ";
        }
        out << "\n";
        return out;
    }
}; 

int main() {
    bool v[3] = { 0, 1, 1 };
    Casa c1(true, 120.5f, 3, v);
    cout << c1 << endl;

    Casa c2 = c1;  // constructor de copiere
    Casa c3;
    c3 = c1;       // operator=
    cout << c2 << endl;
    cout << c3 << endl;
    return 0;
}kllo.mnb            n                                n bo8o778ohn bb nb hhhhnb bbnn bbbnhhbbbbbbbbbbn nb nbh