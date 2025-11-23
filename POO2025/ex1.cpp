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

    void afisare() const {
        cout << "Numele restaurantului este: " << nume << endl;
        cout << "Adresa: " << adresa << endl;
        cout << "Rating: " << rating << endl;
    }
};

int main() {
    Restaurant r;   
    r.afisare();

    return 0;
}
