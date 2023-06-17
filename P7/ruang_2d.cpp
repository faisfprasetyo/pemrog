#include <bits/stdc++.h>
using namespace std;

class Ruang2D
{
protected:
    double sisi1, sisi2, sisi3, sisi4;

public:
    void set(double a, double t)
    {
        sisi1 = a;
        sisi2 = t;
        sisi3 = sqrt(a * a + t * t);
    }
    double luas() { return sisi1 * sisi2; }
    double keliling() { return sisi1 + sisi2 + sisi3 + sisi4; }
};

class Koleksi
{
private:
    vector<Segiempat> S4;
    vector<Segitiga> S3;
    template <typename T>
    bool cmp(const T &a, const T &b)
    {
        return a.luas() > b.luas();
    }

public:
    Koleksi()
    {
        S4.clear();
        S3.clear();
    }
    void addSegiempat(double p, double l)
    {
        Segiempat s;
        s.set(p, l);
        S4.push_back(s);
    }
    void addSegitiga(double a, double t)
    {
        Segitiga s;
        s.set(a, t);
        S3.push_back(s);
    }
    void sortSegiempat()
    {
        sort(S4.begin(), S4.end(), cmp);
    }
    void sortSegitiga()
    {
        sort(S3.begin(), S3.end(), cmp<Segitiga>);
    }
};

int main()
{
    int m, n;
    cin >> m >> n;
    Koleksi K;
    for (int i = 0; i < m; i++)
    {
        int p, l;
        cin >> p >> l;
        K.addSegiempat(p, l);
    }
    K.sortSegiempat();

    for (int i = 0; i < n; i++)
    {
        int a, t;
        cin >> a >> t;
        K.addSegitiga(a, t);
    }
    K.sortSeitiga();
}