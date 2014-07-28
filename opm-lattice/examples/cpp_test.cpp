#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
int main()
{
    const int NX = 3;
    const int NY = 3;
    const int NZ = 3;
    int num = 0;
    std::vector<double> vec;
    for (int k = 0; k < NZ; ++k) {
        for (int j = 0; j < NY; ++j) {
            for (int i = 0; i < NX; ++i) {
                vec.push_back(++num);
                std::cout << i << " " << j << " " << k << " " << std::endl;
            }
        }
    }
    for (auto i : vec) {
        std::cout << i << std::endl;
    }

    int x = 1, y = 0, z = 2;
    int index = NZ*NY*z + NY*y + x;
    std::cout << "("<< x << "," << y <<"," << z << ")" << "are: " << vec[index] << std::endl;
    std::vector<int> t;
    for (int i = 0; i < 5; ++i) {
        t.push_back(++i);
    }
    for (auto i : t)
    std::cout << i << std::endl;
}
