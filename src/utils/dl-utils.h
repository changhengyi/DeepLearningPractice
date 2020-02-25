
template <class T>

int getArrayLenth(T& array)
{
    return sizeof(array) / sizeof(array[0]);
}
