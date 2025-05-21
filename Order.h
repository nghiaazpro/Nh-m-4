#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <vector>
#include "Customer.h"
#include "Employee.h"
#include "Product.h"
using namespace std;

class Order {
private:
    Customer customer;
    Employee employee;
    vector<Product*> products; 
    vector<int> quantities;
    string orderDate;          

public:
    Order() : orderDate("") {}

    ~Order() {
        for (auto p : products)
            delete p;
    }

    void input() {
    	
    	cout << "Nhap ngay don hang: ";
        getline(cin, orderDate);

        cout << "\nNhap thong tin khach hang:\n";
        customer.input();

        cout << "\nNhap thong tin nhan vien:\n";
        employee.input();

        int numProducts;
        cout << "\nNhap so san pham khach hang muon mua: ";
        cin >> numProducts;
        cin.ignore();

        for (int i = 0; i < numProducts; ++i) {
            cout << "\n--- San pham thu " << i + 1 << " ---\n";
            Product* p = new Product();
            p->input();
            products.push_back(p);

            int q;
            cout << "Nhap so luong: ";
            cin >> q;
            cin.ignore();
            quantities.push_back(q);
        }
    }

    void display() const {
        cout << "Ngay don hang: " << orderDate << endl;
        cout << customer;
        cout << employee;

        double total = 0;
        for (size_t i = 0; i < products.size(); ++i) {
            cout << "\nSan pham thu " << i + 1 << ":\n";
            cout << *(products[i]);
            cout << "So luong: " << quantities[i] << endl;
            total += products[i]->getPrice() * quantities[i];
        }
        cout << "Tong tien don hang: " << total << endl;
    }
};

#endif
