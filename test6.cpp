#include <iostream>
#include <vector>

class t {
public:
    t(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
    }

    int find(int v) {
        if (v == parent[v]) return v;
        return parent[v] = find(parent[v]);
    }

    bool merge(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (size[a] < size[b]) std::swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        return true;
    }

    int sz(int v) {
        return size[find(v)];
    }

private:
    std::vector<int> parent;
    std::vector<int> size;
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, m;
    std::cin >> n >> m;
    t dsu(n);

    for (int i = 0; i < m; ++i) {
        int query, x, y;
        std::cin >> query >> x;
        if (query == 1) {
            std::cin >> y;
            dsu.merge(x, y);
        }
        else if (query == 2) {
            std::cin >> y;
            if (dsu.find(x) == dsu.find(y)) {
                std::cout << "YES\n";
            }
            else {
                std::cout << "NO\n";
            }
        }
        else if (query == 3) {
            std::cout << dsu.sz(x) << "\n";
        }
    }

    return 0;
}