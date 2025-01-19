#include <iostream>
using namespace std;

template <typename T>
struct LinkedList
{
    T data;
    LinkedList *next;
    LinkedList(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

template <typename T>
class List
{
    LinkedList<T> *head;
    int list_length;
    int current_position;

public:
    void init(int length, int X  ,T* a)
    {
        this->list_length = length;
        head = NULL;
        current_position = 0;
        LinkedList<T> *temp = head;
        for (int i = 0; i < length; i++)
        {
            LinkedList<T> *newNode = new LinkedList<T>(a[i]);
            if (head == NULL)
            {
                head = newNode;
                temp = head;
            }
            else
            {
                temp->next = newNode;
                temp = temp->next;
            }
        }
    }

    void insert(T item)
    {
        //current_position = min(current_position, 0);
        LinkedList<T> *newNode = new LinkedList<T>(item);
        LinkedList<T> *temp = head;
        if (current_position == 0)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            for (int i = 0; i < current_position - 1; i++)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
        list_length++;
    }
    T remove()
    {
      
        LinkedList<T> *temp = head;
        T item;
        if (current_position == 0)
        {
            item = head->data;
            head = head->next;
            delete temp;
        }
        else
        {
            for (int i = 0; i < current_position - 1; i++)
            {
                temp = temp->next;
            }
            LinkedList<T> *temp2 = temp->next;
            item = temp2->data;
            temp->next = temp2->next;
            delete temp2;
        }
        list_length--;
        if (current_position == list_length)
        {
            current_position--;
        }
        if(list_length==0)
        {
            head=NULL;
            current_position=0;
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
      
        LinkedList<T> *temp = head;
        for (int i = 0; i < current_position; i++)
        {
            temp = temp->next;
        }
        return temp->data;
    }
    void print()
    {
        cout << "<";
        LinkedList<T> *temp = head;
        for (int i = 0; i < list_length; i++)
        {
            if (i == current_position)
            {
                cout << "|";
            }
            cout << temp->data;

            temp = temp->next;
            if (i + 1 != current_position && i + 1 != list_length)
            {
                cout << ",";
            }
        }
        cout << ">";
        cout << endl;
    }
};
