import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();
    System.out.println("Is palindrome? " + isPalindrome(n));

    sc.close();
  }

  private static boolean isPalindrome(int n) {
    if (n < 0) {
      return false;
    }

    int temp = n;
    int reversedNumber = 0;

    while (temp != 0) {
      int lastDigit = temp % 10;
      reversedNumber = reversedNumber * 10 + lastDigit;
      temp /= 10;
    }

    return reversedNumber == n;
  }
}
