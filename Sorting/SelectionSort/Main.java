import java.util.Arrays;

public class Main {
  public static void main(String[] args) {
    int[] numbers = new int[] { 7, 1, 4, 2, 3 };
    System.out.println("Before selection sort:");
    System.out.println(Arrays.toString(numbers));

    selectionSort(numbers);

    System.out.println("After selection sort:");
    System.out.println(Arrays.toString(numbers));
  }

  private static void selectionSort(int[] arr) {
    for (int i = 0; i < arr.length - 1; i++) {
      int smallestIdx = i;
      for (int j = i + 1; j < arr.length; j++) {
        if (arr[j] < arr[smallestIdx]) {
          smallestIdx = j;
        }
      }

      // Swap
      int temp = arr[i];
      arr[i] = arr[smallestIdx];
      arr[smallestIdx] = temp;
    }
  }
}
