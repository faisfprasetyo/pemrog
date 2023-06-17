#include <iostream>

#include <string>

using namespace std;

class Buku
{
public:
    Buku() {}

    Buku(string s) : judul(s) {}

    void display() { cout << judul << endl; }

private:
    string judul;

}

int main()
{
    Buku b = new Buku("Pemrograman Objek");

    b->display();

    return 0;
}