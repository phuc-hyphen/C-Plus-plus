#pragma once

#include <initializer_list>
#include <ostream>
// #include <vector>

#include "config.h"
class Vector
{
    
public:
    // DO NOT CHANGE THIS
    Vector(const Vector &) = default;
    Vector &operator=(const Vector &) = default;
    ~Vector() = default;
    //

    // Add suitable constructors
    Vector();

    Vector(std::initializer_list<value> cor_list);
    // : cor(cor_list.begin(), cor_list.end())
    // , vector_size{ cor_list.size() } {};
    // possibly more

    // Public Member functions here

    // Vector &operator+=(const Vector &rhs);
    // Vector &operator-=(const Vector &rhs);
    // Vector &operator*(const Vector &rhs);
    // Vector operator+(const Vector &rhs);
    // Vector operator+(int nrb);
    // Vector operator*(int nrb);
    // Vector operator-(const Vector &rhs);

    // Vector &operator[](const Vector &rhs);
    // More to go
    

private:
    // Private Member functions here
    friend std::ostream &operator<<(std::ostream &out, const Vector &rhs);
    // Member variables are ALWAYS private, and they go here
    int cor[NDIM];
    // std::vector<int> cors_;
    // size_t vector_size = NDIM;
};

// Nonmember function operators go here

