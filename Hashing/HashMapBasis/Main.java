import java.util.HashMap;
import java.util.Scanner;

public class Main {
  private static HashMap<Integer, Integer> hm = new HashMap<>();

  public static void main(String[] args) {
    int[] numbers = new int[] { 1, 2, 3, 1, 3, 2, 12 };

    int count = -1; // Not yet started
    Scanner sc = new Scanner(System.in);

    while (count != 0) {
      System.out.print("Enter key to search: ");
      int key = sc.nextInt();

      count = countAppearances(numbers, key);
      System.out.println(key + " appears " + count + " times.");
    }

    sc.close();
  }

  private static int countAppearances(int[] array, int key) {
    if (hm.size() == 0) {
      buildHashMap(array);
    }

    if (!hm.containsKey(key)) {
      return 0;
    }

    return hm.get(key);
  }

  private static void buildHashMap(int[] array) {
    for (int x : array) {
      int freq = 0;

      if (hm.containsKey(x)) {
        freq = hm.get(x);
      }

      freq++;
      hm.put(x, freq);
    }
  }
}
