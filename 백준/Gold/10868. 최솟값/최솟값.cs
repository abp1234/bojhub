using System;
using System.IO;
using System.Text;

class Program
{
    const int INF = int.MaxValue;
    static int[] data;
    static int[] tree;

    static int Init(int start, int end, int idx)
    {
        if (start == end)
        {
            tree[idx] = data[start];
            return tree[idx];
        }

        int mid = (start + end) / 2;
        tree[idx] = Math.Min(Init(start, mid, idx * 2), Init(mid + 1, end, idx * 2 + 1));
        return tree[idx];
    }

    static int Find(int start, int end, int idx, int left, int right)
    {
        if (left > end || right < start)
            return INF;

        if (left <= start && end <= right)
            return tree[idx];

        int mid = (start + end) / 2;
        return Math.Min(Find(start, mid, idx * 2, left, right), Find(mid + 1, end, idx * 2 + 1, left, right));
    }

    static void Main()
    {
        using (var reader = new StreamReader(new BufferedStream(Console.OpenStandardInput())))
        using (var writer = new StreamWriter(new BufferedStream(Console.OpenStandardOutput())))
        {
            var input = reader.ReadLine().Split();
            int N = int.Parse(input[0]);
            int M = int.Parse(input[1]);

            data = new int[N + 1];
            for (int i = 1; i <= N; i++)
            {
                data[i] = int.Parse(reader.ReadLine());
            }

            tree = new int[N * 4];
            Init(1, N, 1);

            StringBuilder sb = new StringBuilder();

            for (int i = 0; i < M; i++)
            {
                var range = reader.ReadLine().Split();
                int a = int.Parse(range[0]);
                int b = int.Parse(range[1]);
                sb.AppendLine(Find(1, N, 1, a, b).ToString());
            }

            writer.Write(sb.ToString());
        }
    }
}
