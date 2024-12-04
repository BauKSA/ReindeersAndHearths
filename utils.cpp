#include<random>
#include<chrono>

#include "Utils.h"

float generate_random(int a, int b) {
    static std::mt19937 generator(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_real_distribution<double> distribution(a, b);
    double random_number = distribution(generator);

    return random_number;
}