#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> date_index; //日期对应第i天
unordered_set<int> big_mon = {1, 3, 5, 7, 8, 10, 12};
unordered_map<int, vector<string>> index_people;  //第i天对应人
map<string, vector<string>> name_date;
int a[370], s[370];
int cnt;
int n, m;

bool check(int x)
{
    for (int i = 1; i + x <= 365; i ++ )
    {
        int l = i, r = i + x;
        int sum = s[r] - s[l - 1];
        if (sum >= m) return true;
        
    }
    return false;
}

int main()
{   
    for (int i = 1; i <= 12; i ++ )
    {
        string m;
        if (i < 10) m = "0" + to_string(i);
        else m = to_string(i);
        string target = "2021-" + m + '-';///////
        string t = target;/////
        for (int j = 1; j <= 31; j ++ )
        {
            target = t;/////
            if (i == 2 && j >= 29) continue;
            if (!big_mon.count(i) && j >= 31) continue;

            if (j < 10) target += "0" + to_string(j);
            else target += to_string(j);
            cnt ++ ;
            date_index[target] = cnt;
        }
    }
    for (auto t : date_index)
        cout << t.second << ' ' << t.first << endl;

    
    cin >> n;
    string name, dd;
    for (int i = 0; i < n; i ++ )
    {
        cin >> name >> dd;
        int index = date_index[dd];
        
        bool is_exsit = false;
        for (auto s : index_people[index])
            if (s == name)
                is_exsit = true;
        if (!is_exsit) index_people[index].push_back(name);
    }
    cin >> m;

    for (int i = 1; i <= 365; i ++ )
        s[i] = s[i - 1] + index_people[i].size();

    int l = 0, r = 365;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }

    if (l == 0) cout << -1 << endl;
    else cout << l << endl;
    
    return 0;
}