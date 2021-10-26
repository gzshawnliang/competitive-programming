#include <cfloat> // DBL_MAX
#include <cmath>  // std::nextafter
#include <ctime>
#include <iostream>
#include <random>
#include <vector>
#include <chrono>

using namespace std;

int main()
{


    unsigned long long l=static_cast<unsigned long long>(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    
    std::random_device r;
    std::seed_seq seed{l};
    std::mt19937 rng(seed);
    
    std::default_random_engine defEngine = std::default_random_engine(seed);
    std::uniform_int_distribution<int> dis(100, 600);
    //dis(defEngine) ;
    std::cout << "random numbers: ";
    for (int i = 0; i < 10; ++i)
        std::cout << dis(defEngine) << " ";

    std::cout << std::endl;

    int T = 100;
    while (T--)
    {
        //std::cout << dist6(rng) << std::endl;
    }

    return 0;
}
