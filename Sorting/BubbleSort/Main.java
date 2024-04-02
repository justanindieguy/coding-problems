import java.util.Arrays;

public class Main {
  public static void main(String[] args) {
    int[] numbers = new int[] { 13, 46, 24, 52, 20, 9 };
    System.out.println("Before bubble sort:");
    System.out.println(Arrays.toString(numbers));

    bubbleSort(numbers);

    System.out.println("After bubble sort:");
    System.out.println(Arrays.toString(numbers));
  }

  private static void bubbleSort(int[] arr) {
    for (int i = 0; i < arr.length - 1; i++) {
      boolean hasSwapped = false;

      for (int j = 0; j < arr.length - i - 1; j++) {
        if (arr[j] > arr[j + 1]) {
          hasSwapped = true;

          int temp = arr[j];
          arr[j] = arr[j + 1];
          arr[j + 1] = temp;
        }
      }

      if (!hasSwapped) {
        break;
      }
    }
  }
}
