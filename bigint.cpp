#include "bigint.hpp"

void bigint::clear_data(){
    size_t first_non_zero = this->num.find_first_not_of('0');
    if (first_non_zero == std::string::npos)
        this->num = "0";
    else if (first_non_zero > 0)
        this->num.erase(0, first_non_zero);
}

bigint::bigint(std::string num){
    this->num = num;
    this->clear_data();
    std::reverse(this->num.begin(), this->num.end());
}

bigint::bigint(unsigned int n){
    if (n == 0){
        this->num = "0";
        return ;
    }
    while (n > 0){
        this->num.push_back((n % 10) + '0');
        n /= 10;
    }
}

bigint::~bigint(){

}

bigint &bigint::operator=(const bigint &other){
    if (this != &other){
        this->num = other.num;
    }
    return *this;
}

bigint::bigint(const bigint &other){
    this->num = other.num;
}

const std::string bigint::getNum() const{
    return this->num;
}

std::ostream &operator<<(std::ostream &os, const bigint &obj){
    std::string temp = obj.getNum();
    std::reverse(temp.begin(), temp.end());
    os << temp;
    return os;
}

bool bigint::operator==(const bigint &other){
    if (this->num.compare(other.num) == 0)
        return true;
    return false;
}

bool bigint::operator!=(const bigint &other){
    if (this->num.compare(other.num) != 0)
        return true;
    return false;
}

unsigned int  toNum (std::string num){
    std::string t = num;
    std::reverse(t.begin(), t.end());
    unsigned int n;
    std::stringstream ss(t);
    ss >> n;
    return n;
}

bool bigint::operator<(const bigint &other){
    unsigned int n1 = toNum(this->num);
    unsigned int n2 = toNum(other.num);
    if (n1 < n2)
        return true;
    return false;
}

bool bigint::operator<=(const bigint &other){
    unsigned int n1 = toNum(this->num);
    unsigned int n2 = toNum(other.num);
    if (n1 <= n2)
        return true;
    return false;
}

bool bigint::operator>(const bigint &other){
    unsigned int n1 = toNum(this->num);
    unsigned int n2 = toNum(other.num);
    if (n1 > n2)
        return true;
    return false;
}

bool bigint::operator>=(const bigint &other){
    unsigned int n1 = toNum(this->num);
    unsigned int n2 = toNum(other.num);
    if (n1 >= n2)
        return true;
    return false;
}

bigint bigint::operator+(const bigint &other){
    unsigned int n1 = toNum(this->num);
    unsigned int n2 = toNum(other.num);
    unsigned int r = n1 + n2;
    bigint result(r);
    return result;
}

bigint &bigint::operator+=(const bigint &other){
    bigint result = this->operator+(other);
    return (this->operator=(result));
}