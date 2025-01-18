#include "Arr_List.cpp"
// #include "LL_List.cpp"
class CRS
{
    List<List<int>> garage;
    int NumOfCars, NumberOfGarages, GarageSize;

public:
    CRS(int X, int Y, int Z)
    {
        NumOfCars = X;
        NumberOfGarages = Y;
        GarageSize = Z;
        //garage.init(Y);
        garage.init(0, Y);
        for (int i = 0; i < Y; i++)
        {
            List<int> cars;
            cars.init(0, Z);
            garage.insert(cars);
        }
        cin.ignore();

        for (int i = 0; i < Y; i++)
        {
            string s;
            getline(cin, s);

            stringstream ss(s);
            int g;
            ss >> g;

            garage.moveToPos(g - 1);

            List<int> cars = garage.getValue();
            int car;
            while (ss >> car)
            {
                // cars.insert(car);
                if (cars.length() == 0)
                {
                    cars.insert(car);
                }
                else
                {
                    int pos = cars.currPos();
                    cars.moveToEnd();
                    int x = cars.getValue();
                    cars.insert(car);
                    cars.next();
                    cars.remove();
                    cars.insert(x);
                    cars.moveToPos(pos);
                }
            }
            List<int> temp = garage.getValue();
            if (g == Y)
            {
                garage.prev();

                garage.next();
            }
            garage.remove();
            garage.insert(cars);
            if (g == Y)
            {
                garage.insert(temp);
                garage.moveToEnd();
                garage.remove();
            }
        }
    }

    void print()
    {
        for (int i = 0; i < garage.length(); i++)
        {
            // cout << "Garage " << i + 1 << ": ";
            garage.moveToPos(i);
            List<int> cars = garage.getValue();
            for (int j = 0; j < cars.length(); j++)
            {
                cars.moveToPos(j);
                cout << cars.getValue() << " ";
            }
            cout << endl;
        }
    }

    void req()
    {
        if (NumOfCars == 0)
        {
            cout << "No cars available." << endl;
            return;
        }
        for (int i = 0; i < NumberOfGarages; i++)
        {
            garage.moveToPos(i);
            List<int> cars = garage.getValue();
            if (cars.length() != 0)
            {
                cars.moveToStart();
                int mi = 0;
                int m = cars.getValue();
                for (int j = 0; j < cars.length(); j++)
                {
                    if (cars.getValue() < m)
                    {
                        m = cars.getValue();
                        mi = j;
                    }
                    cars.next();
                }
                cars.moveToPos(mi);
                cars.remove();

                if (i == NumberOfGarages - 1)
                {
                    garage.prev();
                    List<int> t = garage.getValue();
                    garage.next();
                    garage.remove();
                    garage.insert(cars);
                    garage.insert(t);
                    garage.moveToEnd();
                    garage.remove();
                }
                else
                {
                    garage.remove();
                    garage.insert(cars);
                }
                NumberOfGarages--;
                return;
            }
        }
    }

    void ret(int num)
    {

        for (int i = NumberOfGarages - 1; i >= 0; i--)
        {
            garage.moveToPos(i);
            List<int> cars = garage.getValue();
            if (cars.length() < GarageSize)
            {
                if (cars.length() == 0)
                {
                    cars.insert(num);
                }
                else
                {
                    cars.moveToStart();
                    int mi = 0;
                    int m = cars.getValue();
                    for (int j = 0; j < cars.length(); j++)
                    {
                        if (cars.getValue() > m)
                        {
                            m = cars.getValue();
                            mi = j;
                        }
                        cars.next();
                    }
                    if (mi == cars.length() - 1)
                    {
                        cars.moveToEnd();
                        int tm = cars.getValue();
                        cars.insert(num);
                        cars.insert(tm);
                        cars.moveToEnd();
                        cars.remove();
                    }
                    else
                    {
                        cars.moveToPos(mi + 1);
                        cars.insert(num);
                    }
                }
                if (i == NumberOfGarages - 1)
                {
                    garage.prev();
                    List<int> t = garage.getValue();
                    garage.next();
                    garage.remove();
                    garage.insert(cars);
                    garage.insert(t);
                    garage.moveToEnd();
                    garage.remove();
                }
                else
                {
                    garage.remove();
                    garage.insert(cars);
                }
                NumberOfGarages++;
                return;
            }
        }
        cout << "All garages are full. Cannot insert car " << num << "." << endl;
    }
};

int main()
{
    int X, Y, Z;
    cin >> X >> Y >> Z;

    CRS garage(X, Y, Z);
    garage.print();
    string s;
    cin >> s;
    while (s != "end")
    {
        if (s == "req")
        {
            garage.req();
        }
        else if (s == "ret")
        {
            int num;
            cin >> num;
            garage.ret(num);
        }
        garage.print();
        cin >> s;
    }

    return 0;
}
