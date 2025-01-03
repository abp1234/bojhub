import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        String str = br.readLine();

        StringBuilder sang = new StringBuilder();
        StringBuilder hee = new StringBuilder();
        boolean[] visit = new boolean[n];

        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> {
            if (a[0] != b[0]) return Integer.compare(a[0], b[0]);
            return Integer.compare(a[1], b[1]);
        });

        for (int i = 0; i < n; i++) {
            pq.add(new int[]{str.charAt(i) - 'a', -i});
        }

        int idx = n - 1;
        while (!pq.isEmpty() && idx >= 0) {
            while (idx >= 0 && visit[idx]) {
                idx--;
            }
            if (idx < 0) break;

            sang.append(str.charAt(idx));
            visit[idx] = true;
            idx--;

            while (!pq.isEmpty() && visit[-pq.peek()[1]]) {
                pq.poll();
            }

            if (pq.isEmpty()) break;

            hee.append((char) ('a' + pq.peek()[0]));
            visit[-pq.poll()[1]] = true;
        }

        String result = "NE\n";
        if (hee.toString().compareTo(sang.toString()) < 0) {
            result = "DA\n";
        }

        bw.write(result);
        bw.write(hee.toString() + "\n");
        bw.flush();
        bw.close();
    }
}
