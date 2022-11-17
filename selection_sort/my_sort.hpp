// Change me instead
// All occurences of XXX need to be replaced with
// something more meaningful

template <class T>
void my_selection_sort(T begin, T end)
{
    end--;
    while (begin != end)
    {
        T max = begin;
        for (T st = begin; st != end; st++)
        {
            if (*max < *st)
                max = st;
        }
        if (*max > *end)
            std::swap(*max, *end);
        end--;
    }
}