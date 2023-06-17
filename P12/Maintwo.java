import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

interface Bilangan {
    void sum();
    void print();
}

class Bildes implements Bilangan {
    private double a;
    private double b;
    private double nilai;

    Bildes(double x, double y) {
        a = x;
        b = y;
    }

    public void sum() {
        nilai = a + b;
    }

    public void print() {
        System.out.printf("%.2f\n", nilai);
    }
}

class Bilpec implements Bilangan {
    private int pembilang;
    private int penyebut;
    private int p;
    private int q;
    private int r;
    private int s;

    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        } else {
            return gcd(b, a % b);
        }
    }

    Bilpec(int w, int x, int y, int z) {
        p = w;
        q = x;
        r = y;
        s = z;
    }

    public void sum() {
        pembilang = p * s + q * r;
        penyebut = q * s;
        int x = gcd(pembilang, penyebut);
        pembilang /= x;
        penyebut /= x;
    }

    public void print() {
        System.out.println(pembilang + " " + penyebut);
    }
}

public class Maintwo {
    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        List<Bilangan> bilangan = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            int type = scanner.nextInt();
            if (type == 1) {
                Bilangan desimal = new Bildes(scanner.nextDouble(), scanner.nextDouble());
                desimal.sum();
                bilangan.add(desimal);
            } else {
                Bilangan pecahan = new Bilpec(scanner.nextInt(), scanner.nextInt(), scanner.nextInt(), scanner.nextInt());
                pecahan.sum();
                bilangan.add(pecahan);
            }
        }
        int awal = scanner.nextInt();
        int akhir = scanner.nextInt();
        for (int i = awal - 1; i < akhir; i++) {
            bilangan.get(i).print();
        }
        scanner.close();
    }
}