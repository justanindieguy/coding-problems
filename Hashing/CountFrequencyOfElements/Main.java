import java.util.HashMap;

public class Main {

  public static void main(String[] args) {
    int[] numbers = new int[] { 10, 5, 10, 15, 10, 5 };
    System.out.println("Iteration:");
    countFrequency(numbers);

    System.out.println();

    System.out.println("Frequency Map:");
    HashMap<Integer, Integer> hm = buildFrequencyMap(numbers);
    hm.forEach((k, v) -> System.out.println(k + " -> " + v));
  }

  private static void countFrequency(int[] array) {
    boolean[] visited = new boolean[array.length];

    for (int i = 0; i < array.length; i++) {
      if (visited[i]) {
        continue;
      }

      int freq = 1;
      for (int j = i + 1; j < array.length; j++) {
        if (array[i] == array[j]) {
          visited[j] = true;
          freq++;
        }
      }

      System.out.println(array[i] + " -> " + freq);
    }
  }

  private static HashMap<Integer, Integer> buildFrequencyMap(int[] array) {
    HashMap<Integer, Integer> hm = new HashMap<>();

    for (int val : array) {
      int freq = 0;

      if (hm.containsKey(val)) {
        freq = hm.get(val);
      }

      freq++;
      hm.put(val, freq);
    }

    return hm;
  }
}
