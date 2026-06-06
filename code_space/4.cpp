#include <bits/stdc++.h>

using namespace std;

const int N = 20;

int n = 16;
char st[N][N];

unordered_map<char, int> mp;

string direction = "URDL";
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

struct player
{
    char id;
    pair<int, int> pos;
    int dir;
    string s;
    int score;
}play[2];

int main()
{
    string a, b;
    cin >> a >> b;

    mp['U'] = 0, mp['R'] = 1, mp['D'] = 2, mp['L'] = 3;
    play[0] = {'D', {0, 0}, 1, a, 1};
    play[1] = {'W', {15, 15}, 3, b, 1};

    for (int i = 0; i < 256; i ++ )
    {
        if (a[i] == 'F')
        {
            if (b[i] != 'F' && b[i].pos)
        }
    }
    
}