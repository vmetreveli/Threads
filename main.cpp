#include <thread>
#include <iostream>

void print_numbers_in_background() {
    auto ix{0};
// Attention: an infinite loop!
    while (true) {
        std::cout << "Background: " << ix++ << std::endl;
    }
}

int main() {
    std::thread background{print_numbers_in_background};
    auto jx{0};
    while (jx < 100) {
        std::cout << "Main: " << jx++ << std::endl;
    }
}