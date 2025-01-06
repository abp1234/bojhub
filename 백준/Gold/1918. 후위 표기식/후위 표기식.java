import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Deque;
import java.util.ArrayDeque;

public class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        char[] strn = br.readLine().trim().toCharArray();
        Deque<Character> stk = new ArrayDeque<>();
        StringBuilder res = new StringBuilder();

        for(char c : strn){
            if(Character.isAlphabetic(c)){
                res.append(c);
            }else{
                switch (c){
                    case'(':
                        stk.push(c);
                        break;
                    case '*':
                    case '/':
                        while(!stk.isEmpty() && (stk.peek()=='*'||stk.peek()=='/')){
                            res.append(stk.pop());
                        }
                        stk.push(c);
                        break;
                    case '+':
                    case '-':
                        while (!stk.isEmpty()&&stk.peek()!='('){
                            res.append(stk.pop());
                        }
                        stk.push(c);
                        break;
                    case')':
                        while(!stk.isEmpty()&&stk.peek()!='('){
                            res.append(stk.pop());
                        }
                        if(!stk.isEmpty()){
                            stk.pop();
                        }
                        break;

                }
            }
        }
        while(!stk.isEmpty()){
            res.append(stk.pop());
        }

        bw.write(res.toString());
        bw.flush();
        bw.close();
        br.close();
    }
}