import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();

    printPattern(n);

    sc.close();
  }

  public static void printSpaces(int limit) {
    for (int j = 0; j < limit; j++) {
      System.out.print(" ");
    }
  }

  public static void printPattern(int n) {
    for (int i = 0; i < n; i++) {
      int totalSpaces = n - i - 1, totalStars = 2 * i + 1;

      printSpaces(totalSpaces);

      for (int j = 0; j < totalStars; j++) {
        System.out.print("*");
      }

      printSpaces(n - i - 1);

      System.out.println();
    }
  }
}
