import java.util.*;
import java.io.*;

public class _05inputstream {
    public static void main(String[] args) {
        try {
            FileInputStream file = new FileInputStream("test.txt");
            Scanner input = new Scanner(file);

            ArrayList<String> list = new ArrayList<>();
            while (input.hasNextLine()) {
                list.add(input.nextLine());
            }
            Collections.sort(list);

            for (int i = 0; i < list.size(); ++i) {
                System.out.println(list.get(i));
            }
        }
        catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }
}
