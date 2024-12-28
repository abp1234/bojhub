import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    static final int[] DY = {-1, 1, 0, 0};
    static final int[] DX = {0, 0, -1, 1};
    static int[][] M;
    static int n, m;

    static class Node {
        int y, x;
        boolean skip;

        Node(int y, int x, boolean skip) {
            this.y = y;
            this.x = x;
            this.skip = skip;
        }
    }

    static boolean f(int mid) {
        if (M[0][0] > mid) return false;

        Queue<Node> q = new ArrayDeque<>();
        boolean[][][] vis = new boolean[n][m][2];
        q.add(new Node(0, 0, false));
        vis[0][0][0] = true;

        while (!q.isEmpty()) {
            Node cur = q.poll();
            int cy = cur.y, cx = cur.x;
            boolean skip = cur.skip;

            if (cy == n - 1 && cx == m - 1) return true;

            for (int i = 0; i < 4; i++) {
                int ny = cy + DY[i];
                int nx = cx + DX[i];

                if (ny >= 0 && nx >= 0 && ny < n && nx < m && M[ny][nx] <= mid && !vis[ny][nx][skip ? 1 : 0]) {
                    vis[ny][nx][skip ? 1 : 0] = true;
                    q.add(new Node(ny, nx, skip));
                }
            }

            if (!skip) {
                for (int i = 0; i < 4; i++) {
                    int ny = cy + DY[i] * 2;
                    int nx = cx + DX[i] * 2;

                    if (ny >= 0 && nx >= 0 && ny < n && nx < m && M[ny][nx] <= mid && !vis[ny][nx][1]) {
                        vis[ny][nx][1] = true;
                        q.add(new Node(ny, nx, true));
                    }
                }
            }
        }

        return false;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        M = new int[n][m];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                M[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        int p = 0, q = (int) 1e9, r = 0;
        while (p <= q) {
            int mid = (p + q) / 2;
            if (f(mid)) {
                r = mid;
                q = mid - 1;
            } else {
                p = mid + 1;
            }
        }

        bw.write(r + "\n");
        bw.flush();
        bw.close();
        br.close();
    }
}
