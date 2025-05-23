#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>
using namespace std;

// Dinh nghia lop Product (San pham)
class Product {
protected: //Thuoc tinh
    string id;             // ID san pham
    string name;           // Ten san pham
    double price;          // Gia san pham
    string manufacturer;   // Nha san xuat

public:
    // Constructor mac dinh
    Product() : id(""), name(""), price(0.0), manufacturer("") {}

    // Phuong thuc nhap thong tin san pham	
    virtual void input() {
        cout << "Nhap ID: "; getline(cin, id);
        cout << "Nhap ten: "; getline(cin, name);
        cout << "Nhap gia: "; cin >> price; cin.ignore();
        cout << "Nhap nha san xuat: "; getline(cin, manufacturer);
    }

    // Phuong thuc hien thi thong tin san pham
    virtual void display() const {
        cout << "ID: " << id << ", Ten: " << name 
             << ", Gia: " << price << ", NSX: " << manufacturer << endl;
    }

    // Phuong thuc lay gia san pham
    double getPrice() const { return price; }

    // Nap chong toan tu << de hien thi thong tin san pham
    friend ostream& operator<<(ostream& os, const Product& p) {
        p.display();
        return os;
    }

    // Destructor ao de dam bao giai phong tai nguyen dung cach khi ke thua
    virtual ~Product() {}
};

#endif




