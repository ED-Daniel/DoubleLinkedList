#include <iostream>
#include <algorithm>
#include <vector>
#include "LinkedList.h"

int main() {
    LinkedList<int> a;
    a.push_back(1);
    a.push_back(4);
    a.push_back(2);
    a.push_back(6);

    for (const int target: {3, 4, 5}) {
        const int num_items = std::count(a.ra_begin(), a.ra_end(), target);
        std::cout << "number: " << target << ", count: " << num_items << '\n';
    }

    return 0;
}
