#include <iostream>
using namespace std;

template <typename T>
class List
{
    T *arr;
    int list_length;
    int chunksize;
    int current_position;

public:
    void init(int length, int chunksize ,T* a)
    {
        this->list_length = length;
        this->chunksize = chunksize;
        arr = new T[chunksize];
        current_position = 0;
        for (int i = 0; i < length; i++)
        {
            arr[i] = a[i];
        }
    }
    void insert(T item)
    {
        // current_position = min(current_position, 0);
        // if (list_length == chunksize)
        // {
        //     T *temp = new T[chunksize];
        //     for (int i = 0; i < chunksize; i++)
        //     {
        //         temp[i] = arr[i];
        //     }
        //     delete[] arr;
        //     arr = new T[chunksize * 2];
        //     for (int i = 0; i < chunksize; i++)
        //     {
        //         arr[i] = temp[i];
        //     }
        //     chunksize *= 2;
        //     delete[] temp;
        // }
        if (list_length == chunksize)
        {

            T *temp = new T[chunksize * 2];
            for (int i = 0; i < list_length; i++)
            {

                temp[i] = arr[i];
            }
            delete[] arr;
            arr = temp;
            chunksize *= 2;
        }
        for (int i = list_length; i > current_position; i--)

        {

            arr[i] = arr[i - 1];
        }

        arr[current_position] = item;
        list_length++;
        // for (int i = list_length - 1; i >= current_position; i--)
        // {
        //     arr[i + 1] = arr[i];
        // }
        // arr[current_position] = item;
        // list_length++;
        // cout << list_length << current_position << endl;
    }
    T remove()
    {
        T item = arr[current_position];
        for (int i = current_position; i < list_length - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        list_length--;
        if (current_position == list_length)
        {
            current_position--;
        }
        if (list_length == 0)
        {
            current_position = 0;
        }
        return item;
    }
    void moveToStart()
    {
        current_position = 0;
    }
    void moveToEnd()
    {
        current_position = list_length - 1;
    }
    void prev()
    {
        if (current_position > 0)
        {
            current_position--;
        }
    }
    void next()
    {
        if (current_position < list_length - 1)
        {
            current_position++;
        }
    }
    int length()
    {
        return list_length;
    }
    int currPos()
    {
        return current_position;
    }
    void moveToPos(int pos)
    {
        if (pos >= 0 && pos < list_length)
        {
            current_position = pos;
        }
    }
    T getValue()
    {
        return arr[current_position];
    }
    void print()
    {
        cout << "<";
        for (int i = 0; i < list_length; i++)
        {
            if (i == current_position)
            {
                cout << "|";
            }
            cout << arr[i];
            if (i + 1 != current_position && i + 1 != list_length)
            {
                cout << ",";
            }
        }
        cout << ">";
        cout << endl;
    }
};
