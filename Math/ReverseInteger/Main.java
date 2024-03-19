import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();
    System.out.println(reverseIntegerStringApproach(n));
    System.out.println(reverseIntegerMathApproach(n));

    sc.close();
  }

  private static int reverseIntegerStringApproach(int n) {
    String s = new StringBuilder(String.valueOf(n)).reverse().toString();
    return Integer.parseInt(s);
  }

  private static int reverseIntegerMathApproach(int n) {
    int ans = 0;

    while (n != 0) {
      int lastDigit = n % 10;
      ans = ans * 10 + lastDigit;
      n /= 10;
    }

    return ans;
  }
}
