import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main{
    static int n,m,b;
    static char[][] mp;
    static  boolean[][][] vis;
    static int[] dx ={0,0,1,-1};
    static int[] dy={1,-1,0,0};
    static Pair st, en;

    static class Pair{
        int x,y,cnt,bs;
        Pair(int x, int y, int cnt, int bs){
            this.x = x;
            this.y = y;
            this.cnt = cnt;
            this.bs = bs;
        }
    }

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer stz = new StringTokenizer(br.readLine());
        m = Integer.parseInt(stz.nextToken());
        n = Integer.parseInt(stz.nextToken());
        mp = new char[n][m];

        int idx = 0;
        for(int i=0;i<n;i++){
            String line = br.readLine();
            for(int j =0;j<m;j++){
                mp[i][j]=line.charAt(j);
                if(mp[i][j]=='S'){
                    st = new Pair(i,j,0,0);
                }else if(mp[i][j]=='X'){
                    mp[i][j]=(char)('0'+idx++);
                }
            }
        }
        b=(1<<idx)-1;
        vis = new boolean[n][m][1<<idx];

        int res = bfs();
        bw.write(res+"\n");
        bw.flush();
        br.close();
        bw.close();
    }

    static int bfs(){
        Queue<Pair> q = new ArrayDeque<>();
        q.add(st);
        vis[st.x][st.y][0]=true;

        while(!q.isEmpty()){
            Pair cur = q.poll();
            int x = cur.x, y=cur.y,cnt = cur.cnt, bs =cur.bs;

            if(mp[x][y]=='E'&&bs==b){
                return cnt;
            }

            for(int i=0;i<4;i++){
                int nx = x+dx[i],ny=y+dy[i],nbs=bs;

                if(nx>=0 && ny>=0&&nx<n&&ny<m&&mp[nx][ny]!='#'){
                    if('0'<=mp[nx][ny]&&mp[nx][ny]<='4'){
                        nbs |=(1<<(mp[nx][ny]-'0'));
                    }
                    if(!vis[nx][ny][nbs]){
                        vis[nx][ny][nbs]=true;
                        q.add(new Pair(nx,ny,cnt+1,nbs));
                    }
                }
            }
        }
        return -1;
    }
}