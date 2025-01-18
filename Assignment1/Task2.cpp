// #include "Arr_List.cpp"
#include "LL_List.cpp"
template <typename T>
class ExtendedList
{
    List<T> list;

public:
    ExtendedList(int length, int chunksize)
    {
        list.init(length, chunksize);
    }
    void clear()
    {
        while (list.length() > 0)
        {
            list.remove();
        }
    }
    void append(T item)
    {
        if (list.length() == 0)
        {
            list.insert(item);
        }
        else
        {
            int pos = list.currPos();
            list.moveToEnd();
            int x = list.getValue();
            list.insert(item);
            list.next();
            list.remove();
            list.insert(x);
            list.moveToPos(pos);
        }
    }
    int Search(T item)
    {
        if (list.length() == 0)
        {
            return -1;
        }
        int pos = list.currPos();
        list.moveToStart();
        for (int i = 0; i < list.length(); i++)
        {
            if (list.getValue() == item)
            {
                list.moveToPos(pos);
                return i;
            }
            list.next();
        }
        list.moveToPos(pos);
        return -1;
    }
    void print()
    {
        list.print();
    }
};

int main()
{
    int K, X;
    cin >> K >> X;
    ExtendedList<int> list(0, X);

    int el;
    for (int i = 0; i < K; i++)
    {
        cin >> el;
        list.append(el);
    }
    cout << "1. Append\n2. Search\n3. Clear\n0. Exit\n";
    int x;
    while (true)
    {
        cin >> x;
        if (x == 1)
        {
            int item;
            cin >> item;
            list.append(item);
            list.print();
        }
        else if (x == 2)
        {
            int item;
            cin >> item;
            cout << list.Search(item) << endl;
        }
        else if (x == 3)
        {
            list.clear();
            list.print();
        }
        else if (x == 0)
        {
            break;
        }
    }
    return 0;
}