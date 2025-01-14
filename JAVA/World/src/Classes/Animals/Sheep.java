package Classes.Animals;

import Classes.Animal;

public class Sheep extends Animal {
    public Sheep(int x, int y) {
        super(4,4,"Sheep");
        this.setX(x);
        this.setY(y);
        this.setAge(0);
    }
}
