#include "LL_List.cpp"
// #include "Arr_List.cpp"
bool same(List<char> A, int n)
{
    int i = 0, j = n - 1;
    while (i < j)
    {
        A.moveToPos(i);
        char x = A.getValue();
        A.moveToPos(j);
        char y = A.getValue();
        if (x != y)
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int main()
{
    int n;
    cin >> n;

    List<char> A;
    A.init(0, n, nullptr);
    for (int i = 0; i < n; i++)
    {
        char digit;
        cin >> digit;
        if (A.length() == 0)
        {
            A.insert(digit);
        }
        else
        {
            int pos = A.currPos();
            A.moveToEnd();
            char x = A.getValue();
            A.insert(digit);
            A.next();
            A.remove();
            A.insert(x);
            A.moveToPos(pos);
        }
    }
    // A.print();
    if (same(A, n))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}