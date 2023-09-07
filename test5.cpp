#include <iostream>
#include <vector>
#include <tuple>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m; // n - city, m - count(roands)
    std::cin >> n >> m;

    std::tuple<long, long, long> t; // city-city-len(road)
    std::vector<std::tuple<long, long, long>> v;
    v.reserve(m);
    for (size_t i = 0; i < m; ++i) {
        long a, b, c;
        std::cin >> a >> b >> c;
        t = std::make_tuple(a, b, c);
        v.push_back(t);
    }


    return 0;
}