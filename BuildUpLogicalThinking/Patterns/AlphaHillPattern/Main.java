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
      for (int j = 0; j < n - i - 1; j++) {
        System.out.print(" ");
      }

      char c = 'A';
      int breakpoint = (2 * i) / 2;
      for (int j = 0; j < 2 * i + 1; j++) {
        System.out.print(c);

        if (j < breakpoint) {
          c++;
        } else {
          c--;
        }
      }

      for (int j = 0; j < n - i - 1; j++) {
        System.out.print(" ");
      }

      System.out.println();
    }
  }
}
