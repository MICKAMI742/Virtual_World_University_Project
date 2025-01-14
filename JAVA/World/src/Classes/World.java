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
                panel.add(button);
            }
        }
    }

    public void repaintWorld(JPanel panel){
        for(int i = 0; i < width; i++){
            for(int j = 0; j < height; j++){
                panel.repaint();
            }
        }
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
    }

    public void addOrganism(){
        JFrame frame = new JFrame("Wybierz zwierze ktore chcesz dodac");
        JPanel panel = new JPanel();
        frame.add(panel);
    }
}
