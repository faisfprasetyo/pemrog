import java.util.*;

class Barang {
    private int id;
    private int jumlah;
    private String kelompok;
    private String nama;
    
    public Barang(int id, int jumlah, String kelompok, String nama) {
        this.id = id;
        this.jumlah = jumlah;
        this.kelompok = kelompok;
        this.nama = nama;
    }
    
    public String getKelompok() {
        return kelompok;
    }
    
    public int getJumlah() {
        return jumlah;
    }
    
    public String getNama() {
        return nama;
    }
    
    public void print() {
        System.out.println(nama + " " + jumlah);
    }
}

class Kelompok {
    private String nama;
    private int jumlah;
    
    public Kelompok(String nama, int jumlah) {
        this.nama = nama;
        this.jumlah = jumlah;
    }
    
    public int getJumlah() {
        return jumlah;
    }
    
    public String getNama() {
        return nama;
    }
}

class Database {
    private List<Barang> barang;
    private Map<String, Integer> pairKelompok;
    private List<Kelompok> pasanganKelompok;
    
    public Database() {
        barang = new ArrayList<>();
        pairKelompok = new HashMap<>();
        pasanganKelompok = new ArrayList<>();
    }
    
    public void init() {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        
        for (int i = 0; i < n; i++) {
            int id = scanner.nextInt();
            String kelompok = scanner.next();
            String nama = scanner.next();
            int jumlah = scanner.nextInt();
            
            Barang item = new Barang(id, jumlah, kelompok, nama);
            barang.add(item);
            pairKelompok.put(kelompok, pairKelompok.getOrDefault(kelompok, 0) + 1);
        }
        
        Collections.sort(barang, Comparator.comparing(Barang::getNama));
        
        for (Map.Entry<String, Integer> entry : pairKelompok.entrySet()) {
            Kelompok temp = new Kelompok(entry.getKey(), entry.getValue());
            pasanganKelompok.add(temp);
        }
        
        pasanganKelompok.sort(Comparator.comparingInt(Kelompok::getJumlah).reversed());
        
        for (Kelompok kelompok : pasanganKelompok) {
            System.out.println(kelompok.getNama() + " " + kelompok.getJumlah());
        }
        
        System.out.println("*****");
        
        scanner.close();
    }
    
    public void query() {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        
        for (int i = 0; i < n; i++) {
            String kelompok = scanner.next();
            System.out.println("Daftar Barang " + kelompok);
            
            for (Barang item : barang) {
                if (item.getKelompok().equals(kelompok)) {
                    item.print();
                }
            }
            
            if (i < n - 1) {
                System.out.println("*****");
            }
        }
        
        scanner.close();
    }
}

public class Main {
    public static void main(String[] args) {
        Database database = new Database();
        database.init();
        database.query();
    }
}

