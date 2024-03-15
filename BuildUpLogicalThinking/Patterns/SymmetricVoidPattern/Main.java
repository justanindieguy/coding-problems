import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();
    printPattern(n);

    sc.close();
  }

  private static void printPattern(int n) {
    int initialSpaces = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n - i; j++) {
        System.out.print("*");
      }

      for (int j = 0; j < initialSpaces; j++) {
        System.out.print(" ");
      }

      for (int j = 0; j < n - i; j++) {
        System.out.print("*");
      }

      initialSpaces += 2;
      System.out.println();
    }

    initialSpaces = 2 * (n - 1);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= i; j++) {
        System.out.print("*");
      }

      for (int j = 0; j < initialSpaces; j++) {
        System.out.print(" ");
      }

      for (int j = 0; j <= i; j++) {
        System.out.print("*");
      }

      initialSpaces -= 2;
      System.out.println();
    }
  }
}
