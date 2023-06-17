#include <iostream>

using namespace std;

class Sepatu
{
    public :

    char style;

double price;
};
int main()
{

    Sepatu s1, s2;

    s1.style = 'A';

    s1.price = 99.99;

    cout << s1.style << " Rp" << s1.price << endl;

    s2.price = s2.price / 9;

    cout << s2.style << " Rp" << s2.price  << endl;

    return 0;
}