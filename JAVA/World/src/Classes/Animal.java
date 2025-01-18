package Classes;

import Classes.Animals.*;

import java.awt.*;
import java.util.Random;

public abstract class Animal extends Organism {

    public Animal(int initiative, int power, String genre, Color color){
        super(initiative, power, genre, color);
    }

    @Override
    public void action(World w){
        Random rand = new Random();
        switch(rand.nextInt(8)){
            case 0: // right
                if(w.checkCollision(this.getX()+1, this.getY()) != null){
                    collision(w, w.checkCollision(this.getX()+1, this.getY()));
                }
                if(this.getX() + 1 < w.getWidth())
                    this.setX(this.getX() + 1);
                break;
            case 1: // left
                if(w.checkCollision(this.getX()-1, this.getY()) != null){
                    collision(w, w.checkCollision(this.getX()-1, this.getY()));
                }
                if(this.getX() - 1 >= 0)
                    this.setX(this.getX() - 1);
                break;
            case 2: // up
                if(w.checkCollision(this.getX(), this.getY() - 1) != null){
                    collision(w, w.checkCollision(this.getX(), this.getY() - 1));
                }
                if(this.getY() - 1 >= 0)
                    this.setY(this.getY() - 1);
                break;
            case 3: // down
                if(w.checkCollision(this.getX(), this.getY() + 1) != null){
                    collision(w, w.checkCollision(this.getX(), this.getY() + 1));
                }
                if(this.getY() + 1 < w.getHeight())
                    this.setY(this.getY() + 1);
                break;
            case 4: // right + up
                if(w.checkCollision(this.getX() + 1, this.getY() - 1) != null){
                    collision(w, w.checkCollision(this.getX() + 1, this.getY() - 1));
                }
                if(this.getX() + 1 < w.getWidth() && this.getY() - 1 >= 0){
                    this.setX(this.getX() + 1);
                    this.setY(this.getY() - 1);
                }
                break;
            case 5: // left + downs
                if(w.checkCollision(this.getX() - 1, this.getY() + 1) != null){
                    collision(w,w.checkCollision(this.getX() - 1, this.getY() + 1));
                }
                if(this.getX() - 1 >= 0 && this.getY() + 1 < w.getHeight()){
                    this.setX(this.getX() - 1);
                    this.setY(this.getY() + 1);
                }
                break;
            case 6: // right + down
                if(w.checkCollision(this.getX()+1,this.getY()+1) != null){
                    collision(w, w.checkCollision(this.getX()+1,this.getY()+1));
                }
                if(this.getX() + 1 < w.getWidth() && this.getY() + 1 < w.getHeight()){
                    this.setX(this.getX() + 1);
                    this.setY(this.getY() + 1);
                }
                break;
            case 7: // left + up
                if(w.checkCollision(this.getX() - 1, this.getY()-1) != null){
                    collision(w, w.checkCollision(this.getX() - 1, this.getY()-1));
                }
                if(this.getX() - 1 >= 0 && this.getY() - 1 >= 0){
                    this.setX(this.getX() - 1);
                    this.setY(this.getY() - 1);
                }
                break;
        }
    }

    @Override
    public void collision(World w, Organism o){
            switch (this) {
                case Capibara capibara when o instanceof Capibara ->
                        w.addOrganism(new Capibara(this.getX(), this.getY()));
                case Mosquito mosquito when o instanceof Mosquito ->
                        w.addOrganism(new Mosquito(this.getX(), this.getY()));
                case Sheep sheep when o instanceof Sheep ->
                        w.addOrganism(new Sheep(this.getX(), this.getY()));
                case Snail snail when o instanceof Snail ->
                        w.addOrganism(new Snail(this.getX(), this.getY()));
                case Wolf wolf when o instanceof Wolf ->
                        w.addOrganism(new Wolf(this.getX(), this.getY()));
                default -> {
                    if (this.getPower() >= o.getPower()) {
                        w.removeOrganism(o);
                    } else {
                        w.removeOrganism(this);
                    }
                }
        }
    }
}
