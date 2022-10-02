#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
     int turnon;
    int s; 
    int n = 10;
    int path[13]; //1 means turn on;

    vector<string>res;

    int p[10];
    string state2time()
    {
        string str,h,m;
        int hh=0,mm=0,p;

        p=1;
        for(int i = 3;i>=0;i--)
        {
            hh = hh + path[i]*p;
            p*=2;
        }

        p=1;
        for(int i = 9;i>=4;i--)
        {
            mm = mm + path[i]*p;
            p*=2;
        }

        if(hh<=11 && mm<=59) 
        {
            do
            {
                h+=hh%10+'0';
                hh/=10;
            }while(hh>0);
            reverse(h.begin(),h.end());

            if(mm<10) m+="0",m+= mm+'0';
            else
            {
                do
                {
                    m+=mm%10+'0';
                    mm/=10;
                }while(mm>0);
                reverse(m.begin(),m.end());
            }
           

            str = h + ":" + m;
            cout << str<<endl;
            return str;
            
        }
        else 
        {
            return "";
        }

    }



    void dfs(int u , int s)//u表示当前是第几个点，s表示已经放了几个点
    {
        if(u==n)
        {
            if(s ==turnon)
            {
                //输出点的排列组合
                for(int i = 0;i<n;i++) cout << path[i];
                cout << endl;

                string str = state2time();
                if(str.size()!=0)  res.push_back(str);

            }
            return;
        }

        dfs(u+1,s);

        path[u] = 1;
        dfs(u+1,s+1);
        path[u] = 0;
    }

    vector<string> readBinaryWatch(int turnedOn) {
        turnon = turnedOn;
        dfs(0,0);//
        return res;
    }
};