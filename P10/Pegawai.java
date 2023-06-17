import java.util.*;

class Pegawaio{
protected String id;
protected int usia;
protected int tipe;
protected int income;
public Pegawaio() {id=" "; usia=income=0; tipe=1;}
public void set(String pid, int u, int t) {id=pid; usia=u; tipe=t;}
public String getID () {return id;}
public void show() {System.out.printf("%s %d %d\n", id, tipe, income);}
};

class Tetap extends Pegawaio{
    public void setIncome(int income){
        super.income += income;
    }
}
class Harian extends Pegawaio{
    public void setIncome(int income){
        super.income += income;
    }
}
public class Pegawai{
    public static void main(String []args) {
        Vector<Tetap> tetapo=new Vector<Tetap>();
        Vector<Harian> hariano=new Vector<Harian>();

        Scanner input = new Scanner(System.in);

        int n = input.nextInt();

        for(int i=0; i<n; i++) {
            String id=input.next();
            int usia=input.nextInt();
            int tipe=input.nextInt();

            if(tipe==1){
                Tetap tetap=new Tetap();
                int pokok=input.nextInt();
                tetap.set(id, usia, tipe);
                tetap.setIncome(pokok);
                tetapo.add(tetap);
            }else{
                Harian harian=new Harian();
                harian.set(id, usia, tipe);
                hariano.add(harian);
            }
        }
        String id=input.next();
        while(!id.equals("END")){
            for(int i = 0; i<tetapo.size() ; i++){
                if(id.equals(tetapo.get(i).getID()) ){
                    int pokok = input.nextInt();
                    tetapo.get(i).setIncome(pokok);
                    break;
                }
            }
            for(int i = 0; i<hariano.size() ; i++){
                if(id.equals(hariano.get(i).getID())){
                    int pokok = input.nextInt();
                   hariano.get(i).setIncome(pokok);
                   break;
                }
            }
            id = input.next();
        }

        for(int i = 0; i<tetapo.size() ; i++){
           tetapo.get(i).show();
        }
        for(int i = 0; i<hariano.size() ; i++){
           hariano.get(i).show();
        }

        

        input.close();
    }

};