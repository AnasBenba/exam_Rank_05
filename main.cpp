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

    bigint s1("0"), s2("0");
    bigint r1 = s1 + s2;
    std::cout << "Test 10 (0 + 0)            : " << r1 << " | expected: 0\n";

    bigint r2 = bigint("0") + bigint("123");
    std::cout << "Test 11 (0 + 123)          : " << r2 << " | expected: 123\n";

    bigint r3 = bigint("123") + bigint("0");
    std::cout << "Test 12 (123 + 0)          : " << r3 << " | expected: 123\n";

    bigint r4 = bigint("999") + bigint("1");
    std::cout << "Test 13 (999 + 1)          : " << r4 << " | expected: 1000\n";

    bigint r5 = bigint("123456789") + bigint("987654321");
    std::cout << "Test 14 (123456789 + 987654321) : " << r5 << " | expected: 1111111110\n";

    // Commutativity and associativity (printed side-by-side)
    bigint r6_left  = (bigint("1") + bigint("2")) + bigint("3");
    bigint r6_right = bigint("1") + (bigint("2") + bigint("3"));
    std::cout << "Test 15 ((1+2)+3) vs (1+(2+3)) : " << r6_left << " / " << r6_right << " | expected: 6 / 6\n";

    std::cout << "\n===== IN-PLACE ADDITION (+=) =====\n";
    bigint p1("500"); p1 += bigint("500");
    std::cout << "Test 16 (500 += 500)       : " << p1 << " | expected: 1000\n";

    bigint p2("1999"); p2 += bigint("1");
    std::cout << "Test 17 (1999 += 1)        : " << p2 << " | expected: 2000\n";

    // Chained += (right-to-left evaluation)
    bigint p3("10"), p4("20"), p5("30");
    p3 += p4 += p5; // p4 = 20+30=50; p3 = 10+50=60
    std::cout << "Test 18 chain (p3 += (p4 += p5)) : p3=" << p3 << " p4=" << p4 << " p5=" << p5
              << " | expected: p3=60 p4=50 p5=30\n";

    return 0;
}