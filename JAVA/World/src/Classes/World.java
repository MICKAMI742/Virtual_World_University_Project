package Classes;
import javax.swing.*;
import java.awt.*;
import java.util.List;
import java.util.ArrayList;

public class World {
    private List<Organism> organisms;
    private int width, height;
    private int numOrganisms = 0;
    private int capacity;
    final private JButton[][] buttons;


    public void makeTurn(){
        for(int i = 0; i < numOrganisms; i++){
            organisms.get(i).action(this);
            organisms.get(i).setAge(organisms.get(i).getAge()+1);
        }
    }

    public void drawWorld(JPanel panel){
        for(int i = 0; i < width; i++){
            for(int j = 0; j < height; j++){
                JButton button = new JButton();
                buttons[i][j] = button;
                panel.add(button);
            }
        }
        for(Organism organism : organisms){
            buttons[organism.getX()][organism.getY()].setBackground(organism.getColor());
        }
    }

    public void repaintWorld(JPanel panel){
        for(Organism organism : organisms){
                JButton button = buttons[organism.getX()][organism.getY()];
                button.setBackground(organism.getColor());
        }
        panel.repaint();
    }

    public World(int x, int y){
        try{
            this.width = x;
            this.height = y;
            this.capacity = this.width * this.height;
            this.organisms = new ArrayList<>();
        }catch(NumberFormatException e){
            JFrame frame = new JFrame();
            // Obsługa błędu, jeśli dane nie są liczbami
            JOptionPane.showMessageDialog(frame,
                    "Proszę wprowadzić poprawne liczby!",
                    "Błąd",
                    JOptionPane.ERROR_MESSAGE);
        }
        buttons = new JButton[width][height];
    }

    public void addOrganism(Organism o){
        this.organisms.add(o);
    }

    public void addOrganismByChoice(){
        JFrame frame = new JFrame("Wybierz zwierze ktore chcesz dodac");
        JPanel panel = new JPanel();
        frame.add(panel);
    }
}
