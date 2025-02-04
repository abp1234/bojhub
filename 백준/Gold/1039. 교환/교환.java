import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class Main{
    static class Q{
        int n,k;
        Q(int n, int k){
            this.n = n;
            this.k = k;
        }
    }

    public static void main(String[] z) throws Exception{
        BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter w = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer x = new StringTokenizer(r.readLine());

        int n = Integer.parseInt(x.nextToken());
        int k = Integer.parseInt(x.nextToken());
        int m = String.valueOf(n).length();
        if (m < 2) {
            w.write("-1\n");
            w.flush();
            return;
        }
        int ans = bfs(n,k,m);

        w.write(ans+"\n");
        w.flush();
    }

    static int bfs(int n, int k, int m){
        int mx = (int) Math.pow(10, m);
        Queue<Q> q = new LinkedList<>();
        boolean[][] v = new boolean[k + 1][mx];

        q.add(new Q(n,0));
        v[0][n] = true;

        int a = -1;
        while (!q.isEmpty()){
            Q p = q.poll();
            if(p.k==k){
                a=Math.max(a,p.n);
                continue;
            }

            char[] s = String.valueOf(p.n).toCharArray();
            for(int i = 0;i<m-1;i++){
                for(int j = i+1;j<m;j++){
                    if(i==0&&s[j]=='0')continue;
                    swap(s,i,j);
                    int nn = Integer.parseInt(new String(s));
                    if(!v[p.k + 1][nn]){
                        v[p.k + 1][nn] = true;
                        q.add(new Q(nn, p.k + 1));
                    }
                    swap(s,i,j);
                }
            }
        }
        return a;
    }
    static void swap(char[] s, int i, int j){
        char t= s[i];
        s[i]=s[j];
        s[j]=t;
    }
}