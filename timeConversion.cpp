#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s)
{
    int firstDigit = (int)s[0] - '0';
    int secondDigit = (int)s[1] - '0';
    int hours = (firstDigit * 10 + secondDigit % 10);

    string hourString;

    if (s[8] == 'A')
    {
        if (hours == 12)
        {
            hourString = "00";
        }
        else
        {
            if (hours < 10)
            {
                hourString = "0" + to_string(hours);
            }
            else
            {
                hourString = to_string(hours);
            }
        }
    }
    else
    {
        if (hours == 12)
        {
            hourString = "12";
        }
        else
        {
            hours += 12;
            hourString = to_string(hours);
        }
    }

    string endString;

    for (int i = 2; i <= 7; i++)
    {
        endString += s[i];
    }

    return hourString + endString;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
