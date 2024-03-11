import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();
    printPattern(n);

    sc.close();
  }

  private static void printSpaces(int limit) {
    for (int i = 0; i < limit; i++) {
      System.out.print(" ");
    }
  }

  private static void printStars(int limit) {
    for (int i = 0; i < limit; i++) {
      System.out.print("*");
    }
  }

  public static void printPattern(int n) {
    for (int i = n - 1; i >= 0; i--) {
      int spaceLimit = n - i - 1, stars = 2 * i + 1;

      printSpaces(spaceLimit);
      printStars(stars);
      printSpaces(spaceLimit);

      System.out.println();
    }
  }
}
