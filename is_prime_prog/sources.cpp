#include "sources.h"

int i;
bool Is_Prime(int i)
{
    if (i < 2)
        return false;
    for (int j = 2; j < i; j++)
    {
        if (i % j == 0)
            return false;
    }
    return true;
}
bool Is_Prime_faster(int i)
{
    if (i < 2 || i % 2 == 0)
        return false;

    for (int j = 2; j <= ceil(sqrt(i)); j++)
    {
        if (i % j == 0)
            return false;
    }
    return true;
}
