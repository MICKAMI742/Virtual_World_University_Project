package Classes.Plants;

import Classes.Plant;

import java.awt.*;

public class Berry extends Plant {
    public Berry(int x, int y) {
        super(0,0,"Berry", new Color(75,0,130));
        this.setX(x);
        this.setY(y);
        this.setAge(0);
    }

    public Berry(int initiative, int power, int x, int y, int age){
        super(initiative,power,"Berry", new Color(75,0,130));
        this.setX(x);
        this.setY(y);
        this.setAge(age);
    }
}
