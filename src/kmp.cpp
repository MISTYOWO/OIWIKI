#include "kmp.h"
#include <vector>

std::vector<int> getNext(const std::string& t) {
    std::vector<int> next(t.size(), -1);

    for (int i = 0;i < t.size();i++) {
        if (i == 0) {
            continue;
        }
        int id = i-1;
        while (id >= 0) {
            if (t[next[id] + 1] == t[i]) {
                next[i] = next[id]+1;
                break;
            }
            id = next[id];
        }
    }

    return next;
}
int find(const std::string& s, const std::string& t) {
    std::vector<int> next = getNext(t);
    int ret = -1;
    int j = 0;
    for (int i = 0; i < s.size();i++) {
        if (s[i] == t[j]) {
            j++;
        } else {
            int id = j - 1;
            while (id >= 0) {
                if (s[i] == t[next[id] + 1]) {
                    j = next[id]+1;
                    break;
                }
                j = next[id]+1;
                id = next[id];
                break;
            }
        }
        if (j == t.size()) {
            ret = i - t.size() + 1;
        }
    }
    return ret;
}
