#pragma once

#include <cassert>
#include <initializer_list>
#include <memory>
#include <ostream>

#include "config.h"

class Vector
{
public:
    // DO NOT CHANGE THIS
    Vector(const Vector &);// copy constructor
    Vector &operator=(const Vector &);// copy assignment
    ~Vector() = default;
    //

    // Add suitable constructors
    // Vector(const Vector &rhs);  
    Vector(size_t N);
    Vector(std::initializer_list<value> l);

    size_t size() const;

    // Public Member functions here
    Vector &operator+=(const Vector &rhs);
    // More to go
    Vector &operator-=(const Vector &rhs);
    Vector &operator+=(value v);
    Vector &operator*=(value v);

    Vector operator+(const Vector &rhs) const;
    Vector operator+(value v) const;
    Vector operator-(const Vector &rhs);
    value operator*(const Vector &rhs) const;
    Vector operator*(value v) const;
    value &operator[](size_t idx);
    value operator[](size_t idx) const;

    // Vector &operator=(const Vector &rhs); 

private:
    // Private Member functions here (if necessary)
    size_t v_size;
    std::unique_ptr<value[]> v_data;
    // Member variables are ALWAYS private, and they go here
};

// Nonmember function operators go here
Vector operator*(const value &s, const Vector &v);
Vector operator+(const value &s, const Vector &v);
std::ostream &operator<<(std::ostream &o, const Vector &v);