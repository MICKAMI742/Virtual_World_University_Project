package Classes.Plants;

import Classes.Plant;

import java.awt.*;

public class Grass extends Plant {
    public Grass(int x, int y) {
        super(0,0,"Grass", new Color(34,139,34));
        this.setX(x);
        this.setY(y);
        this.setAge(0);
    }

    public Grass(int initiative, int power, int x, int y, int age) {
        super(initiative, power, "Grass", new Color(34,139,34));
        this.setX(x);
        this.setY(y);
        this.setAge(age);
    }
}
