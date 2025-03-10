import java.io.*;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {
    static final int IF = 100000000;

    static class SM{
        Map<Character,Map<Character,Integer>>m;
        SM(){
            m=new HashMap<Character,Map<Character,Integer>>();
        }
        void in(){
            char[] ch = new char[]{'A','C','G','T','*'};
            int[][] ar = {
                    { 5, -1, -2, -1, -3 },
                    { -1, 5, -3, -2, -4 },
                    { -2, -3, 5, -2, -2 },
                    { -1, -2, -2, 5, -1 },
                    { -3, -4, -2, -1, 0 }
            };

            for(int i =0;i<5;i++){
                Map<Character,Integer>mm = new HashMap<Character,Integer>();
                for (int j = 0; j < 5; j++){
                    mm.put(ch[j],ar[i][j]);
                }
                m.put(ch[i],mm);
            }
        }
        int sc(char a, char b){
            return m.get(a).get(b);
        }
    }

    static class DP{
        int[][] d;
        DP(int n, int m){
            d = new int[n][m];
            for(int i = 0; i<n;i++){
                for(int j =0;j<m;j++){
                    d[i][j]=-1;
                }
            }
        }
    }

    static int rc(int a, int b, int n, int m, String s1, String s2, DP dp, SM sm){
        if(a == n){
            int tt =0;
            for(int i = b; i<m;i++){
                tt += sm.sc('*',s2.charAt(i));
            }
            return tt;
        }
        if(b==m){
            int tt =0;
            for(int i = a; i<n;i++){
                tt += sm.sc(s1.charAt(i),'*');
            }
            return tt;
        }

        if(dp.d[a][b]!=-1)return dp.d[a][b];
        int rt = -IF;
        rt = Math.max(rt,rc(a+1,b+1,n,m,s1,s2,dp,sm)+sm.sc(s1.charAt(a),s2.charAt(b)));
        rt = Math.max(rt,rc(a,b+1,n,m,s1,s2,dp,sm)+sm.sc('*',s2.charAt(b)));
        rt = Math.max(rt, rc(a+1,b,n,m,s1,s2,dp,sm)+sm.sc(s1.charAt(a),'*'));
        dp.d[a][b]=rt;
        return rt;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        SM sm = new SM();
        sm.in();

        int tc = Integer.parseInt(br.readLine().trim());
        for(int i = 0; i<tc;i++){

            StringTokenizer st1 = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st1.nextToken());
            String s1 = st1.nextToken();

            StringTokenizer st2 = new StringTokenizer(br.readLine());
            int m = Integer.parseInt(st2.nextToken());
            String s2 = st2.nextToken();

            if(n<m){
                int t = n;n=m;m=t;
                String tp = s1;s1=s2;s2=tp;
            }
            DP dp = new DP(n+1,m+1);
            int rs = rc(0,0,n,m,s1,s2,dp,sm);
            sb.append(rs).append("\n");
        }
        bw.write(sb.toString());
        bw.flush();
        bw.close();
        br.close();
    }
}