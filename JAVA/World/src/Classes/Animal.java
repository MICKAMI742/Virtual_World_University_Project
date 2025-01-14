package Classes;

import java.awt.*;

public abstract class Animal extends Organism {

    public Animal(int initiative, int power, String genre, Color color){
        super(initiative, power, genre, color);
    }

    @Override
    public void action(World w){

    }

    @Override
    public void collision(World w, Organism o){

    }
}
