/*
-------------------------------------------------------------------
* @Name:           1385G Columns Swaps
* @Author:         Thomas
* @Create Time:    2020/7/23 22:07:16  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1385/problem/G
* @Description:    AC
-------------------------------------------------------------------
                                     /~\
                                    |oo )
                                    _\=/_
                    ___        #   /  _  \
                   / ()\        \\//|/.\|\\
                 _|_____|_       \/  \_/  ||
                | | === | |         |\ /| ||
                |_|  O  |_|         \_ _/  #
                 ||  O  ||          | | |
                 ||__*__||          | | |
                |~ \___/ ~|         []|[]
                /=\ /=\ /=\         | | |
________________[_]_[_]_[_]________/_]_[_\_________________________
*/
import java.io.*;
import java.util.*;

public class CF_1385G_ColumnsSwaps3
{
    public static void main(String[] args) throws IOException
    {
        boolean isLocal= System.getProperty("ONLINE_JUDGE") == null;
        long startTime = 0;
        if (isLocal)
        {
            startTime = System.currentTimeMillis();
            //redirect stdin/stdout to local file
            System.setIn(new FileInputStream(new File("CF_1385G_ColumnsSwaps.in")));
            System.setOut(new PrintStream(new File("CF_1385G_ColumnsSwaps.out")));
        }

        FastReader in = new FastReader(System.in);
        PrintStream out = System.out;
        new Solution(in, out).Solve();

        out.close();
        
        if (isLocal)
        {
            System.err.println("program exited after: " + (System.currentTimeMillis() - startTime) + "ms");
        }        
    }

    private static class FastReader
    {
        private BufferedReader reader;
        private StringTokenizer tokenizer;
    
        public FastReader(InputStream input)
        {
            reader = new BufferedReader(new InputStreamReader(input));
            tokenizer = new StringTokenizer("");
        }
    
        public String next()
        {
            while (!tokenizer.hasMoreTokens())
            {
                // TODO add check for eof if necessary
                try
                {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e)
                {
                    e.printStackTrace();
                }
                
            }
            return tokenizer.nextToken();
        }
    
        public int nextInt()
        {
            return Integer.parseInt(next());
        }

        public long nextLong()
        {
            return Long.parseLong(next());
        }
    
        public double nextDouble()
        {
            return Double.parseDouble(next());
        }

        String nextLine()
        { 
            String str = ""; 
            try
            { 
                str = reader.readLine(); 
            } 
            catch (IOException e) 
            { 
                e.printStackTrace(); 
            } 
            return str; 
        }         
    }
    
    private static class Pair<Key,Value> {
        private Key key;
        private Value value;
    
        public Pair(Key key, Value value){
            this.key = key;
            this.value = value;
        }
    
        public Key getKey(){ return this.key; }
        public Value getValue(){ return this.value; }
    
        public void setKey(Key key){ this.key = key; }
        public void setValue(Value value){ this.value = value; }
    }
    
    private static class Solution
    {
        private FastReader In;
        private PrintStream Out;

        public Solution(FastReader in, PrintStream out)
        {
            this.In = in;
            this.Out = out;
        }

        private int[] col;
        private ArrayList<Integer> pth;
        private ArrayList<ArrayList<Pair<Integer, Integer>>> g;
    
        private boolean dfs(int u, int las)
        {
            pth.add(u);
            for (int i = 0, siz = g.get(u).size(); i <= siz - 1; ++i)
            {
                var v = g.get(u).get(i);
                if (v.getKey().intValue() == las) continue;
    
                int nxtCol = -1;
                if (v.getValue().intValue() == 1) nxtCol = col[u];
                else                              nxtCol = 1 - col[u];
    
                if (col[v.getKey().intValue()] != -1)
                {
                    return (col[v.getKey().intValue()] == nxtCol);
                }
    
                col[v.getKey().intValue()] = nxtCol;
                if (dfs(v.getKey().intValue(), u) == false) return false;
            }
            return true;
        }
    
        public void Solve()
        {
            int tct = In.nextInt();
            for (int tcc = 1; tcc <= tct; ++tcc)
            {
                int n = In.nextInt();
                
                var cntX = new int[n + 1];
    
                var pos = new ArrayList<ArrayList<Pair<Integer, Integer>>>(n + 1);
                for (int i = 0; i <= n; ++i)
                    pos.add(new ArrayList<Pair<Integer, Integer>>());
    
    
                for (int i = 0; i <= n - 1; ++i)
                {
                    int tmp = In.nextInt();
                    ++cntX[tmp];
    
                    pos.get(tmp).add(new Pair<Integer, Integer>(i, 0));
                }
    
                for (int i = 0; i <= n - 1; ++i)
                {
                    int tmp = In.nextInt();
                    ++cntX[tmp];
    
                    pos.get(tmp).add(new Pair<Integer, Integer>(i, 1));
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
                g = new ArrayList<ArrayList<Pair<Integer, Integer>>>(n);
                Collections.fill(g, new ArrayList<Pair<Integer, Integer>>());
                for (int i = 0; i <= n - 1; ++i)
                    g.add(new ArrayList<Pair<Integer, Integer>>());
    
                for (int x = 1; x <= n; ++x)
                {
                    int typ = (pos.get(x).get(0).getValue().intValue() == pos.get(x).get(1).getValue().intValue() ? 0 : 1);
                    
                    g.get(pos.get(x).get(0).getKey().intValue()).add(new Pair<Integer, Integer>(pos.get(x).get(1).getKey().intValue(), typ));
                    g.get(pos.get(x).get(1).getKey().intValue()).add(new Pair<Integer, Integer>(pos.get(x).get(0).getKey().intValue(), typ));
                }
    
                for (int u = 0; u <= n - 1; ++u) col[u] = -1;
    
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
                        pth.forEach(v->
                        {
                            if (col[v] == 1) tmp.add(v.intValue() + 1);
                        });
    
                        if (tmp.size() > pth.size() - tmp.size())
                        {
                            tmp.clear();
                            pth.forEach(v->
                            {
                                if (col[v] == 0) tmp.add(v.intValue() + 1);
                            });
                        }
    
                        tmp.forEach(v->
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
                        if (i > 0) Out.print(' ');
                        Out.print(ans.get(i).intValue());
                    }
                    Out.println();
                }
                else
                {
                    Out.println(-1);
                }
            }
        }
    }
    
}



