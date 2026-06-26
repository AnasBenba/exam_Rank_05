#pragma once
#include <string>
#include <algorithm>

class Bigint {
    private:
        std::string num;
    public:
        Bigint(std::string num);
        Bigint(unsigned int n);
        ~Bigint();
        Bigint &operator=(const Bigint &other);
        Bigint(const Bigint &other);
        void clear_data();
        const std::string getNum() const;
};