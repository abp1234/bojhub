using System;
using System.Collections.Generic;
using System.Linq;

struct Pt
{
    public int R, C;
    public Pt(int r, int c) { R = r; C = c; }
    
    public void Deconstruct(out int r, out int c)
    {
        r = R;
        c = C;
    }

}

class Prg
{
    static readonly int[] dr = { -1, 1, 0, 0 };
    static readonly int[] dc = { 0, 0, -1, 1 };
    static int N, M;
    static Dictionary<Pt, List<Pt>> tInfo = new Dictionary<Pt, List<Pt>>();

    static int Bfs()
    {
        int cnt = 1;
        var vis = new bool[N, N];
        var lit = new bool[N, N];

        var q = new Queue<Pt>();
        vis[0, 0] = lit[0, 0] = true;
        q.Enqueue(new Pt(0, 0));

        while(q.Count>0)
        {
            var curr = q.Dequeue();
            int r = curr.R, c =curr.C;

            if(tInfo.TryGetValue(new Pt(r,c), out var lst))
            {
                foreach(var next in lst)
                {
                    int tr = next.R, tc = next.C;
                    if (!lit[tr, tc])
                    {
                        lit[tr,tc] = true;
                        cnt++;

                        for (int d = 0; d < 4; d++)
                        {
                            int nr = tr + dr[d], nc = tc + dc[d];
                            if (InBound(nr, nc) && vis[nr, nc])
                                q.Enqueue(new Pt(nr, nc));
                        }
                    }
                }
            }

            for(int d = 0;d<4;d++)
            {
                int nr = r + dr[d], nc = c + dc[d];
                if(InBound(nr,nc)&& !vis[nr, nc] && lit[nr,nc])
                {
                    vis[nr, nc] = true;
                    q.Enqueue(new Pt(nr, nc));
                }
            }
        }

        return cnt;
    }

    static bool InBound(int r, int c) => r >= 0 && r < N && c >= 0 && c < N;

    static void Main()
    {
        var input = Console.ReadLine().Split();
        N = int.Parse(input[0]);
        M=int.Parse(input[1]);

        for(int i=0;i<M;i++)
        {
            var line = Console.ReadLine().Split();
            var sr = int.Parse(line[0]) - 1;
            var sc = int.Parse(line[1]) - 1;
            var tr = int.Parse(line[2]) - 1;
            var tc = int.Parse(line[3]) - 1;

            var key = new Pt(sr, sc);
            if (!tInfo.ContainsKey(key)) tInfo[key] = new List<Pt>();
            tInfo[key].Add(new Pt(tr, tc));
        }
        Console.WriteLine(Bfs());
    }

}