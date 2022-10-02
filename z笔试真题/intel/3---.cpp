#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    char str[] = {'a', 'b', 'c'};
    int len = strlen(str);
    int f[2];
    f[0] = f[1] = 0;
    char last = ' ';
    int cnt = 0;
    for (int i = 1; i <= len; i ++ )
    {
        char c = str[i - 1];
        if (c == last){
            f[i & 1] = f[(i - 1) & 1] + cnt;
            cnt ++ ;
        } else{
            f[i & 1] = f[(i - 1) & 1];
            last = c;
            cnt = 1;
        }
    }
    return f[len & 1];



    cout << f[len & 1] << endl;
    return 0;
}