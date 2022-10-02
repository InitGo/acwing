class Solution 
{
public:
    const int base = 131;
    typedef unsigned long long ULL;
    ULL hl[2010], hr[2010], p[2010];

    ULL get(ULL h[], int l, int r)
    {
        return h[r] - h[l - 1] * p[r - l + 1];
    }

    bool check(int mid, int i, int n)  //字符串总长度为n,以第i个字符为中心，半径是mid(不包括i)的字串 是否是回文串
    {
        return get(hl, i - mid, i - 1) == get(hr, n - (i + mid) + 1, n - (i + 1) + 1);
    }

    string longestPalindrome(string s) 
    {
        string str; // 添加'#'使得最长回文子串长度必定是奇数
        for (int i = 0; i < s.size(); i ++ )
        {
            str += '#';
            str += s[i];
        }
        str += '#';

        string rstr = str; //str的逆序串
        reverse(rstr.begin(), rstr.end());

        //初始化字符串哈希数组
        int n = str.size();
        p[0] = 1;
        for (int i = 1; i <= n; i ++ )
        {
            hl[i] = hl[i - 1] * base + str[i - 1];
            p[i] = p[i - 1] * base;
        }

        for (int i = 1; i <= n; i ++ )
            hr[i] = hr[i - 1] * base + rstr[i - 1];

        string raw;  //存扩张'#'后的最长回文子串
        for (int i = 1; i <= n; i ++ )
        {
            int l = 0, r = min(i - 1, n - i);
            while (l < r)
            {
                int mid = l + r + 1 >> 1;
                if (check(mid, i, n)) l = mid;
                else r = mid - 1;
            }

            string ths = str.substr(i - l - 1, l + l + 1);  //ths是以i为中心的最长回文子串
            if (ths.size() > raw.size()) raw = ths;
        }

        string ans;  //ans存从raw中去掉'#'后的最长回文子串
        for (int i = 0; i < raw.size(); i ++ )
            if (raw[i] != '#')
                ans += raw[i]; 
        return ans;
    }
};