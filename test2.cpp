#include <iostream>
#include <map>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string s;
    std::cin >> s;
    
    std::map<char, int> m;
    for (size_t i = 0; i < s.size(); ++i)
        m[s[i]]++;

    long min = 2 * 10e5 + 1;
    for (auto it = m.begin(); it != m.end(); ++it)
        if (it->first == 's' || it->first == 'h' || it->first == 'e' || it->first == 'r' || it->first == 'i' || it->first == 'f') {
            if (it->second < min) {
                min = it->second;
            }
        }
    if(m.find('f') != m.end() && m['f'] >= 2)
        std::cout << min;
    else std::cout << 0;

    return 0;
}