import java.util.Arrays;

public class Main {
  public static void main(String[] args) {
    int[] numbers = new int[] { 5, 4, 3, 2, 1 };

    System.out.println("Original Array: " + Arrays.toString(numbers));
    reverseArrayRecursive(numbers);
    System.out.println("Reversed Array: " + Arrays.toString(numbers));

    int[] digits = new int[] { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };

    System.out.println("Original Array: " + Arrays.toString(digits));
    reverseArrayIterative(digits);
    System.out.println("Reversed Array: " + Arrays.toString(digits));
  }

  private static void reverseArrayIterative(int[] array) {
    int length = array.length;

    for (int i = 0; i < length / 2; i++) {
      int temp = array[i];
      array[i] = array[length - i - 1];
      array[length - i - 1] = temp;
    }
  }

  private static void reverseArrayRecursive(int[] array, int i, int j) {
    if (i > j) {
      return;
    }

    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;

    reverseArrayRecursive(array, i + 1, j - 1);
  }

  private static void reverseArrayRecursive(int[] array) {
    reverseArrayRecursive(array, 0, array.length - 1);
  }
}
