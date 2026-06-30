#include "searchable_array_bag.hpp"

searchable_array_bag::searchable_array_bag() : array_bag(), searchable_bag(){}
searchable_array_bag::~searchable_array_bag(){
}
searchable_array_bag::searchable_array_bag(const searchable_array_bag &other) : array_bag(other), searchable_bag(other){
}
searchable_array_bag &searchable_array_bag::operator=(const searchable_array_bag &other){
    if (this != &other){
        array_bag::operator=(other);
    }
    return *this;
}

bool searchable_array_bag::has(int i) const{
    for (int y = 0; y < this->size_; y++){
        if (this->data_[y] == i)
            return true;
    }
    return false;
}