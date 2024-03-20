import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    System.out.print("Enter a number: ");
    int n = sc.nextInt();
    printAllDivisorsBruteForce(n);
    printAllDivisorsOptimal(n);

    sc.close();
  }

  private static void printAllDivisorsBruteForce(int n) {
    System.out.println("The divisors of " + n + " are:");

    for (int i = 1; i <= n; i++) {
      if (n % i == 0) {
        System.out.print(i + " ");
      }
    }

    System.out.println();
  }

  private static void printAllDivisorsOptimal(int n) {
    System.out.println("The divisors of " + n + " are:");

    // Divisors greater than the square root are the quotients of 1 ... sqrt(n)
    // divisions
    for (int i = 1; i <= (int) Math.sqrt(n); i++) {
      if (n % i == 0) {
        System.out.print(i + " ");

        // Do not print same number twice for perfect squares.
        if (i != n / i) {
          // The quotient is also a divisor.
          System.out.print(n / i + " ");
        }
      }
    }

    System.out.println();
  }
}
