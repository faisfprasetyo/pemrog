import java.util.Scanner;
import java.util.ArrayList;

abstract class Bilangan{
    abstract public void print();
    abstract public void sum();
}

class Bildes extends Bilangan{
    public double a;
    public double b;
    public double nilai;

    Bildes(double x, double y){
        a=x;
        b=y;
    }

    public void sum(){
        nilai=a+b;
    }

    public void print(){
        System.out.printf("%.2f\n", nilai);
    }
}

class Bilpec extends Bilangan{
    public int pembilang;
    public int penyebut;
    public int p;
    public int q;
    public int r;
    public int s;
    int gcd(int a, int b){
        if(b==0){
            return a;
        }
        else{
            return gcd(b, a%b);
        }
    }
    
    Bilpec(int w, int x, int y, int z){
        p=w;
        q=x;
        r=y;
        s=z;
    }

    public void sum(){
        pembilang=p*s+q*r;
        penyebut=q*s;
        int x=gcd(pembilang, penyebut);
        pembilang/=x;
        penyebut/=x;
    }

    public void print(){
        System.out.println(pembilang + " " + penyebut);
    }
}

public class Main{
    public static void main(String args[]){
        Scanner scanner=new Scanner(System.in);
        int n=scanner.nextInt();
        ArrayList<Bilangan> bilangan=new ArrayList<Bilangan>();

        for(int i=0; i<n; i++){
            int type=scanner.nextInt();
            if(type==1){
                Bilangan desimal = new Bildes(scanner.nextDouble(), scanner.nextDouble());
                desimal.sum();
                bilangan.add(desimal);
            }
            else{
                Bilangan pecahan = new Bilpec(scanner.nextInt(), scanner.nextInt(), scanner.nextInt(), scanner.nextInt());
                pecahan.sum();
                bilangan.add(pecahan);
            }
        }
        int awal=scanner.nextInt();
        int akhir=scanner.nextInt();
        for(int i=awal-1; i<akhir; i++){
            bilangan.get(i).print();
        }
    }
}