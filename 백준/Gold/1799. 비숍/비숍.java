import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Chess{
    int N;
    int[] ans = new int[2];
    int[][] board;
    boolean[] l,r;

    Chess(int N){
        this.N = N;
        this.board = new int[N][N];
        this.l = new boolean[2*N-1];
        this.r = new boolean[2*N-1];
    }

    public void tracking(int row, int col, int count, int color){
        if(col>=N){
            row++;
            if(col%2==0)col=1;
            else col=0;
        }
        if(row>=N){
            ans[color]=Math.max(ans[color],count);
            return;
        }

        if(board[row][col]==1&&!l[col - row + N -1]&& !r[row+col]){
            l[col - row+N-1]=true;
            r[row+col]= true;
            tracking(row, col+2, count+1, color);
            l[col - row + N-1]=false;
            r[row+col]=false;
        }
        tracking(row, col+2, count, color);
    }

    public int getMaxBishops(){
        return ans[0] + ans[1];
    }
}


public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        
        Chess chess =new Chess(N);

        for(int i =0;i<N;i++){
            for(int j=0;j<N;j++){
                chess.board[i][j]=sc.nextInt();
            }
        }

        chess.tracking(0,0,0,0);
        chess.tracking(0,1,0,1);

        System.out.println(chess.getMaxBishops());
    }
}