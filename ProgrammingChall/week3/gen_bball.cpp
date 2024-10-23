#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(0));
    int n = std::rand() % 10 + 1; // Generates a random number between 1 and 100
    std::cout << n << "\n";
    for (int i = 0; i < n; i++) {
        std::cout << std::rand() % 10 << " ";
    }
    std::cout << "\n";
    for (int i = 0; i < n; i++) {
        std::cout << std::rand() % 10 << " ";
    }
    std::cout << "\n";
    return 0;
}
