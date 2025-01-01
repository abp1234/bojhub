import java.io.*;
import java.util.*;

class Main{

    static final int MAX = Integer.MAX_VALUE;
    static int[] p;
    static Map<Integer, List<Integer>> cm = new HashMap<>();

    static int fd(int a){
        if(p[a]==a)return a;
        return p[a]=fd(p[a]);
    }

    static void un(int a, int b){
        int da = fd(a);
        int db = fd(b);
        if(da>db)p[db]=da;
        else p[da]=db;
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());

        p=new int[n];
        for(int i=0;i<n;i++){
            p[i]=i;
        }

        int[][] el = new int[n][n];
        for(int[] row:el){
            Arrays.fill(row, MAX);
        }
        for(int i=0;i<m;i++){
            st=new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken())-1;
            int b = Integer.parseInt(st.nextToken())-1;
            el[a][b]=el[b][a]=1;
            un(a,b);
        }
        for(int k=0;k<n;k++){
            int dk = fd(k);
            cm.computeIfAbsent(dk, v -> new ArrayList<>()).add(k);
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if (el[i][j] > el[i][k] + el[k][j] && el[i][k] != MAX && el[k][j] != MAX) {
                        el[i][j]=el[i][k]+el[k][j];
                    }
                }
            }
        }

        List<Integer> ans = new ArrayList<>();
        for(List<Integer> c : cm.values()){
            int r = 0, rv =MAX;
            for(int a :c){
                int tv =0;
                for(int b : c){
                    if(a==b)continue;
                    tv=Math.max(tv,el[a][b]);
                }
                if(rv>tv){
                    r=a;
                    rv=tv;
                }
            }ans.add(r+1);
        }
        Collections.sort(ans);
        StringBuilder sb = new StringBuilder();
        sb.append(ans.size()).append("\n");
        for(int a : ans){
            sb.append(a).append("\n");
        }
        bw.write(sb.toString());
        bw.flush();
        bw.close();
        br.close();
    }
}