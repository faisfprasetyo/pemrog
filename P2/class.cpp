#include <iostream>
using namespace std;

class satu
{
private:
    int n;

public:
    satu()
    {
        n = 0;
    }
    satu(int valuex)
    {
        n = valuex;
    }
    void set(int value)
    {
        n = value;
    }
    void print()
    {
        cout << n << endl;
    }
    int get()
    {
        return n;
    }
    int inc()
    {
        return n++;
    }
    int dec()
    {
        return n--;
    }
};

int main()
{
    satu myClass;
    int m;
    cin >> m;
    while (m != -9)
    {
        switch (m)
        {
        case 0:
            cin >> m;
            if (m>=0)
            {
                myClass.set(m);
            }
            else
            {
                myClass.set(0);
            }
            break;

        case 1:
            myClass.inc();
            break;
            
        case -1:
            if (myClass.get()>0)
            {
                m = myClass.dec();
            }
            break;

        case 9:
            myClass.print();
            break;

        case -9:
            m = -9;
            break;
        }
        cin >> m;
    }
}
