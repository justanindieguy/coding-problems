import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    System.out.print("Enter a number: ");
    int n = sc.nextInt();
    sc.close();

    printBacktracking(n);
    System.out.println("Summation  of first " + n + "th numbers = " + summation(n));
    System.out.println("Factorial of " + n + " = " + factorial(n));
    System.out.println("Fib of " + n + " = " + fib(n));
  }

  private static void printBacktracking(int n) {
    if (n == 0) {
      return;
    }

    printBacktracking(n - 1);
    System.out.println(n);
  }

  private static int summation(int n) {
    if (n == 0) {
      return 0;
    }

    return n + summation(n - 1);
  }

  private static int factorial(int n) {
    if (n == 0) {
      return 1;
    }

    return n * factorial(n - 1);
  }

  private static int fib(int n, int[] arrayMap) {
    if (n == 0) {
      return 0;
    }

    if (n == 1) {
      return 1;
    }

    if (arrayMap[n] != 0) {
      return arrayMap[n];
    }

    int fibOfN = fib(n - 1, arrayMap) + fib(n - 2, arrayMap);
    arrayMap[n] = fibOfN;

    return fibOfN;
  }

  private static int fib(int n) {
    int[] arrayMap = new int[n + 1];
    return fib(n, arrayMap);
  }
}
