#include <thread>
#include <iostream>

void print_numbers_in_background(int end) {
    auto ix{0};
// Attention: an infinite loop!
    while (ix <= end) {
        std::cout << "Background: " << ix++ << std::endl;
    }
}

int main() {
    std::thread background{print_numbers_in_background, 10};
    auto jx{0};
    while (jx < 100) {
        std::cout << "Main: " << jx++ << std::endl;
    }
    // background.join(); for waiting thread
}