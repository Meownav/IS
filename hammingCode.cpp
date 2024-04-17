#include <iostream>
#include <string>
#include <math.h>
#include <random>
#include <time.h>

int main()
{
    srand(0);
    std::string msg;
    std::cout << "Enter the msg: ";
    std::cin >> msg;

    int redBits = 0;
    int parity = 0;
    int msgSize = msg.size();

    for (int i = 0; (pow(2, i) < msgSize + i + 1); i++)
    {
        redBits++;
        msg.insert((int)pow(2, i) - 1, "x", 1);
    }

    std::cout << msg << std::endl;
    std::cout << "Enter the parity Even(0) or Odd(1): ";
    std::cin >> parity;

    for (int i = 0; i < redBits; i++)
    {
        int localParity = parity;
        for (int j = i + 1; j < msg.length(); j++)
        {
            if (((int)pow(2, i) & j) && msg.at(j - 1) != 'x')
            {
                localParity ^= msg.at(j - 1) == '1';
            }
        }
        msg.replace(msg.find_first_of('x'), 1, localParity == 1 ? "1" : "0");
        std::cout << msg << std::endl;
    }
    // _ _ 1 _ 0 1 0 _ 1 0 1 0
    std::cout << "Sending the msg: \n"
              << msg << std::endl;
    int randPos = rand() % msg.length();
    msg.replace(randPos, 1, msg.at(randPos) == '1' ? "0" : "1");
    std::cout << "Receiving the msg:\n"
              << msg << std::endl;

    for (int i = 0; i < redBits; i++)
    {
        }
}
