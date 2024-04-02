import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();
    printPattern(n);

    sc.close();
  }

  private static void printCharacterRow(char c, int limit) {
    for (int i = 0; i < limit; i++) {
      System.out.print(c);
    }

    System.out.println();
  }

  public static void printPattern(int n) {
    for (int i = 1; i < n * 2; i++) {
      int stars = i;

      if (i > n) {
        stars = 2 * n - i;
      }

      printCharacterRow('*', stars);
    }
  }
}
