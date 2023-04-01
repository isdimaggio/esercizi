package Calcolatrice;

import javax.swing.*;
import javax.swing.border.Border;
import javax.swing.border.EmptyBorder;
import java.awt.*;

public class Gui extends JFrame {

    private float registro1 = 0;
    private float registro2 = 0;
    private boolean registro2Attivo = false;
    private boolean decimaleAttivo1 = false;
    private boolean decimaleAttivo2 = false;
    private int cifreDec1 = 0;
    private int cifreDec2 = 0;
    private char operando = 'n';
    private boolean risultatoOttenuto = false;
    private boolean decimaliPermessi = false;

    private final JLabel displayPrincipale;
    private final JLabel displaySecondario;

    public Gui() {
        super("Cacolatrice");

        setSize(250, 390);
        setLocation(600, 200);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setDefaultLookAndFeelDecorated(true);
        setResizable(true);
        setVisible(true);

        JPanel pane = new JPanel();

        JButton templatePulsante;
        pane.setLayout(new GridBagLayout());
        GridBagConstraints layout = new GridBagConstraints();
        layout.weighty = 1;
        layout.weightx = 0.5;
        layout.fill = GridBagConstraints.BOTH;

        // display superiore
        displaySecondario = new JLabel("0", SwingConstants.RIGHT);
        displaySecondario.setBorder(new EmptyBorder(0, 0, -15, 10));
        displaySecondario.setFont(new Font("Courier", Font.PLAIN, 15));
        displaySecondario.setForeground(Color.WHITE);
        layout.gridwidth = 4;
        layout.gridx = 0;
        layout.gridy = 0;
        pane.add(displaySecondario, layout);

        // display
        displayPrincipale = new JLabel("0", SwingConstants.RIGHT);
        displayPrincipale.setBorder(new EmptyBorder(0, 0, 0, 10));
        displayPrincipale.setFont(new Font("Courier", Font.PLAIN, 45));
        displayPrincipale.setForeground(Color.WHITE);
        layout.gridwidth = 4;
        layout.gridx = 0;
        layout.gridy = 1;
        pane.add(displayPrincipale, layout);

        // PRIMA RIGA DI TASTI
        templatePulsante = creaBottoneStandard("C");
        templatePulsante.addActionListener(e -> clear());
        templatePulsante.setBackground(new Color(68, 66, 62));
        templatePulsante.setBorder(bordoPulsanti(true, true));
        layout.gridwidth = 1;
        layout.gridx = 0;
        layout.gridy = 2;
        pane.add(templatePulsante, layout);

        templatePulsante = creaBottoneStandard("\u00B1");
        templatePulsante.addActionListener(e -> cambioSegno());
        templatePulsante.setBackground(new Color(68, 66, 62));
        templatePulsante.setBorder(bordoPulsanti(true, true));
        layout.gridx = 1;
        layout.gridy = 2;
        pane.add(templatePulsante, layout);

        templatePulsante = creaBottoneStandard("%");
        templatePulsante.addActionListener(e -> percentuale());
        templatePulsante.setBackground(new Color(68, 66, 62));
        templatePulsante.setBorder(bordoPulsanti(true, true));
        layout.gridx = 2;
        layout.gridy = 2;
        pane.add(templatePulsante, layout);

        templatePulsante = creaBottoneStandard("\u00F7");
        templatePulsante.addActionListener(e -> divisione());
        templatePulsante.setBackground(new Color(207, 140, 52));
        templatePulsante.setBorder(bordoPulsanti(true, false));
        layout.gridx = 3;
        layout.gridy = 2;
        pane.add(templatePulsante, layout);

        // SECONDA RIGA DI TASTI
        templatePulsante = creaBottoneStandard("7");
        templatePulsante.addActionListener(e -> push(7));
        templatePulsante.setBackground(new Color(98, 95, 94));
        templatePulsante.setBorder(bordoPulsanti(true, true));
        layout.gridx = 0;
        layout.gridy = 3;
        pane.add(templatePulsante, layout);

        templatePulsante = creaBottoneStandard("8");
        templatePulsante.addActionListener(e -> push(8));
        templatePulsante.setBackground(new Color(98, 95, 94));
        templatePulsante.setBorder(bordoPulsanti(true, true));
        layout.gridx = 1;
        layout.gridy = 3;
        pane.add(templatePulsante, layout);

        templatePulsante = creaBottoneStandard("9");
        templatePulsante.addActionListener(e -> push(9));
        templatePulsante.setBackground(new Color(98, 95, 94));
        templatePulsante.setBorder(bordoPulsanti(true, true));
        layout.gridx = 2;
        layout.gridy = 3;
        pane.add(templatePulsante, layout);

        templatePulsante = creaBottoneStandard("X");
        templatePulsante.addActionListener(e -> moltiplicazione());
        templatePulsante.setBackground(new Color(207, 140, 52));
        templatePulsante.setBorder(bordoPulsanti(true, false));
        layout.gridx = 3;
        layout.gridy = 3;
        pane.add(templatePulsante, layout);


        // TERZA RIGA DI TASTI
        templatePulsante = creaBottoneStandard("4");
        templatePulsante.addActionListener(e -> push(4));
        templatePulsante.setBackground(new Color(98, 95, 94));
        templatePulsante.setBorder(bordoPulsanti(true, true));
        layout.gridx = 0;
        layout.gridy = 4;
        pane.add(templatePulsante, layout);

        templatePulsante = creaBottoneStandard("5");
        templatePulsante.addActionListener(e -> push(5));
        templatePulsante.setBackground(new Color(98, 95, 94));
        templatePulsante.setBorder(bordoPulsanti(true, true));
        layout.gridx = 1;
        layout.gridy = 4;
        pane.add(templatePulsante, layout);

        templatePulsante = creaBottoneStandard("6");
        templatePulsante.addActionListener(e -> push(6));
        templatePulsante.setBackground(new Color(98, 95, 94));
        templatePulsante.setBorder(bordoPulsanti(true, true));
        layout.gridx = 2;
        layout.gridy = 4;
        pane.add(templatePulsante, layout);

        templatePulsante = creaBottoneStandard("-");
        templatePulsante.addActionListener(e -> sottrazione());
        templatePulsante.setBackground(new Color(207, 140, 52));
        templatePulsante.setBorder(bordoPulsanti(true, false));
        layout.gridx = 3;
        layout.gridy = 4;
        pane.add(templatePulsante, layout);

        // QUARTA RIGA DI TASTI
        templatePulsante = creaBottoneStandard("1");
        templatePulsante.addActionListener(e -> push(1));
        templatePulsante.setBackground(new Color(98, 95, 94));
        templatePulsante.setBorder(bordoPulsanti(true, true));
        layout.gridx = 0;
        layout.gridy = 5;
        pane.add(templatePulsante, layout);

        templatePulsante = creaBottoneStandard("2");
        templatePulsante.addActionListener(e -> push(2));
        templatePulsante.setBackground(new Color(98, 95, 94));
        templatePulsante.setBorder(bordoPulsanti(true, true));
        layout.gridx = 1;
        layout.gridy = 5;
        pane.add(templatePulsante, layout);

        templatePulsante = creaBottoneStandard("3");
        templatePulsante.addActionListener(e -> push(3));
        templatePulsante.setBackground(new Color(98, 95, 94));
        templatePulsante.setBorder(bordoPulsanti(true, true));
        layout.gridx = 2;
        layout.gridy = 5;
        pane.add(templatePulsante, layout);

        templatePulsante = creaBottoneStandard("+");
        templatePulsante.addActionListener(e -> addizione());
        templatePulsante.setBackground(new Color(207, 140, 52));
        templatePulsante.setBorder(bordoPulsanti(true, false));
        layout.gridx = 3;
        layout.gridy = 5;
        pane.add(templatePulsante, layout);

        // QUINTA RIGA CON TASTO DEFORME
        templatePulsante = creaBottoneStandard("0");
        templatePulsante.addActionListener(e -> push(0));
        templatePulsante.setBackground(new Color(98, 95, 94));
        templatePulsante.setBorder(bordoPulsanti(false, true));
        layout.gridwidth = 2;
        layout.gridx = 0;
        layout.gridy = 6;
        pane.add(templatePulsante, layout);

        templatePulsante = creaBottoneStandard(",");
        templatePulsante.addActionListener(e -> decimale());
        templatePulsante.setBackground(new Color(98, 95, 94));
        templatePulsante.setBorder(bordoPulsanti(false, true));
        layout.gridwidth = 1;
        layout.gridx = 2;
        layout.gridy = 6;
        pane.add(templatePulsante, layout);

        templatePulsante = creaBottoneStandard("=");
        templatePulsante.addActionListener(e -> risultato());
        templatePulsante.setBackground(new Color(207, 140, 52));
        templatePulsante.setBorder(bordoPulsanti(false, false));
        layout.gridx = 3;
        layout.gridy = 6;
        pane.add(templatePulsante, layout);

        pane.setBackground(new Color(34, 34, 34));
        add(pane);

        //repaint della finestra
        validate();
        repaint();

    }

