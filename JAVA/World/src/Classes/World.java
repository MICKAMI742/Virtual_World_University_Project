package Classes;
import javax.swing.*;
import java.awt.*;
import java.util.List;
import java.util.ArrayList;

public class World {
    private List<Organism> organisms;
    private List<Organism> toRemove;
    private List<Organism> toAdd;
    private int width, height;
    private int numOrganisms = 0;
    private int numOfBorn;
    private int capacity;
    final private JButton[][] buttons;


    public void makeTurn(){
        for (Organism organism : organisms) {
            organism.action(this);
            organism.setAge(organism.getAge() + 1);
        }

        if(!toRemove.isEmpty()){
            organisms.removeAll(toRemove);
            toRemove.clear();
        }

        if(!toAdd.isEmpty()){
            organisms.addAll(toAdd);
            toAdd.clear();
        }
    }

    public void drawWorld(JPanel panel){
        for(int i = 0; i < width; i++){
            for(int j = 0; j < height; j++){
                JButton button = new JButton();
                button.setBackground(Color.WHITE);
                buttons[i][j] = button;
                panel.add(button);
            }
        }
        for(Organism organism : organisms){
            buttons[organism.getX()][organism.getY()].setBackground(organism.getColor());
        }
    }

    public void repaintWorld(JPanel panel){
        for(int i = 0; i < width; i++){
            for(int j = 0; j < height; j++){
                JButton button = buttons[i][j];
                button.setBackground(Color.WHITE);
            }
        }
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
            this.toRemove = new ArrayList<>();
            this.toAdd = new ArrayList<>();
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
        toAdd.add(o);
    }

    public void addOrganismByChoice(){
        JFrame frame = new JFrame("Wybierz zwierze ktore chcesz dodac");
        JPanel panel = new JPanel();
        frame.add(panel);
    }

    public int getWidth(){
        return width;
    }

    public int getHeight(){
        return height;
    }

    public void removeOrganism(Organism o){
        toRemove.add(o);
    }

    Organism checkCollision(int x, int y){
        for(Organism o : organisms){
            if(o.getX() == x && o.getY() == y){
                return o;
            }
        }
        return null;
    }
}
