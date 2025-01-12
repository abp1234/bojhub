import java.io.BufferedWriter;
import java.io.BufferedReader;
import java.io.OutputStreamWriter;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.StringTokenizer;

class B {
    int w,c,i;

    B(int w, int c, int i){
        this.w = w;
        this.c = c;
        this.i = i;
    }
}

public class Main{
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        int n = Integer.parseInt(br.readLine());
        List<B> balls = new ArrayList<>();

        for(int j = 0; j < n;j++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int c = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());
            balls.add(new B(w,c,j));
        }

        balls.sort(Comparator.comparingInt((B b) -> b.w).thenComparingInt(b -> b.c));

        int[] ans = new int[n];
        int[] cSum = new int[200020];
        int[] wSum = new int[200020];
        int sum = 0;

        for(int k = 0;k<n;k++){
            B b = balls.get(k);
            int w = b.w;
            int c = b.c;
            int idx = b.i;

            cSum[c]+=w;
            wSum[w]+=w;
            sum+=w;

            ans[idx] = sum - cSum[c] - wSum[w] + w;

            if(k>0 && balls.get(k-1).c == c && balls.get(k-1).w == w){
                ans[idx] = ans[balls.get(k-1).i];
            }
        }
        for(int a: ans){
            sb.append(a).append("\n");
        }
        
        bw.write(sb.toString());
        bw.flush();
        br.close();
        bw.close();

    }
}