    public Border bordoPulsanti(boolean bottom, boolean right) {
        return BorderFactory.createMatteBorder(
                0,
                0,
                bottom ? 1 : 0,
                right ? 1 : 0,
                new Color(34, 34, 34)
        );
    }

    public JButton creaBottoneStandard(String titolo) {
        JButton button = new JButton(titolo);
        button.setFont(new Font("Courier", Font.PLAIN, 22));
        button.setMargin(new Insets(0, 0, 0, 0));
        button.setForeground(Color.WHITE);
        button.setOpaque(true);
        button.setBorderPainted(true);
        return button;
    }

    void aggiornaDisplays() {
        if(registro2Attivo) {
            if(decimaleAttivo1){
                displaySecondario.setText(registro1 + " " + operatorToUnicode(operando));
            }else{
                displaySecondario.setText((int)registro1 + " " + operatorToUnicode(operando));
            }
            if(decimaleAttivo2){
                displayPrincipale.setText(String.valueOf(registro2));
            }else{
                displayPrincipale.setText(String.valueOf((int)registro2));
            }
        }else{
            if(decimaleAttivo1){
                displayPrincipale.setText(String.valueOf(registro1));
            }else{
                displayPrincipale.setText(String.valueOf((int)registro1));
            }
            displaySecondario.setText("0");
        }
        // agg dinamico font r1
        int lunghezzaR1 = String.valueOf(registro1).length() - 8;
        if(lunghezzaR1 > 0){
            int l = lunghezzaR1 * 2;
            displayPrincipale.setFont(new Font("Courier", Font.PLAIN, 45 - l));
        }else{
            displayPrincipale.setFont(new Font("Courier", Font.PLAIN, 45));
        }
    }

