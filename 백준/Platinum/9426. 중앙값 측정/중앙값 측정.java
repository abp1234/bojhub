import java.io.*;
import java.util.*;

public class Main{
    private static final int MAX_N = 250001;
    private static final int MAX_T = 1000001;
    private static int N,K;
    private static int[] arr = new int[MAX_N];
    private static int[] segTree = new int[MAX_T];
    private static long ans = 0;

    private static void input(BufferedReader br) throws IOException{
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(br.readLine()); 
        }
    }

    private static void update(int node, int start, int end, int val, int diff){
        if(start==end){
            segTree[node]+=diff;
            return;
        }
        int mid =(start+end)/2;
        if(val<=mid){
            update(node*2,start,mid,val,diff);
        }else{
            update(node*2+1,mid+1,end,val,diff);
        }
        segTree[node]=segTree[node*2]+segTree[node*2+1];
    }

    private static int find(int node, int start, int end, int val){
        if(start == end){
            return start;
        }
        int mid = (start+end)/2;
        if(val<=segTree[node*2]){
            return find(node*2,start,mid,val);
        }else{
            return find(node*2+1,mid+1,end,val-segTree[node*2]);
        }
    }

    private static void init(){
        for(int i=0;i<K-1;i++){
            update(1,0,65535,arr[i],1);
        }
    }

    private static void calculate(){
        for(int i =K-1;i<N;i++){
            update(1,0,65535,arr[i],1);
            ans+=find(1,0,65535,(K+1)/2);
            update(1,0,65535,arr[i-K+1],-1);
        }
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        input(br);
        init();
        calculate();
        bw.write(ans+"\n");
        bw.flush();
        bw.close();
    }
}