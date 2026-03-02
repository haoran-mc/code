// 多态
public class _01Animal {
    public static void main(String[] args) {
        Object[] objects = {
            new Bird(), new Fish()
        };
        for (int i = 0; i < objects.length; ++ i) {
            // 强制类型转换
            // 等价于Object object = new Animal();
            System.out.println(disPlayObject(objects[i]));
        }
        String s1 = new String();
        String s2 = new String();
        // boolean b = s1.compareTo(s2);

        int number = Integer.MAX_VALUE + 1;
        System.out.println(number);
    }

    // 在使用父类的地方可以使用子类
    public static String disPlayObject(Object object) {
        if (object instanceof Animal)
            return ((Animal)object).toString();
        else
            return "Wrong!";
    }
}

class Animal {
    private int age;
    private double weight;
    private String name;

    public Animal() {}
    public Animal(int age, double weight, String name) {
        this.age = age;
        this.weight = weight;
        this.name = name;
    }

    public void setAge(int age) {
        this.age = age;
    }
    public int getAge() {
        return this.age;
    }

    public void setWeight(double weight) {
        this.weight = weight;
    }
    public double getWeight() {
        return this.weight;
    }

    public void setName(String name) {
        this.name = name;
    }
    public String getName() {
        return this.name;
    }

    @Override
    public String toString() {
        return "age: " + age + "; weight: " + weight + "; name: " + name;
    }
}

class Bird extends Animal {
    private double flySpeed;

    public Bird() {}
    public Bird(int age, double weight, String name, double flySpeed) {
        super(age, weight, name);
        this.flySpeed = flySpeed;
    }

    public void setFlySpeed(double flySpeed) {
        this.flySpeed = flySpeed;
    }
    public double getFlySpeed() {
        return this.flySpeed;
    }

    @Override
    public String toString() {
        return "age: " + super.getAge() + "; weight: " + super.getWeight() + "; name: " + super.getName() + "; flySpeed: " + flySpeed;
    }
}

class Fish extends Animal {
    private double swimSpeed;

    public Fish() {}
    public Fish(int age, double weight, String name, double swimSpeed) {
        super(age, weight, name);
        this.swimSpeed = swimSpeed;
    }

    public void setSwimSpeed(double swimSpeed) {
        this.swimSpeed = swimSpeed;
    }
    public double getSwimSpeed() {
        return this.swimSpeed;
    }

    @Override
    public String toString() {
        return "age: " + super.getAge() + "; weight: " + super.getWeight() + "; name: " + super.getName() + "; swimSpeed: " + swimSpeed;
    }
}
