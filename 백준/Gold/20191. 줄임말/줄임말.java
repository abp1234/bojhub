import java.io.BufferedWriter;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;
import java.util.ArrayList;


class Po{
    int v;
    Po(int x){this.v = x;}
}

public class Main{
    public static void main(String[] ar) throws IOException{
        BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        String s = br.readLine();
        String t = br.readLine();

        int sl = s.length();
        int tl = t.length();

        @SuppressWarnings("unchecked")
        ArrayList<Po>[] pos = new ArrayList[26];

        for(int i =0;i<26;i++){
            pos[i] = new ArrayList<>();
        }

        for(int i = 0; i<tl;i++){
            char c = t.charAt(i);
            pos[c-'a'].add(new Po(i));
        }

        int cnt = 1;
        int last = 0;

        for(int i = 0; i<sl;i++){
            char c = s.charAt(i);
            int idx = c - 'a';

            if(pos[idx].isEmpty()){
                cnt=-1;
                break;
            }

            int bs = bin(pos[idx],last);

            if(bs == pos[idx].size()){
                cnt++;
                last = 0;
                bs = bin(pos[idx],last);

                if(bs == pos[idx].size()){
                    cnt = -1;
                    break;
                }
            }

            last = pos[idx].get(bs).v +1;
        }
        sb.append(cnt).append("\n");

        bw.write(sb.toString());
        bw.flush();

        bw.close();
        br.close();
    }

    static int bin(ArrayList<Po> arr, int key){
        int st =0;
        int ed = arr.size();

        while(st < ed){
            int md = (st+ed)>>>1;
            if(arr.get(md).v<key){
                st=md+1;
            }else{
                ed=md;
            }
        }
        return st;
    }
}