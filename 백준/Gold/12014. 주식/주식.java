import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] z) throws Exception{
        BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter w = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer x = new StringTokenizer(r.readLine());
        int t = Integer.parseInt(x.nextToken());

        StringBuilder s = new StringBuilder();
        for(int i = 1; i<=t;i++){
            x = new StringTokenizer(r.readLine());
            int n = Integer.parseInt(x.nextToken());
            int k = Integer.parseInt(x.nextToken());

            ArrayList<Integer> a = new ArrayList<>();
            x = new StringTokenizer(r.readLine());
            for(int j = 0; j < n;j++){
                a.add(Integer.parseInt(x.nextToken()));
            }

            ArrayList<Integer> l = new ArrayList<>();
            l.add(a.get(0));

            for(int j = 1;j<n;j++){
                int v = a.get(j);
                if(l.get(l.size()-1)<v){
                    l.add(v);
                }else{
                    int p = Collections.binarySearch(l,v);
                    if(p<0)p=-p-1;
                    l.set(p,v);
                }
            }
            s.append("Case #").append(i).append("\n");
            s.append(l.size()>=k?1:0).append("\n");
        }
        w.write(s.toString());
        w.flush();
        w.close();
    }
}