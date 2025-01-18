import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.ArrayList;
import java.util.Arrays;

public class Main{

    static class R{
        int[] a;
        R(int c){
            a = new int[c];
        }
    }

    public static void main(String[] args) throws  IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int nn = Integer.parseInt(st.nextToken());
        int cc = Integer.parseInt(st.nextToken());
        int mm = Integer.parseInt(st.nextToken());

        ArrayList<R> al = new ArrayList<R>(nn);

        for(int i = 0; i <nn; i++){
            st = new StringTokenizer(br.readLine());
            R r = new R(cc);
            for(int j =0; j<cc;j++){
                r.a[j]=Integer.parseInt(st.nextToken());
            }
            al.add(r);
        }
        int[] dp = new int[500010];

        for (int j = 1; j < cc;j++){
            Arrays.fill(dp,0);

            for(int i = 0; i< nn; i++){
                R r = al.get(i);
                for(int k = 1; k <= mm; k++){
                    if(k - r.a[j-1]<0)continue;
                    dp[k]=Math.max(dp[k], dp[k-r.a[j-1]]+(r.a[j]-r.a[j-1]));
                }
            }mm+=dp[mm];
        }


        StringBuilder sb = new StringBuilder();
        sb.append(mm);
        bw.write(sb.toString());
        bw.newLine();
        bw.flush();

        bw.close();
        br.close();
    }

}