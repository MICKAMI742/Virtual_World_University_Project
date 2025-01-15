package Classes.Animals;

import Classes.Animal;

import java.awt.*;

public class Snail extends Animal {
    public Snail(int x, int y) {
        super(1,1,"Snail", new Color(45,123,123));
        this.setX(x);
        this.setY(y);
        this.setAge(0);
    }
}