    void push(int n){
        if(risultatoOttenuto){
            clear();
        }
        // se piu di SETTE cifre INTERE non far inserire per prevenire overflow
        // max tre cifre decimali
        if(registro2Attivo){
            if(decimaleAttivo2){
                if(cifreDec2 < 3){
                    int j = 10;
                    for(int i = 0; i < cifreDec2; i++){
                        j = j * 10;
                    }
                    registro1 += (float) n / j;
                    cifreDec2++;
                }else{
                    aggiornaDisplays();
                    return;
                }
            }else{
                if((int) (Math.log10((int)registro2) + 1) > 6){
                    aggiornaDisplays();
                    return;
                }
                registro2 = (registro2 * 10) + n;
            }
        }else {
            if (decimaleAttivo1) {
                if (cifreDec1 < 3) {
                    int j = 10;
                    for (int i = 0; i < cifreDec1; i++) {
                        j = j * 10;
                    }
                    registro1 += (float) n / j;
                    cifreDec1++;
                } else {
                    aggiornaDisplays();
                    return;
                }
            } else {
                if ((int) (Math.log10((int) registro1) + 1) > 6) {
                    aggiornaDisplays();
                    return;
                }
                registro1 = (registro1 * 10) + n;
            }
        }
        aggiornaDisplays();
    }

    void clear() {
        registro1 = 0;
        registro2 = 0;
        registro2Attivo = false;
        decimaleAttivo1 = false;
        decimaleAttivo2 = false;
        cifreDec1 = 0;
        cifreDec2 = 0;
        operando = 'n';
        risultatoOttenuto = false;
        aggiornaDisplays();
    }

    void cambioSegno() {
        if(registro2Attivo){
            registro2 = registro2 * -1;
        }else{
            registro1 = registro1 * -1;
        }
        aggiornaDisplays();
    }

    void percentuale() {
        operando = '%';
        registro2Attivo = true;
        risultatoOttenuto = false;
        aggiornaDisplays();
    }

    void divisione() {
        operando = '/';
        registro2Attivo = true;
        risultatoOttenuto = false;
        aggiornaDisplays();
    }

    void moltiplicazione() {
        operando = '*';
        registro2Attivo = true;
        risultatoOttenuto = false;
        aggiornaDisplays();
    }

    void sottrazione() {
        operando = '-';
        registro2Attivo = true;
        risultatoOttenuto = false;
        aggiornaDisplays();
    }

    void addizione() {
        operando = '+';
        registro2Attivo = true;
        risultatoOttenuto = false;
        aggiornaDisplays();
    }

    void decimale() {
        int risultato = 0;
        if(!decimaliPermessi){
            risultato = JOptionPane.showConfirmDialog(
                    this,
                    "La funzionalità 'decimali' è ancora in prova, vuoi usarla?\n" +
                            "La scelta sarà ricordata.",
                    "Calcolatrice",
                    JOptionPane.YES_NO_OPTION,
                    JOptionPane.QUESTION_MESSAGE
            );
        }
        if(risultato == JOptionPane.YES_OPTION || decimaliPermessi){
            decimaliPermessi = true;
            if(registro2Attivo){
                decimaleAttivo2 = true;
            }else{
                decimaleAttivo1 = true;
            }
        }
    }

    void risultato() {
        float risultatoFinale = 0;
        switch (operando) {
            case '+' -> risultatoFinale = registro2 + registro1;
            case '-' -> risultatoFinale = registro1 - registro2;
            case '*' -> risultatoFinale = registro1 * registro2;
            case '/' -> risultatoFinale = registro1 / registro2;
            case '%' -> risultatoFinale = (registro1 * registro2) / 100;
        }
        if(operando != 'n'){
            registro1 = risultatoFinale;
            registro2 = 0;
            registro2Attivo = false;
            decimaleAttivo1 = true;
            decimaleAttivo2 = false;
            cifreDec1 = 0;
            cifreDec2 = 0;
            operando = 'n';
            risultatoOttenuto = true;
        }
        aggiornaDisplays();
    }

    char operatorToUnicode(char symbol){
        return switch (symbol) {
            case '+' -> '+';
            case '-' -> '-';
            case '*' -> '\u00D7';
            case '/' -> '\u00F7';
            case '%' -> '%';
            default -> '\0';
        };
    }

}
