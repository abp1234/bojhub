import java.io.BufferedWriter;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.ArrayList;
import java.util.List;

public class Main{
    static final int IF = 1000000000;
    static int N,M;
    static int[][] g;
    static List<Integer>[][] p;

    public static void In() throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());

        g = new int[N+1][N+1];
        p = new ArrayList[N+1][N+1];

        for(int i = 1;i<=N;i++){
            for(int j =1; j<=N;j++){
                g[i][j]=IF;
                p[i][j] = new ArrayList<>();
            }
        }

        for(int i = 0;i<M;i++){
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());
            g[x][y]=Math.min(g[x][y],w);
        }
        br.close();
    }
    public static void Fl(){
        for(int k =1;k<=N;k++){
            for(int i =1;i<=N;i++){
                if(i==k)continue;
                for(int j = 1;j<=N;j++){
                    if(j==i||j==k)continue;
                    if(g[i][j]>g[i][k]+g[k][j]){
                        g[i][j]=g[i][k]+g[k][j];
                        p[i][j].clear();
                        p[i][j].addAll(p[i][k]);
                        p[i][j].add(k);
                        p[i][j].addAll(p[k][j]);
                    }
                }
            }
        }
    }

    public static void Out() throws IOException{
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        for(int i = 1; i<=N;i++){
            for(int j = 1; j<=N;j++){
                if(g[i][j]==IF){
                    sb.append("0 ");
                }else{
                    sb.append(g[i][j]).append(" ");
                }
            }
            sb.append('\n');
        }
        for(int i =1;i<=N;i++){
            for(int j = 1; j<=N;j++){
                if(g[i][j]==IF){
                    sb.append("0\n");
                }else{
                    int sz = p[i][j].size()+2;
                    sb.append(sz).append(" ").append(i).append(" ");
                    for(int nd : p[i][j]){
                        sb.append(nd).append(" ");
                    }
                    sb.append(j).append("\n");
                }
            }

        }
        bw.write(sb.toString());
        bw.flush();
        bw.close();
    }
    public static void main(String[] at) throws IOException{
        In();
        Fl();
        Out();
    }
    }

