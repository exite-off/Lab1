#include <fstream>
#include <iostream>
#include <random>
#include <vector>

std::vector<int> random_options(const int max, const int amount) {
    std::vector<int> options(amount);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, max);
    for (int i = 0; i < amount; i++) {
        options[i] = dist(gen);
    }
    return options;
}

int main() {
    // Todo...

    return 0;
}
