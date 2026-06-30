// #include "bigint.hpp"

// int main(){
//     std::cout << "===== CONSTRUCTION & PRINTING =====\n";
//     bigint t1("000123");
//     std::cout << "Test 1  (normalize \"000123\"): " << t1 << " | expected: 123\n";

//     bigint t2("0");
//     std::cout << "Test 2  (zero): " << t2 << " | expected: 0\n";

//     bigint t3(4294967295u); // from unsigned int ctor (value depends on platform size; here just format check)
//     std::cout << "Test 3  (from unsigned int): " << t3 << " | expected: 4294967295\n";

//     std::cout << "\n===== COMPARISONS =====\n";
//     bigint a("1234"), b("1234"), c("999"), d("10000"), e("1235");
//     std::cout << "Test 4  (==)  1234 == 1234 : " << ((a == b) ? "true" : "false") << " | expected: true\n";
//     std::cout << "Test 5  (!=)  1234 != 999  : " << ((a != c) ? "true" : "false") << " | expected: true\n";
//     std::cout << "Test 6  (<)   999  < 10000 : " << ((c < d)  ? "true" : "false") << " | expected: true\n";
//     std::cout << "Test 7  (<=)  1234 <= 1234 : " << ((a <= b) ? "true" : "false") << " | expected: true\n";
//     std::cout << "Test 8  (>)   1235 > 1234  : " << ((e > a)  ? "true" : "false") << " | expected: true\n";
//     std::cout << "Test 9  (>=)  1235 >= 1235 : " << ((e >= e) ? "true" : "false") << " | expected: true\n";

//     bigint s1("0"), s2("0");
//     bigint r1 = s1 + s2;
//     std::cout << "Test 10 (0 + 0)            : " << r1 << " | expected: 0\n";

//     bigint r2 = bigint("0") + bigint("123");
//     std::cout << "Test 11 (0 + 123)          : " << r2 << " | expected: 123\n";

//     bigint r3 = bigint("123") + bigint("0");
//     std::cout << "Test 12 (123 + 0)          : " << r3 << " | expected: 123\n";

//     bigint r4 = bigint("999") + bigint("1");
//     std::cout << "Test 13 (999 + 1)          : " << r4 << " | expected: 1000\n";

//     bigint r5 = bigint("123456789") + bigint("987654321");
//     std::cout << "Test 14 (123456789 + 987654321) : " << r5 << " | expected: 1111111110\n";

//     // Commutativity and associativity (printed side-by-side)
//     bigint r6_left  = (bigint("1") + bigint("2")) + bigint("3");
//     bigint r6_right = bigint("1") + (bigint("2") + bigint("3"));
//     std::cout << "Test 15 ((1+2)+3) vs (1+(2+3)) : " << r6_left << " / " << r6_right << " | expected: 6 / 6\n";

//     std::cout << "\n===== IN-PLACE ADDITION (+=) =====\n";
//     bigint p1("500"); p1 += bigint("500");
//     std::cout << "Test 16 (500 += 500)       : " << p1 << " | expected: 1000\n";

//     bigint p2("1999"); p2 += bigint("1");
//     std::cout << "Test 17 (1999 += 1)        : " << p2 << " | expected: 2000\n";

//     // Chained += (right-to-left evaluation)
//     bigint p3("10"), p4("20"), p5("30");
//     p3 += p4 += p5; // p4 = 20+30=50; p3 = 10+50=60
//     std::cout << "Test 18 chain (p3 += (p4 += p5)) : p3=" << p3 << " p4=" << p4 << " p5=" << p5
//               << " | expected: p3=60 p4=50 p5=30\n";
    
//     std::cout << "\n===== DIGIT SHIFTS (<<, >>) =====\n";
//     bigint sh1("42");
//     std::cout << "Test 19 (\"42\" << 3)       : " << (sh1 << 3) << " | expected: 42000\n";
//     std::cout << "Test 20 (\"42\" << 0)       : " << (sh1 << 0) << " | expected: 42\n";

//     bigint sh2("1337");
//     std::cout << "Test 21 (\"1337\" >> 2)     : " << (sh2 >> 2) << " | expected: 13\n";
//     std::cout << "Test 22 (\"1337\" >> 0)     : " << (sh2 >> 0) << " | expected: 1337\n";
//     std::cout << "Test 23 (\"1337\" >> 5)     : " << (sh2 >> 5) << " | expected: 0\n";

//     std::cout << "\n===== COMPOUND SHIFTS (<<=, >>=) =====\n";
//     bigint sc1("500");
//     sc1 <<= 4;
//     std::cout << "Test 24 sc1 <<= 4 (\"500\") : " << sc1 << " | expected: 5000000\n";

//     bigint sc2("12345");
//     sc2 >>= 2;
//     std::cout << "Test 25 sc2 >>= 2 (\"12345\"): " << sc2 << " | expected: 123\n";

//     // Parentheses for chaining because assignment operators are right-associative
//     bigint sc3("5");
//     (sc3 <<= 2) <<= 2; // 5 -> 500 -> 50000
//     std::cout << "Test 26 chain (sc3 <<= 2 <<= 2): " << sc3 << " | expected: 50000\n";

//     bigint sc4("987654");
//     (sc4 >>= 2) >>= 2; // 987654 -> 9876 -> 98
//     std::cout << "Test 27 chain (sc4 >>= 2 >>= 2): " << sc4 << " | expected: 98\n";

