import java.util.*;

abstract class Tanah {
protected double area;  
abstract double getArea();

}

class Persegi_Panjang extends Tanah {
  protected double panjang;
  protected double lebar;

  Persegi_Panjang(double a, double b) {
    panjang = a;
    lebar = b;
  }

  public double getpanjang() {
    return panjang;
  }

  public double getlebar() {
    return lebar;
  }

  public double getArea() {
    return 2*(panjang + lebar);
  }
}

class Lingkaran extends Tanah {
  protected double radius;

  Lingkaran(double a) {
    radius = a;
  }

  public double getradius() {
    return radius;
  }

  public double getArea() {
    return Math.PI * radius * 2;
  }
}

public class Pagtan{
  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    Vector<Double> v = new Vector<Double>();
    

    int n, jenis;
    double a, b,rataan1 =0, rataan2=0 ;

    n = s.nextInt();

    for (int i = 0; i < n; i++) {
      jenis = s.nextInt();
      if (jenis == 0) {
        a = s.nextDouble();
        b = s.nextDouble();
        Persegi_Panjang PP = new Persegi_Panjang(a, b);
        v.add(PP.getArea());
        rataan1 +=PP.getArea();

      } else if (jenis == 1) {
        a = s.nextDouble();
        Lingkaran L = new Lingkaran(a);
        v.add(L.getArea());
        rataan1 += L.getArea();
      }
    }
    rataan1 /= n;

    for (int i = 0; i < v.size(); i++) {
      if (rataan1 < v.get(i)) {
        rataan2 += v.get(i);
      }
    }
    System.out.printf("%.2f",rataan2);
    s.close();

  }
}