#include<bits/stdc++.h>
using namespace std;

class bilangan_pecahan
{
private:
    int angka; 
    int bagi; 
    int pembilang;

    int gcd(int a, int b)
    {
        while(b != 0)
        {
            int temp= a;
            a= b;
            b= a % b;
        }
        return a;
    }

public:
    bilangan_pecahan()
    {
        this -> angka= 0;
        this -> bagi= 0;
        this -> pembilang= 0;
    }
    bilangan_pecahan operator+ (bilangan_pecahan bil)
    {
        this -> angka += bil.angka;
        int c = this-> bagi * bil.bagi / gcd(this ->bagi, bil.bagi);

        this ->pembilang= this -> pembilang + bil.pembilang;
        this ->bagi= c;
    }
    bilangan_pecahan operator* (bilangan_pecahan bil)
    {
        this ->bagi *= bil.bagi;
        this ->pembilang *= bil.pembilang;
        int c = gcd(this ->bagi, this->pembilang);

        this ->bagi /=c;
        this ->pembilang /=c;
    }
    void set(int angka, int pembilang, int bagi)
    {
        this -> angka=angka;
        this -> bagi=bagi;
        this -> pembilang=pembilang;
    }
    void print()
    {
        int gcd = this ->gcd(this -> pembilang, this ->bagi);
        this -> pembilang /=gcd;
        this -> bagi /=gcd;

        printf("%d %d/%d\n", this ->angka, this ->pembilang, this ->bagi);

    }

    
};

int main()
{
    bilangan_pecahan bil= bilangan_pecahan();
    cout << bil.gcd(2,8) << endl;
    return 0;
}