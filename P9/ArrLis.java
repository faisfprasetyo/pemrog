import java.util.*;
import java.util.Scanner;
import java.text.DecimalFormat;

class Bil {
    private ArrayList<Integer> list = new ArrayList<Integer>();
    private int counter = 0;
    private double sum = 0.00;

    Bil() {

    }

    public void setNilai(int a) {
        list.add(a);
    }

    public void del(int n) {
        list.remove(n - 1 - counter);
        counter++;
    }

    double mean() {
        sum = 0.00;
        for (int i = 0; i < list.size(); i++) {
            sum += list.get(i);
        }
        return sum / list.size();
    }

    public int sizeFirst() {
        return list.size();
    }

    public int sizeLast() {
        return list.size();
    }
};

public class ArrLis {
    public static void main(String[] args) {
        Bil b = new Bil();

        Scanner inp = new Scanner(System.in);
        int n = inp.nextInt();

        while (n != -9) {
            b.setNilai(n);
            n = inp.nextInt();
        }

        int sizeAwal = b.sizeFirst();
        double meanAwal = b.mean();
        n = inp.nextInt();

        while (n != -9) {
            b.del(n);
            n = inp.nextInt();
        }
        int sizeAkhir = b.sizeLast();
        double meanAkhir = b.mean();

        DecimalFormat df = new DecimalFormat("0.00");

        System.out.println(sizeAwal + " " + sizeAkhir);
        System.out.println(df.format(meanAwal) + " " + df.format(meanAkhir));

        inp.close();
    }
}