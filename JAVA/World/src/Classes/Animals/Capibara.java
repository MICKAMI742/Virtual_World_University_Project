package Classes.Animals;

import Classes.Animal;

import java.awt.*;

public class Capibara extends Animal {
    // random world creation
    public Capibara(int x, int y) {
        super(9,9,"Capibara", new Color(139,69,19));
        this.setX(x);
        this.setY(y);
        this.setAge(0);
    }

    // reading from file
    public Capibara(int initiative, int power, int x, int y, int age) {
        super(initiative,power,"Capibara", new Color(139,69,19));
        this.setX(x);
        this.setY(y);
        this.setAge(age);
    }
}
