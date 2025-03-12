import java.io.*;
import java.util.*;

class Main{
    static int[] v, rv;
    static List<Integer>[] g;
    static List<Integer>[] r;
    static int s, e, n, l;

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        l = Integer.parseInt(st.nextToken());

        v = new int[n+1];
        rv = new int[l+1];
        g = new ArrayList[n+1];
        r = new ArrayList[l];

        for(int i =0;i<=n;i++)g[i]=new ArrayList<>();
        for(int i = 0; i<l;i++)r[i]=new ArrayList<>();

        for(int i =0; i<l;i++){
            st = new StringTokenizer(br.readLine());
            while(st.hasMoreTokens()){
                int x = Integer.parseInt(st.nextToken());
                if(x==-1) break;
                g[x].add(i);
                r[i].add(x);
            }
        }

        st=new StringTokenizer(br.readLine());
        s = Integer.parseInt(st.nextToken());
        e = Integer.parseInt(st.nextToken());

        int res = bfs();
        bw.write(res+"\n");
        bw.flush();
    }

    static int bfs(){
        Deque<Integer> q = new ArrayDeque<>();
        q.add(s);
        v[s]=1;

        while (!q.isEmpty()){
            int c = q.poll();

            if(c==e)return (s==e)?0:v[c]-2;

            for(int i : g[c]){
                if(rv[i]==1)continue;
                rv[i]=1;

                for(int j : r[i]){
                    if(v[j]>0||j==-1)continue;
                    v[j]=v[c]+1;
                    q.add(j);
                }
            }
        }
        return -1;
    }
}