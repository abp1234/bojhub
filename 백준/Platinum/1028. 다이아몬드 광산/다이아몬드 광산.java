import java.io.*;
import java.util.*;

public class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));


        String[] firstLine = br.readLine().split(" ");
        int r = Integer.parseInt(firstLine[0]);
        int c = Integer.parseInt(firstLine[1]);
        int res = 0;

        int[][] ld = new int[r][c];
        int[][] rd = new int[r][c];

        for(int i = 0; i < r;i++){
            String line = br.readLine();
            for(int j=0;j<c;j++){
                char input = line.charAt(j);
                if(input=='0'){
                    ld[i][j]=0;
                    rd[i][j]=0;
                }else{
                    ld[i][j]=1;
                    rd[i][j]=1;
                }
            }
        }

        for(int i=r-2;i>=0;i--){
            for(int j=0;j<c;j++){
                if(ld[i][j]==1&&j!=0){
                    ld[i][j]+=ld[i+1][j-1];
                }
                if(rd[i][j]==1&&j!=c-1){
                    rd[i][j]+=rd[i+1][j+1];
                }
            }
        }

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(ld[i][j]!=0&&rd[i][j]!=0){
                    res = Math.max(res,1);
                    if(ld[i][j]!=1&&rd[i][j]!=1){
                        int n =Math.min(ld[i][j],rd[i][j]);
                        while(n>1){
                            if(rd[i+n-1][j-n+1]>=n&&ld[i+n-1][j+n-1]>=n){
                                res=Math.max(res,n);
                            }
                            n--;
                        }
                    }
                }
            }
        }

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        bw.write(res+"\n");
        bw.flush();
        bw.close();
    }
}