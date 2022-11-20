package EsercizioLibreria;

public class Libro {

    private String titolo;
    private String autore;
    private int numeroPagine;
    private String genere;

    public Libro(
            String titolo,
            String autore,
            int numeroPagine,
            String genere
    ) throws Exception {
        //
        this.titolo = titolo;
        this.autore = autore;
        if (numeroPagine < 2) {
            throw new Exception("numero di pagine non valido");
        } else {
            this.numeroPagine = numeroPagine;
        }
        this.genere = genere;
    }

    public String getTitolo() {
        return titolo;
    }

    public void setTitolo(String titolo) {
        this.titolo = titolo;
    }

    public String getAutore() {
        return autore;
    }

    public void setAutore(String autore) {
        this.autore = autore;
    }

    public int getNumeroPagine() {
        return numeroPagine;
    }

    public void setNumeroPagine(int numeroPagine) throws Exception {
        if (numeroPagine < 2) {
            throw new Exception("numero di pagine non valido");
        } else {
            this.numeroPagine = numeroPagine;
        }
    }

    public String getGenere() {
        return genere;
    }

    public void setGenere(String genere) {
        this.genere = genere;
    }

}
