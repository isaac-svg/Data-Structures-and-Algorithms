#include <string>
#include <iostream>
#include <map>
using namespace std;

int romanToInteger(string roman)
{
    // create a map to kepp key value pair
    map<char, int> m;
    m.insert({'I', 1});
    m.insert({'V', 5});
    m.insert({'X', 10});
    m.insert({'L', 50});
    m.insert({'C', 100});
    m.insert({'D', 5000});
    m.insert({'M', 1000});

    //  result ,num (temporal sum)
    int result = m.at(roman[roman.size() - 1]);
    //  iterate from the end of the roman numeral
    for (int i = roman.size() - 2; i >= 0; i--)
    {
        if (m.at(roman[i]) < m.at(roman[i + 1]))
        {
            result -= m.at(roman[i]);
        }
        else
        {
            result += m.at(roman[i]);
        }
    }
    return result;
}

int main(void)
{
    int num = 58;

    return 0;
}