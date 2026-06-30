#include "vect2.hpp"

vect2::vect2(){
    this->vect[0] = 0;
    this->vect[1] = 0;
}

vect2::vect2(int n1, int n2){
    this->vect[0] = n1;
    this->vect[1] = n2;
}

vect2::vect2(const vect2 &other){
    this->vect[0] = other.vect[0];
    this->vect[1] = other.vect[1];
}

vect2 &vect2::operator=(const vect2 &other){
    if (this != &other){
        this->vect[0] = other.vect[0];
        this->vect[1] = other.vect[1];
    }
    return *this;
}

vect2::~vect2(){}

int vect2::operator[](int index) const{
    int r = this->vect[index];
    return r;
}

std::ostream &operator<<(std::ostream &os, const vect2 &other){
    os << "{" << other.operator[](0) << ", " << other.operator[](0) << "}";
    return os;
}