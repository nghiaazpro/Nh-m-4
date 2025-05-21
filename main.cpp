#include <iostream>
#include "Order.h"

using namespace std;

int main() {
    Order order;

    cout << "===== Nhap don hang =====\n";
    order.input();

    cout << "\n===== Thong tin don hang =====\n";
    order.display();

    return 0;
}
