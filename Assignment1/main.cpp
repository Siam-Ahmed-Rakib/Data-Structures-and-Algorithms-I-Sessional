// #include "Arr_List.cpp"
#include "LL_List.cpp"
int main()
{
    List<int> list;
    int K, X;
    cin >> K >> X;
    list.init(0, X);
    int el;
    for (int i = 0; i < K; i++)
    {
        cin >> el;
        if (list.length() == 0)
        {
            list.insert(el);
        }
        else
        {
            int pos = list.currPos();
            list.moveToEnd();
            int x = list.getValue();
            list.insert(el);
            list.next();
            list.remove();
            list.insert(x);
            list.moveToPos(pos);
        }
    }
    list.moveToStart();
    int x;
    list.print();
    cout << "1. Insert\n2. Remove\n3. Move to Start\n4. Move to End\n5. Previous\n6. Next\n7. Length\n8. Current Position\n9. Move to Position\n10. Get Value\n0. Exit\n";
    while (true)
    {
        cin >> x;
        if (x == 1)
        {
            int item;
            cin >> item;
            list.insert(item);
        }
        else if (x == 2)
        {
            if(list.length() > 0)
            {
                list.remove();
            }
            else 
            {
                cout << "List is empty." << endl;
            }

        }
        else if (x == 3)
        {
            list.moveToStart();
        }
        else if (x == 4)
        {
            list.moveToEnd();
        }
        else if (x == 5)
        {
            list.prev();
        }
        else if (x == 6)
        {
            list.next();
        }
        else if (x == 7)
        {
            cout << list.length() << endl;
        }
        else if (x == 8)
        {
            cout << list.currPos() << endl;
        }
        else if (x == 9)
        {
            int pos;
            cin >> pos;
            list.moveToPos(pos);
        }
        else if (x == 10)
        {
            if(list.length() > 0)
            {
                cout << list.getValue() << endl;
            }
            else 
            {
                cout << "List is empty." << endl;
            }
        }

        else if (x == 0)
        {
            break;
        }
        list.print();
    }
}