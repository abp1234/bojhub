import java.io.*;
import java.util.*;

public class Main{
    static class Seg{
        int x1, y1, x2, y2;
        Seg(int x1, int y1, int x2, int y2){
            this.x1 = x1;
            this.y1 = y1;
            this.x2 = x2;
            this.y2 = y2;
        }
    }

    static boolean cross(Seg a, Seg b){
        return Math.max(a.x1, a.x2)>=Math.min(b.x1, b.x2)&&
                Math.max(b.x1, b.x2)>=Math.min(a.x1, a.x2)&&
                Math.max(a.y1, a.y2)>=Math.min(b.y1,b.y2)&&
                Math.max(b.y1, b.y2)>=Math.min(a.y1, a.y2);
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int m = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(st.nextToken());

        int k = Integer.parseInt(br.readLine());
        List<Seg> segs = new ArrayList<>();

        for(int i = 0; i < k;i++){
            st = new StringTokenizer(br.readLine());
            st.nextToken();
            int x1 = Integer.parseInt(st.nextToken());
            int y1 = Integer.parseInt(st.nextToken());
            int x2 = Integer.parseInt(st.nextToken());
            int y2 = Integer.parseInt(st.nextToken());
            segs.add(new Seg(x1, y1, x2, y2));
        }

        st = new StringTokenizer(br.readLine());
        int sx = Integer.parseInt(st.nextToken());
        int sy = Integer.parseInt(st.nextToken());
        int dx = Integer.parseInt(st.nextToken());
        int dy = Integer.parseInt(st.nextToken());

        segs.add(new Seg(sx,sy,sx,sy));
        segs.add(new Seg(dx,dy,dx,dy));

        Queue<int[]> q=new ArrayDeque<>();
        boolean[] vis = new boolean[k+2];
        q.add(new int[]{k,0});

        while (!q.isEmpty()){
            int[] cur = q.poll();
            int idx = cur[0];
            int cnt = cur[1];
            if(vis[idx])continue;
            vis[idx]=true;

            if(idx==k+1){
                System.out.println(cnt-1);
                return;
            }

            for(int i=0;i<k+2;i++){
                if(!vis[i]&&cross(segs.get(idx), segs.get(i))){
                    q.add(new int[]{i,cnt+1});
                }
            }
        }

    }
}