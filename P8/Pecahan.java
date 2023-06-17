import java.util.Scanner;

public class Bilangan {
    private int x;
    private int y;
    private int z;

    private int getGCD(int a, int b) {
        int c;
        while (b != 0) {
            c = a % b;
            a = b;
            b = c;
        }
        return a;
    }

    public Bilangan() {
        x = y = z = 0;
    }

    public Bilangan(int a1, int b1, int c1) {
        x = a1;
        z = b1;
        y = c1;
    }

    public void set(int a1, int b1, int c1) {
        x = a1;
        z = b1;
        y = c1;
    }

    public void print() {
        int gcd = getGCD(y, z);
        z /= gcd;
        y /= gcd;
        if (z == y) {
            x += z;
            System.out.println(x);
        } else {
            System.out.printf("%d %d/%d \n", x, z, y);
        }
    }

    public void mul(int a1, int b1, int c1) {
        x *= a1;
    }

    public Bilangan add(Bilangan bil) {
        x += bil.x;

        int c = y * bil.y / getGCD(y, bil.y);

        z = z * (c / y);

        bil.z = bil.z * (c / bil.z);

        z = z + bil.z;
        y = c;

        return this;
    }

    public Bilangan multiply(Bilangan bil) {
        x += bil.x;

        int c = y * bil.y / getGCD(y, bil.y);

        z = z*(c/y);
        bil.z=bil.z*(c/bil.z);
        z=z+bil.z;
        y=c;
    }
    
