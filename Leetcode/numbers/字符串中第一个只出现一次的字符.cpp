class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char, int> count;
        for (auto c : s) count[c] ++ ;;

        char res = ' ';
        for (auto c : s)
            if (count[c] == 1)
            {
                res = c;
                break;
            }
        return res;
    }
};