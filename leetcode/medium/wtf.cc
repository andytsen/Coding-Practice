// no stl btw

int equalSubstring(string s, string t, int maxCost) {
    auto i = 0, j = 0;
    while (i < s.size()) {
        maxCost -= abs(s[i] - t[i++]);
        if (maxCost < 0) maxCost += abs(s[j] - t[j++]);
    }
    return i - j;
}
