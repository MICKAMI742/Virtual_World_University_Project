package Classes.Animals;

import Classes.Animal;

import java.awt.*;

public class Sheep extends Animal {
    public Sheep(int x, int y) {
        super(4,4,"Sheep", Color.CYAN);
        this.setX(x);
        this.setY(y);
        this.setAge(0);
    }
}
