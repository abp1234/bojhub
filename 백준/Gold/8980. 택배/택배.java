import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

class Pkg{
    int s, r, b;

    Pkg(int s, int r, int b){
        this.s = s;
        this.r = r;
        this.b = b;
    }
}

public class Main{
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(br.readLine());

        List<Pkg> pkgs = new ArrayList<>();
        for(int i = 0; i < m;i++){
            st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            int r = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            pkgs.add(new Pkg(s,r,b));
        }

        pkgs.sort((a, b) -> Integer.compare(a.r, b.r));

        int[] capa = new int[n+1];
        for(int i = 1; i <= n;i++){
            capa[i]=c;
        }

        int ttl = 0;

        for(Pkg p : pkgs){
            int minCap = Integer.MAX_VALUE;
            for(int i = p.s;i<p.r;i++){
                minCap = Math.min(minCap, Math.min(capa[i],p.b));
            }

            for(int i = p.s;i<p.r;i++){
                capa[i]-=minCap;
            }
            ttl+=minCap;
        }
        bw.write(ttl+"\n");
        bw.flush();

        br.close();
        bw.close();
    }

}