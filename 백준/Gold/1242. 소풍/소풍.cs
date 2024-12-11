using System;
using System.Collections.Generic;

namespace CSharp2
{
    struct Tgt
    {
        public int V;
    }
    class Pgm
    {
        static void Main(string[] args)
        {
            try
            {
                int n, k, m;
                var inp = Console.ReadLine()?.Split(' ');
                if (inp == null || inp.Length != 3) throw new ArgumentException("이상한 인풋");

                n = int.Parse(inp[0]);
                k = int.Parse(inp[1]);
                m = int.Parse(inp[2]);

                int cnt = 0;
                int t;

                Func<int, int, int> calcTgt = (x, y) => y % x == 0 ? x : y % x;
                t = calcTgt(n, k);

                while(true)
                {
                    cnt++;
                    if (t==m)
                    {
                        break;   
                    }

                    if(m-t>0)
                    {
                        m -= t;
                        n--;
                        if (n == 0) throw new InvalidOperationException("0");
                        t = calcTgt(n, k);
                    }
                    else
                    {
                        m = n + (m - t);
                        n --;
                        if (n == 0) throw new InvalidOperationException("0");
                        t = calcTgt(n, k);
                    }
                }
                Console.WriteLine(cnt);
            }
            catch(Exception ex)
            {
                Console.WriteLine($"Error:{ex.Message}");
            }
        }
    }
}