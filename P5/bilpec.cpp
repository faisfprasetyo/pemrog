#include <iostream>

using namespace std;

class Bilangan
{
private:
  int x;
  int y;
  int z;

  int getGCD(int a, int b)
  {
    int c;
    while (b != 0)
    {
      int c = a % b;
      a = b;
      b = c;
    }

    return a;
  }

public:
  Bilangan()
  {
    x = y = z = 0;
  }

  Bilangan(int a1, int b1, int c1)
  {
    x = a1;
    z = b1;
    y = c1;
  }
  void set(int a1, int b1, int c1)
  {
    x = a1;
    z = b1;
    y = c1;
  }

  void print()
  {
    int gcd = getGCD(this->y, z);
    z /= gcd;
    y /= gcd;
    if (z == y)
    {
      x += z;
      cout << x << endl;
    }
    else
    {
      printf("%d %d/%d \n", x, z, y);
    }
  }

  void mul(int a1, int b1, int c1)
  {
    x *= a1;
  }

  Bilangan operator+(Bilangan &bil)
  {
    x += bil.x;

    int c = y * bil.y / getGCD(y, bil.y);

    z = z * (c / y);

    bil.z = bil.z * (c / bil.z);

    z = z + bil.z;
    y = c;
  }

  Bilangan operator*(Bilangan &bil)
  {
    x += bil.x;

    int c = y * bil.y / getGCD(y, bil.y);

    z = z * (c / y);

    bil.z = bil.z * (c / bil.z);

    z = z + bil.z;
    y = c;
  }

  void inc()
  {
    this - x++;
  }
  void denc()
  {
    x--;
  }
};

int main()
{
  Bilangan cp = Bilangan();
  int a, b, c;
  string kode;

  while (kode != "end")
  {
    cin >> kode;
    if (kode == "set")
    {
      cin >> a >> b >> c;
      cp.set(a, b, c);
    }
    else if (kode == "p")
    {
      cp.print();
    }
    else if (kode == "add")
    {
      cin >> a >> b >> c;
      Bilangan c1(a, b, c);
      cp.operator+(c1);
    }
    else if (kode == "mul")
    {
      cin >> a >> b >> c;
      cp.mul(a, b, c);
    }
    else if (kode == "inc")
    {
      cp.inc();
    }
    else if (kode == "dec")
    {
      cp.denc();
    }
    else if (kode == "end")
    {
      break;
    }
  }

  return 0;
}