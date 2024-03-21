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
      for (char ch = (char) ('A' + n - i - 1); ch <= (char) ('A' + n - 1); ch++) {
        System.out.print(ch + " ");
      }

      System.out.println();
    }
  }
}
