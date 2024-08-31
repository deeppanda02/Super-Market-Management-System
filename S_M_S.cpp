#include<iostream>
#include<fstream>
#include<windows.h>
using namespace std;

class Market{
    private:
        string Name;
        int Quantity, Price;
    
    public:
    	// CALLING CONSTRUCTOR
    	
        Market() : Name(""), Quantity(0), Price(0) {} // TO USE NAME , QUANTITY , AND PRICE FUNCTION WE NEED FUNCTIONS SO WE ARE USING "GETTERS" AND "SETTERS"
		
		// SETTERS-------->
        void setName(string name) {
            Name = name;
        }

        void setQuant(int quantity) {
            Quantity = quantity;
        }

        void setPrice(int price) {
            Price = price;
        }
		
		// GETTER FUNCTION----> AND WE HAVE TO RETURN A TYPE
		
        string getName() {
            return Name;
        }

        int getQuant() {
            return Quantity;
        }

        int getPrice() {
            return Price;
        }
};

void addItem(Market m) {
    string name;
    int quantity, price;
    
    cout << "Enter Name Of Item: ";
    cin >> name;
    m.setName(name); // The name that we got from user now we are setting it here.
    
    cout << "Enter Quantity: ";
    cin >> quantity;
    m.setQuant(quantity);
    
    cout << "Enter Price: ";
    cin >> price;
    m.setPrice(price);
    
    ofstream out("E:/Super Market Management System/Super_Market.txt", ios::app);
    if (!out) {
        cout << "File Cannot Be Opened" << endl;
    } else {
        out << m.getName() << "   ,   " << m.getQuant() << "   ,   " << m.getPrice() << endl;
        cout << "Item Saved Successfully!" << endl;
    }
    out.close();
}

void search(Market m) {
    string name;
    cout << "Enter Name Of Item: ";
    cin >> name;
    
    ifstream in("E:/Super Market Management System/Super_Market.txt");
    if (!in) {
        cout << "File Not Found" << endl;
    } else {
        string line;
        bool found = false;
        while (getline(in, line)) {
            int pos = line.find(name);
            if (pos != string::npos) {
                cout << "Item | Quantity | Price" << endl;
                cout << line << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "Item Not Found!" << endl;
        }
    }
}

int main() {
    Market m;
    bool exit = false;
    while (!exit) {
        system("cls");
        cout << "Welcome To Super Market Management System" << endl;
        cout << "*****************************************" << endl;	
        cout << "1. Add Items" << endl;
        cout << "2. Search Items" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter Choice: ";

        int val;
        cin >> val;
        if (val == 1) {
            system("cls");
            addItem(m);
            Sleep(5000);
        } else if (val == 2) {
            system("cls");
            search(m);
            Sleep(5000);
        } else if (val == 3) {
            system("cls");
            exit = true;
            cout << "Good Luck!" << endl;
            Sleep(3000);
        }
    }
}