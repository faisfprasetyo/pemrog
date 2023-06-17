import java.util.ArrayList;
import java.util.Scanner;

public class Vector {

    private ArrayList<Integer> v;
    private double mean;
    private double meanAfter;
    private int size;
    private int sizeAfter;

    public Vector() {
        v = new ArrayList<Integer>();
        mean = -9.99;
        meanAfter = -9.99;
        size = 0;
        sizeAfter = 0;
    }

    public void addData(int num) {
        v.add(num);
    }

    public void removeData(int index, int hasRemove) {
        v.remove(index - hasRemove - 1);
    }

    public void printData() {
        for (int i = 0; i < v.size(); i++) {
            System.out.println(v.get(i));
        }
    }

    public void grmean() {
        if (v.size() == 0) {
            mean = -9.99;
        } else {
            double sum = 0;
            for (int i = 0; i < v.size(); i++) {
                sum += v.get(i);
            }
            mean = sum / v.size();
            size = v.size();
        }
    }

    public void grmeanAfter() {
        if (v.size() == 0) {
            meanAfter = -9.99;
        } else {
            double sum = 0;
            for (int i = 0; i < v.size(); i++) {
                sum += v.get(i);
            }
            meanAfter = sum / v.size();
            sizeAfter = v.size();
        }
    }

    public double getMean() {
        return mean;
    }

    public double getMeanAfter() {
        return meanAfter;
    }

    public int getSize() {
        return size;
    }

    public int getSizeAfter() {
        return sizeAfter;
    }

    public static void main(String[] args) {
        Vector v = new Vector();
        Scanner scanner = new Scanner(System.in);
        int num;
        int counting = 0;

        System.out.printf("%.2f", v.getMean()); // mean awal
        System.out.println();

        while (true) {
            num = scanner.nextInt();
            if (num == -9) {
                break;
            }
            v.addData(num);
        }

        while (true) {
            num = scanner.nextInt();
            if (num == -9) {
                break;
            }
            v.removeData(num, counting);
            counting++;
        }

        v.grmeanAfter();

        System.out.print(v.getSize() + " ");
        System.out.println(v.getSizeAfter());

        System.out.printf("%.2f", v.getMean());
        System.out.print(" ");
        System.out.printf("%.2f", v.getMeanAfter());
        System.out.println();
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < v.size(); i++) {
            sb.append(v.get(i));
            sb.append("\n");
        }
        return sb.toString();
    }
}
