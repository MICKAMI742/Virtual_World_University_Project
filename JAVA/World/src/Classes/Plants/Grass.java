package Classes.Plants;

import Classes.Plant;

import java.awt.*;

public class Grass extends Plant {
    public Grass(int x, int y) {
        super(0,0,"Grass", Color.green);
        this.setX(x);
        this.setY(y);
        this.setAge(0);
    }
}
