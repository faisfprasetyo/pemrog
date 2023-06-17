#include <bits/stdc++.h>
using namespace std;

class pewarisan_pegawai
{
protected:
    string id;
    int usia;
    int tipe;
    int income;

public:
    void set(string pid, int u, int t)
    {
        id = pid;
        usia = u;
        tipe = t;
    }
    void print()
    {
        cout << id << " " << tipe << " " << income << endl;
    }
};

class PegawaiTetap: public pewarisan_pegawai
{
private:
    int lembur;
    vector < string, pewarisan_pegawai > data;

public:
    PegawaiTetap()
    {
        data.clear();
    }
    void set(string pid, int usia, int t)
    {
    }
};

class PegawaiHarian:  public pewarisan_pegawai
{
    private:
    vector < string, pewarisan_pegawai > data;

    public:
    PegawaiHarian()
    {
            data.clear();
    }
};
int main()
{
    vector<PegawaiTetap>
    int t;
    cin >> t;
    string id; 
    int usia, tipe, income;
    for (int i = 0; i < t; i++)
    {
        cin >> id >> usia >> tipe;
        if (tipe == i)
        {
            cin >> income;
            ttp.set(id, usia, tipe);
            ttp.setIncome(income);
            tetap.push_back(hrn);
        }
        else if (tipe == 2)
        {
            hrn.set (id, usia, tipe);
            harian.push_back(hrn);
        }
    }
    
    string x = "";
    while(x != "END")
    {
        cin >> id;
        vector<PegawaiTetap>::iterator it = tetap.begin():
        for (it2 = harian.begin(); it2 != tetap.end(); ++it)
        {
            it print;
        }
        
    }

}

pewarisan_pegawai::pewarisan_pegawai(/* args */)
{
}

pewarisan_pegawai::~pewarisan_pegawai()
{
}
