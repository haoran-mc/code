package prac;

public class prac5 {
    public static void main(String[] args) {
        Object[] objects = {
                new bird(), new insect(), new reptilia(), new fish()
        };
        for (int i = 0; i < 100; ++i) {
            int idx = (int)(Math.random() * 4);
            if (objects[idx] instanceof Animal) {
                System.out.print(((Animal) objects[idx]).getCategory());
                System.out.print(": ");
            }

            if (objects[idx] instanceof Talent)
                System.out.println(((Talent) objects[idx]).showTalent());
        }
    }
}

interface Talent {
    public abstract String showTalent();
}

abstract class Animal {
    private int id;
    private String category;

    public void setId(int id) {
        this.id = id;
    }
    public void setCategory(String category) {
        this.category = category;
    }
    public int getId() {
        return this.id;
    }
    public String getCategory() {
        return this.category;
    }

    public abstract String showTalent();
}

class bird extends Animal implements Talent {
    private static int idxnum = 1;
    public bird() {
        setCategory("Bird");
    }
    @Override
    public String showTalent() {
        return "I can fly!";
    }
}

class insect extends Animal implements Talent {
    private static int idxnum = 1;
    public insect() {
        setCategory("Insect");
    }
    @Override
    public String showTalent() {
        return "I can be eaten!";
    }
}

class reptilia extends Animal implements Talent {
    private static int idxnum = 1;
    public reptilia() {
        setCategory("Reptilia");
    }
    @Override
    public String showTalent() {
        return "I can play basketball!";
    }
}

class fish extends Animal implements Talent {
    private static int idxnum = 1;
    public fish() {
        setCategory("Fish");
    }
    @Override
    public String showTalent() {
        return "I can swim!";
    }
}
