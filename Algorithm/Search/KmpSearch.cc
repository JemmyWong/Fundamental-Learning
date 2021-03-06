#include <iostream>
#include <string>
#include <vector>

std::vector<int> generateNext(const std::string& pattern) {
    const auto len = pattern.size();
    std::vector<int> next(len, 0);

    next[0] = -1;
    int k = -1;
    for (int i = 1; i < len; ++i) {
        while (k != -1 && pattern[k+1] != pattern[i])
            k = next[k];

        if (pattern[k+1] == pattern[i])
            ++k;

        next[i] = k;
    }

    return next;
}

int kmpSearch(const std::string& str, const std::string& pattern) {
    /* consist with c strstr */
    if (pattern.empty())
        return 0;

    const auto next = generateNext(pattern);
    for (int i = 0, j = 0; i < str.size(); ++i) {
        while (j > 0 && str[i] != pattern[j])
            j = next[j-1] + 1;

        if (str[i] == pattern[j])
            ++j;

        if (j == pattern.size())
            return i-j+1;
    }

    return -1;
}

int main() {
    const std::string str = "ababaeadac";
    const std::string pattern = "dac";

    int idx = kmpSearch(str, pattern);
    std::cout << idx << std::endl;

    return 0;
}