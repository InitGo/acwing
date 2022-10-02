#include <bits/stdc++.h>

using namespace std;

string word[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
string num[] = {"-", "-", "double", "triple", "quadruple", "quintuple", "sextuple", "septuple", "octuple", "nonuple", "decuple"};

int get(char c)
{
    return c - '0';
}

void read_it(string str)
{
    int index = 0;
    for (int i = 0; i < str.size(); i++)
    {
        int cnt = 1;
        int t = get(str[i]);
        int j = i + 1;
        while (j < str.size() && t == get(str[j]))
        {
            j++;
            cnt++;
        }
        if (cnt > 1 && cnt <= 10)
            cout << num[cnt] << ' ';
        cout << word[t] << ' ';
        if (cnt > 10)
            for (int k = 0; k < cnt - 1; k++)
                cout << word[t] << ' ';

        i = j - 1;
    }
}

int main()
{
    int T;
    cin >> T;
    for (int C = 1; C <= T; C++)
    {
        string str, op;
        cin >> str >> op;

        stringstream ssin(op);
        int len, start = 0;
        pair<int, int> seq[110];
        int index = 0;
        while (ssin >> len)
        {
            // cout << abs(len) << endl;
            len = abs(len);
            seq[index++] = {start, len};
            start += len;
        }

        printf("Case #%d: ", C);
        for (int q = 0; q < index; q++)
        {
            auto t = seq[q];
            read_it(str.substr(t.first, t.second));
        }
        cout << endl;
    }
    return 0;
}