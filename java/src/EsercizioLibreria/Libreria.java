package EsercizioLibreria;

import java.util.ArrayList;
import java.util.List;

public class Libreria {

    private List<Scaffale> scaffali = new ArrayList<>();

    public void inserisciLibro(int scaffale, int posDentroScaffale, Libro libro) throws Exception {
        if (scaffali.get(scaffale) == null) {
            throw new Exception("posizione invalida");
        }
        scaffali.get(scaffale).setPosScaffale(posDentroScaffale, libro);
    }

    public List<Libro> visualizzaLibriScaffale(int scaffale) throws Exception {
        if (scaffali.get(scaffale) == null) {
            throw new Exception("posizione invalida");
        }
        return scaffali.get(scaffale).getListaLibri();
    }

    public List<Libro> listaLibriLibreria() {
        List<Libro> listaLibri = new ArrayList<>();
        for (Scaffale scaffale : scaffali) {
            listaLibri.addAll(scaffale.getListaLibri());
        }
        return listaLibri;
    }

    public int calcPagScaffale(int scaffale) throws Exception {
        if (scaffali.get(scaffale) == null) {
            throw new Exception("posizione invalida");
        }
        return scaffali.get(scaffale).calcTotPagine();
    }

}
