import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    System.out.print("Enter number: ");
    int n = sc.nextInt();

    System.out.println("Is armstrong number? " + isArmstrongNumber(n));

    sc.close();
  }

  private static boolean isArmstrongNumber(int n) {
    int temp = n;
    int digits = countDigits(n);
    int powerSum = 0;

    while (temp != 0) {
      int currentDigit = temp % 10;
      powerSum += Math.pow(currentDigit, digits);
      temp /= 10;
    }

    return powerSum == n;
  }

  private static int countDigits(int n) {
    int digits = 0;

    while (n != 0) {
      digits++;
      n /= 10;
    }

    return digits;
  }
}
