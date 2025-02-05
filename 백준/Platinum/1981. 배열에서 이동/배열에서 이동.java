import java.io.*;
import java.util.*;

class Main{
    static int[][] b;
    static int n, min, max, s, e;
    static int[][] d = {{1,0},{-1,0},{0,1},{0,-1}};

    public static void main(String[] z) throws Exception{
        BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter w = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(r.readLine().trim());
        b = new int[n][n];
        min = 256; max = -1;

        for(int i = 0; i< n; i++){
            StringTokenizer x = new StringTokenizer(r.readLine());
            for(int j = 0; j < n;j++){
                b[i][j]=Integer.parseInt(x.nextToken());
                min=Math.min(min,b[i][j]);
                max= Math.max(max,b[i][j]);
            }
        }
        s = b[0][0];
        e = b[n-1][n-1];

        int ans = binSearch();
        w.write(ans+"\n");
        w.flush();
        w.close();
    }

    static int binSearch(){
        int l = 0, r = max, ans =0;
        while (l<=r){
            int m = (l+r)/2;
            if(chk(m)){
                ans=m;
                r=m-1;
            }else{
                l=m+1;
            }
        }
        return ans;
    }
    static boolean chk(int m){
        for(int i = min; i <= max; i++){
            if(i<=s&&s<=i+m&&i<=e&&e<=i+m){
                if(bfs(i,i+m))return true;
            }
        }
        return false;
    }

    static boolean bfs(int a, int e){
        boolean[][] v = new boolean[n][n];
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{0,0});
        v[0][0]=true;

        while (!q.isEmpty()){
            int[] p = q.poll();
            int y = p[0], x = p[1];

            if(y==n-1&&x==n-1)return true;
            for(int[] dir : d){
                int ny = y +dir[0], nx = x+dir[1];
                if(ny<0||nx<0||ny>=n||nx>=n)continue;
                if(v[ny][nx])continue;
                int num = b[ny][nx];
                if(num<a || num>e)continue;
                v[ny][nx]=true;
                q.add(new int[]{ny, nx});
            }
        }
        return false;
    }

}