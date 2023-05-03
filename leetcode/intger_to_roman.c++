#include <string>
#include <iostream>

using namespace std;
/**
 * @brief numeral class to keep keys as strings(Roman numerals) and values as numbers (integers)
 * this can be achieved using a map or a vector pair
 *
 */
class Numeral
{

public:
    int value;
    string symbol;
    Numeral(int value, string symbol)
    {
        this->value = value;
        this->symbol = symbol;
    }
};
string integerToRoman1(int num)
{
    // using an array to keep the order of the objects
    Numeral numerals[] = {
        Numeral(1000, "M"),
        Numeral(900, "CM"),
        Numeral(500, "D"),
        Numeral(400, "CD"),
        Numeral(100, "C"),
        Numeral(90, "XC"),
        Numeral(50, "L"),
        Numeral(40, "XL"),
        Numeral(10, "X"),
        Numeral(9, "IX"),
        Numeral(5, "V"),
        Numeral(4, "IV"),
        Numeral(1, "I"),
    };
    string result = "";
    for (Numeral numeral : numerals)
    {
        int numberOfSymbols = num / numeral.value;
        if (numberOfSymbols != 0)
        {
            do
            {
                result += numeral.symbol;
                numberOfSymbols -= 1;
            } while (numberOfSymbols > 0);
        }

        num %= numeral.value;
    }
    return result;
}
int main(void)
{
    int num = 58;
    string result = integerToRoman1(num);
    cout << result;

    return 0;
}