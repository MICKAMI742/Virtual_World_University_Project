package Classes.Animals;

import Classes.Animal;

import java.awt.*;

public class Mosquito extends Animal {
    public Mosquito(int x, int y) {
        super(1,1,"Mosquito", new Color(23,123,123));
        this.setX(x);
        this.setY(y);
        this.setAge(0);
    }
}
