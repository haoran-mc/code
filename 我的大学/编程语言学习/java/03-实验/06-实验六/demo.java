package prac;

public class demo {
    public static void main(String[] args) {
        Object[] objects = {
                new Tiger(), new Chicken(), new Apple()
        };
        for (int i = 0; i < objects.length; ++i) {
            if (objects[i] instanceof Edible)
                System.out.println(((Edible)objects[i]).howToEat());

            if (objects[i] instanceof demoAnimal)
                System.out.println(((demoAnimal)objects[i]).sound());
        }
    }
}

interface Edible {
    public abstract String howToEat();
}

abstract class demoAnimal {
    private double weight;

    public double getWeight() {
        return weight;
    }

    public void setWeight(double weight) {
        this.weight = weight;
    }

    public abstract String sound();
}

class Chicken extends demoAnimal implements Edible {
    @Override
    public String howToEat() {
        return "Chicken: Fry it";
    }

    @Override
    public String sound() {
        return "Chicken: cock-a-doodle-doo";
    }
}

class Tiger extends demoAnimal {
    @Override
    public String sound() {
        return "Tiger: RROOAARR";
    }
}

abstract class Fruit implements Edible {
    // Data fields,
}

class Apple extends Fruit {
    @Override
    public String howToEat() {
        return "Apple: Make apple cider";
    }
}

class Orange extends Fruit {
    @Override
    public String howToEat() {
        return "Orange: Make orange juice";
    }
}
