#include <iostream>
#include "LinkedList.h"

int main() {
    LinkedList<int> a;
    a.push_back(1);
    a.push_back(5);
    a.push_back(3);
    std::cout << a << std::endl;
    std::cout << a.get_front() << " " << a.get_back() << std::endl;
    a.clear();
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_front(1);
    a.insert(10, 3);
    a.insert(12, 1);
    std::cout << a << std::endl;
    std::cout << a.size() << std::endl;
    std::cout << a << std::endl;
    a.swap(0, 3);
    std::cout << a << std::endl;
    a.reverse();
    std::cout << a << std::endl;

    for (auto element : a) {
        std::cout << element << " ";
    }

    std::cout << std::endl;

    for (auto it = a.r_begin(); it != a.r_end(); ++it) {
        std::cout << *it << " ";
    }

    return 0;
}
