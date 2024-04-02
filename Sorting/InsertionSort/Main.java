import java.util.Arrays;

public class Main {
  public static void main(String[] args) {
    int[] numbers = new int[] { 13, 46, 24, 52, 20, 9 };
    System.out.println("Before insertion sort:");
    System.out.println(Arrays.toString(numbers));

    insertionSort(numbers);

    System.out.println("After insertion sort:");
    System.out.println(Arrays.toString(numbers));
  }

  private static void insertionSort(int[] arr) {
    for (int i = 0; i <= arr.length - 1; i++) {
      int j = i;
      while (j > 0 && arr[j - 1] > arr[j]) {
        // Swapping
        int temp = arr[j];
        arr[j] = arr[j - 1];
        arr[j - 1] = temp;

        j--;
      }
    }
  }
}
