public class _fight {
    public static void main(String[] args) {
        Titan T = new Titan();
        Zues  Z = new Zues();
        while (true) {
            T.battle(Z);
            if (Z.getEnergy() <= 0) {
                System.out.println("Zues的Energy值为" + Z.getEnergy() + ", 已经失败，获胜者是Titan!");
                break;
            }
            Z.battle(T);
            if (T.getEnergy() <= 0) {
                System.out.println("Titan的Energy值为" + T.getEnergy() + ", 已经失败，获胜者是Zues!");
                break;
            }
        }
    }
}

class Titan {
    private int Energy;

    public Titan() {this.Energy = 800;}
    public Titan(int Energy) {this.Energy = Energy;}

    public void setEnergy(int Energy) {this.Energy = Energy;}
    public int getEnergy() {return this.Energy;}

    public void battle(Zues z) {
        int decrease = (int)(10 + 91 * Math.random());
        int z_Energy = z.getEnergy();
        z.setEnergy(z_Energy - decrease);
        System.out.println("Titan攻击Zues, 产生" + decrease + "点攻击值, Zuse当前Energy值为" + (z_Energy - decrease));
    }
}

class Zues {
    private int Energy;

    public Zues() {this.Energy = 1000;}
    public Zues(int Energy) {this.Energy = Energy;}

    public void setEnergy(int Energy) {this.Energy = Energy;}
    public int getEnergy() {return this.Energy;}

    public void battle(Titan t) {
        int decrease = (int)(71 * Math.random());
        int t_Energy = t.getEnergy();
        t.setEnergy(t_Energy - decrease);
        System.out.println("Zues攻击Titan, 产生" + decrease + "点攻击值, Titan当前Energy值为" + (t_Energy - decrease));
    }
}
