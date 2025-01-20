import java.io.*;
import java.util.*;

class UF {
    int[] p;
    int c;

    UF(int n){
        p = new int[n+1];
        for(int i =0;i<=n;i++){
            p[i]=i;
        }
        c=n;
    }
    int f(int a){
        if(p[a]==a) return a;
        return p[a]=f(p[a]);
    }

    void u(int a, int b){
        int pa = f(a);
        int pb = f(b);
        if(pa==pb)return;
        if(pa>pb){
            int tmp = pa;
            pa=pb;
            pb=tmp;
        }
        p[pb]=pa;
        c--;
    }
}

public class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());


        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        List<double[]>q=new ArrayList<>();
        UF uf = new UF(n);

        for(int i = 0; i < m;i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            double c = Double.parseDouble(st.nextToken());
            q.add(new double[]{c, 0, a, b});
        }
        int qn = Integer.parseInt(br.readLine());
        int[] ans = new int[qn];

        for(int i = 0; i< qn; i++){
            double c = Double.parseDouble(br.readLine());
            q.add(new double[]{c,1,i});
        }
        q.sort((a,b)->Double.compare(b[0],a[0])!=0?Double.compare(b[0],a[0]):Double.compare(a[1],b[1]));

        for(double[]e:q){
            if(e[1]==0){
                uf.u((int)e[2],(int)e[3]);
            }else{
                ans[(int)e[2]]=uf.c;
            }
        }

        StringBuilder sb = new StringBuilder();
        for(int i : ans){
            sb.append(i).append("\n");
        }
        bw.write(sb.toString());
        bw.flush();
        bw.close();
    }
}