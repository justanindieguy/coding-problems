import java.util.ArrayList;
import java.util.Arrays;

public class Main {
  public static void main(String[] args) {
    int arr[] = { 9, 4, 7, 6, 3, 1, 5 };

    System.out.println("Before sorting array:");
    System.out.println(Arrays.toString(arr));

    System.out.println();

    System.out.println("After sorting array:");
    Solution.mergeSort(arr, 0, arr.length - 1);
    System.out.println(Arrays.toString(arr));
  }
}

class Solution {
  private static void merge(int[] arr, int low, int mid, int high) {
    ArrayList<Integer> temp = new ArrayList<>(); // Temporary array.
    int left = low; // Starting index of left half of the array.
    int right = mid + 1; // Starting index of right half of the array.

    // Storing elements in the temporary array in a sorted manner.
    while (left <= mid && right <= high) {
      if (arr[left] <= arr[right]) {
        temp.add(arr[left]);
        left++;
      } else {
        temp.add(arr[right]);
        right++;
      }
    }

    // If elements on the left half are still left.
    while (left <= mid) {
      temp.add(arr[left]);
      left++;
    }

    // If elements on the right half are still left.
    while (right <= high) {
      temp.add(arr[right]);
      right++;
    }

    for (int i = low; i <= high; i++) {
      arr[i] = temp.get(i - low);
    }
  }

  public static void mergeSort(int[] arr, int low, int high) {
    if (low >= high) {
      return;
    }

    int mid = (low + high) / 2;
    mergeSort(arr, low, mid); // Left half.
    mergeSort(arr, mid + 1, high); // Right half.
    merge(arr, low, mid, high);
  }
}
