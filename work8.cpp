// Simple C++ program, binary search with stored log and read from that .txt file previous values computed

#include <iostream>
#include <vector>
#include <fstream>
#include <unistd.h>
#include <string>

int directory = chdir("D:\\Stuff\\C++");

void create_log(int element)
{
    std::ofstream file;
    file.open("Memo.txt", std::ios_base::app);
    file << element << ";";
    file.close();


}

int read_log(int element)
{
    std::ifstream file;
    file.open("Memo.txt");
    std::string line, memo;

    while (getline(file, line))
    {
        for (int i = 0; i != line.size(); i++)
        {
            if (line[i] != ';')
                memo += line[i];            
            else
                if (std::stoi(memo) == element)
                    return std::stoi(memo);
                else
                {
                    memo = "";
                }             
            
        }
    }
    file.close(); // close file!
    if (memo == "")
        return -1;
        
    return std::stoi(memo);
}

bool binary_search(std::vector<int> iterator, int element)
{
    int stored_rezolt = read_log(element); // check if a previous output for this call exists
    if (element == stored_rezolt)
    {
        std::cout << "Entered here" << "\n";
        std::cout << stored_rezolt << "\n";
        std::cout << "Element can be found\n";
        return true;
    }

    int middle, size;
    std::vector<int> new_iterator;

    size = iterator.size();

    if (size == 0)
    {
        std::cout << "Element can't be found\n";

        return false;
    }
    else if (size == 1 || size == 2)
    {
        if (element == iterator[0] || element == iterator[1])
        {
            create_log(element);
            std::cout << "Element can be found \n";
        }
    }

    if (size % 2 == 0)
        middle = (size / 2);
    else
        middle = (size / 2) + 1;

    
    if (element == iterator[middle])
    {
        create_log(element); // store this output
        std::cout << "Element can be found \n";
    }
    else if (element > iterator[middle])
    {
        for (int i = middle; i != size; i++)
            new_iterator.push_back(iterator[i]);       
        
        binary_search(new_iterator, element);
    }
    else
    {
        for (int i = 0; i != middle; i++)
            new_iterator.push_back(iterator[i]);

        binary_search(new_iterator, element);
    }

    return true;
}


int main()
{
    std::vector<int> a = {1,2,3,4,5,6,7,8,9,10,11};
    binary_search(a, 2);

    return 0;
}

