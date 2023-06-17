import java.util.Scanner;

public class person {
    private String nama;
    private int usia;
    private int tinggi;
    private double berat;

    public person() {
        nama = "";
        usia = 0;
        tinggi = 0;
        berat = 0.0;
    }

    public void set(String nama1, int usia1, int tinggi1, double berat1) {
        nama = nama1;
        usia = usia1;
        tinggi = tinggi1;
        berat = berat1;
    }

    public void print() {
        System.out.println(nama + " " + usia);
    }

    public double get() {
        return tinggi;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.printf("%.2f\n", input);
        int n = input.nextInt();
        input.nextLine();

        String nama;
        int usia;
        int tinggi;
        double berat;
        double mean = 0.0;
        Person[] obj = new Person[n];

        for (int i = 0; i < n; i++) {
            nama = input.next();
            usia = input.nextInt();
            tinggi = input.nextInt();
            berat = input.nextDouble();
            obj[i] = new Person();
            obj[i].set(nama, usia, tinggi, berat);
            mean += tinggi;
        }

        mean = mean / n;

        int above_mean = 0;

        for (int i = 0; i < n; i++) {
            obj[i].print();

            if (obj[i].getTinggi() > mean) {
                above_mean++;
            }
        }

        System.out.println(mean);
        System.out.println(above_mean);
    }
}
