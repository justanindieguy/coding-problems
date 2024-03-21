import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    System.out.print("Enter a number: ");
    int n = sc.nextInt();
    sc.close();

    System.out.println(n + " is prime? " + checkIfIsPrimeBruteForce(n));
    System.out.println(n + " is prime? " + checkIfIsPrimeOptimal(n));
  }

  private static boolean checkIfIsPrimeBruteForce(int n) {
    if (n == 0) {
      return false;
    }

    for (int i = 2; i < n; i++) {
      if (n % i == 0) {
        return false;
      }
    }

    return true;
  }

  private static boolean checkIfIsPrimeOptimal(int n) {
    if (n == 0) {
      return false;
    }

    for (int i = 2; i <= (int) Math.sqrt(n); i++) {
      if (n % i == 0) {
        return false;
      }
    }

    return true;
  }
}
