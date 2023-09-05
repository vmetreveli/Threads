//#include <thread>
//#include <iostream>
//
//void print_numbers_in_background(int end) {
//    auto ix{0};
//// Attention: an infinite loop!
//    while (ix <= end) {
//        std::cout << "Background: " << ix++ << std::endl;
//    }
//}
//
//int main() {
//    std::thread background{print_numbers_in_background, 10};
//    auto jx{0};
//    //auto jx=0;
//
//    while (jx < 100) {
//        std::cout << "Main: " << jx++ << std::endl;
//    }
//    // background.join(); for waiting thread
//}

//
#include <thread>
#include <iostream>
std::atomic_int a=0;
int counter = 0;
std::mutex m;
void foo() {
    std::lock_guard g{m};
    counter++;
}

int main() {
    std::thread A{foo};
    std::thread B{foo};
    std::thread C{[] { foo(); }};
    std::thread D{[] {
        for (int i = 0; i < 10; ++i) {
            foo();
        }
    }};
    std::cout << "Count: " << counter;
}