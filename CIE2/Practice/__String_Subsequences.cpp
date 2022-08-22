#include <iostream>

using namespace std;

int subsequeneces(string str, string output[])
{
    if (str.length() == 0)
    {
        output[0] = "";
        return 1;
    }

    int small_output = subsequeneces(str.substr(1), output);
    for (int i = 0; i < small_output; i++)
    {
        output[i + small_output] = str[0] + output[i];
    }

    return 2 * small_output;
}

int main()
{
    string output[20];

    int output_size = subsequeneces("abcd", output);
    for (int i = 0; i < output_size; i++)
    {
        cout << output[i] << endl;
    }
}