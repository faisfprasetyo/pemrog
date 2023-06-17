#include<iostream>
#include<iomanip>
#include<string>
#include<bits/stdc++.h>
using namespace std;

class Person
{
 private:
 string nama;
    int usia;
    int tinggi;
    double berat;
 public:
    Person()
    {
        nama = " ";
        usia = 0;
        tinggi = 0;
        berat = 0.0;
    }
    void setPerson(string nm, int u, int t, double b) 
    {
        nama=nm;
        usia=u;
        tinggi=t;
        berat=b;
    }
    string getNama()
    {
        return nama;
    }
    int getUsia()
    {
        return usia;
    }
    int getTinggi()
    {
        return tinggi;
    }
    double getBerat()
    {
        return berat;
    }
    double getIMT()
    {
        double imt = 1.0 * berat / (0.01 * tinggi * 0.01 * tinggi);
        return imt;
    }
    string getStatusGizi()
    {
        double imt = getIMT();
        if (imt >= 28)
        {
            return "sangat gemuk";
        }
        else if (imt >= 25)
        {
            return "gemuk";
        }
        else if (imt >= 18.5)
        {
            return "normal";
        }
        else if (imt >= 17)
        {
            return "kurus";
        }
        else
        {
            return "sangat kurus";
        }
    }
};
int main()
{
    int dt;
    cin >> dt;
    Person orang[dt];
    string nm; 
    int u, t; 
    double b;
    double sum = 0;
    int imt[5] = {0};
    for (int i = 0; i < dt; i++)
    {
        cin >> nm >> u >> t >> b;
        orang[i].setPerson(nm, u, t, b);
        sum += orang[i].getTinggi();
        if(orang[i].getStatusGizi() == "sangat gemuk") imt[4]
        ++;
        else if (orang[i].getStatusGizi() == "gemuk") imt[3]
        ++;
        else if (orang[i].getStatusGizi() == "normal") imt[2]
        ++;
        else if (orang[i].getStatusGizi() == "kurus") imt[1]
        ++;
        else imt[0]++;
    }
    double mean = sum / dt;
    int count = 0;
    for (int i = 0; i < dt; i++)
    {
        cout << orang[i].getNama() << " " << 
        orang[i].getUsia() << " " <<
        orang[i].getTinggi() << " " << fixed << 
        setprecision(2) << orang[i].getBerat() << fixed <<
        setprecision(2) << " " << orang[i].getIMT() << " " << 
        orang[i].getStatusGizi() << endl;
        if(orang[i].getTinggi() > mean) count++;
    }
    cout << fixed << setprecision(2) << mean << endl << count << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << imt[i];
        if(i == 4) cout << endl;
        else cout << " ";
    }
    return 0;    
}
