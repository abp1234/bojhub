import java.io.*;
import java.util.*;

public class Main{
    static final long MOD = 1000000;
    static long[][] arr = {{1,1},{1,0}};
    static final long[][] rem ={{1,1},{1,0}};

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        long n = Long.parseLong(br.readLine().trim());
        if(n>1)rec(n-1);
        bw.write(arr[0][0]+"\n");
        bw.flush();
        br.close();
        bw.close();
    }

    static void rec(long x){
        if(x==1)return;
        rec(x/2);
        mul(arr,arr);
        if(x%2==1)mul(arr,rem);
    }

    static void mul(long[][] a, long[][] b){
        long[][] tmp = new long[2][2];
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                for(int k=0;k<2;k++){
                    tmp[i][j]=(tmp[i][j]+a[i][k]*b[k][j])%MOD;
                }
            }
        }
        for(int i=0;i<2;i++)System.arraycopy(tmp[i],0,a[i],0,2);
    }
}