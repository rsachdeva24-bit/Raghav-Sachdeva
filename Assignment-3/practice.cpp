#include <iostream>
#include <string>
using namespace std;

class ShoppingCart {
private:
    int cart_id;
    string customer_name;
    int item_count;

public:
    // parameterized constructor
    ShoppingCart(int id, string name, int count)
        : cart_id(id), customer_name(std::move(name)), item_count(count) {}

    // destructor (prints a message when the object is deleted)
    ~ShoppingCart() {
        cout << "Thank you, " << customer_name << endl;
    }

    void display_cart() const {
        cout << "Cart ID: " << cart_id << endl;
        cout << "Customer Name: " << customer_name << endl;
        cout << "Number of Items in Cart: " << item_count << endl;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // array of pointers (class has no default ctor)
    ShoppingCart **carts = new ShoppingCart*[n];

    for (int i = 0; i < n; ++i) {
        int id, count;
        string name;

        cin >> id;          // ID on its own line or separated by whitespace
        cin >> ws;          // eat leftover whitespace/newline before getline
        getline(cin, name); // full customer name (may contain spaces)
        cin >> count;       // item count

        carts[i] = new ShoppingCart(id, name, count);
    }

    for (int i = 0; i < n; ++i) {
        carts[i]->display_cart();
    }

    // cleanup: triggers destructor for each cart
    for (int i = 0; i < n; ++i) {
        delete carts[i];
    }
    delete[] carts;

    return 0;
}
