package Classes.Animals;

import Classes.Animal;

import java.awt.*;

public class Snail extends Animal {
    public Snail(int x, int y) {
        super(1,1,"Snail", new Color(210,180,140));
        this.setX(x);
        this.setY(y);
        this.setAge(0);
    }

    public Snail(int initiative, int power, int x, int y, int age) {
        super(initiative, power, "Snail", new Color(210,180,140));
        this.setX(x);
        this.setY(y);
        this.setAge(age);
    }
}
