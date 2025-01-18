package Classes.Animals;

import Classes.Animal;

import java.awt.*;

public class Mosquito extends Animal {
    public Mosquito(int x, int y) {
        super(1,1,"Mosquito", new Color(47,79,79));
        this.setX(x);
        this.setY(y);
        this.setAge(0);
    }

    public Mosquito(int initiative, int power, int x, int y, int age) {
        super(initiative, power, "Mosquito", new Color(47,79,79));
        this.setX(x);
        this.setY(y);
        this.setAge(age);
    }
}
