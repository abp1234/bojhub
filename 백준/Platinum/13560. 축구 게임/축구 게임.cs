using System;
using System.Linq;


class Pgm
{
    static int Sol(int[] w,int n)
    {
        if(w.Sum()!=n*(n-1)/2)
        {
            return -1;
        }

        int u = 0;
        for(int i=0;i<n;i++)
        {
            u += w[i] - i;
            if(u<0)
            {
                return -1;
            }
        }
        return 1;
    }

    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        var w = Console.ReadLine()
            .Split(' ')
            .Select(int.Parse)
            .OrderBy(x => x)
            .ToArray();

        Console.WriteLine(Sol(w, n));
    }
}