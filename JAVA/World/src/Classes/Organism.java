package Classes;

import java.awt.*;
import java.io.Serializable;
import java.util.Objects;
import java.util.Random;

abstract public class Organism {
    private int power;
    private int initiative;
    private int x, y;
    private int age;
    private String genre;
    private World world; // world reference
    final private Color color;

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

    public Organism(int initiative, int power, String genre, Color color) {
        this.initiative = initiative;
        this.power = power;
        this.genre = genre;
        this.color = color;
        age = 0;

    }

    public Color getColor() {
        return color;
    }

    public String getGenre() {
        return genre;
    }

    // helps generate unique hashset to my legend
    // of organisms
    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Organism organism = (Organism) o;
        return Objects.equals(genre, organism.genre);
    }

    @Override
    public int hashCode() {
        return Objects.hash(genre);
    }

    @Override
    public String toString() {
        return this.genre + " " + this.initiative +" "+ this.power + " " + this.x + " " + this.y + " " + this.age + "\n";
    }
}
