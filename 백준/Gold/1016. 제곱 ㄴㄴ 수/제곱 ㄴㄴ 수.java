import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        long mn = Long.parseLong(st.nextToken());
        long mx = Long.parseLong(st.nextToken());

        long count = mx - mn + 1;
        boolean[] me = new boolean[(int) count];

        for (long i = 2; i * i <= mx; i++) {
            long sq = i * i;
            long stt = (mn % sq == 0) ? mn : ((mn / sq) + 1) * sq;

            for (long j = stt; j <= mx; j += sq) {
                int idx = (int) (j - mn);
                if (!me[idx]) {
                    me[idx] = true;
                    count--;
                }
            }
        }

        bw.write(String.valueOf(count));
        bw.flush();
        bw.close();
        br.close();
    }
}
