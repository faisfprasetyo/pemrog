#include <iostream>
#include<bits/stdc++.h>

using namespace std;

class Fraction {
private:
    int numerator;    // pembilang
    int denominator;  // penyebut
public:
    Fraction(int n = 0, int d = 1) {   // constructor
        numerator = n;
        denominator = d;
        simplify();   // panggil fungsi simplify untuk menyederhanakan pecahan
    }
    void simplify() {    // fungsi untuk menyederhanakan pecahan
        int gcd = __gcd(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
    }
    friend ostream& operator<<(ostream& os, const Fraction& f) {   // operator overloading untuk menampilkan pecahan
        if (f.numerator == 0) {
            os << "0";
        } else if (f.denominator == 1) {
            os << f.numerator;
        } else {
            os << f.numerator << " " << f.denominator;
        }
        return os;
    }
    Fraction operator+(const Fraction& f) const {   // operator overloading untuk penjumlahan
        int lcm = denominator * f.denominator / __gcd(denominator, f.denominator);
        int num = numerator * (lcm / denominator) + f.numerator * (lcm / f.denominator);
        Fraction result(num, lcm);
        return result;
    }
    Fraction operator*(const Fraction& f) const {   // operator overloading untuk perkalian
        Fraction result(numerator * f.numerator, denominator * f.denominator);
        return result;
    }
    Fraction& operator++() {   // operator overloading untuk postfix increment
        numerator += denominator;
        simplify();
        return *this;
    }
    Fraction& operator--() {   // operator overloading untuk postfix decrement
        numerator -= denominator;
        simplify();
        return *this;
    }
};

int main() {
    Fraction f;
    string cmd;
    while (cin >> cmd) {
        if (cmd == "set") {
            int a, b, c;
            cin >> a >> b >> c;
            f = Fraction(a * c + b, c);   // inisialisasi pecahan
        } else if (cmd == "p") {
            cout << f << endl;   // tampilkan pecahan
        } else if (cmd == "add") {
            int a, b, c;
            cin >> a >> b >> c;
            f = f + Fraction(a * c + b, c);   // tambahkan pecahan
        } else if (cmd == "mul") {
            int a, b, c;
            cin >> a >> b >> c;
            f = f * Fraction(a, c);   // kalikan pecahan
        } else if (cmd == "inc") {
            f++;   // postfix increment
        } else if (cmd == "dec") {
            f--;   // postfix decrement
        } else if (cmd == "end") {
            break;   // akhiri program
        }
    }
    return 0;
}
