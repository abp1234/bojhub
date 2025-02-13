import java.io.*;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

class Main{
    static class N{
        int v;
        N p;
        N(int v, N p){this.v=v;this.p=p;}
    }

    public static void main(String[] z) throws IOException{
        BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter w = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer t;
        StringBuilder o = new StringBuilder();

        int n = Integer.parseInt(r.readLine());
        int[] l = new int[n];
        for(int i = 0;i < n;i++){
            l[i]=Integer.parseInt(r.readLine());
        }

        Deque<N> s = new ArrayDeque<>();
        s.push(new N(1000000001, null));
        int p = 1, i = 0;
        long a = 0;
        
        while (i<n){
            if(l[i]<s.peek().v){
                s.push(new N(l[i],s.peek()));
                p++;
                i++;
            }else{
                N x = s.pop();
                p--;
                a += Math.min(l[i], s.peek().v);
            }
        }
        s.pop();
        p--;
        while (p>1){
            a+=s.pop().v;
            p--;
        }
        o.append(a).append("\n");
        w.write(o.toString());
        w.flush();
        w.close();
        r.close();
    }
}