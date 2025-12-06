#include <iostream>
#include <string>
using namespace std;

class Restaurant {
private:
    string nume;
    string adresa;
    int rating;

public:
    Restaurant() {
        this->nume = "";
        this->adresa = "";
        this->rating = 0;
    }

    string getNume() const {
        return this->nume;
    }

    string getAdresa() const {
        return this->adresa;
    }

    int getRating() const {
        return this->rating;
    }

    void setNume(const string& nume) {
        this->nume = nume;
    }

    void setAdresa(const string& adresa) {
        this->adresa = adresa;
    }

    void setRating(int rating) {
        this->rating = rating;
    }

    void afisare() const {
        cout << "Numele restaurantului este: " << nume << endl;
        cout << "Adresa: " << adresa << endl;
        cout << "Rating: " << rating << endl;
    }

    friend ostream& operator<<(ostream& out, const Restaurant& r) {
        out << r.nume << " " << r.adresa << " " << r.rating;
        return out;
    }
};

int main() {
    Restaurant r;

    r.setNume("La Mama");
    r.setAdresa("Strada Florilor 10");
    r.setRating(5);

    cout << r;

    return 0;
}
