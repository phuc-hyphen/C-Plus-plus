#include "vector.hh"

std::ostream &operator<<(std::ostream &out, const Vector &rhs)
{
    out << "{";
    for (size_t i = 0; i < NDIM; i++)
    {
        out << rhs.cor[i];
        if (i != NDIM - 1)
            out << ",";
    }
    out << "}" << std::endl;
    return out;
}
Vector::Vector()
{
    for (size_t i = 0; i < NDIM; i++)
        cor[i] = 0;
}
Vector::Vector(std::initializer_list<value> cor_list)
{
    // int vector_size = cor_list.size();
    int count = 0;
    for (value i : cor_list)
    {
        if (count < NDIM)
        {
            cor[count] = i;
            count++;
        }
    }
}
Vector &Vector::operator+=(const Vector &rhs)
{
    for (size_t i = 0; i < NDIM; i++)
    {
        this->cor[i] += rhs.cor[i];
    }
    return *this;
}

Vector Vector::operator+(const Vector &rhs)
{
    auto v = Vector();
    for (size_t i = 0; i < NDIM; i++)
    {
        v.cor[i] = this->cor[i] + rhs.cor[i];
    }
    return v;
}
Vector &Vector::operator-=(const Vector &rhs)
{
    for (size_t i = 0; i < NDIM; i++)
    {
        this->cor[i] -= rhs.cor[i];
    }
    return *this;
}

Vector Vector::operator-(const Vector &rhs)
{
    auto v = Vector();
    for (size_t i = 0; i < NDIM; i++)
    {
        v.cor[i] = this->cor[i] - rhs.cor[i];
    }
    return v;
}
Vector Vector::operator*(const value num)
{
    auto v = Vector();
    for (size_t i = 0; i < NDIM; i++)
    {
        v.cor[i] = this->cor[i] * num;
    }
    return *this;
}

value Vector::operator*(const Vector &rhs)
{
    value sum = 0;
    for (size_t i = 0; i < NDIM; i++)
    {
        sum += this->cor[i] * rhs.cor[i];
    }
    return sum;
}
value &Vector::operator[](std::size_t index)
{
    return this->cor[index];
}
Vector &Vector::operator*=(const value num)
{
    for (size_t i = 0; i < NDIM; i++)
    {
        this->cor[i] *= num;
    }
    return *this;
}
Vector &Vector::operator+=(const value num)
{
    for (size_t i = 0; i < NDIM; i++)
    {
        this->cor[i] += num;
    }
    return *this;
}