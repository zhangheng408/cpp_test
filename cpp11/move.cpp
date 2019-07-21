#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <functional>

const std::vector<int> f1(const std::string s) {
    std::vector<int> v(26, 0);
    for (auto c:s) {
        if (c >= 'a' && c<= 'z') {
            v[c - 'a']++;
        } else if (c >= 'A' && c<= 'Z') {
            v[c - 'A']++;
        }
    }
    return v;
}

const std::vector<int> f2(const std::string& s) {
    std::vector<int> v(26, 0);
    for (auto c:s) {
        if (c >= 'a' && c<= 'z') {
            v[c - 'a']++;
        } else if (c >= 'A' && c<= 'Z') {
            v[c - 'A']++;
        }
    }
    return v;
}

// the return type can be non reference
const std::vector<int>&& f3(const std::string& s) {
    std::vector<int> v(26, 0);
    for (auto c:s) {
        if (c >= 'a' && c<= 'z') {
            v[c - 'a']++;
        } else if (c >= 'A' && c<= 'Z') {
            v[c - 'A']++;
        }
    }
    return std::move(v);
}

using FuncType1 = std::function<const std::vector<int>(const std::string)>;
using FuncType2 = std::function<const std::vector<int>(const std::string&)>;

void bench(FuncType2 func, const std::string& comments) {
    static const int benchNum = 1000;
    static std::string s = "1s3 PSt";
    time_t start = clock();
    for (int i = 0; i < benchNum; ++i) {
        auto ret = func(s);
    }
    time_t end = clock();
    std::cout << comments << " " << (end - start) << std::endl;
}

int main() {
    bench(f1, std::string("normal"));
    bench(f2, std::string("param ref"));
    bench(f3, std::string("param ref & ret right ref(move)"));
    return 0;
}