//     // Mixed chain
//     bigint sc5("12345");
//     (sc5 <<= 3) >>= 4; // 12345 -> 12345000 -> 1234
//     std::cout << "Test 28 chain (sc5 <<= 3 >>= 4): " << sc5 << " | expected: 1234\n";

//     std::cout << "\n===== MIXED OPERATIONS =====\n";
//     bigint mix1 = (bigint("12") << 2) + bigint("34");   // 1200 + 34 = 1234
//     std::cout << "Test 29 ((\"12\" << 2) + \"34\"): " << mix1 << " | expected: 1234\n";

//     bigint mix2 = (bigint("99999") >> 3) + (bigint("1") << 4); // 99 + 10000 = 10099
//     std::cout << "Test 30 ((\"99999\" >> 3) + (\"1\" << 4)): " << mix2 << " | expected: 10099\n";

//     std::cout << "\n[END] Review outputs visually against expected values above.\n";
//     return 0;
// }

#include "bigint.hpp"
#include <iostream>

int main() {
    std::cout << "===== CONSTRUCTION & NORMALIZATION =====\n";
    bigint t1("000123");
    std::cout << "Test 1  (normalize \"000123\"): " << t1 << " | expected: 123\n";
    bigint t2("0000");
    std::cout << "Test 2  (normalize \"0000\")  : " << t2 << " | expected: 0\n";
    bigint t3(""); // Assuming your constructor handles empty string as 0
    std::cout << "Test 3  (empty string)      : " << t3 << " | expected: 0\n";

    std::cout << "\n===== INCREMENT (++) EDGE CASES =====\n";
    bigint i1("0");
    std::cout << "Test 4  (prefix ++0)        : " << ++i1 << " | expected: 1\n";
    
    bigint i2("99");
    std::cout << "Test 5  (prefix ++99)       : " << ++i2 << " | expected: 100\n";
    
    bigint i3("10");
    bigint i4 = i3++; // Postfix test: i4 gets 10, i3 becomes 11
    std::cout << "Test 6  (postfix 10++)      : returned=" << i4 << ", new_val=" << i3 << " | expected: returned=10, new_val=11\n";

    std::cout << "\n===== DECREMENT (--) EDGE CASES =====\n";
    bigint d1("0");
    std::cout << "Test 7  (prefix --0 guard)  : " << --d1 << " | expected: 0\n";
    
    bigint d2("1");
    std::cout << "Test 8  (prefix --1)        : " << --d2 << " | expected: 0\n";
    
    bigint d3("  100  "); // The massive trailing zero test!
    std::cout << "Test 9  (prefix --100)      : " << --d3 << " | expected: 99\n";
    
    bigint d4("1000");
    std::cout << "Test 10 (prefix --1000)     : " << --d4 << " | expected: 999\n";

    bigint d5("50");
    bigint d6 = d5--; // Postfix test: d6 gets 50, d5 becomes 49
    std::cout << "Test 11 (postfix 50--)      : returned=" << d6 << ", new_val=" << d5 << " | expected: returned=50, new_val=49\n";

    std::cout << "\n===== ADDITION CASCADES (+) =====\n";
    bigint a1("  999  ");
    bigint a2("1    ");
    std::cout << "Test 12 (999 + 1)           : " << (a1 + a2) << " | expected: 1000\n";
    std::cout << "Test 13 (1 + 999)           : " << (a2 + a1) << " | expected: 1000\n";
    
    bigint a3("999999999999999999"); // Pushing beyond standard int limits
    bigint a4("1");
    std::cout << "Test 14 (Massive + 1)       : " << (a3 + a4) << " | expected: 1000000000000000000\n";

    std::cout << "\n===== IN-PLACE ADDITION (+=) =====\n";
    bigint p1("99"); 
    p1 += bigint("2");
    std::cout << "Test 15 (99 += 2)           : " << p1 << " | expected: 101\n";

    std::cout << "\n===== COMPARISONS =====\n";
    bigint c1("100"), c2("99"), c3("100"), c4("0");
    std::cout << "Test 16 (100 > 99)          : " << ((c1 > c2) ? "true" : "false") << " | expected: true\n";
    std::cout << "Test 17 (99 < 100)          : " << ((c2 < c1) ? "true" : "false") << " | expected: true\n";
    std::cout << "Test 18 (100 == 100)        : " << ((c1 == c3) ? "true" : "false") << " | expected: true\n";
    std::cout << "Test 19 (100 != 99)         : " << ((c1 != c2) ? "true" : "false") << " | expected: true\n";
    std::cout << "Test 20 (0 == 0)            : " << ((c4 == bigint("0")) ? "true" : "false") << " | expected: true\n";

    std::cout << "\n===== SHIFTS (<<, >>) =====\n";
    bigint sh1("123");
    std::cout << "Test 21 (123 << 2)          : " << (sh1 << 2) << " | expected: 12300\n";
    std::cout << "Test 22 (123 >> 1)          : " << (sh1 >> 1) << " | expected: 12\n";
    std::cout << "Test 23 (123 >> 5)          : " << (sh1 >> 5) << " | expected: 0\n";
    std::cout << "Test 24 (0 << 5)            : " << (bigint("0") << 5) << " | expected: 0\n";

    std::cout << "\n[END] If everything matches, your logic is flawless!\n";
    return 0;
}