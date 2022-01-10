using System;
using System.Linq;
using System.IO;
using System.Text;
using System.Collections;
using System.Collections.Generic;

/**
 * catch up and win
 **/
class Player
{
    static void Main(string[] args)
    {
        int K = int.Parse(Console.ReadLine()); // representing after how many turns the sus man will make another move
        List<string> mapdata = new List<string>();
        mapdata.Add("************");
        for (int i = 0; i < 10; i++)
        {
            string s = Console.ReadLine(); // the map
            mapdata.Add("*" + s + "*");
            // Console.Error.WriteLine($"{s}");
        }
        mapdata.Add("************");

        foreach (var x in mapdata)
            Console.Error.WriteLine(x);

        ShortestPath shortestPath = new ShortestPath(mapdata);

        // game loop
        Random rnd = new Random();
        while (true)
        {
            string enePos = Console.ReadLine();
            int eneY = int.Parse(enePos.Split(" ")[0]); // the sus man's coordinate
            int eneX = int.Parse(enePos.Split(" ")[1]); // the sus man's coordinate
            ++eneY;
            ++eneX;
            Console.Error.WriteLine($"P:{shortestPath.P.Item1},{shortestPath.P.Item2}");

            var dirs = shortestPath.getDirection(shortestPath.P);
            if (dirs.Count == 1)
            {
                Console.WriteLine(dirs[0].Item1);

                //update My location
                shortestPath.P = dirs[0].Item2;
            }
            else
            {
                List<(int, char, (int, int))> dirDist = new List<(int, char, (int, int))>();
                foreach (var (d, (x, y)) in dirs)
                {
                    var data = (shortestPath.run((x, y), (eneX, eneY)), d, (x, y));
                    dirDist.Add(data);
                }
                dirDist = dirDist.OrderBy(t => t.Item1).ToList();

                int selectIndex = 0;
                if (dirDist[0].Item1 == dirDist[1].Item1)
                    selectIndex = rnd.Next(0, 2);

                Console.Error.WriteLine($"dirDist:{dirDist[0].Item1},{dirDist[1].Item1}");
                Console.WriteLine(dirDist[selectIndex].Item2);

                //update My location
                shortestPath.P = dirDist[selectIndex].Item3;
            }

        }
    }
}

class ShortestPath
{
    public (int, int) P;//My location
    private const int INF = int.MaxValue / 2;
    private List<string> a;
    private readonly Dictionary<char, (int, int)> dirs = new Dictionary<char, (int, int)>()
    {
        { 'U',(0,  -1)},
        { 'D',(0,   1)},
        { 'L',(-1,  0)},
        { 'R',(1,   0)},
    };

    private Dictionary<(int, int), List<(int, int)>> g;

    private int hash((int, int) p)
    {
        return p.Item1 * 10 + p.Item2;
    }

    public List<(char, (int, int))> getDirection((int, int) curr)
    {
        List<(char, (int, int))> dir = new List<(char, (int, int))>();
        var (x, y) = curr;

        foreach (var k in dirs)
        {
            var (dX, dY) = k.Value;
            if (a[y + dY][x + dX] != '*')
                dir.Add((k.Key, (x + dX, y + dY)));
        }
        return dir;
    }

    public ShortestPath(List<string> data)
    {
        this.a = data;

        //create graph
        g = new Dictionary<(int, int), List<(int, int)>>();
        (int, int) E;
        for (int y = 1; y <= 10; ++y)
        {
            for (int x = 1; x <= 10; ++x)
            {
                if (a[y][x] == 'P')
                    P = (x, y);
                else if (a[y][x] == 'E')
                    E = (x, y);
                else if (a[y][x] == '*')
                    continue;

                List<(char, (int, int))> currDirs = getDirection((x, y));
                foreach (var k in currDirs)
                {
                    if (g.ContainsKey((x, y)))
                        g[(x, y)].Add(k.Item2);
                    else
                        g.Add((x, y), new List<(int, int)> { k.Item2 });
                }
            }
        }
        // Console.Error.WriteLine($"{g.Count}");
    }
    public int run((int, int) start, (int, int) target)
    {
        int[] distance = Enumerable.Repeat<int>(INF, 12 * 12).ToArray();
        int S = hash(start);
        distance[S] = 0;
        Queue<(int, int)> q = new Queue<(int, int)>();
        q.Enqueue(start);
        while (q.Count > 0)
        {
            (int, int) now = q.Dequeue();
            if (g.ContainsKey(now))
            {
                foreach (var neighbour in g[now])
                {
                    int v = hash(neighbour);
                    int u = hash(now);
                    if (distance[v] > distance[u] + 1)
                    {
                        distance[v] = distance[u] + 1;
                        q.Enqueue(neighbour);
                    }
                }
            }
        }
        return distance[hash(target)];
    }
}