#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;

class Ruang2D
{
protected:
    double sisi1, sisi2, sisi3, sisi4;

public:
    virtual double luas() = 0;
    virtual double keliling() = 0;
    void set(double s1 = 0, double s2 = 0,
             double s3 = 0, double s4 = 0);
};

void Ruang2D::set(double s1, double s2, double s3, double s4)
{
    sisi1 = s1;
    sisi2 = s2;
    sisi3 = s3;
    sisi4 = s4;
}

class Segiempat : public Ruang2D
{
public:
    double luas();
    double keliling();
};

double Segiempat::luas()
{
    return sisi1 * sisi2;
}

double Segiempat::keliling()
{
    return (2 * sisi1) + (2 * sisi2);
}

class Segitiga : public Ruang2D
{
public:
    double luas();
    double keliling();
};

double Segitiga::luas()
{
    return 0.5 * sisi1 * sisi2;
}

double Segitiga::keliling()
{
    return sisi1 + sisi2 + sqrt(sisi1 * sisi1 + sisi2 * sisi2);
}

struct Ruang2DInfo
{
    Ruang2D *ruang;
    double luas;
    double keliling;
    bool operator<(const Ruang2DInfo &other) const
    {
        if (luas == other.luas)
        {
            return keliling > other.keliling;
        }
        return luas > other.luas;
    }
};

int main()
{
    int m, n;
    cin >> m >> n;

    vector<Ruang2DInfo> segiempatVec;
    for (int i = 0; i < m; i++)
    {
        double s1, s2;
        cin >> s1 >> s2;

        Segiempat *segiempat = new Segiempat();
        segiempat->set(s1, s2);
        double luas = segiempat->luas();
        double keliling = segiempat->keliling();

        segiempatVec.push_back({segiempat, luas, keliling});
    }

    vector<Ruang2DInfo> segitigaVec;
    for (int i = 0; i < n; i++)
    {
        double s1, s2;
        cin >> s1 >> s2;

        Segitiga *segitiga = new Segitiga();
        segitiga->set(s1, s2);
        double luas = segitiga->luas();
        double keliling = segitiga->keliling();

        segitigaVec.push_back({segitiga, luas, keliling});
    }

    sort(segiempatVec.begin(), segiempatVec.end());
    sort(segitigaVec.begin(), segitigaVec.end());

    cout << fixed << setprecision(1);
    cout << "SEGIEMPAT" << endl;
    for (const auto &info : segiempatVec)
    {
        cout << info.luas << " " << info.keliling << endl;
    }
    cout << fixed << setprecision(1);
    cout << "SEGITIGA" << endl;
    for (const auto &info : segitigaVec)
    {
        cout << info.luas << " " << info.keliling << endl;
    }
}
