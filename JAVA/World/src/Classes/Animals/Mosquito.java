package Classes.Animals;

import Classes.Animal;
import Classes.World;

import java.awt.*;
import java.util.function.BiConsumer;

public class Mosquito extends Animal {
    public Mosquito(int x, int y) {
        super(1,1,"Mosquito", new Color(47,79,79));
        this.setX(x);
        this.setY(y);
        this.setAge(0);
    }

    public Mosquito(int initiative, int power, int x, int y, int age) {
        super(initiative, power, "Mosquito", new Color(47,79,79));
        this.setX(x);
        this.setY(y);
        this.setAge(age);
    }

    private int searchForMoqsquitoAround(World w){
        int numOfMoqsquitoAround = 0;
        for(int i = -1; i <= 1; i++){
            for(int j = -1; j <= 1; j++){
                if(w.checkCollision(this.getX()+ i, this.getY() + j) instanceof Mosquito){
                    numOfMoqsquitoAround++;
                }
            }
        }
        return numOfMoqsquitoAround;
    }

    private void addPower(World w){
        this.setPower(this.getPower()+ searchForMoqsquitoAround(w));
        this.setInitiative(this.getInitiative() + searchForMoqsquitoAround(w));
    }

    @Override
    public void action(World w){
        setPower(1);
        setInitiative(1);
        addPower(w);
        super.action(w);
    }
}
