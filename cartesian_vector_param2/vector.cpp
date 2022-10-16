#include "vector.hh"

Vector::Vector()
{
    for (size_t i = 0; i < NDIM; i++)
        cor[i] = 0;
    
}
std::ostream &operator<<(std::ostream &out, const Vector &rhs)
{
    out << "{";
    for (size_t i = 0; i < NDIM; i++)
    {
        out << rhs.cor[i];
        if (i != NDIM-1)
            out << ",";
    }
    out << "}" << std::endl;
    return out;
}

Vector::Vector(std::initializer_list<value> cor_list)
{
    // int vector_size = cor_list.size();
    int count = 0;
    for (value i : cor_list)
    {
        cor[count] = i;
        count++;
    }
}
