#include "searchable_tree_bag.hpp"
#include <cstddef>

searchable_tree_bag::searchable_tree_bag(): tree_bag(), searchable_bag(){}
searchable_tree_bag::~searchable_tree_bag(){}

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag &other): tree_bag(other), searchable_bag(other){}

searchable_tree_bag &searchable_tree_bag::operator=(const searchable_tree_bag &other){
    if (this != &other){
        tree_bag::operator=(other);
    }
    return *this;
}

bool searchable_tree_bag::search_tree(const node *tree, int i) const{
    if (tree == NULL)
        return false;
    if (tree->value == i)
        return true;
    if (tree->value > i)
        return search_tree(tree->l, i);
    else
        return search_tree(tree->r, i);
}

bool searchable_tree_bag::has(int i) const{
    return search_tree(this->tree_, i);
}