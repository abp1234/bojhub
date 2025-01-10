import java.io.*;
import java.util.*;

public class Main {
    static int n, m;
    static char[][] map;
    static int[][] near;
    static int[] dx = {-1, 0, 1, 1, 1, 0, -1, -1};
    static int[] dy = {1, 1, 1, 0, -1, -1, -1, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        map = new char[n][m];
        near = new int[n][m];
        Queue<int[]> q = new LinkedList<>();


        for (int i = 0; i < n; i++) {
            String row = br.readLine();
            for (int j = 0; j < m; j++) {
                map[i][j] = row.charAt(j);
                if (map[i][j] >= '1' && map[i][j] <= '8') {
                    q.add(new int[]{i, j});
                }
            }
        }


        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] != '.') {
                    int cnt = 0;
                    for (int k = 0; k < 8; k++) {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if (isInBounds(nx, ny) && map[nx][ny] == '.') {
                            cnt++;
                        }
                    }
                    near[i][j] = cnt;
                }
            }
        }


        int t = 0;
        while (true) {
            Queue<int[]> q2 = new LinkedList<>();


            while (!q.isEmpty()) {
                int[] cur = q.poll();
                int a = cur[0];
                int b = cur[1];

                int cnt = 0;
                for (int k = 0; k < 8; k++) {
                    int nx = a + dx[k];
                    int ny = b + dy[k];
                    if (isInBounds(nx, ny) && map[nx][ny] == '.') {
                        cnt++;
                    }
                }

                if (cnt >= map[a][b] - '0') {
                    q2.add(new int[]{a, b});
                }
            }

            if (q2.isEmpty()) {
                System.out.println(t);
                break;
            }


            while (!q2.isEmpty()) {
                int[] cur = q2.poll();
                int a = cur[0];
                int b = cur[1];

                map[a][b] = '.';

                for (int k = 0; k < 8; k++) {
                    int nx = a + dx[k];
                    int ny = b + dy[k];
                    if (isInBounds(nx, ny) && map[nx][ny] >= '1' && map[nx][ny] <= '8') {
                        near[nx][ny]++;
                        if (near[nx][ny] == map[nx][ny] - '0') {
                            q.add(new int[]{nx, ny});
                        }
                    }
                }
            }
            t++;
        }
    }


    static boolean isInBounds(int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }
}
