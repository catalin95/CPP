// Simple C++ program to get the binary of a number

#include <iostream>


int binary(int x)
{
    if (x == 0)
        return 0;
    
    std::string output, output_string;

    while (x != 0)
    {
        output += std::to_string(x % 2);
        x /= 2;
    }

    for (int i = output.size() - 1; i != -1; i--)
        output_string += output[i];

    return std::stoi(output_string);
}


