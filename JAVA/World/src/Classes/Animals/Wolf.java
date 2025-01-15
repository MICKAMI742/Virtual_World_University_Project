package Classes.Animals;

import Classes.Animal;

import java.awt.*;

public class Wolf extends Animal {
    public Wolf(int x, int y) {
        super(4,9, "Wolf", new Color(5, 255, 255));
        this.setX(x);
        this.setY(y);
        this.setAge(0);
    }
}
