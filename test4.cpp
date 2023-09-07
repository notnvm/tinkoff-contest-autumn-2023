#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    long n, m, res;
    std::cin >> n >> m;
    std::vector<long> p;
    std::vector<long> r;

    p.reserve(m);
    for (size_t i = 0; i < m; ++i) {
        int b;
        std::cin >> b;
        p.push_back(b);
    }

    std::vector<long> p2;
    p2.reserve(m);
    std::copy(p.begin(), p.end(), std::back_inserter(p2));
    std::copy(p.begin(), p.end(), std::back_inserter(p2));
    std::sort(p2.rbegin(), p2.rend());

    if (std::accumulate(p.begin(), p.end(), 0) == n) {
        r = p;
    }
    else {
        res = 0;
        for (auto elem : p2) {
            if (res + elem <= n) {
                res += elem;
                r.push_back(elem);
            }
        }
        if (res != n)
            r.clear();
    }
    
    if (r.size() != 0) {
        std::cout << r.size() << "\n";
        for (auto elem : r)
            std::cout << elem << " ";
    }
    else std::cout << -1;

    return 0;
}