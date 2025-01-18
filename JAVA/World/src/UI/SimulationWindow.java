package UI;
import Classes.Animals.*;
import Classes.Organism;
import Classes.Plants.Berry;
import Classes.Plants.Grass;
import Classes.Plants.Guarana;
import Classes.World;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.FileInputStream;
import java.util.*;
import java.util.List;
import java.util.random.*;

public class SimulationWindow
{
    // Default values
    final Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize();
    final Dimension buttonSize = new Dimension(20, 20);

    // creates random world
    public SimulationWindow(int width, int height){
        JFrame frame = new JFrame("Okno symulacji");

        // World initialization
        World world = createRandomWorld(width, height);
        world.firstTurn(); // pushing organisms from temp lists


        // Sets frame size and sets position in the middle of the screen
        frame.setSize(screenSize);
        frame.setLocationRelativeTo(null);

        frame.setLayout(new BorderLayout()); // Use BorderLayout to separate grid and side panel

        // Panel for the grid of buttons
        JPanel gridPanel = new JPanel(new GridLayout(height, width, 10, 10));

        // Create buttons in a grid
        world.drawWorld(gridPanel);

        // Add the grid panel to the center
        frame.add(gridPanel, BorderLayout.CENTER);

        // Panel for statistics and legend
        JPanel sidePanel = new JPanel();
        sidePanel.setLayout(new BoxLayout(sidePanel, BoxLayout.Y_AXIS));
        sidePanel.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));

        // Add components for statistics
        JLabel statsLabel = new JLabel("Statystyki:");
        statsLabel.setFont(new Font("Arial", Font.BOLD, 16));
        sidePanel.add(statsLabel);

        // Displaying stats
        JLabel stat1 = new JLabel("Urodzenia: ");
        JLabel stat2 = new JLabel("Śmierci: ");
        sidePanel.add(stat1);
        sidePanel.add(stat2);

        // Implements line of free space
        sidePanel.add(Box.createRigidArea(new Dimension(0, 20)));

        // Add components for legend
        JLabel legendLabel = new JLabel("Legenda:");
        legendLabel.setFont(new Font("Arial", Font.BOLD, 16));
        sidePanel.add(legendLabel);
        showLegend(sidePanel, world.getOrganism());

        JButton simulateButton = new JButton("Następna tura");
        simulateButton.setPreferredSize(buttonSize);
        sidePanel.add(simulateButton);

        // It will call action for every organism
        simulateButton.addActionListener(e -> {
            world.makeTurn();
            world.repaintWorld(gridPanel);
        });

        JButton saveButton = new JButton("Zapisz świat");
        saveButton.setPreferredSize(buttonSize);
        sidePanel.add(saveButton);

        // It will save world to file
        saveButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                world.saveWorldToFile();
            }
        });

        // Add the side panel to the right
        frame.add(sidePanel, BorderLayout.EAST);

        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }

    // reads world from file
    public SimulationWindow(World world){

    }

    private World createRandomWorld(int width, int height){
        World world = new World(width, height);
        int numOfRandomOrganisms = new Random().nextInt(width * 2);
        for (int i = 0; i < numOfRandomOrganisms; i++) {
            int randomOrganism = new Random().nextInt(8);
            int x = new Random().nextInt(width);
            int y = new Random().nextInt(height);
            switch (randomOrganism){
                case 0:
                    world.addOrganism(new Capibara(x,y));
                    break;
                case 1:
                    world.addOrganism(new Wolf(x,y));
                    break;
                case 2:
                    world.addOrganism(new Mosquito(x,y));
                    break;
                case 3:
                    world.addOrganism(new Sheep(x,y));
                    break;
                case 4:
                    world.addOrganism(new Snail(x,y));
                    break;
                case 5:
                    world.addOrganism(new Berry(x,y));
                    break;
                case 6:
                    world.addOrganism(new Grass(x,y));
                    break;
                case 7:
                    world.addOrganism(new Guarana(x,y));
                    break;
            }
        }
        return world;
    }

    private void showLegend(JPanel panel, List<Organism> o){
        Set<Organism> unique = new HashSet<>(o);

        for(Organism oi : unique){
            JLabel label = new JLabel(oi.getGenre());
            label.setFont(new Font("Arial", Font.BOLD, 16));
            label.setHorizontalAlignment(JLabel.CENTER);
            label.setForeground(oi.getColor());
            panel.add(label);
        }

        panel.revalidate();
        panel.repaint();
    }
}
