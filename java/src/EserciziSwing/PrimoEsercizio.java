package EserciziSwing;

import javax.swing.*;
import java.awt.*;

public class PrimoEsercizio {

    public static void main(String[] args) {
        JFrame finestra = new JFrame("Esercizio");
        finestra.setSize(400, 400);
        finestra.setVisible(true);

        finestra.setLayout(new GridBagLayout());
        finestra.add(new JLabel("O"), new GridBagConstraints());
    }

}