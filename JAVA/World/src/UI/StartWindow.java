package UI;


import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.*;
import java.util.Objects;

import Classes.*;
import Classes.Animals.*;
import Classes.Plants.Berry;
import Classes.Plants.Grass;
import Classes.Plants.Guarana;

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
                int returnVal = fileChooser.showOpenDialog(frame);
                if (returnVal == JFileChooser.APPROVE_OPTION) {
                    File file = fileChooser.getSelectedFile();
                    SimulationWindow simulationWindow = new SimulationWindow(Objects.requireNonNull(readOrganismsFromFile(file)).getWidth(),
                            Objects.requireNonNull(readOrganismsFromFile(file)).getHeight());
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

    private static World readOrganismsFromFile(File file){
        try {
            BufferedReader reader = new BufferedReader(new FileReader(file));
            String line;
            World world = null;

            if((line = reader.readLine()) != null){
                String[] tokens = line.split(" ");
                world = new World(Integer.parseInt(tokens[0]),
                        Integer.parseInt(tokens[1]));
            }

            String genre = "";
            int initiative = 0;
            int power = 0;
            int x = 0;
            int y = 0;
            int age = 0;


            while((line = reader.readLine()) != null){
                String[] data = line.split(" ");
                if(data.length == 6){
                    genre = data[0];
                    initiative = Integer.parseInt(data[1]);
                    power = Integer.parseInt(data[2]);
                    x = Integer.parseInt(data[3]);
                    y = Integer.parseInt(data[4]);
                    age = Integer.parseInt(data[5]);
                }

                if(world != null){
                    switch(genre){
                        case "Mosquito":
                            world.addOrganism(new Mosquito(initiative,power,x,y,age));
                        case "Wolf":
                            world.addOrganism(new Wolf(initiative,power,x,y,age));
                        case "Sheep":
                            world.addOrganism(new Sheep(initiative,power,x,y,age));
                        case "Capibara":
                            world.addOrganism(new Capibara(initiative,power,x,y,age));
                        case "Snail":
                            world.addOrganism(new Snail(initiative,power,x,y,age));
                        case "Berry":
                            world.addOrganism(new Berry(initiative,power,x,y,age));
                        case "Grass":
                            world.addOrganism(new Grass(initiative,power,x,y,age));
                        case "Guarana":
                            world.addOrganism(new Guarana(initiative,power,x,y,age));
                    }
                }
            }

            reader.close();
            return world;
        } catch (Exception e)
        {

        }
        return null;
    }
}
