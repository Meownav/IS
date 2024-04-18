#include <iostream>
#include <string>

int main()
{
    std::string msg;
    int key;
    std::cout << "Enter the message and the key";
    std::cin >> msg >> key;
    if (key == 1)
    {
        std::cout << msg;
        exit(0);
    }
    for (int i = 0; i < key; i++)
    {
        for (int j = 0, idx = i; idx < msg.length(); j++)
        {
            std::cout << msg.at(idx);
            if ((i == 0) || (i == key - 1))
            {
                idx += 2 * key - 2;
            }
            else
            {
                if (j % 2 == 0) // Even.
                {
                    idx += (2 * key) - (2 * i) - 2;
                }
                else // Odd.
                {
                    idx += 2 * i;
                }
            }
        }
        std::cout << std::endl;
    }
}
