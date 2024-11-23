import java.io.BufferedWriter;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.Arrays;

class M{
    int a;
    int b;
    long[][] d;
    int[] c;

    M(int a, int b){
        this.a=a;
        this.b=b;
        this.d=new long[a][a];
        this.c=new int[b+1];
        Arrays.fill(this.c,-1);
    }
}

public class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int[] arr= new int[n];

        st = new StringTokenizer(br.readLine());
        for(int i=0;i<n;i++){
            arr[i]=Integer.parseInt(st.nextToken());
        }

        int val = Arrays.stream(arr).max().getAsInt();
        M m = new M(n,val);

        for(int i=0;i<n;i++){
            m.c[arr[i]]=i;
        }

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int d=Math.abs(arr[i]-arr[j]);
                if(arr[j]+d<=val&&m.c[arr[j]+d]!=-1){
                    m.d[i][j]=arr[i]+arr[j];
                }
            }
        }

        for(int i=0;i<n-1;i++){
            for(int j=0;j<n;j++){
                if(m.d[i][j]!=0){
                    int d = Math.abs(arr[i]-arr[j]);
                    if(arr[j]+d<=val&m.c[arr[j]+d]!=-1){
                        m.d[i][j]=arr[i]+arr[j];
                    }
                }
            }
        }

        for(int i=0;i<n-1;i++){
            for(int j=0;j<n;j++){
                if(m.d[i][j]!=0){
                    int d=Math.abs(arr[i]-arr[j]);
                    if(arr[j]+d<=val&&m.c[arr[j]+d]!=-1){
                        m.d[j][m.c[arr[j]+d]]=Math.max(m.d[j][m.c[arr[j]+d]],m.d[i][j]+arr[m.c[arr[j]+d]]);
                    }
                }
            }
        }
        long ans=0;
        for(long[] x:m.d){
            ans=Math.max(ans,Arrays.stream(x).max().getAsLong());
        }

        bw.write(String.valueOf(ans));
        bw.flush();
    }
}