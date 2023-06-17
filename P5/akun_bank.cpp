#include <bits/stdc++.h>
using namespace std;

class akun_bank
{
private:
    map<string, int> transaksi;

public:
    akun_bank()
    {
        this->transaksi.clear();
    }

    void addtransaksi(string code)
    {
        transaksi[code]++;
    }
    void print()
    {
        map<string, int>::iterator it;
        for (it = transaksi.begin(); it != transaksi.end(); ++it)
        {
            cout << it->first << " " << it->second << endl;
        }
    }
};
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        akun_bank semprul = akun_bank();
        cin >> n;
        string transaksi;
        getline(cin, transaksi);
        for (int j = 0; j < n; j++)
        {
            getline(cin, transaksi);
            semprul.addtransaksi(transaksi);
        }
        semprul.print();
    }
}