#include <vector>
#include <iostream>

using namespace std;

int main() {
    int *t = new int[20]();
    for(int i = 0; i < 20; i++) {
        t[i] = i + 1;
    }
    std::cout << *t << t[0] << std::endl;
    std::cout << "Address: " << t << std::endl;
    std::cout << &t[0];
}