// Simple C++ program, for any given number and given power will output a new number composed of the given number digits raised to the given power

#include <iostream>
#include <string>

std::string power(int x, int y)
{
   int output = 1;
   int base = x;

   for (int i = 0; i != y; i++)
        output *= base;

    return std::to_string(output);
}

std::string calculate(int x, int y)
{
    std::string converted = std::to_string(x);
    char a;
    std::string output;

    for (int i = 0; i != converted.size(); i++)
    {
        a = converted[i];
        std::string b(1, a);
        output += power(std::stoi(b), y);
    }
    return output;
}

