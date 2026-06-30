#pragma once

#include <iostream>
#include <string>

class vect2{
    private:
        int vect[2];
    public:
        vect2();
        vect2(int n1, int n2);
        vect2(const vect2 &other);
        vect2 &operator=(const vect2 &other);
        int operator[](int index) const;
        ~vect2();
};

std::ostream &operator<<(std::ostream &os, const vect2 &other);