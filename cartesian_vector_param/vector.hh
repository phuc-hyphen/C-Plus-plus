#pragma once

#include <ostream>

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
    // possibly more

    // Public Member functions here
    Vector &operator+=(const Vector &rhs);
    Vector operator+(const Vector &rhs);
    Vector &operator+=(const value num);

    Vector &operator-=(const Vector &rhs);
    Vector operator-(const Vector &rhs);

    Vector operator*(const value num);
    value operator*(const Vector &rhs);
    Vector &operator*=(const value num);

    value &operator[](std::size_t index);

    // More to go

private:
    // Private Member functions here
    friend std::ostream &operator<<(std::ostream &out, const Vector &rhs);
    // Member variables are ALWAYS private, and they go here
    value cor[NDIM];
};

// Nonmember function operators go here