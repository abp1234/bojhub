import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main {
    static int[][][] bd = new int[4][4][2]; 
    static int[] dx = {-1, -1, 0, 1, 1, 1, 0, -1};
    static int[] dy = {0, -1, -1, -1, 0, 1, 1, 1};
    static int mx = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter w = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < 4; i++) {
            StringTokenizer t = new StringTokenizer(r.readLine());
            for (int j = 0; j < 4; j++) {
                int n = Integer.parseInt(t.nextToken());
                int d = Integer.parseInt(t.nextToken()) - 1;
                bd[i][j][0] = n;
                bd[i][j][1] = d;
            }
        }

        dfs(0, 0, 0, cp(bd));
        sb.append(mx).append("\n");
        w.write(sb.toString());
        w.flush();
        w.close();
        r.close();
    }

    static void dfs(int sx, int sy, int sc, int[][][] b) {
        sc += b[sx][sy][0];
        b[sx][sy][0] = 0;
        if (sc > mx) mx = sc;
        
        for (int f = 1; f <= 16; f++) {
            int fx = -1, fy = -1;
            out:
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (b[i][j][0] == f) {
                        fx = i;
                        fy = j;
                        break out;
                    }
                }
            }
            if (fx == -1) continue;
            int fd = b[fx][fy][1];
            for (int i = 0; i < 8; i++) {
                int nd = (fd + i) % 8;
                int nx = fx + dx[nd];
                int ny = fy + dy[nd];
                if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4 || (nx == sx && ny == sy)) continue;
                b[fx][fy][1] = nd;
                int[] tmp = b[fx][fy];
                b[fx][fy] = b[nx][ny];
                b[nx][ny] = tmp;
                break;
            }
        }

        int sd = b[sx][sy][1];
        for (int i = 1; i <= 4; i++) {
            int nx = sx + dx[sd] * i;
            int ny = sy + dy[sd] * i;
            if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4 || b[nx][ny][0] == 0) continue;
            dfs(nx, ny, sc, cp(b));
        }
    }

    static int[][][] cp(int[][][] b) {
        int[][][] nb = new int[4][4][2];
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                nb[i][j] = b[i][j].clone();
        return nb;
    }
}
