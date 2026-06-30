#include "bigint.hpp"

void bigint::clear_data(){
    size_t first_non_zero = this->num.find_first_not_of('0');
    if (first_non_zero == std::string::npos)
        this->num = "0";
    else if (first_non_zero > 0)
        this->num.erase(0, first_non_zero);
}

std::string trim(std::string num){
    std::string r = "0";
    size_t start = num.find_first_not_of(" \t\r\n\v");
    size_t end = num.find_last_not_of(" \t\r\n\v");
    if (start > end || start == std::string::npos)
        return r;
    return (num.substr(start, end - start + 1));
}

bigint::bigint(std::string num){
    std::string n = trim(num);
    this->num = n;
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

bool bigint::operator==(const bigint &other) const{
    if (this->num.compare(other.num) == 0)
        return true;
    return false;
}

bool bigint::operator!=(const bigint &other) const{
    if (this->num.compare(other.num) != 0)
        return true;
    return false;
}

bool bigint::operator<(const bigint &other) const{
    if (this->num.length() < other.num.length())
        return true;
    if (this->num.length() > other.num.length())
        return false;
    for (int i = this->num.length() - 1; i >= 0; i--){
        if (this->num[i] < other.num[i])
            return true;
        if (this->num[i] > other.num[i])
            return false;
    }
    return false;
}

bool bigint::operator<=(const bigint &other) const{
    if (this->num.length() < other.num.length())
        return true;
    if (this->num.length() > other.num.length())
        return false;
    for (int i = this->num.length() - 1; i >= 0; i--){
        if (this->num[i] < other.num[i])
            return true;
        if (this->num[i] > other.num[i])
            return false;
    }
    return true;
}

bool bigint::operator>(const bigint &other) const{
    if (this->num.length() > other.num.length())
        return true;
    if (this->num.length() < other.num.length())
        return false;
    for (int i = this->num.length() - 1; i >= 0; i--){
        if (this->num[i] > other.num[i])
            return true;
        if (this->num[i] < other.num[i])
            return false;
    }
    return false;
}

bool bigint::operator>=(const bigint &other) const{
    if (this->num.length() > other.num.length())
        return true;
    if (this->num.length() < other.num.length())
        return false;
    for (int i = this->num.length() - 1; i >= 0; i--){
        if (this->num[i] > other.num[i])
            return true;
        if (this->num[i] < other.num[i]){
            return false;
        }
    }
    return true;
}

bigint &bigint::operator+(const bigint &other){
    std::string res = "";
    int carry = 0;
    size_t n1 = this->num.length();
    size_t n2 = other.num.length();
    size_t i = 0;
    while (i < n1 || i < n2 || carry)
    {
        int sum = carry + ((i < n1) ? (this->num[i] - '0') : 0) + ((i < n2) ? (other.num[i] - '0') : 0);
        carry = sum / 10;
        res.push_back((sum % 10) + '0');
        i++;
    }
    this->num = res;
    return *this;
}

bigint &bigint::operator<<=(int num){
    if (this->num == "0")
        return *this;
    if (num <= 0)
        return *this;
    this->num.insert(0, num, '0');
    return *this;
}

bigint bigint::operator<<(int num) const{
    bigint temp = bigint(this->num);
    std::reverse(temp.num.begin(), temp.num.end());
    temp <<= num;
    return temp;
}

bigint &bigint::operator>>=(int num){
    if (this->num == "0")
        return *this;
    if (num <= 0)
        return *this;
    if (static_cast<size_t>(num) >= this->num.length()){
        this->num = "0";
        return *this;
    }
    this->num.erase(0, num);
    return *this;
}

bigint bigint::operator>>(int num) const{
    bigint temp = bigint(this->num);
    std::reverse(temp.num.begin(), temp.num.end());
    temp >>= num;
    return temp;
}

bigint &bigint::operator+=(const bigint &other){
    bigint result = this->operator+(other);
    return (this->operator=(result));
}

bigint &bigint::operator++(){
    bigint obj(1);
    this->operator+(obj);
    return *this;
}

bigint bigint::operator++(int){
    bigint temp = *this;
    this->operator++();
    return temp;
}

bigint &bigint::operator--(){
    if (this->num == "0")
        return *this;
    for (int i = 0; this->num[i]; i++){
        if (this->num[i] != '0'){
            this->num[i] -= 1;
            break;
        }
        this->num[i] = '9';
    }
    std::reverse(this->num.begin(), this->num.end());
    this->clear_data();
    std::reverse(this->num.begin(), this->num.end());
    return *this;
}

bigint bigint::operator--(int){
    bigint temp = *this;
    this->operator--();
    return temp;
}