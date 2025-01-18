package Classes.Animals;

import Classes.Animal;

import java.awt.*;

public class Wolf extends Animal {
    public Wolf(int x, int y) {
        super(4,9, "Wolf", new Color(105,105,105));
        this.setX(x);
        this.setY(y);
        this.setAge(0);
    }

    public Wolf(int initiative, int power, int x, int y, int age){
        super(initiative,power, "Wolf", new Color(105,105,105));
        this.setX(x);
        this.setY(y);
        this.setAge(age);
    }
}
