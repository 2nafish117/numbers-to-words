#include <iostream>
#include <fstream>
#include <string>
#include "number.hpp"

int main()
{
    Number num;
    std::ofstream output;
    output.open("output.txt");

    for(int i = 1;i <= 999;i++)
        output << num.toWordsHundreds(std::to_string(i)) << std::endl;

    return 0;
}