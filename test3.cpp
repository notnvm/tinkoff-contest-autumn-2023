#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> joe;
    std::vector<int> win;
    joe.reserve(n);
    win.reserve(n);

    for (size_t i = 0; i < n; ++i) {
        int b;
        std::cin >> b;
        joe.push_back(b);
    }
    
    for (size_t i = 0; i < n; ++i) {
        int b;
        std::cin >> b;
        win.push_back(b);
    }

    if (joe == win)
        std::cout << "YES";

    if (n != 1) {

        size_t first, last;

        // find first differt element between joe and win
        for (size_t i = 0; i < n; ++i)
            if (joe[i] != win[i]) {
                first = i;
                break;
            }
        // find last different element between joe and win
        for (size_t i = n - 1; i >= 0; --i)
            if (joe[i] != win[i]) {
                last = i;
                break;
            }

        std::sort(joe.begin() + first, joe.begin() + last + 1);
        if (joe == win)
            std::cout << "YES";
        else std::cout << "NO";
    }

    return 0;
}