package UI;

import Classes.Animals.*;
import Classes.Organism;
import Classes.Plants.Berry;
import Classes.Plants.Grass;
import Classes.Plants.Guarana;
import Classes.World;

import javax.swing.*;

public class AddOrganismWindow {
    private String stringSelected;
    private final int x;
    private final int y;
    public AddOrganismWindow(int x, int y, World w) {
        this.x = x;
        this.y = y;
        JFrame frame = new JFrame("Add Organism");
        frame.setSize(200, 200);
        frame.setLocationRelativeTo(null);
        DefaultListModel<String> model = new DefaultListModel<>();
        model.addElement("Wolf");
        model.addElement("Capibara");
        model.addElement("Snail");
        model.addElement("Sheep");
        model.addElement("Mosquito");
        model.addElement("Grass");
        model.addElement("Guarana");
        model.addElement("Berry");
        JList<String> list = new JList<>(model);
        list.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
        list.addListSelectionListener(e -> {
            stringSelected = list.getSelectedValue();
            addOrganism(w);
            w.makeTurn();
            frame.dispose();
        });
        frame.add(list);
        frame.setVisible(true);
    }

    public void addOrganism(World w) {
        switch(stringSelected){
            case "Wolf":
                w.addOrganism(new Wolf(x,y));
                break;
            case "Capibara":
                w.addOrganism(new Capibara(x,y));
                break;
            case "Snail":
                w.addOrganism(new Snail(x,y));
                break;
            case "Sheep":
                w.addOrganism(new Sheep(x,y));
                break;
            case "Mosquito":
                w.addOrganism(new Mosquito(x,y));
                break;
            case "Grass":
                w.addOrganism(new Grass(x,y));
                break;
            case "Guarana":
                w.addOrganism(new Guarana(x,y));
                break;
            case "Berry":
                w.addOrganism(new Berry(x,y));
                break;
            default:
                break;
        }
    }
}
