#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, s, res;
    std::vector<int> a;
    std::cin >> n >> s;
    a.reserve(n);
    for (size_t i = 0; i < n; ++i) {
        int b;
        std::cin >> b;
        a.push_back(b);
    }

    std::sort(a.rbegin(), a.rend());

    for (size_t i = 0; i < a.size(); ++i)
        if (a[i] <= s) {
            res = a[i];
            break;
        }

    if(res != 0)
        std::cout << res;
    else std::cout << 0;

    return 0;
}