#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    uint32_t number = 0x12340056;
    uint32_t check[4] = {0x00ffffff, 0xff00ffff, 0xffff00ff, 0xffffff00};

    uint32_t ans = 0;
    for (int i = 0; i < 4; i ++ )
        if ((number & check[i]) == number)
        {
            for (int j = 0; j < 4; j ++ )
            {
                if (j == i) continue;
                int t = (3 - j) * 8;
                ans ^= (number >> t) & 0xff;
            }
            int q = (3 - i) * 8;
            number += ans << q;
            break;
        }
    //return number;
    //printf("%ld\n", number);
 
    printf("0x%08x", number);
    return 0;
}