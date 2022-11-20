package FinestreCasuali;

import javax.swing.*;
import java.awt.*;

public class Main {

    public static void main(String[] args) {
        JFrame[] finestre = new JFrame[4];
        for (JFrame finestra : finestre) {
            finestra = new JFrame("random");
            finestra.setSize(randDimension(100, 900));
            finestra.setLocation(
                    new Point(
                            randNum(100, 900),
                            randNum(100, 900)
                    )
            );
            finestra.setVisible(true);
            finestra.getContentPane().setBackground(new Color(
                    randNum(0, 255),
                    randNum(0, 255),
                    randNum(0, 255)
            ));
        }
    }

    public static Dimension randDimension(int min, int max) {
        return new Dimension(randNum(min, max), randNum(min, max));
    }

    public static int randNum(int min, int max) {
        return (int) ((Math.random() * (max - min)) + min);
    }

}
