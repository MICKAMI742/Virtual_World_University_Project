package Classes.Plants;

import Classes.Plant;

import java.awt.*;

public class Guarana extends Plant {

    public Guarana(int x, int y) {
        super(0,0,"Guarana", new Color(220,20,60));
        this.setX(x);
        this.setY(y);
        this.setAge(0);
    }

    public Guarana(int initiative, int power, int x, int y, int age) {
        super(initiative,power,"Guarana", new Color(220,20,60));
        this.setX(x);
        this.setY(y);
        this.setAge(age);
    }
}
