class Solution {
public:
    unordered_map<string, vector<string>> ne;
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        for (auto a : wordList)
            for (auto b : wordList)
                if (check(a, b)) ne[a].push_back(b);

        for (auto b : wordList)
            if (check(beginWord, b)) ne[beginWord].push_back(b);

        bool is_exist = false;
        for (auto s : wordList) 
            if (s == endWord)
                is_exist = true;

        if (!is_exist) return 0;

        int t = bfs(beginWord, endWord);
        return t;
    }

    bool check(string& a, string& b)
    {
        int cnt = 0;
        for (int i = 0; i < a.size(); i ++ )
        {
            if (a[i] != b[i]) cnt ++ ;
            if (cnt >= 2) return false;
        }
        return cnt == 1;
    }

    int extend(queue<string>& q, unordered_map<string, int>& da, unordered_map<string, int>& db)
    {
        int d = da[q.front()];
        while (q.size() && da[q.front()] == d)
        {
            auto t = q.front();
            q.pop();

            for (auto c : ne[t])
            {
                if (db.count(c)) return da[t] + db[c] + 2;
                if (da.count(c)) continue;
                da[c] = da[t] + 1;
                q.push(c);
            }
        }
        return -1;
    }

    int bfs(string a, string b)
    {
        queue<string> qa, qb;
        unordered_map<string, int> da, db;

        qa.push(a), qb.push(b);
        da[a] = 0, db[b] = 0;

        while (qa.size() && qb.size())
        {
            int t;
            if (qa.size() <= qb.size()) t = extend(qa, da, db);
            else t = extend(qb, db, da);
            if (t != -1) return t;
        }

        return 0;
    }
};