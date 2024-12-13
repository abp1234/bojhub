using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;

struct Pt
{
    public int X;
    public int Y;

    public Pt(int x,int y)
    {
        X = x;
        Y = y;
    }
}

class Pr
{
    static void Main(string[] args)
    {
        int tc = int.Parse(Console.ReadLine());
        for (int _ = 0; _ < tc; _++)
        {
            int n = int.Parse(Console.ReadLine());
            var cache = new HashSet<Pt>();
            var pts = new List<Pt>();
            int ans = 0;

            for (int i = 0; i < n; i++)
            {
                var input = Console.ReadLine().Split(' ');
                int x = int.Parse(input[0]);
                int y = int.Parse(input[1]);
                var p = new Pt(x, y);
                cache.Add(p);
                pts.Add(p);
            }

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (i == j) continue;
                    var p1 = pts[i];
                    var p2 = pts[j];

                    int distSq = (p1.X - p2.X) * (p1.X - p2.X) + (p1.Y - p2.Y) * (p1.Y - p2.Y);
                    if (ans >= distSq) continue;

                    int xDiff = p1.X - p2.X;
                    int yDiff = p1.Y - p2.Y;

                    if (cache.Contains(new Pt(p1.X - yDiff, p1.Y + xDiff)) &&
                        cache.Contains(new Pt(p2.X - yDiff, p2.Y + xDiff)))
                    {
                        ans = Math.Max(ans, distSq);
                    }


                }
            }
            Console.WriteLine(ans);
        }
    }
}