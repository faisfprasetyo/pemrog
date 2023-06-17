import java.util.Scanner;
import java.util.ArrayList;

abstract class Bilangan {
    abstract public void print();
}

class BilanganDesimal extends Bilangan {
    public double nilai;

    BilanganDesimal(double nilai) {
        this.nilai = nilai;
    }

    public void add(BilanganDesimal b) {
        this.nilai += b.nilai;
    }

    public void print() {
        System.out.printf("%.2f\n", nilai);
    }
}

class BilanganPecahan extends Bilangan {
    public int pembilang;
    public int penyebut;

    BilanganPecahan(int pembilang, int penyebut) {
        this.pembilang = pembilang;
        this.penyebut = penyebut;
    }

    void add(BilanganPecahan b) {
        int p = this.pembilang;
        int q = this.penyebut;
        int r = b.pembilang;
        int s = b.penyebut;

        this.pembilang = p * s + q * r;
        this.penyebut = q * s;

        // Disederhanakan dengan FPB
        int gcd = gcd(this.pembilang, this.penyebut);
        this.pembilang /= gcd;
        this.penyebut /= gcd;
    }

    private int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    public void print() {
        System.out.println(pembilang + " " + penyebut);
    }
}

abstract class Operasi {
    abstract void add();
}

class OperasiDesimal extends Operasi {
    public BilanganDesimal a;
    public BilanganDesimal b;

    OperasiDesimal(BilanganDesimal a, BilanganDesimal b) {
        this.a = a;
        this.b = b;
    }

    void add() {
        a.add(b);
        a.print();
    }
}

class OperasiPecahan extends Operasi {
    public BilanganPecahan a;
    public BilanganPecahan b;

    OperasiPecahan(BilanganPecahan a, BilanganPecahan b) {
        this.a = a;
        this.b = b;
    }

    void add() {
        a.add(b);
        a.print();
    }

}

public class Mainmainmain {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        ArrayList<Operasi> operasi = new ArrayList<Operasi>();

        for (int i = 0; i < n; i++) {
            int jenis = sc.nextInt();
            if (jenis == 1) {
                BilanganDesimal a = new BilanganDesimal(sc.nextDouble());
                BilanganDesimal b = new BilanganDesimal(sc.nextDouble());
                OperasiDesimal o = new OperasiDesimal(a, b);
                operasi.add(o);
            } else {
                BilanganPecahan a = new BilanganPecahan(sc.nextInt(), sc.nextInt());
                BilanganPecahan b = new BilanganPecahan(sc.nextInt(), sc.nextInt());
                OperasiPecahan o = new OperasiPecahan(a, b);
                operasi.add(o);
            }
        }

        int startIndex = sc.nextInt();
        int endIndex = sc.nextInt();

        for (int i = startIndex - 1; i < endIndex; i++) {
            Operasi o = operasi.get(i);
            o.add();
        }

        sc.close();
    }
}