import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();

    printPattern(n);

    sc.close();
  }

  private static void printCharacter(char c, int limit) {
    for (int i = 0; i < limit; i++) {
      System.out.print(c);
    }
  }

  private static void printPyramid(int n) {
    for (int i = 0; i < n; i++) {
      int spaces = n - i - 1, stars = i * 2 + 1;

      printCharacter(' ', spaces);
      printCharacter('*', stars);
      printCharacter(' ', spaces);

      System.out.println();
    }
  }

  private static void printInvertedPyramid(int n) {
    for (int i = 0; i < n; i++) {
      int stars = 2 * n - (2 * i + 1);

      printCharacter(' ', i);
      printCharacter('*', stars);
      printCharacter(' ', i);

      System.out.println();
    }
  }

  private static void printPattern(int n) {
    printPyramid(n);
    printInvertedPyramid(n);
  }
}
