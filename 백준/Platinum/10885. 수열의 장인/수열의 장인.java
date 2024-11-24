import java.io.*;
import java.util.StringTokenizer;

public class Main{
    private static final int MOD = 1000000007;

    private static int[] seq=new int[100000];
    private static long ans;
    private static int ansTwo;

    private static void check(int idx, int[] nowTwo, int[] nowMinus){
        if(seq[idx]==0){
            nowTwo[0]=0;
            nowMinus[0]=0;
            return;
        }
        if(seq[idx]<0){
            nowMinus[0]++;
            if(seq[idx]==-2)nowTwo[0]++;
        }else if(seq[idx]==2){
            nowTwo[0]++;
        }

        if(nowMinus[0]%2==0){
            ansTwo=Math.max(ansTwo,nowTwo[0]);
            ans=1;
        }
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        int t = Integer.parseInt(br.readLine());

        while(t-->0){
            int n = Integer.parseInt(br.readLine());
            StringTokenizer st = new StringTokenizer(br.readLine());

            ans = -3;
            ansTwo = 0;

            for(int i=0;i<n;i++){
                seq[i]=Integer.parseInt(st.nextToken());
                ans = Math.max(ans, seq[i]);
            }

            int[] nowTwo = new int[1];
            int[] nowMinus = new int[1];
            for(int i=0;i<n;i++){
                check(i,nowTwo,nowMinus);
            }

            nowTwo[0]=0;
            nowMinus[0]=0;
            for(int i=n-1;i>=0;i--){
                check(i,nowTwo,nowMinus);
            }
            while(ansTwo-->0){
                ans=(ans*2)%MOD;
            }

            sb.append(ans).append("\n");
        }
        bw.write(sb.toString());
        bw.flush();
        bw.close();
    }
}