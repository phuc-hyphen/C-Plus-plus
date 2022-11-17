// Change me instead
// All occurences of XXX need to be replaced with
// something more meaningful

template <class T>
void my_selection_sort(T begin, T end)
{
    // begin++;

    // *begin > *(end-1);
    T st = begin;
    T ed = end - 1;
    while (st != end && ed != begin)
    {
        T min = st;
        T max = st;
        for (T ptr = st; ptr != ed; st++)
        {
            if (*min > *st)
                min = st;
            if (*max < *st)
                max = st;
        }
        std::swap(*min, *max);

        st++;
        ed--;
    }
}