public class _05wrong {
    public static void main(String[] args) {
        Fruit[] fruits = {
            new Fruit(2), new Fruit(3), new Fruit(1)
        };
        java.util.Arrays.sort(fruits);
    }
}

class Fruit {
    private double weight;

    public Fruit() {};
    public Fruit(double weight) {
        this.weight = weight;
    }
}
