#include "bigint.hpp"

void Bigint::clear_data(){
    size_t first_non_zero = this->num.find_first_not_of('0');
    if (first_non_zero == std::string::npos)
        this->num = "0";
    else if (first_non_zero > 0)
        this->num.erase(0, first_non_zero);
}

Bigint::Bigint(std::string num){
    this->num = num;
    this->clear_data();
    std::reverse(this->num.begin(), this->num.end());
}

Bigint::Bigint(unsigned int n){
    if (n == 0){
        this->num = "0";
        return ;
    }
    while (n > 0){
        this->num.push_back((n % 10) + '0');
        n /= 10;
    }
}

Bigint::~Bigint(){

}

Bigint &Bigint::operator=(const Bigint &other){
    if (this != &other){
        this->num = other.num;
    }
    return *this;
}

Bigint::Bigint(const Bigint &other){
    this->num = other.num;
}

const std::string Bigint::getNum() const{
    return this->num;
}

std::ostream &operator<<(std::ostream &os, const Bigint &obj){
    std::string temp = obj.getNum();
    std::reverse(temp.begin(), temp.end());
    os << temp;
    return os;
}