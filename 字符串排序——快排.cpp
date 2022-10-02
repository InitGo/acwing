    string sort_str(string str) {
        int l = 0, r = str.size() - 1;
        if (l >= r) return "";
        char mid = str[0];
        int i = l - 1, j = r + 1;
        while (i < j) {
            do i ++ ; while (str[i] < mid);
            do j -- ; while (str[j] > mid);
            if (i < j) swap(str[i], str[j]);
        }

        return sort_str(str.substr(l, j + 1)) + sort_str(str.substr(j + 1));
    }