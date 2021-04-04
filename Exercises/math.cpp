#include <iostream>

class Math
{
    public:

        int logarithm(int base, int number)
        {
            if (number < 0)
            {
                std::cout << "Please provide only positive numbers!\n";
                return 0;
            }

            int initial = 1, counter = 0;

            while (initial != number)
            {
                initial *= base;
                if (initial > number)
                {
                    std::cout << "Not implemented behaviour, please give a valid base and number\n";
                    return 0;
                }
                else
                    counter++;
            }

            return counter;
        }

        int exponent(int number, int power)
        {
            int base = number;

            if (power == 0)
                return 1;
            else
            {
                for (int i = 0; i != (power - 1); i++)
                    number *= base;
            }

            return number;
        }

};
