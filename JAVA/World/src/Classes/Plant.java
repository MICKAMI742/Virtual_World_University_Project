package Classes;

import Classes.Plants.*;

import java.awt.*;
import java.util.Random;

public abstract class Plant extends Organism{

    public Plant(int initiative, int power, String genre, Color color){
        super(initiative, power, genre, color);
    }

    @Override
    public void action(World w){
        Random rand = new Random();
        double random = rand.nextDouble(100);
        int x = rand.nextInt(w.getWidth());
        int y = rand.nextInt(w.getHeight());
        if(random <= 1){
            switch(this){
                case Berry berry -> w.addOrganism(new Berry(x,y));
                case Grass grass -> w.addOrganism(new Grass(x,y));
                case Guarana guarana -> w.addOrganism(new Guarana(x,y));
                default -> {
                }
            }
        }
    }

    @Override
    public void collision(World w, Organism o){

    }
}
