#include <iostream>
#include <string>


class Positional
{
    public:
        int power_of_2(int power)
        {
            if (power == 0)
                return 1;

            int new_number = 1, base = 2;

            for (int i = 0; i != power; i++)
                new_number *= base;

            return new_number;
        } 

        int power_of_16(int power)
        {
            if (power == 0)
                return 1;

            int new_number = 1, base = 16;

            for (int i = 0; i != power; i++)
                new_number *= base;

            return new_number;
        }   

        std::string binary_rep(int number)
        {
            std::string remainder, final_string;
            int size = number;

            for (int i = 0; i != size; i++)
            {
                remainder += std::to_string(number % 2);
                number /= 2;

                if (number == 0)
                    break;
            }

            int length = remainder.size();
            
            while (length != 0)
            {
                final_string += remainder[length];
                length --;
            }

            return final_string;
        }

        int decimal_rep(std::string number)
        {
            int last = number.size() - 1, new_number = 0, index = 0;
        
            while (last != -1)
            {
                if (number[last] == '0')
                {
                    new_number += (0 * power_of_2(index));
                    index ++;
                    last --;
                 }
                else
                {
                    new_number += (1 * power_of_2(index));
                    index ++;
                    last --;
                }
            }
            return new_number;
        }

        std::string hexadecimal_rep(int number)
        {
            int result = 0;
            std::string remainder, new_number;

            for (int i = 0; i != number; i++)
            {
                result += number % 16;
                if (result == 10)
                {
                    remainder += "A";
                    result = 0;
                }
                else if (result == 11)
                {
                    remainder += "B";
                    result = 0;
                }
                else if (result == 12)
                {
                    remainder += "C";
                    result = 0;
                }
                else if (result == 13)
                {
                    remainder += "D";
                    result = 0;
                }
                else if (result == 14)
                {
                    remainder += "E";
                    result = 0;
                }
                else if (result == 15)
                {
                    remainder += "F";
                    result = 0;
                }
                else
                {
                    remainder += std::to_string(result);
                    result = 0;
                }
                number /= 16;
                if (number == 0)
                    break;

            }

            int last = remainder.size() - 1;
            
            while(last != -1)
            {
                new_number += remainder[last];
                last--;
            }

            return new_number;
        }

    

};  

int main()
{

    Positional a;

    std::cout << a.hexadecimal_rep(254) << "\n";
    
    return 0;
}

