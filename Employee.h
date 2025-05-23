#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"
#include <iostream>
#include <string>
using namespace std;

class Employee : public Person {
private:
    string position;
    
public:
    Employee() : Person(), position("") {}

    void input() override {
        Person::input();
        cout << "Nhap vi tri: "; getline(cin, position);
       
    }

    void display() const override {
        cout << "Nhan vien:\n";
        Person::display();
        cout << ", Vi tri: " << position  << endl;
    }

    friend ostream& operator<<(ostream& os, const Employee& e) {
        e.display();
        return os;
    }
};

#endif

