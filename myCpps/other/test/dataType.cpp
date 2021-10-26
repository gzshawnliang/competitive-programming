#include <limits>
#include <iostream>
 
int main() 
{
    std::cout << "type\tlowest\thighest\n";

    std::cout << "bool\t"
              << std::numeric_limits<bool>::lowest() << '\t'
              << std::numeric_limits<bool>::max() << '\n';  

    std::cout << "short\t"
              << std::numeric_limits<short>::lowest() << '\t'
              << std::numeric_limits<short>::max() << '\n'; 

    std::cout << "unsignedshort\t"
              << std::numeric_limits<unsigned short>::lowest() << '\t'
              << std::numeric_limits<unsigned short>::max() << '\n';                             

    std::cout << "int\t"
              << std::numeric_limits<int>::lowest() << '\t'
              << std::numeric_limits<int>::max() << '\n';

    std::cout << "unsigned int\t"
              << std::numeric_limits<unsigned int>::lowest() << '\t'
              << std::numeric_limits<unsigned int>::max() << '\n';              

    std::cout << "long\t"
              << std::numeric_limits<long>::lowest() << '\t'
              << std::numeric_limits<long>::max() << '\n';

    std::cout << "unsignedlong\t"
              << std::numeric_limits<unsigned long>::lowest() << '\t'
              << std::numeric_limits<unsigned long>::max() << '\n';              

    std::cout << "longlong\t"
              << std::numeric_limits<long long>::lowest() << '\t'
              << std::numeric_limits<long long>::max() << '\n';

    std::cout << "unsignedlonglong\t"
              << std::numeric_limits<unsigned long long>::lowest() << '\t'
              << std::numeric_limits<unsigned long long>::max() << '\n';              

    std::cout << "float\t"
              << std::numeric_limits<float>::lowest() << '\t'
              << std::numeric_limits<float>::max() << '\n';


    std::cout << "double\t"
              << std::numeric_limits<double>::lowest() << '\t'
              << std::numeric_limits<double>::max() << '\n';

    std::cout << "longdouble\t"
              << std::numeric_limits<long double>::lowest() << '\t'
              << std::numeric_limits<long double>::max() << '\n';              
}