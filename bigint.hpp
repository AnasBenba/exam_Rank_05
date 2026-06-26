#pragma once
#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>

class bigint {
    private:
        std::string num;
    public:
        bigint(std::string num);
        bigint(unsigned int n);
        ~bigint();
        bigint &operator=(const bigint &other);
        bigint(const bigint &other);
        void clear_data();
        const std::string getNum() const;

        // comparisons
        bool operator==(const bigint &other);
        bool operator!=(const bigint &other);
        bool operator<(const bigint &other);
        bool operator<=(const bigint &other);
        bool operator>(const bigint &other);
        bool operator>=(const bigint &other);
        // addition
        bigint operator+(const bigint &other);
        bigint &operator+=(const bigint &other);
};

std::ostream &operator<<(std::ostream &os, const bigint &obj);