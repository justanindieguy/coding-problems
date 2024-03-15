import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();
    System.out.println("Number of digits in " + n + " is " + countDigitsMath(n));
    System.out.println("Number of digits in " + n + " is " + countDigitsString(n));
    System.out.println("Number of digits in " + n + " is " + countDigitsLog(n));

    sc.close();
  }

  private static int countDigitsMath(int n) {
    int count = 0;

    while (n != 0) {
      n /= 10;
      count++;
    }

    return count;
  }

  private static int countDigitsString(int n) {
    return String.valueOf(n).length();
  }

  private static int countDigitsLog(int n) {
    int digits = (int) Math.floor(Math.log10(n) + 1);
    return digits;
  }
}
