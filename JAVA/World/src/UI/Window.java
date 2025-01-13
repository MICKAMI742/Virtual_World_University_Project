package UI;

import Classes.World;

import javax.swing.*;
import java.awt.*;

public class Window {
    public static void startWindow() {
        // Creates instance of frame with specified name
        JFrame frame = new JFrame("Swiat zwierzat i roslin | Michal Kaminski 200788");

        // Gets info about screen size
        Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize();

        // Sets frame size and sets position in the middle of the screen
        frame.setSize(screenSize);
        frame.setLocationRelativeTo(null);

        // Displays window maximized
        frame.setExtendedState(JFrame.MAXIMIZED_BOTH);

        // Sets behaviour of frame if closed
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        // Shows window
        frame.setVisible(true);
    }
}
