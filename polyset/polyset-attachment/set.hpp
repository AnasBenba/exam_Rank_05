#pragma once

#include "searchable_bag.hpp"

class set{
    private:
        searchable_bag *bag_;
    public:
        set();
        set(searchable_bag &bag);
        set(searchable_bag *bag);
        set(const set &other);
        set &operator=(const set &other);
        ~set();

        void insert(int x);
        void insert(int *arr, int n);
        bool has(int x) const;
        void print() const;
        void clear();
};