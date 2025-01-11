#include "Arr_List.cpp"

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
        while(list.length() > 0)
        {
            list.remove();
        }
    }
    void append(T item)
    {
        int pos = list.currPos();
        list.moveToEnd();
        int x=list.getValue();
        list.insert(item);
        list.next();
        list.remove();
        list.insert(x);
        list.moveToPos(pos);
    }
    int Search(T item)
    {
        int pos = list.currPos();
        list.moveToStart();
        for(int i=0;i<list.length();i++)
        {
            if(list.getValue() == item)
            {
                list.moveToPos(pos);
                return i;
            }
            list.next();
        }
        list.moveToPos(pos);
        return -1;
    }
};