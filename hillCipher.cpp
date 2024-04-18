#include <iostream>
#include <string>

int main()
{
    std::string msg, key;
    std::cout << "Enter the message and the key: ";
    std::cin >> msg >> key;

    for (int i = 0; i < key.length() / msg.length(); i++)
    {
        int letter = 0;
        for (int j = 0; j < msg.length(); j++)
        {
            letter += ((key.at((3 * i) + j) % 97) * (msg.at(j) % 97));
        }
        std::cout << (char)('a' + (letter % 26));
    }
}
