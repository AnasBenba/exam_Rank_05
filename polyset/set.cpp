#include "set.hpp"
#include <cstddef>

set::set() : bag_(NULL){}
set::set(searchable_bag &bag) : bag_(&bag){}
set::set(searchable_bag *bag) : bag_(bag){}
set::set(const set &other){
    this->bag_ = other.bag_;
}
set &set::operator=(const set &other){
    if (this != &other)
        this->bag_ = other.bag_;
    return *this;
}

set::~set(){

}

bool set::has(int x) const{
    if (this->bag_ == NULL)
        return false;
    return this->bag_->has(x);
}

void set::insert(int x){
    for (int i = 0; i < this->)
}

void set::clear(){
    if (this->bag_ == NULL)
        return;
    this->bag_->clear();
}

void set::print() const{
    if (this->bag_ == NULL)
        return;
    this->bag_->print();
}