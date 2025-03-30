import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static int[] dx = {-1,1,0,0};
    static int[] dy = {0,0,-1,1};
    static int[] rk = {1,0,3,2};

    static int[][] diceMap = new int[4][3];
    static int[][] mapList = new int[6][6];
    static boolean[] visited = new boolean[7];

    static void diceMove(int k){
        if(k==0){
            int temp = diceMap[1][0];
            diceMap[1][0] = diceMap[1][1];
            diceMap[1][1] = diceMap[1][2];
            diceMap[1][2] = diceMap[3][1];
            diceMap[3][1] = temp;
        } else if(k==1){

            int temp = diceMap[1][0];
            diceMap[1][0] = diceMap[3][1];
            diceMap[3][1] = diceMap[1][2];
            diceMap[1][2] = diceMap[1][1];
            diceMap[1][1] = temp;
        } else if (k==2){
            int temp = diceMap[0][1];
            diceMap[0][1] = diceMap[1][1];
            diceMap[1][1] = diceMap[2][1];
            diceMap[2][1] = diceMap[3][1];
            diceMap[3][1] = temp;
        }else{
            int temp = diceMap[0][1];
            diceMap[0][1] = diceMap[3][1];
            diceMap[3][1] = diceMap[2][1];
            diceMap[2][1] = diceMap[1][1];
            diceMap[1][1] = temp;
        }
    }

    static boolean dfs(int x, int y){
        visited[mapList[y][x]] = true;
        if(diceMap[1][1]!=0){
            return false;
        }
        diceMap[1][1] = mapList[y][x];
        boolean result = true;
        int cnt = 1;

        for(int k=0; k<4; k++){
            int ax = x + dx[k], ay=y+dy[k];
            if(ax>=0&&ax<6&&ay>=0&&ay<6&&mapList[ay][ax]>0&&!visited[mapList[ay][ax]]){
                diceMove(k);
                boolean _result = dfs(ax, ay);
                result &= _result;
                cnt += _result ? 1 : 0;
                diceMove(rk[k]);
            }
        }
        return result;
    }

    static boolean search(){
        for(int i = 0; i<6;i++){
            for(int j = 0; j<6;j++){
                if(mapList[i][j]==1){
                    return dfs(j,i);
                }
            }
        }
        return false;
    }

    public static void solve() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));


        for(int i = 0; i<6; i++){
            StringTokenizer st=new StringTokenizer(br.readLine());
            for(int j = 0; j<6;j++){
                mapList[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        boolean isValid = search();
        int cnt = isValid ? 6 : 0;

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        bw.write((isValid && cnt ==6)? String.valueOf(diceMap[3][1]):"0");
        bw.newLine();
        bw.flush();
    }

    public static void main(String[] args) throws IOException {
        solve();
    }


}