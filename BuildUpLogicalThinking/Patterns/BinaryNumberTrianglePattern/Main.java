import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();
    printPattern(n);

    sc.close();
  }

  private static void printPattern(int n) {
    for (int i = 1; i <= n; i++) {
      int startingDigit = i % 2;

      for (int j = 0; j < i; j++) {
        System.out.print(startingDigit);
        startingDigit = 1 - startingDigit;
      }

      System.out.println();
    }
  }
}
