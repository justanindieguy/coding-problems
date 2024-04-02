import java.util.HashMap;
import java.util.Map;

public class Main {

  public static void main(String[] args) {
    int[] numbers = new int[] { 10, 5, 10, 15, 10, 5 };
    countFreqIterative(numbers);
    countFreqMap(numbers);
  }

  // Time Complexity: O(N^2)
  private static void countFreqIterative(int[] arr) {
    int maxEle = 0;
    int maxFreq = 0;
    int minEle = 0;
    int minFreq = arr.length;
    boolean[] visited = new boolean[arr.length];

    for (int i = 0; i < arr.length; i++) {
      if (visited[i]) {
        continue;
      }

      int freq = 1;
      for (int j = i + 1; j < arr.length; j++) {
        if (arr[i] == arr[j]) {
          visited[j] = true;
          freq++;
        }
      }

      if (freq > maxFreq) {
        maxEle = arr[i];
        maxFreq = freq;
      }

      if (freq < minFreq) {
        minEle = arr[i];
        minFreq = freq;
      }
    }

    System.out.println("The lowest frequency element is: " + minEle);
    System.out.println("The highest frequency element is: " + maxEle);
  }

  // Time Complexity: O(N)
  private static void countFreqMap(int[] arr) {
    HashMap<Integer, Integer> fm = buildFrequencyMap(arr);

    int maxEle = 0;
    int maxFreq = 0;
    int minEle = 0;
    int minFreq = arr.length;

    for (Map.Entry<Integer, Integer> entry : fm.entrySet()) {
      int freq = entry.getValue();
      int element = entry.getKey();

      if (freq < minFreq) {
        minEle = element;
        minFreq = freq;
      }

      if (freq > maxFreq) {
        maxEle = element;
        maxFreq = freq;
      }
    }

    System.out.println("The lowest frequency element is: " + minEle);
    System.out.println("The highest frequency element is: " + maxEle);
  }

  private static HashMap<Integer, Integer> buildFrequencyMap(int[] arr) {
    HashMap<Integer, Integer> fm = new HashMap<>();

    for (int value : arr) {
      int freq = 0;

      if (fm.containsKey(value)) {
        freq = fm.get(value);
      }

      freq++;
      fm.put(value, freq);
    }

    return fm;
  }
}
