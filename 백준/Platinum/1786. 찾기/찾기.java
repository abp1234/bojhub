import java.io.*;
import java.util.*;

class KMP{
    char[] t, p;
    int[] pi;
    int n, m;

    KMP(String txt, String pat){
        t = txt.toCharArray();
        p = pat.toCharArray();
        n = t.length;
        m = p.length;
        pi = new int[m];
    }

    void makePi(){
        int j =0;
        for(int i =1;i<m;i++){
            while(j>0&&p[i]!=p[j])j=pi[j-1];
            if(p[i]==p[j])pi[i]=++j;
        }
    }

    void solve(BufferedWriter bw) throws  IOException{
        List<Integer> r = new ArrayList<>();
        int j = 0, c= 0;

        for(int i =0;i<n;i++){
            while(j>0&&t[i]!=p[j])j=pi[j-1];
            if(t[i]==p[j]){
                if(j==m-1){
                    r.add(i-m+2);
                    c++;
                    j=pi[j];
                }else j++;
            }
        }

        StringBuilder sb = new StringBuilder();
        sb.append(c).append("\n");
        for(int x : r)sb.append(x).append("\n");
        bw.write(sb.toString());
    }
}

public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String t = br.readLine();
        String p = br.readLine();

        KMP kmp = new KMP(t,p);
        kmp.makePi();
        kmp.solve(bw);

        bw.flush();
        bw.close();
        br.close();
    }


}