import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();
    printPattern(n);

    sc.close();
  }

  private static void printPattern(int n) {
    int num = 1;

    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < i; j++) {
        System.out.print(num + " ");
        num++;
      }

      System.out.println();
    }
  }
}
