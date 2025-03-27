import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class Main {
    static int n, k, res = 0;
    static List<String> w = new ArrayList<>();
    static StringBuilder sb = new StringBuilder();

    static class K{
        char[] p;
        int[] t;

        K(String s){
            this.p = s.toCharArray();
            this.t = new int[p.length];
            int i = 0;
            for(int j = 1; j < p.length; j++){
                while  (i>0 && p[i] != p[j])i=t[i-1];
                if(p[i] == p[j])t[j]=++i;
            }
        }

        boolean m(char[] a){
            int i =0,c=-1;
            for(int j =0;j<a.length;j++){
                while(i>0&&p[i]!=a[j])i=t[i-1];
                if(p[i]==a[j]){
                    i++;
                    if(i==p.length){
                        c++;
                        i=t[i-1];
                    }
                }
            }
            return c==k;
        }
    }
    static void d(boolean[] v,List<String> cur){
        if(cur.size()==n){
            StringBuilder tmp = new StringBuilder();
            for(String s : cur)tmp.append(s);
            char[] a = (tmp.toString()+tmp).toCharArray();
            K kmp = new K(tmp.toString());
            if(kmp.m(a))res++;
            return;
        }
        for(int i =0; i<n;i++){
            if(!v[i]){
                v[i]=true;
                cur.add(w.get(i));
                d(v,cur);
                cur.remove(cur.size()-1);
                v[i]=false;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) w.add(br.readLine());
        k = Integer.parseInt(br.readLine());
        d(new boolean[n], new ArrayList<>());

        bw.write(res+"\n");
        bw.flush();
        bw.close();
    }

}