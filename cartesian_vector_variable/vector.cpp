#include "vector.hh"

// constructors
size_t Vector::size() const
{
    return this->v_size;
}
Vector::Vector(const Vector &rhs)
{
    v_size = rhs.v_size;
    v_data = std::make_unique<value[]>(rhs.v_size);
    for (size_t i = 0; i < rhs.v_size; i++)
        v_data[i] = rhs[i];
}
Vector::Vector(size_t N)
{
    v_size = N;
    v_data = std::make_unique<value[]>(N);
    for (size_t i = 0; i < N; i++)
        v_data[i] = 0;
}

Vector::Vector(std::initializer_list<value> l)
{
    v_size = l.size();

    std::initializer_list<value>::iterator it;
    v_data = std::make_unique<int[]>(v_size);

    size_t count = 0;
    for (it = l.begin(); it != l.end(); ++it)
        v_data[count++] = *it;
}

Vector &Vector::operator=(const Vector &rhs)
{
    // if (rhs.v_size != v_size)
    v_size = rhs.v_size;
    this->v_data = std::make_unique<value[]>(v_size);
    for (size_t i = 0; i < rhs.v_size; i++)
        v_data[i] = rhs[i];
    return *this;
}
Vector &Vector::operator+=(const Vector &rhs)
{
    if (rhs.v_size != v_size)
        throw std::runtime_error("Incompatible size");
    for (size_t i = 0; i < v_size; i++)
    {
        this->v_data[i] += rhs.v_data[i];
    }
    return *this;
}

Vector &Vector::operator-=(const Vector &rhs)
{
    if (rhs.v_size != v_size)
        throw std::runtime_error("Incompatible size");
    for (size_t i = 0; i < v_size; i++)
    {
        this->v_data[i] -= rhs.v_data[i];
    }
    return *this;
}
Vector &Vector::operator+=(value v)
{
    for (size_t i = 0; i < v_size; i++)
    {
        this->v_data[i] += v;
    }
    return *this;
}
Vector &Vector::operator*=(value v)
{
    for (size_t i = 0; i < v_size; i++)
    {
        this->v_data[i] *= v;
    }
    return *this;
}
Vector Vector::operator+(const Vector &rhs) const
{
    if (rhs.v_size != v_size)
        throw std::runtime_error("Incompatible size");

    auto s = Vector(rhs.v_size);
    for (size_t i = 0; i < v_size; i++)
    {
        s.v_data[i] = this->v_data[i] + rhs.v_data[i];
    }
    return s;
}
Vector Vector::operator+(value v) const
{
    auto s = Vector(this->v_size);
    for (size_t i = 0; i < v_size; i++)
    {
        s.v_data[i] = this->v_data[i] + v;
    }
    return s;
}
Vector Vector::operator-(const Vector &rhs)
{
    if (rhs.v_size != v_size)
        throw std::runtime_error("Incompatible size");
    auto v = Vector(v_size);
    for (size_t i = 0; i < v_size; i++)
    {
        v.v_data[i] = this->v_data[i] - rhs.v_data[i];
    }
    return v;
}
value Vector::operator*(const Vector &rhs) const
{
    if (rhs.v_size != v_size)
        throw std::runtime_error("Incompatible size");
    value sum = 0;
    for (size_t i = 0; i < v_size; i++)
    {
        sum += this->v_data[i] * rhs.v_data[i];
    }
    return sum;
}
Vector Vector::operator*(value v) const
{
    auto s = Vector(v_size);
    for (size_t i = 0; i < v_size; i++)
    {
        s.v_data[i] = this->v_data[i] * v;
    }
    return v;
}

value &Vector::operator[](std::size_t idx)
{
    if (idx >= v_size)
        throw std::runtime_error("Index out of size");
    return this->v_data[idx];
}

value Vector::operator[](std::size_t idx) const
{
    if (idx >= v_size)
        throw std::runtime_error("Index out of size");
    return this->v_data[idx];
}

// Nonmember function operators go here
Vector operator*(const value &s, const Vector &v)
{
    auto newVec = Vector(v.size());
    for (size_t i = 0; i < v.size(); i++)
    {
        newVec[i] = s * v[i];
    }
    return newVec;
}
Vector operator+(const value &s, const Vector &v)
{
    auto newVec = Vector(v.size());
    for (size_t i = 0; i < v.size(); i++)
    {
        newVec[i] = s + v[i];
    }
    return newVec;
}
std::ostream &operator<<(std::ostream &out, const Vector &rhs)
{
    out << "{";
    for (size_t i = 0; i < rhs.size(); i++)
    {
        out << rhs[i];
        if (i != rhs.size() - 1)
            out << ",";
    }
    out << "}";
    return out;
}