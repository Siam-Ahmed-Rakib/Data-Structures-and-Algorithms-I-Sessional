#include "Arr_List.cpp"
int main()
{
    List<int> list;
    int K,X;
    cin >> K >> X;
    list.init(K,X);
    int x;
    cout << "1. Insert\n2. Remove\n3. Move to Start\n4. Move to End\n5. Previous\n6. Next\n7. Length\n8. Current Position\n9. Move to Position\n10. Get Value\n0. Exit\n"; 
    while(true)
    {
        cin >> x;
        if(x==1)
        {
            int item;
            cin >> item;
            list.insert(item);
            
        }
        else if(x==2)
        {
            cout << list.remove() << endl;
           
        }
        else if(x==3)
        {
            list.moveToStart();
        }
        else if(x==4)
        {
            list.moveToEnd();
        }
        else if(x==5)
        {
            list.prev();
        }
        else if(x==6)
        {
            list.next();
        }
        else if(x==7)
        {
            cout << list.length() << endl;
        }
        else if(x==8)
        {
            cout << list.currPos() << endl;
        }
        else if(x==9)
        {
            int pos;
            cin >> pos;
            list.moveToPos(pos);
        }
        else if(x==10)
        {
            cout << list.getValue() << endl;
        }
       
        else if(x==0)
        {
            break;
        }
        list.print();
        
    }
}