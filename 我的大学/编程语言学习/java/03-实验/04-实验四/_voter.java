import java.util.*;

public class _voter {
    public static void main(String[] args) {
        Voter voter1 = new Voter("王明", "Yes"); voter1.vote();
        Voter voter2 = new Voter("王明", "Yes"); voter2.vote();
        Voter voter3 = new Voter("李丽", "Yes"); voter3.vote();
        Voter voter4 = new Voter("赵亮", "No");  voter4.vote();

        Voter.printInfo();
    }
}

class Voter {
    public static int count;
    public static int Yes;
    public static int No;

    private String name;
    private int maxTicket;
    private String note;
    private static ArrayList<String> Voted = new ArrayList<>();
    private static ArrayList<String> Note = new ArrayList<>();

    public Voter() {}
    public Voter(String name, String note) {
        this.name = name;
        this.note = note;
    }
    public Voter(String name, int maxTicket, String note) {
        this.name = name;
        this.maxTicket = maxTicket;
        this.note = note;
    }

    public void vote() {
        if (Voted.contains(name)) {
            System.out.println(name + "您不允许重复投票。");
            return ;
        }
        count++;
        if (note.equals("Yes")) {
            Yes++;
            Voted.add(name);
            Note.add("Yes");
        }
        else {
            No++;
            Voted.add(name);
            Note.add("No");
        }
        System.out.println(name + "感谢您的投票。");
    }

    public static void printInfo() {
        System.out.println("\n当前的投票数为: " + count);
        System.out.println("参与投票的选民和结果如下:");
        for (int i = 0; i < Voted.size(); ++i) {
            System.out.println(Voted.get(i) + " 的意见是 " + Note.get(i));
        }
        System.out.println("结果: Yes: " + Yes + ", No: " + No);
    }
}
