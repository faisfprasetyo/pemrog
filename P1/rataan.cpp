#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n, k, bil, simpan, masukan;
    double rata;
    simpan=0;
    rata=0;
    bil=0;
    cin >> n >> k;
    if (n==0 || n<k)
    {
        cout << "0.00" << endl;
    }    
    else
    {
        for (int i=1; i <= n; i++)
        {
            cin >> masukan;
            if (i%k==0)
            {
                simpan+=masukan;
                bil++;
            }
        }
        rata=(simpan*1.0/bil);
        cout << fixed << setprecision(2) << (double) rata << endl;  
    }
    return 0;
}
