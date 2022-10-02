#include<iostream>
#include<vector>
using namespace std;

vector<vector<string>> ans;//定义二维的string
const int N =4;
char g[N][N]; //二维数组n*n
int main()
{
    for(int i = 0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            g[i][j] = '.';
        }
    }

    // for(int i=0;i<N;i++)
    // {
    //     vector<string> a;//定义一个子类型，存每一行的结果
    //     for(int s = 0;s< N;s++) a.push_back(  string(1,g[i][s]));
        
    //     ans.push_back(a);
    // }

    for(int i=0;i<N;i++)
    {
        string l;

        for(int s = 0;s< N;s++) l+=g[i][s];
        vector<string> vi(l.begin(),l.end());
        ans.push_back(vi);
    }

    cout << endl << endl;
    for(int i = 0;i<ans.size();i++)
    {

        for(int l = 0;l<ans[0].size();l++)
        {
            cout <<  ans[i][l] << '+' << g[i][l] << ' ';
        }
        cout << endl;
        
    }


    

    return 0;
}