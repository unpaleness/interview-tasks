#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
    const auto is_verbose = argc > 1;
    std::vector<int> a;
    int tmp;
    while (std::cin >> tmp) { a.push_back(tmp); }
    for (int i = 0; i < a.size(); ++i) {
        if (is_verbose) { std::cout << "a[" << i << "] = " << a[i] << '\n'; }
        while (a[i] != i) {
            tmp = a[i];
            if (is_verbose) { std::cout << "a[" << i << "] (" << tmp << ") != " << i << '\n'; }
            if (tmp < 0 || tmp >= a.size()) {
                std::cerr << "Value " << tmp << " is out of range\n";
                return 1;
            }
            if (is_verbose) { std::cout << "a[" << i << "] (" << tmp << ") <-> a[" << tmp << "] (" << a[tmp] << ")\n"; }
            a[i] -= a[tmp];
            a[tmp] += a[i];
            a[i] = a[tmp] - a[i];
            if (a[i] == tmp) {
                std::cout << tmp << '\n';
                return 0;
            }
        }
    }
    std::cout << "-1\n";
    return 0;
}
