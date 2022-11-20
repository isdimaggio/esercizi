package EsercizioLibreria;

import java.util.ArrayList;
import java.util.List;
import java.util.Objects;

public class Scaffale {

    private List<Libro> listaLibri = new ArrayList<>();

    public void setPosScaffale(int pos, Libro libro) throws Exception {
        if (pos < 0) {
            throw new Exception("posizione invalida");
        }
        listaLibri.set(pos, libro);
    }

    public List<Libro> getListaLibri() {
        return listaLibri;
    }

    public int calcTotPagine() {
        int tot = 0;
        for (Libro libro : listaLibri) {
            if (libro != null) {
                tot += libro.getNumeroPagine();
            }
        }
        return tot;
    }

    public List<Libro> trovaLibri(String titolo, String autore) {
        List<Libro> trovati = new ArrayList<>();
        for (Libro libro : listaLibri) {
            if (libro != null) {
                //il libro esiste
                if (!Objects.equals(titolo, "")) {
                    // la ricerca per titolo deve essere fatta
                    if (libro.getTitolo().toLowerCase().contains(titolo.toLowerCase())) {
                        trovati.add(libro);
                    }
                }
                if (!Objects.equals(autore, "")) {
                    // la ricerca per autore deve essere fatta
                    if (libro.getTitolo().toLowerCase().contains(titolo.toLowerCase())) {
                        if (!trovati.contains(libro)) {
                            // se il libro non è gia in lista
                            trovati.add(libro);
                        }
                    }
                }
            }
        }
        return trovati;
    }
}
