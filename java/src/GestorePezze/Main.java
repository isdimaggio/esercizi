package GestorePezze;

import java.awt.*;
import java.util.Objects;
import java.util.Scanner;

public class Main {

    private static Pezza[] pezze = new Pezza[10];

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        for (int i = 0; i < 10; i++) {
            pezze[i] = new Pezza(randPosition(), randDimension(), randColor());
        }

        System.out.println("USAGE");
        System.out.println(" add {index}                | aggiunge una pezza alla pos. specificata");
        System.out.println(" remove {index}             | toglie una pezza dalla pos. specificata");
        System.out.println(" dim {index} {w} {h}        | imposta altezza e larghezza");
        System.out.println(" col {index} {r} {g} {b}    | imposta il colore");
        System.out.println(" pos {index} {x} {y}        | imposta la posizione");
        System.out.println(" exit                       | elimina tutto ed esce");
        System.out.println();

        do {
            System.out.print("> ");
            String[] commandLine = sc.nextLine().split("\\s+");

            if (commandLine[0].contains("exit"))
                return;

            if (commandLine.length < 2) {
                System.out.println("Comando non riconosciuto");
                continue;
            }

            switch (commandLine[0]) {
                case "add" -> {
                    if (commandLine.length != 2) {
                        System.out.println("Argomenti invalidi");
                        continue;
                    }
                    int index = Integer.parseInt(commandLine[1]);
                    if (index > 10 || index < 0) {
                        System.out.println("Posizione array non valida.");
                        continue;
                    }
                    pezze[index].setVisible(true);
                    pezze[index].toFront();
                    pezze[index].repaint();
                }
                case "remove" -> {
                    if (commandLine.length != 2) {
                        System.out.println("Argomenti invalidi");
                        continue;
                    }
                    int index = Integer.parseInt(commandLine[1]);
                    if (index > 10 || index < 0) {
                        System.out.println("Posizione array non valida.");
                        continue;
                    }
                    pezze[index].setVisible(false);
                    pezze[index].toFront();
                    pezze[index].repaint();
                }
                case "dim" -> {
                    if (commandLine.length != 4) {
                        System.out.println("Argomenti invalidi");
                        continue;
                    }
                    int index = Integer.parseInt(commandLine[1]);
                    if (index > 10 || index < 0) {
                        System.out.println("Posizione array non valida.");
                        continue;
                    }
                    int dimensionW = Integer.parseInt(commandLine[2]);
                    if (dimensionW > 900 || dimensionW < 20) {
                        System.out.println("Dimensione W non valida");
                        continue;
                    }
                    int dimensionH = Integer.parseInt(commandLine[3]);
                    if (dimensionH > 900 || dimensionH < 20) {
                        System.out.println("Dimensione H non valida");
                        continue;
                    }
                    pezze[index].setSize(new Dimension(dimensionW, dimensionH));
                }
                case "col" -> {
                    if (commandLine.length != 5) {
                        System.out.println("Argomenti invalidi");
                        continue;
                    }
                    int index = Integer.parseInt(commandLine[1]);
                    if (index > 10 || index < 0) {
                        System.out.println("Posizione array non valida.");
                        continue;
                    }
                    int red = Integer.parseInt(commandLine[1]);
                    if (red > 255 || red < 0) {
                        System.out.println("colore rosso non valido");
                        continue;
                    }
                    int green = Integer.parseInt(commandLine[1]);
                    if (green > 255 || green < 0) {
                        System.out.println("colore verde non valido");
                        continue;
                    }
                    int blue = Integer.parseInt(commandLine[1]);
                    if (blue > 255 || blue < 0) {
                        System.out.println("colore blu non valido");
                        continue;
                    }
                    pezze[index].setBackground(new Color(red, green, blue));
                }
                case "pos" -> {
                    if (commandLine.length != 4) {
                        System.out.println("Argomenti invalidi");
                        continue;
                    }
                    int index = Integer.parseInt(commandLine[1]);
                    if (index > 10 || index < 0) {
                        System.out.println("Posizione array non valida.");
                        continue;
                    }
                    int x = Integer.parseInt(commandLine[2]);
                    if (x > 900 || x < 20) {
                        System.out.println("Posizione X non valida");
                        continue;
                    }
                    int y = Integer.parseInt(commandLine[3]);
                    if (y > 900 || y < 20) {
                        System.out.println("Posizione Y non valida");
                        continue;
                    }
                    pezze[index].setLocation(new Point(x, y));
                }
                default -> System.out.println("Comando sconosciuto");
            }

        } while (!Objects.equals(sc.nextLine(), "exit"));

    }

    public static Dimension randDimension() {
        return new Dimension(randNum(100, 900), randNum(100, 900));
    }

    public static Point randPosition() {
        return new Point(randNum(100, 900), randNum(100, 900));
    }

    public static Color randColor() {
        return new Color(randNum(0, 255), randNum(0, 255), randNum(0, 255));
    }

    public static int randNum(int min, int max) {
        return (int) ((Math.random() * (max - min)) + min);
    }

}
