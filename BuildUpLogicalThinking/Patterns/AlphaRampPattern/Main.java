import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();
    printPattern(n);

    sc.close();
  }

  private static void printPattern(int n) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= i; j++) {
        System.out.print((char) (int) ('A' + i) + " ");
      }

      System.out.println();
    }
  }
}
