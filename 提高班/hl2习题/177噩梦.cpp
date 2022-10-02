#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

const int N = 810;

int n, m;
char g[N][N];
int st[N][N];
PII ghost[2];


//检查当前点是否合法
//题目意思复杂，又是有墙，又是鬼占区，看起来可以走的格子条件很苛刻，判断逻辑混乱
//但是只要提取出框架，用check函数统一处理格子是否可达，逻辑就变得十分清晰了，与其它bfs没有本质区别，只不过是check函数多写一点
//从题目复杂的描述跳出来思考，抽象出check函数，这点非常关键，很值得细品
bool check(int x, int y, int step)
{
    if (x < 0 || x >= n || y < 0 || y >= m || g[x][y] == 'X') return false;  //出界/墙，不能走

    for (int i = 0; i < 2; i ++ )  //鬼占区，不能走
        if (abs(x - ghost[i].first) + abs(y - ghost[i].second) <= step * 2)  //不必explicit地对ghost所占地区进行扩展/标记，只需要判断当前点到ghost的曼哈顿距离是否合法
            return false;
    return true;
}

int bfs()
{
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    memset(st, 0, sizeof st);

    int cnt = 0;
    PII boy, girl;
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < m; j ++ )
            if (g[i][j] == 'M') boy = {i, j};
            else if (g[i][j] == 'G') girl = {i, j};
            else if (g[i][j] == 'Z') ghost[cnt ++ ] = {i, j};

    queue<PII> qb, qg;
    qb.push(boy);
    qg.push(girl);

    int step = 0;  //记录步数
    while (qb.size() && qg.size())  //这里可以用|| 和 &&， 用||如果不可达会多搜一些，但是答案是对的
    {
        step ++ ;  //全局的step表示步数

        for (int i = 0; i < 3; i ++ )  //boy可以走三个格子，扩展三层
            for (int j = 0, len = qb.size(); j < len; j ++ )  //扩展一层
            {
                auto t = qb.front();
                qb.pop();
                int x = t.first, y = t.second;
                if (!check(x, y, step)) continue;  //为什么这里要check一下？--> 扩展之前先检查一下，这个点不再合法:不能用来扩展了
                for (int k = 0; k < 4; k ++ )  //四个方向
                {
                    int a = x + dx[k], b = y + dy[k];
                    if (check(a, b, step))
                    {
                        //st = 0表示没人走， 1表示男孩走过， 2表示女孩走过  这里太妙了，用全局的st数组存两人可以到达的格子
                        //为什么可以用一个全局变量来表示？ --> 因为这里每一个step，两个方向都各自扩展一次，且求的是第一次相遇时的步数
                        //即max(da[][], db[][]), 所以不需要记录从每个方向出发，到可达点的距离，只需要记录最大值
                        if (st[a][b] == 2)  //如果这个格子girl走过，则找到了相遇点，返回step
                        {
                            return step;  //返回max(da[a][b], db[a][b])
                        }
                        if (!st[a][b])  //如果没人走过，标记一下，扩展该格子
                        {
                            st[a][b] = 1;
                            qb.push({a, b});
                        }
                    }
                }
            }

        for (int i = 0; i < 1; i ++ )
            for (int j = 0, len = qg.size(); j < len; j ++ )
            {
                auto t = qg.front();
                qg.pop();

                int x = t.first, y = t.second;
                if (!check(x, y, step)) continue;
                for (int k = 0; k < 4; k ++ )
                {
                    int a = x + dx[k], b = y + dy[k];
                    if (check(a, b, step))
                    {
                        if (st[a][b] == 1)
                        {
                            return step;
                        }
                        if (!st[a][b])
                        {
                            st[a][b] = 2;
                            qg.push({a, b});
                        }
                    }
                }
            }
    }

    return -1;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T -- )
    {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i ++ ) scanf("%s", g[i]);

        printf("%d\n", bfs());
    }

    return 0;
}

// 扩展是为了在空间上求出所有能到的格子，与时间无关
// 用step是为了记录当前扩展的时间，每一个时间点都进行扩展并判断有无相遇