#include <iostream>
#include <string>

int main()
{
    std::string msg;
    int key;
    std::cout << "Enter the message and the key: ";
    std::cin >> msg >> key;

    for (auto chr : msg)
    {
        std::cout << (char)(chr + key);
    }
}