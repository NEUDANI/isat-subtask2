#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function 1: Decimal to Binary
string decimalToBinary(int decimal)
{
    string binary = "";

    if (decimal == 0)
        return "0";

    while (decimal > 0)
    {
        binary = char((decimal % 2) + '0') + binary;
        decimal = decimal / 2;
    }

    return binary;
}

// Function 2: Binary to Decimal
int binaryToDecimal(string binary)
{
    int decimal = 0;

    for (int i = 0; i < binary.length(); i++)
    {
        decimal = decimal * 2 + (binary[i] - '0');
    }

    return decimal;
}

// Function 3: Hexadecimal to Decimal
int hexadecimalToDecimal(string hexadecimal)
{
    int decimal = 0;

    for (int i = 0; i < hexadecimal.length(); i++)
    {
        char digit = hexadecimal[i];
        int value;

        if (digit >= '0' && digit <= '9')
        {
            value = digit - '0';
        }
        else if (digit >= 'A' && digit <= 'F')
        {
            value = digit - 'A' + 10;
        }
        else if (digit >= 'a' && digit <= 'f')
        {
            value = digit - 'a' + 10;
        }

        decimal = decimal * 16 + value;
    }

    return decimal;
}

// Function 4: Decimal to Hexadecimal
string decimalToHexadecimal(int decimal)
{
    string hexadecimal = "";
    string digits = "0123456789ABCDEF";

    if (decimal == 0)
        return "0";

    while (decimal > 0)
    {
        hexadecimal = digits[decimal % 16] + hexadecimal;
        decimal = decimal / 16;
    }

    return hexadecimal;
}

int main()
{
    int choice;

    srand(time(0));

    // Display menu ONLY ONCE
    cout << "Conversion Menu:" << endl;
    cout << "1. Convert Decimal to Binary" << endl;
    cout << "2. Convert Binary to Decimal" << endl;
    cout << "3. Convert Hexadecimal to Decimal" << endl;
    cout << "4. Convert Decimal to Hexadecimal" << endl;
    cout << "5. Demo (Generate and convert random integers to binary)" << endl;
    cout << "6. Exit" << endl;

    do
    {
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                int decimal;

                cout << "Enter a decimal number: ";
                cin >> decimal;

                cout << "Binary representation: "
                     << decimalToBinary(decimal) << endl;

                break;
            }

            case 2:
            {
                string binary;

                cout << "Enter a binary number: ";
                cin >> binary;

                cout << "Decimal representation: "
                     << binaryToDecimal(binary) << endl;

                break;
            }

            case 3:
            {
                string hexadecimal;

                cout << "Enter a hexadecimal number: ";
                cin >> hexadecimal;

                cout << "Decimal representation: "
                     << hexadecimalToDecimal(hexadecimal) << endl;

                break;
            }

            case 4:
            {
                int decimal;

                cout << "Enter a decimal number: ";
                cin >> decimal;

                cout << "Hexadecimal representation: "
                     << decimalToHexadecimal(decimal) << endl;

                break;
            }

            case 5:
            {
                int randomNumber = rand() % 100;

                cout << "Generated random integer: "
                     << randomNumber << endl;

                cout << "Binary representation: "
                     << decimalToBinary(randomNumber) << endl;

                break;
            }

            case 6:
            {
                cout << "Exiting the program." << endl;
                break;
            }

            default:
            {
                cout << "Invalid choice." << endl;
            }
        }

    } while (choice != 6);

    return 0;
}
