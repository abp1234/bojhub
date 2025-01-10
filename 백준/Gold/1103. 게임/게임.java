import java.io.*;
import java.util.*;

public class Main {
    static final int MAX = 50;
    static int n, m, ans;
    static int[][] map = new int[MAX][MAX];
    static int[][] dp = new int[MAX][MAX];
    static boolean[][] vis = new boolean[MAX][MAX];
    static int[] dx ={0,0,1,-1};
    static int[] dy ={1,-1,0,0};

    static int max(int a, int b){
        return Math.max(a,b);
    }

    static void input(BufferedReader br) throws IOException{
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        for(int i = 0;i<n;i++){
            String s = br.readLine();
            for(int j =0;j<s.length();j++){
                if(s.charAt(j)=='H')map[i][j]=0;
                else map[i][j] = s.charAt(j)-'0';
            }
        }
    }

    static int dfs(int x, int y){
        if(x<0||y<0||x>=n||y>=m||map[x][y]==0) return 0;
        if(vis[x][y]){
            System.out.println(-1);
            System.exit(0);
        }
        if(dp[x][y]!=-1)return dp[x][y];

        vis[x][y]=true;
        dp[x][y]=0;

        for(int i =0; i<4;i++){
            int nx = x + map[x][y]*dx[i];
            int ny = y + map[x][y]*dy[i];
            dp[x][y] = max(dp[x][y],dfs(nx,ny)+1);
        }

        vis[x][y]=false;
        return dp[x][y];
    }

    static void solve(BufferedReader br) throws IOException{
        input(br);
        for(int[] row: dp) Arrays.fill(row,-1);
        ans = dfs(0,0);
        System.out.println(ans);
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        solve(br);
    }
}