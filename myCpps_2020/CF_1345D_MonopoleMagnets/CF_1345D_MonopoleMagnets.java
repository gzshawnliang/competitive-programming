import java.io.*;
import java.util.*;

public class CF_1345D_MonopoleMagnets
{
    public static void main(String[] args) throws IOException
    {
        boolean isLocal= System.getProperty("ONLINE_JUDGE") == null;
        long startTime = 0;
        if (isLocal)
        {
            startTime = System.currentTimeMillis();
            //redirect stdin/stdout to local file
            System.setIn(new FileInputStream(new File("CF_1345D_MonopoleMagnets.in")));
            System.setOut(new PrintStream(new File("CF_1345D_MonopoleMagnets.out")));
        }

        Scanner in = new Scanner(System.in);
        PrintStream out = System.out;

        new CF_1345D_MonopoleMagnets_Solution().Solve(in, out);

        in.close();
        out.close();
        
        if (isLocal)
        {
            System.err.println("program exited after: " + (System.currentTimeMillis() - startTime) + "ms");
        }        
    }
}


class CF_1345D_MonopoleMagnets_Solution
{
    //final ArrayList<Pair<Integer, Integer>> pls = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    final int[] plsY = new int[]{-1, 0, 1, 0};
    final int[] plsX = new int[]{0, 1, 0, -1};

    int n, m;
    int[][] a;

    boolean g(int y, int x)
    {
        return y >= 0 && y <= n - 1 && x >= 0 && x <= m - 1;
    }

    void dfs(int y, int x)
    {
        a[y][x] = 0;

        for (int p = 0; p <= 3; ++p)
        {
            int nxtY = y + plsY[p], nxtX = x + plsX[p];
            if (g(nxtY, nxtX))
            {
                if (a[nxtY][nxtX] == 1) dfs(nxtY, nxtX);
            }
        }
    }

    public void Solve(Scanner In, PrintStream Out)
    {
        n = In.nextInt(); m = In.nextInt();

        a = new int [n][m];
        for (int y = 0; y <= n - 1; ++y)
        {
            String tmp = In.next();
            for (int x = 0; x <= m - 1; ++x)
            {
                a[y][x] = (tmp.charAt(x) == '#') ? 1 : 0;
            }
        }

        boolean flg = true;
        int cntER = 0;
        for (int y = 0; y <= n - 1 && flg == true; ++y)
        {
            int las = -1;
            for (int x = 0; x <= m - 1 && flg == true; ++x)
            {
                if (a[y][x] == 1)
                {
                    if (x - las > 1 && las >= 0)
                    {
                        flg = false; break;
                    }
                    las = x;
                }
            }

            if (las == -1) ++cntER;
        }

        int cntEC = 0;
        for (int x = 0; x <= m - 1 && flg == true; ++x)
        {
            int las = -1;
            for (int y = 0; y <= n - 1 && flg == true; ++y)
            {
                if (a[y][x] == 1)
                {
                    if (y - las > 1 && las >= 0)
                    {
                        flg = false; break;
                    }
                    las = y;
                }
            }

            if (las == -1) ++cntEC;
        }

        if ((cntER > 0 && cntEC == 0) || (cntER == 0 && cntEC > 0)) flg = false;

        if (flg == false)
        {
            Out.println(-1);
            return;
        }

        int ans = 0;
        for (int y = 0; y <= n - 1; ++y)
        {
            for (int x = 0; x <= m - 1; ++x)
            {
                if (a[y][x] == 1)
                {
                    ++ans;
                    dfs(y, x);
                }
            }
        }

        Out.println(ans);
    }
}
