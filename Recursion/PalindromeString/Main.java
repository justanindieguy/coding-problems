import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    String s = sc.nextLine();
    sc.close();

    if (isPalindromeRecursive(s)) {
      System.out.println("\"" + s + "\"" + " is palindrome");
    } else {
      System.out.println("\"" + s + "\"" + " is NOT palindrome");
    }
  }

  private static boolean isPalindromeIterative(String s) {
    s = s.trim().toLowerCase();
    int length = s.length();
    int left = 0;
    int right = length - 1;

    while (left < right) {
      char l = s.charAt(left);
      char r = s.charAt(right);

      if (!Character.isLetterOrDigit(l)) {
        left++;
        continue;
      }

      if (!Character.isLetterOrDigit(r)) {
        right--;
        continue;
      }

      if (l != r) {
        return false;
      }

      left++;
      right--;
    }

    return true;
  }

  private static boolean isPalindromeRecursive(String s, int left, int right) {
    if (left > right) {
      return true;
    }

    char l = s.charAt(left);
    char r = s.charAt(right);

    if (!Character.isLetterOrDigit(l)) {
      return isPalindromeRecursive(s, left + 1, right);
    }

    if (!Character.isLetterOrDigit(r)) {
      return isPalindromeRecursive(s, left, right - 1);
    }

    if (l != r) {
      return false;
    }

    return isPalindromeRecursive(s, left + 1, right - 1);
  }

  private static boolean isPalindromeRecursive(String s) {
    s = s.trim().toLowerCase();
    return isPalindromeRecursive(s, 0, s.length() - 1);
  }
}
