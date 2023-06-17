#include <bits/stdtr1c++.h>
#include <vector>
#include <iostream>
using namespace std;

class Vector
{
private:
    vector<int> v;
    double mean;
    double meanAfter;
    int size;
    int sizeAfter;


public:
Vector()
{
    mean = -9.99;
    meanAfter = -9.99;
    size = 0;
    sizeAfter = 0;
}
void addData(int num)
{
    v.push_back(num);
}
void removeData(int index, int hasRemove)
{
    v.erase(v.begin() + (index - hasRemove - 1));
}
void printData()
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
}
void grmean()
{
    if (!v.size())
    {
        mean = -9.99;
    }
    else
    {
        double sum = 0;
        for (int i = 0; i < v.size(); i++)
        {
            sum += v[i];
        }
        mean = (double)sum / v.size();
        size = v.size();
    }
}
void grmeanAfter()
{
    if (!v.size())
    {
        meanAfter = -9.99;
    }
    else
    {
        double sum = 0;
        for (int i = 0; i < v.size(); i++)
        {
            sum += v[i];
        }
        meanAfter = (double) sum / v.size();
        size = v.size();
        
    }
    
    
}
double getMean()
{
    return mean;
}
double getMeanAfter()
{
    return meanAfter;
}
double getSize()
{
    return size;
}
double getSizeAfter()
{
    return sizeAfter;
}

};

int main()
{
    Vector v = Vector();
    int num;
    int counting = 0;

    cout << setprecision(2)<< fixed;
    while (1) 
    {
        cin >> num;
        if (num == -9) break;
        v.addData(num);
    }
    while (1)
    {
        cin >> num;
        if(num == -9) break;
        v.removeData(num, counting); 
        counting++;
    }
    v. grmeanAfter();
    cout << v.getSize()<<""<<v.getSizeAfter()<<endl;
    cout << v.getMean()<<""<<v.getMeanAfter()<<endl;

    return 0;

    

    
}