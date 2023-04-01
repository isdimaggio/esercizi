package TabelleHashing;

public class Auto {

    private String targa;
    private String marca;
    private String modello;
    private String colore;
    private int km;

    public Auto(String targa, String marca, String modello, String colore, int km) {
        this.targa = targa;
        this.marca = marca;
        this.modello = modello;
        this.colore = colore;
        this.km = km;
    }

    public String getTarga() {
        return targa;
    }

    public void setTarga(String targa) {
        this.targa = targa;
    }

    public String getMarca() {
        return marca;
    }

    public void setMarca(String marca) {
        this.marca = marca;
    }

    public String getModello() {
        return modello;
    }

    public void setModello(String modello) {
        this.modello = modello;
    }

    public String getColore() {
        return colore;
    }

    public void setColore(String colore) {
        this.colore = colore;
    }

    public int getKm() {
        return km;
    }

    public void setKm(int km) {
        this.km = km;
    }

}
