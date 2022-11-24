// #include <concepts>
#include <set>
#include <type_traits>
template <class CONT>


template <class CONT>
CONT CONT::operator+(const CONT &rhs) const
{
    auto v = CONT(vector_size);
    for (size_t i = 0; i < vector_size; ++i)
    {
        v[i] = data[i] + rhs[i];
    }
    return v;
}
Vector Vector::operator+(value v) const
{
    auto vec = Vector(vector_size);
    for (size_t i = 0; i < vector_size; ++i)
    {
        vec[i] = data[i] + v;
    }
    return vec;
}
value Vector::operator*(const Vector &rhs) const
{
    if (vector_size != rhs.size())
        std::runtime_error("Vector not same size");
    value product = 0;
    for (size_t i = 0; i < vector_size; ++i)
    {
        product += data[i] * rhs[i];
    }
    return product;
}