#include <iostream>

using namespace std;

#define size 256
int table[size];

void s_t(string pat)
{
    for (int i = 0; i < size; i++)
    {
        table[i] = pat.length();
    }

    for (int i = 0; i <= pat.length() - 2; i++)
    {
        table[pat[i]] = pat.length() - 1 - i;
    }
}

int horspool(string str, string pat)
{
    int n = str.length();
    int m = pat.length();
    
    s_t(pat);

    // Will enable checking from behind
    int i = m - 1;

    while (i <= n - 1)
    {
        int k = 0;
        while ((k < m ) && (str[i - k] == pat[m - 1 - k]))
        {
            k++;
        }
        if (k == m)
        {
            return i - m + 1;
        }
        else
        {
            i = i + table[str[i]];
        }
    }
    return -1;
}

int main()
{
    string str, pattern;
    cout << "Enter the string: ";
    getline(cin, str);
    cout << "Enter the pattern: ";
    getline(cin, pattern);

    int checker = horspool(str, pattern);

    if (checker == -1)
    {
        cout << "Pattern not found" << endl;
    }
    else
    {
        cout << "Pattern found at index: " << checker << endl;
    }
    return 0;
}