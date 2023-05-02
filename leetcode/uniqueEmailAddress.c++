/**
 * @file uniqueEmailAddress.c++
 * @author isaac sakyi (isaacsakyi009@gmail.com)
 * @brief 929. Unique Email Addresses

 * @version 0.1
 * @date 2023-05-01
 *
 * @copyright Copyright (c) 2023
 *
 */

/**
 * @brief Approch one
 * Use a doble nested for loop
 * the first loop picks the email address and the second loop picks the single characters of the email address
 * create a string variable to hold the cleaned Email
 * if you encounter a . skip it , if you encounter a + or @ break from the inner loop
 * concatinate the character to the  string
 * find the substring of from the first occurrence of @ and concatinate it to the string
 * push it to an unordered data set
 * return the length
 * f(n) = Og(2(n*m))
 * O(n) = n*m
 */
#include <unordered_set>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int numOfUniqueEmails1(vector<string> &emails)
{
    unordered_set<string> container;

    for (auto &&email : emails)
    {
        string s = "";
        for (auto &&c : email)
        {

            if (c == '+' || c == '@')
                break;
            if (c == '.')
                continue;
            s += c;
        }

        s += email.substr(find(email.begin(), email.end(), '@') - email.begin());
        container.insert(s);
    }
    return container.size();
}
int numberOfUniqueEmail2(vector<string> &emails)
{
    unordered_set<string> uniqEmails;
    for (string &email : emails)
    {
        bool atDomain = false;
        string actEmail;
        int i = 0;
        for (int i = 0; i < email.size();)
        {
            char c = email[i];
            if (atDomain) // if domain is encountered there is no need to do extra checks
            {
                actEmail.push_back(c);
                i++;
            }
            else
            {
                if (c == '@')
                {
                    actEmail.push_back(c);
                    atDomain = true;
                    i++;
                }
                else if (c == '.')
                {
                    // skip
                    i++;
                }
                else if (c == '+')
                {
                    // skip all after till @
                    while (email[i] != '@')
                    {
                        i++;
                    }
                }
                else
                {
                    actEmail.push_back(c);
                    i++;
                }
            }
        }

        uniqEmails.insert(actEmail);
    }

    return uniqEmails.size();
}
