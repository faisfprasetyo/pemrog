#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

class Person
{
private:
    string nama;
    int usia;
    int tinggi;
    double berat;
public:
    Person(){
        nama = " ";
        usia = 0;
        tinggi = 0;
        berat = 0.0;
    }

    void set(string nama1, int usia1, int tinggi1, double berat1 ){
        nama = nama1;
        usia = usia1;
        tinggi = tinggi1;
        berat = berat1;
    }

    void print(){
        cout<< nama<< ""<< usia << endl;
    }

    double get(){
        return tinggi;
    }

    
};

int main(){
    cout<< setprecision(2) << fixed;
    int n;
    cin >> n;

    string nama;
    int usia;
    int tinggi;
    double berat;

    double mean=0.0;

    Person obj[n];

    for(int i = 0; i<n; i++){
        cin>> nama>> usia>> tinggi>> berat;
        obj[i].set(nama, usia, tinggi, berat);
    	mean += tinggi;
    }

    mean = mean / n;

    int above_mean=0;

    for(int i = 0; i<n;i++){
        obj[i].print();
        
        if (obj[i].get() > mean){
            above_mean++;
        }
    }
    
    cout << mean <<endl;
    cout << above_mean <<endl;
    
}