import java.io.*;
import java.util.*;

public class CF_1385G_ColumnsSwaps2
{
    public static void main(String[] args) throws IOException
    {
        boolean isLocal = System.getProperty("ONLINE_JUDGE") == null;
        long startTime = 0;
        if (isLocal)
        {
            startTime = System.currentTimeMillis();
            // redirect stdin/stdout to local file
            System.setIn(new FileInputStream(new File("CF_1385G_ColumnsSwaps.in")));
            System.setOut(new PrintStream(new File("CF_1385G_ColumnsSwaps.out")));
        }

        Scanner in = new Scanner(System.in);
        PrintStream out = System.out;

        new CF_1385G_ColumnsSwaps_Solution2().Solve(in, out);

        in.close();
        out.close();

        if (isLocal)
        {
            System.err.println("program exited after: " + (System.currentTimeMillis() - startTime) + "ms");
        }
    }
}

class Pair<Key, Value>
{
    private Key key;
    private Value value;

    public Pair(Key key, Value value)
    {
        this.key = key;
        this.value = value;
    }

    public Key getKey()
    {
        return this.key;
    }

    public Value getValue()
    {
        return this.value;
    }

    public void setKey(Key key)
    {
        this.key = key;
    }

    public void setValue(Value value)
    {
        this.value = value;
    }
}

class CF_1385G_ColumnsSwaps_Solution2
{
    private int[] col;
    private ArrayList<Integer> pth;
    private ArrayList<Pair<Integer, Integer>>[] g;

    private boolean dfs(int u, int las)
    {
        pth.add(u);

        for (int i = 0, siz =(g[u]==null?0:g[u].size()); i <= siz - 1; ++i)
        {
            var v = g[u].get(i);
            if (v.getKey().intValue() == las)
                continue;

            int nxtCol = -1;
            if (v.getValue().intValue() == 1)
                nxtCol = col[u];
            else
                nxtCol = 1 - col[u];

            if (col[v.getKey().intValue()] != -1)
            {
                return (col[v.getKey().intValue()] == nxtCol);
            }

            col[v.getKey().intValue()] = nxtCol;
            if (dfs(v.getKey().intValue(), u) == false)
                return false;
        }
        
        return true;
    }

    public void Solve(Scanner In, PrintStream Out)
    {
        int tct = In.nextInt();
        for (int tcc = 1; tcc <= tct; ++tcc)
        {
            /*
             * int n = in.nextInt(); // read input as integer long k = in.nextLong(); //
             * read input as long double d = in.nextDouble(); // read input as double String
             * str = in.next(); // read input as String String s = in.nextLine(); // read
             * whole line as String
             */

            int n = In.nextInt();

            var cntX = new int[n + 1];
            // var pos = new ArrayList<ArrayList<Pair<Integer, Integer>>>(n + 1);
            // for (int i = 0; i <= n - 1; ++i)
            // {
            // int tmp = In.nextInt();
            // ++cntX[tmp];

            // pos.get(tmp).add(new Pair<Integer, Integer>(i, 0));
            // }

            ArrayList<Pair<Integer, Integer>>[] pos = new ArrayList[n + 1];
            for (int i = 0; i <= n - 1; ++i)
            {
                int tmp = In.nextInt();
                ++cntX[tmp];

                if (pos[tmp] == null)
                    pos[tmp] = new ArrayList<Pair<Integer, Integer>>();

                pos[tmp].add(new Pair<Integer, Integer>(i, 0));
            }

            // var pos = new ArrayList<ArrayList<Pair<Integer, Integer>>>(n + 1);
            // for (int i = 0; i <= n; ++i)
            // pos.add(new ArrayList<Pair<Integer, Integer>>());

            // for (int i = 0; i <= n - 1; ++i)
            // {
            // int tmp = In.nextInt();
            // ++cntX[tmp];

            // pos.get(tmp).add(new Pair<Integer, Integer>(i, 0));
            // }

            for (int i = 0; i <= n - 1; ++i)
            {
                int tmp = In.nextInt();
                ++cntX[tmp];

                if (pos[tmp] == null)
                    pos[tmp] = new ArrayList<Pair<Integer, Integer>>();

                pos[tmp].add(new Pair<Integer, Integer>(i, 1));
            }

            boolean flg = true;
            for (int x = 1; x <= n; ++x)
            {
                if (cntX[x] != 2)
                {
                    flg = false;
                    break;
                }
            }

            if (flg == false)
            {
                Out.println(-1);
                continue;
            }

            col = new int[n];
            // g = new ArrayList<ArrayList<Pair<Integer, Integer>>>(n);
            g = new ArrayList[n + 1];
            // for (int i = 0; i <= n - 1; ++i)
            // g.add(new ArrayList<Pair<Integer, Integer>>());

            for (int x = 1; x <= n; ++x)
            {
                int x0 = pos[x].get(0).getValue().intValue();
                int x1 = pos[x].get(1).getValue().intValue();

                int typ = (x0 == x1 ? 0 : 1);

                x0 = pos[x].get(0).getKey().intValue();
                x1 = pos[x].get(1).getKey().intValue();                

                if (g[x0] == null)
                    g[x0] = new ArrayList<Pair<Integer, Integer>>();

                g[x0].add(new Pair<Integer, Integer>(x1, typ));

                if (g[x1] == null)
                    g[x1] = new ArrayList<Pair<Integer, Integer>>();

                g[x1].add(new Pair<Integer, Integer>(x0, typ));
            }

            for (int u = 0; u <= n - 1; ++u)
                col[u] = -1;

            var ans = new ArrayList<Integer>();
            for (int u = 0; u <= n - 1; ++u)
            {
                if (col[u] == -1)
                {
                    col[u] = 0;
                    pth = new ArrayList<Integer>();
                    if (dfs(u, -1) == false)
                    {
                        flg = false;
                        break;
                    }

                    var tmp = new ArrayList<Integer>();
                    pth.forEach(v ->
                    {
                        if (col[v] == 1)
                            tmp.add(v.intValue() + 1);
                    });

                    if (tmp.size() > pth.size() - tmp.size())
                    {
                        tmp.clear();
                        pth.forEach(v ->
                        {
                            if (col[v] == 0)
                                tmp.add(v.intValue() + 1);
                        });
                    }

                    tmp.forEach(v ->
                    {
                        ans.add(v);
                    });
                }
            }

            if (flg == true)
            {
                int siz = ans.size();
                Out.println(siz);
                for (int i = 0; i <= siz - 1; ++i)
                {
                    if (i > 0)
                        Out.print(' ');
                    Out.print(ans.get(i).intValue());
                }
                Out.println();
            } else
            {
                Out.println(-1);
            }
        }
    }
}
