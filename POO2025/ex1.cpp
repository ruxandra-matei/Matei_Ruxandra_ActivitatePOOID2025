#include <iostream.h>

using namespace std;

struct Restaurant {
	char nume[50];
	char adresa[100];
	int rating;
};

void afisareRestaurant(const Restaurant& r) {
	cout << "Numele restaurantului este: " << r.nume << endl;
	cout << "Adresa: " << r.adresa << endl;
	cout << "Rating: " << r.rating << endl;
}
int main() {
	Restaurant r1 = {"La Mama", "Strada Florilor 10", 5};
	afisareRestaurant(r1);
	return 0;
}