#include "bigint.hpp"

int main(){
    std::cout << "===== CONSTRUCTION & PRINTING =====\n";
    bigint t1("000123");
    std::cout << "Test 1  (normalize \"000123\"): " << t1 << " | expected: 123\n";

    bigint t2("0");
    std::cout << "Test 2  (zero): " << t2 << " | expected: 0\n";

    bigint t3(4294967295u); // from unsigned int ctor (value depends on platform size; here just format check)
    std::cout << "Test 3  (from unsigned int): " << t3 << " | expected: 4294967295\n";

    std::cout << "\n===== COMPARISONS =====\n";
    bigint a("1234"), b("1234"), c("999"), d("10000"), e("1235");
    std::cout << "Test 4  (==)  1234 == 1234 : " << ((a == b) ? "true" : "false") << " | expected: true\n";
    std::cout << "Test 5  (!=)  1234 != 999  : " << ((a != c) ? "true" : "false") << " | expected: true\n";
    std::cout << "Test 6  (<)   999  < 10000 : " << ((c < d)  ? "true" : "false") << " | expected: true\n";
    std::cout << "Test 7  (<=)  1234 <= 1234 : " << ((a <= b) ? "true" : "false") << " | expected: true\n";
    std::cout << "Test 8  (>)   1235 > 1234  : " << ((e > a)  ? "true" : "false") << " | expected: true\n";
    std::cout << "Test 9  (>=)  1235 >= 1235 : " << ((e >= e) ? "true" : "false") << " | expected: true\n";

    return 0;
}