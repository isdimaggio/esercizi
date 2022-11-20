package Calcolatrice;

import javax.swing.*;
import javax.swing.border.Border;
import javax.swing.border.EmptyBorder;
import java.awt.*;

public class Gui extends JFrame {

    public Gui() {
        super("Cacolatrice");

        setSize(250, 390);
        setLocation(600, 200);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setDefaultLookAndFeelDecorated(true);
        setResizable(true);
        setVisible(true);

        JPanel pane = new JPanel();

        JButton button;
        pane.setLayout(new GridBagLayout());
        GridBagConstraints c = new GridBagConstraints();
        c.weighty = 1;
        c.weightx = 0.5;
        c.fill = GridBagConstraints.BOTH;

        // display
        JLabel disp = new JLabel("1337", SwingConstants.RIGHT);
        disp.setBorder(new EmptyBorder(0, 0, 0, 10));
        disp.setFont(new Font("Courier", Font.PLAIN, 45));
        disp.setForeground(Color.WHITE);
        c.gridwidth = 4;
        c.gridx = 0;
        c.gridy = 0;
        pane.add(disp, c);

        // PRIMA RIGA DI TASTI
        button = bottone("C");
        button.setBackground(new Color(68, 66, 62));
        button.setBorder(bordoChad(true, true));
        c.gridwidth = 1;
        c.gridx = 0;
        c.gridy = 1;
        pane.add(button, c);

        button = bottone("\u00B1");
        button.setBackground(new Color(68, 66, 62));
        button.setBorder(bordoChad(true, true));
        c.gridx = 1;
        c.gridy = 1;
        pane.add(button, c);

        button = bottone("%");
        button.setBackground(new Color(68, 66, 62));
        button.setBorder(bordoChad(true, true));
        c.gridx = 2;
        c.gridy = 1;
        pane.add(button, c);

        button = bottone("\u00F7");
        button.setBackground(new Color(207, 140, 52));
        button.setBorder(bordoChad(true, false));
        c.gridx = 3;
        c.gridy = 1;
        pane.add(button, c);

        // SECONDA RIGA DI TASTI
        button = bottone("7");
        button.setBackground(new Color(98, 95, 94));
        button.setBorder(bordoChad(true, true));
        c.gridx = 0;
        c.gridy = 2;
        pane.add(button, c);

        button = bottone("8");
        button.setBackground(new Color(98, 95, 94));
        button.setBorder(bordoChad(true, true));
        c.gridx = 1;
        c.gridy = 2;
        pane.add(button, c);

        button = bottone("9");
        button.setBackground(new Color(98, 95, 94));
        button.setBorder(bordoChad(true, true));
        c.gridx = 2;
        c.gridy = 2;
        pane.add(button, c);

        button = bottone("X");
        button.setBackground(new Color(207, 140, 52));
        button.setBorder(bordoChad(true, false));
        c.gridx = 3;
        c.gridy = 2;
        pane.add(button, c);


        // TERZA RIGA DI TASTI
        button = bottone("4");
        button.setBackground(new Color(98, 95, 94));
        button.setBorder(bordoChad(true, true));
        c.gridx = 0;
        c.gridy = 3;
        pane.add(button, c);

        button = bottone("5");
        button.setBackground(new Color(98, 95, 94));
        button.setBorder(bordoChad(true, true));
        c.gridx = 1;
        c.gridy = 3;
        pane.add(button, c);

        button = bottone("6");
        button.setBackground(new Color(98, 95, 94));
        button.setBorder(bordoChad(true, true));
        c.gridx = 2;
        c.gridy = 3;
        pane.add(button, c);

        button = bottone("-");
        button.setBackground(new Color(207, 140, 52));
        button.setBorder(bordoChad(true, false));
        c.gridx = 3;
        c.gridy = 3;
        pane.add(button, c);

        // QUARTA RIGA DI TASTI
        button = bottone("1");
        button.setBackground(new Color(98, 95, 94));
        button.setBorder(bordoChad(true, true));
        c.gridx = 0;
        c.gridy = 4;
        pane.add(button, c);

        button = bottone("2");
        button.setBackground(new Color(98, 95, 94));
        button.setBorder(bordoChad(true, true));
        c.gridx = 1;
        c.gridy = 4;
        pane.add(button, c);

        button = bottone("3");
        button.setBackground(new Color(98, 95, 94));
        button.setBorder(bordoChad(true, true));
        c.gridx = 2;
        c.gridy = 4;
        pane.add(button, c);

        button = bottone("+");
        button.setBackground(new Color(207, 140, 52));
        button.setBorder(bordoChad(true, false));
        c.gridx = 3;
        c.gridy = 4;
        pane.add(button, c);

        // QUINTA RIGA CON TASTO DEFORME
        button = bottone("0");
        button.setBackground(new Color(98, 95, 94));
        button.setBorder(bordoChad(false, true));
        c.gridwidth = 2;
        c.gridx = 0;
        c.gridy = 5;
        pane.add(button, c);

        button = bottone(",");
        button.setBackground(new Color(98, 95, 94));
        button.setBorder(bordoChad(false, true));
        c.gridwidth = 1;
        c.gridx = 2;
        c.gridy = 5;
        pane.add(button, c);

        button = bottone("=");
        button.setBackground(new Color(207, 140, 52));
        button.setBorder(bordoChad(false, false));
        c.gridx = 3;
        c.gridy = 5;
        pane.add(button, c);

        pane.setBackground(new Color(34, 34, 34));

        add(pane);

        //repaint della finestra
        validate();
        repaint();

    }

    public Border bordoChad(boolean bottom, boolean right) {
        return BorderFactory.createMatteBorder(
                0,
                0,
                bottom ? 1 : 0,
                right ? 1 : 0,
                new Color(34, 34, 34)
        );
    }

    public JButton bottone(String titolo) {
        JButton button = new JButton(titolo);
        button.setFont(new Font("Courier", Font.PLAIN, 22));
        button.setMargin(new Insets(0, 0, 0, 0));
        button.setForeground(Color.WHITE);
        button.setOpaque(true);
        button.setBorderPainted(true);
        return button;
    }

}
