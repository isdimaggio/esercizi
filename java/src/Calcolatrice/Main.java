package Calcolatrice;

import javax.swing.*;
import java.awt.*;

public class Main {

    public static void main(String[] args) {

        Gui gui = new Gui();

    }

    public JButton bottone(String titolo) {
        JButton button = new JButton();
        button.setFont(new Font("Courier", Font.PLAIN, 22));
        button.setMargin(new Insets(0, 0, 0, 0));
        button.setForeground(Color.WHITE);
        button.setOpaque(true);
        button.setBorderPainted(true);
        return button;
    }

}
