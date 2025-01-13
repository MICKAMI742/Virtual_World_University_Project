package Classes;
import javax.swing.*;
import java.awt.*;

public class World {
    private Organism[] organisms;
    private int width, height;
    private int numOrganisms = 0;
    private int capacity;


    public void makeTurn(){

    }

    public void drawWorld(){

    }

    public World(int x, int y){
        if(x != 0 && y != 0){
            this.width = x;
            this.height = y;
            this.capacity = this.width * this.height;
            this.organisms = new Organism[this.capacity];
        }
    }

    public void addOrganism(){
        numOrganisms++;
    }
}
