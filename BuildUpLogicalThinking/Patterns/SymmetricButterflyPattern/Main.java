import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();
    printPattern(n);

    sc.close();
  }

  private static void printPattern(int n) {
    int initialSpaces = 2 * n - 2;
    for (int i = 1; i <= 2 * n - 1; i++) {
      int stars = i;

      if (i > n) {
        stars = 2 * n - i;
      }

      for (int j = 1; j <= stars; j++) {
        System.out.print("*");
      }

      for (int j = 1; j <= initialSpaces; j++) {
        System.out.print(" ");
      }

      for (int j = 1; j <= stars; j++) {
        System.out.print("*");
      }

      System.out.println();

      if (i < n) {
        initialSpaces -= 2;
      } else {
        initialSpaces += 2;
      }
    }
  }
}
