package UI;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class StartWindow {

    // Default values
    final Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize();
    final Dimension buttonSize = new Dimension(200, 50);

    public StartWindow() {
        // Creates instance of frame with specified name
        JFrame frame = new JFrame("Swiat zwierzat i roslin | Michal Kaminski 200788");

        // Sets frame size and sets position in the middle of the screen
        frame.setSize(screenSize);
        frame.setLocationRelativeTo(null);
        frame.setLayout(new GridBagLayout());


        GridBagConstraints gbc = new GridBagConstraints();
        gbc.insets = new Insets(10, 10, 10, 10);
        gbc.gridx = 0;
        gbc.gridy = 0;

        // 1 function
        JButton randomMapButton = new JButton("Generate random map");
        randomMapButton.setPreferredSize(buttonSize);
        randomMapButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e){
                JFrame formFrame = new JFrame("Formularz");
                formFrame.setSize(300, 150);
                formFrame.setLayout(new GridLayout(3, 2, 5, 5));

                // Dodanie pól tekstowych i etykiet
                formFrame.add(new JLabel("Szerokość"));
                JTextField textField1 = new JTextField();
                formFrame.add(textField1);

                formFrame.add(new JLabel("Wysokość"));
                JTextField textField2 = new JTextField();
                formFrame.add(textField2);

                // Button which leads us to SimulationWindow and passes values from
                // text fields
                JButton generateButton = new JButton("Generuj mape");
                generateButton.addActionListener(event -> formFrame.dispose());
                generateButton.addActionListener(new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent e){
                        try{
                        int width = Integer.parseInt(textField1.getText());
                        int height = Integer.parseInt(textField2.getText());
                        SimulationWindow simulationWindow = new SimulationWindow(width, height);}
                        catch (NumberFormatException ex) {
                            // Obsługa błędu, jeśli dane nie są liczbami
                            JOptionPane.showMessageDialog(formFrame,
                                    "Proszę wprowadzić poprawne liczby!",
                                    "Błąd",
                                    JOptionPane.ERROR_MESSAGE);
                        }
                        frame.dispose();
                    }
                });

                formFrame.add(generateButton);

                formFrame.setVisible(true);
            }
        });
        frame.add(randomMapButton, gbc);

        gbc.gridy = 1;

        // 2 function
        JButton readButton = new JButton("Read map from file");
        readButton.setPreferredSize(buttonSize);
        frame.add(readButton, gbc);

        // Shows dialog window
        readButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JFileChooser fileChooser = new JFileChooser();
                int result = fileChooser.showOpenDialog(frame);
                if (result == JFileChooser.APPROVE_OPTION) {
                    JOptionPane.showMessageDialog(frame, "Wybrano plik: " + fileChooser.getSelectedFile().getAbsolutePath());
                }
            }
        });

        // Displays window maximized
        frame.setExtendedState(JFrame.MAXIMIZED_BOTH);

        // Sets behaviour of frame if closed
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        // Shows window
        frame.setVisible(true);
    }
}
