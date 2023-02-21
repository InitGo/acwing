#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 9, M = 1 << N;

int ones[M];
//打表
// ones每个10进制数字的2进制有多少个1
int row[N], col[N], cell[3][3];
string str;

//初始化
// row, col, cell每一位都置1，表示每个数字都可以使用
void init()
{
    for (int i = 0; i < N; i++)
        row[i] = col[i] = M - 1;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cell[i][j] = M - 1;
}

//在数独棋盘的(x, y)位置上填入/删除t，   is_set = 1/ 0 ：填入/删除
//数独棋盘上空格的变化也会影响相关状态表示，所以不仅是数字变换的问题，还要衔接配上状态变换
//所以需要函数来处理
void draw(int x, int y, int t, bool is_set)
{
    if (is_set)
        str[x * N + y] = '1' + t;
    else
        str[x * N + y] = '.';

    int v = 1 << t; // 1左移t位
    if (!is_set)
        v = -v;

    row[x] -= v;
    col[y] -= v;
    cell[x / 3][y / 3] -= v;
}

//返回(x, y)位置上可以使用的状态数字， 用整数表示，其二进制中为1的位置表示位置数字可用
int get(int x, int y)
{
    return row[x] & col[y] & cell[x / 3][y / 3];
}

bool dfs(int cnt)
{
    if (!cnt)
        return true; //如果找到了一组方案，retrun true

    //优化搜索顺序
    int minv = 10;              //找到选择最少的空格，初始化10个选择
    int x, y;                   //点的结果存入
    for (int i = 0; i < N; i++) //循环以后，找到了可选择的数字最少的点
        for (int j = 0; j < N; j++)
            if (str[i * N + j] == '.') //注意，这里只对空格位置进行搜索
            {
                int state = get(i, j);
                if (ones[state] < minv)
                {
                    minv = ones[state];
                    x = i, y = j;
                }
            }

    //拿到这个具体的状态state
    int state = get(x, y);
    for (int i = 0; i < N; i++) //遍历state中可以使用的数字
    {
        if (!(state >> i & 1))
            continue; //第i位不为1，不可以用，continue
        draw(x, y, i, true);
        if (dfs(cnt - 1))
            return true; //如果找到一组方案， 直接返回
        draw(x, y, i, false);
    }

    return false;
}

int main()
{
    for (int i = 0; i < 1 << N; i++) //枚举二进制数
        for (int j = 0; j < N; j++)  //枚举位数
            ones[i] += i >> j & 1;

    while (cin >> str, str[0] != 'e')
    {
        init();

        int cnt = 0;                //需要填的空格数量
        for (int i = 0; i < N; i++) //坐标转换
            for (int j = 0; j < N; j++)
                if (str[i * N + j] != '.')
                {
                    int t = str[i * N + j] - '1';
                    draw(i, j, t, true);
                }
                else
                    cnt++;
        dfs(cnt);
        cout << str << endl;
    }

    return 0;
}

/*
对于有明显图形的问题，如果要在单元格内操作，
可以用draw、button之类的函数抽象出来操作逻辑，方便使用
尤其是当前操作会改变其他变量的状态时，抽象成函数更加方便使用
如果操作是多元的，传入op参数作为标识
*/