package UI;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class SimulationWindow
{
    // Default values
    final Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize();
    final Dimension buttonSize = new Dimension(20, 20);

    public SimulationWindow(int width, int height){
        JFrame frame = new JFrame("Okno symulacji");

        // Sets frame size and sets position in the middle of the screen
        frame.setSize(screenSize);
        frame.setLocationRelativeTo(null);

        frame.setLayout(new BorderLayout()); // Use BorderLayout to separate grid and side panel

        // Panel for the grid of buttons
        JPanel gridPanel = new JPanel(new GridLayout(height, width, 10, 10));

        // Create buttons in a grid
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                JButton button = new JButton();
                button.setPreferredSize(buttonSize);
                gridPanel.add(button);
            }
        }

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

//        sidePanel.add(Box.createRigidArea(new Dimension(0, 20))); // Spacer

        // Add components for legend
        JLabel legendLabel = new JLabel("Legenda:");
        legendLabel.setFont(new Font("Arial", Font.BOLD, 16));
        sidePanel.add(legendLabel);

        JLabel legend1 = new JLabel("A - Organizm typu A");
        JLabel legend2 = new JLabel("B - Organizm typu B");
        sidePanel.add(legend1);
        sidePanel.add(legend2);

        JButton simulateButton = new JButton("Następna tura");
        simulateButton.setPreferredSize(buttonSize);
        sidePanel.add(simulateButton);

        // It will call action for every organism
        simulateButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

            }
        });

        JButton saveButton = new JButton("Zapisz świat");
        saveButton.setPreferredSize(buttonSize);
        sidePanel.add(saveButton);

        // It will save world to file
        saveButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

            }
        });

        // Add the side panel to the right
        frame.add(sidePanel, BorderLayout.EAST);

        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}
