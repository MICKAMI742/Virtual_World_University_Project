package Classes.Animals;

import Classes.Animal;

import java.awt.*;

public class Capibara extends Animal {
    public Capibara(int x, int y) {
        super(9,9,"Capibara", Color.RED);
        this.setX(x);
        this.setY(y);
        this.setAge(0);
    }
}
