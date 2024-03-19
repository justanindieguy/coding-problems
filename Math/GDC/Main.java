import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    System.out.print("Enter x: ");
    int x = sc.nextInt();

    System.out.print("Enter y: ");
    int y = sc.nextInt();

    System.out.println("Greatest Common Divisor: " + gdcBruteForce(x, y));
    System.out.println("Greatest Common Divisor: " + gdcOptimal(x, y));

    sc.close();
  }

  private static int gdcOptimal(int x, int y) {
    while (y != 0) {
      int temp = y;
      y = x % y;
      x = temp;
    }

    return x;
  }

  private static int gdcBruteForce(int x, int y) {
    int gdc = 1;

    for (int i = 1; i <= Math.min(x, y); i++) {
      if (isCommonDivisor(x, y, i)) {
        gdc = i;
      }
    }

    return gdc;
  }

  private static boolean isCommonDivisor(int x, int y, int dividend) {
    return x % dividend == 0 && y % dividend == 0;
  }
}
