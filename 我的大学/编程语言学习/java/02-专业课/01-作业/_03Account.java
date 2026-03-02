import java.text.*;
import java.util.Date;
import java.util.Scanner;

public class _03Account {
    static Account[] ac = new Account[10];
    static Scanner input = new Scanner(System.in);

    public static void main(String[] args) {
        for (int i = 0; i < 10; ++i) {
            ac[i] = new Account();
            ac[i].setId(i);
            ac[i].setBalance(100);
            ac[i].initDateCreated();
        }
        while (true) {
            System.out.print("Enter an id: ");
            int id = input.nextInt();
            query(id);
            if (id == -1) break;
        }
        input.close();
    }

    static void query(int id) {
        if (id < 0 || id >= 10) {
            System.out.println("There is no such account!");
            return;
        }
        String Date = ac[id].getDateCreated();
        System.out.println("This account was created on" + Date);
        while (true) {
            System.out.println("\nMain menu");
            System.out.println("1: check balance"); //查看余额
            System.out.println("2: withdraw");      //取钱
            System.out.println("3: deposit");       //存钱
            System.out.println("4: exit");          //退出主菜单

            System.out.print("Enter a choice: ");
            int in = input.nextInt();
            if (in == 1)
                System.out.println("The balance is " + ac[id].getBalance());
            else if (in == 2) {
                System.out.print("Enter an amount to withdraw: ");
                int sub = input.nextInt();
                ac[id].setBalance(ac[id].getBalance() - sub);
            }
            else if (in == 3) {
                System.out.print("Enter an amount to deposit: ");
                int add = input.nextInt();
                ac[id].setBalance(ac[id].getBalance() + add);
            }
            else if (in == 4) {
                System.out.println();
                break;
            }
        }
    }
}

class Account {
    private int id;                //用户账号
    private double balance;        //余额
    private double annualInterest; //年利率
    private Date dateCreated;      //开户日期

    public Account() {};
    public Account(int _id, double _balance, double _annualInterest) {
        id = _id;
        balance = _balance;
        annualInterest = _annualInterest;
    };

    public int getId() {return id;}                                //返回该账户的账号
    public double getBalance() {return balance;}                   //返回该账户的余额
    public double getAnnualInterestRate() {return annualInterest;} //返回该账户的念利率

    public void setId(int _id) {id = _id;}                         //设置该账户的账号
    public void setBalance(double _balance) {balance = _balance;}  //设置该账户的余额
    public void setAnnualInterestRate(double _annualInterest) {annualInterest = _annualInterest;} //设置该账户的年利率
    public void initDateCreated() {dateCreated = new Date();}

    public String getDateCreated() { //返回该账户的开户日期
        SimpleDateFormat formatter = new SimpleDateFormat("dd-MM-yyyy HH:mm:ss");
        String Date = formatter.format(dateCreated);
        // String Date = "1";
        return Date;
    }
    public double getMonthlyInterest() {return balance * annualInterest / 12;}  //返回月利息

    public void withdraw(double amount) {balance -= amount;}       //从该账户提取指定金额
    public void deposit(double amount) {balance += amount;}        //从该账户存入指定金额
}
