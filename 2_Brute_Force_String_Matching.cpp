#include <iostream>

using namespace std;

int string_match(string str, string pattern)
{
    for (int i = 0; i <= (str.length() - pattern.length()); i++)
    {
        int j = 0;
        while (j < pattern.length() && pattern[j] == str[i + j])
        {
            j++;
        }
        if (j == pattern.length())
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    string str1, str2;
    cout << "Enter String : ";
    getline(cin, str1);
    cout << "Enter pattern to be found: ";
    getline(cin, str2);

    int string_match_result = string_match(str1, str2);
    if (string_match_result == -1)
    {
        cout << "Pattern not found" << endl;
    }
    else
    {
        cout << "Pattern found at index: " << string_match_result << endl;
    }
    return 0;
}