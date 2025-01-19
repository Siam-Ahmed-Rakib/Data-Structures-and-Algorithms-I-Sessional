#include "LL_List.cpp"

int main()
{
    int m, n;
    cin >> m >> n;

    List<int> A, B, C;
    int ar[m], br[n];
    for (int i = 0; i < m; i++)
    {
        cin >> ar[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> br[i];
    }

    A.init(m, m, ar);
    B.init(n, n, br);
    C.init(0, m + n, nullptr);

    // A.print();
    // B.print();
    A.moveToEnd();
    B.moveToEnd();
    int c = 0;
    int i = m;
    int j = n;
    while (true)
    {
        if (i <= 0 && j <= 0)
        {
            break;
        }
        int a = 0, b = 0;
        if (i > 0)
        {
            a = A.getValue();
            A.prev();
        }
        if (j > 0)
        {
            b = B.getValue();
            B.prev();
        }
        C.insert((a + b + c) % 10);
        c = (a + b + c) / 10;
        i--;
        j--;
    }
    if (c > 0)
        C.insert(c);
    C.moveToStart();
    for (int i = 0; i < C.length(); i++)
    {
        cout << C.getValue();
        C.next();
    }

    return 0;
}
