#pragma once

#include "polyset-attachment/tree_bag.hpp"
#include "polyset-attachment/searchable_bag.hpp"

class searchable_tree_bag: public tree_bag, public searchable_bag{
    private:
        bool search_tree(const node *tree, int i) const;
    public:
        searchable_tree_bag();
        searchable_tree_bag(const searchable_tree_bag &other);
        searchable_tree_bag &operator=(const searchable_tree_bag &other);
        ~searchable_tree_bag();
        virtual bool has(int i) const;
};