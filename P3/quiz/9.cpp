#include <iostream>
using namespace std;

class Box
{
private:
    int row, col;
    int luas() { return row * col; }

public:
    Box()
    {
        row = col = 0;
        cout << luas();
    }

    void setBox(int r, int c)

    {

        row = r;
        col = c;

        cout << luas();
    }
};
int main()

{

    Box obj1, obj2;

    obj1.setBox(3, 6);

    obj2.setBox(2, 9);

    return 0;
}