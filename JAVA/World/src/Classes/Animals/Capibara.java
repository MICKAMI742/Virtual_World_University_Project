package Classes.Animals;

import Classes.Animal;
import Classes.World;

import java.awt.*;
import java.util.Random;

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

    // hides in the grass
    @Override
    public void action(World w){
        changeColor();
        super.action(w);
    }

    private void changeColor(){
        Random rand = new Random();
        if(rand.nextBoolean()){
            this.setColor(new Color(34,139,34));
        }
    }
}
