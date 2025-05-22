import java.util.Arrays;

public class Main {
  public static void main(String[] args) {
    int arr[] = { 3, 2, 1, 5, 4, 9, 10 };

    RecursiveBubbleSort.sort(arr, arr.length);

    System.out.println(Arrays.toString(arr));
  }
}

class RecursiveBubbleSort {
  public static void sort(int[] arr, int n) {
    // Base case: if array size is 1, it's sorted.
    if (n == 1) {
      return;
    }

    for (int i = 0; i < n - 1; i++) {
      if (arr[i] > arr[i + 1]) {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
      }
    }

    sort(arr, n - 1);
  }
}
