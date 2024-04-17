#include <iostream>
#include <string>
#include <algorithm>
#include <exception>

int findInArray(char chr, char *matrix)
{
    for (int i = 0; i < 25; i++)
    {
        if (matrix[i] == chr)
        {
            return i;
        }
    }
    return -1;
}

void checkRowCols(char first, char second, char *matrix)
{
    int p1 = findInArray(first, matrix);
    int p2 = findInArray(second, matrix);
    // std::cout << p1 << " " << p2 << std::endl;

    if (p1 % 5 == p2 % 5)
    {
        (p1 >= 20) ? std::cout << matrix[p1 % 5] : std::cout << matrix[p1 + 5];
        (p2 >= 20) ? std::cout << matrix[p2 % 5] : std::cout << matrix[p2 + 5];
        return;
    }
    if (p1 / 5 == p2 / 5)
    {
        (p1 % 5 == 4) ? std::cout << matrix[p1 - 4] : std::cout << matrix[p1 + 1];
        (p2 % 5 == 4) ? std::cout << matrix[p2 - 4] : std::cout << matrix[p2 + 1];
        return;
    }
    int diff = abs(p1 % 5 - p2 % 5);
    if (p1 > p2)
    {
        std::cout << matrix[p1 - diff] << matrix[p2 + diff];
    }
    std::cout << matrix[p1 + diff] << matrix[p2 - diff];
}

void playFair(char first, char second, char *matrix)
{
    if (first == second)
    {
        checkRowCols(first, 'x', matrix);
        checkRowCols(second, 'x', matrix);
        return;
    }
    checkRowCols(first, second, matrix);
}

int main()
{
    std::string key, msg;
    std::cout << "Enter the msg and the key: ";
    std::cin >> msg >> key;

    char *matrix = new char[25];
    std::replace(msg.begin(), msg.end(), 'j', 'i');
    std::replace(key.begin(), key.end(), 'j', 'i');

    for (int i = 0; i < key.length(); i++)
    {
        matrix[i] = key.at(i);
    }

    for (int i = 97, idx = msg.length() + 1; i < 97 + 26; i++)
    {
        if ((char)(i) == 'i')
        {
            continue;
        }
        if (key.find((char)(i)) >= key.length())
        {
            matrix[idx++] = (char)(i) == 'j' ? 'i' : (char)(i);
        }
    }
    std::cout << " _______ ";
    for (int i = 0; i < 25; i++)
    {
        std::cout << matrix[i];
    }
    std::cout << " _______ ";

    for (int i = 0; i < msg.length(); i += 2)
    {
        char first = msg.at(i);
        char second = 'x';
        try
        {
            second = msg.at(i + 1);
            playFair(first, second, matrix);
        }
        catch (...)
        {
            playFair(first, second, matrix);
        }
    }
}
