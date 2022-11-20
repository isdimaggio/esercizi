package GestorePezze;

import javax.swing.*;
import java.awt.*;

public class Pezza extends JFrame {

    public Pezza(Point posizione, Dimension dimensione, Color colore) {
        super("pezza");
        this.setUndecorated(true);
        this.setSize(dimensione);
        this.setLocation(posizione);
        this.getContentPane().setBackground(colore);
    }

    @Override
    public void setBackground(Color bgColor) {
        super.getContentPane().setBackground(bgColor);
    }
}
