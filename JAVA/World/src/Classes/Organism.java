package Classes;

abstract public class Organism {
    private int power;
    private int initiative;
    private int x, y;
    private int age;
    private String genre;
    private World world; // world reference

    public abstract void action(World w);
    public abstract void collision(World w, Organism o);

    public int getPower() {
        return power;
    }

    public void setPower(int power) {
        this.power = power;
    }

    public int getInitiative() {
        return initiative;
    }

    public void setInitiative(int initiative) {
        this.initiative = initiative;
    }

    public int getX() {
        return x;
    }

    public void setX(int x) {
        this.x = x;
    }

    public int getY() {
        return y;
    }

    public void setY(int y) {
        this.y = y;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }
}
