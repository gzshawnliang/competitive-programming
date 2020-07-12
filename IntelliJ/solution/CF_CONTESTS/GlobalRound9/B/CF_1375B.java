/*
-------------------------------------------------------------------
* @Name:           1375B Neighbor Grid
* @Author:         Shawn
* @Create Time:    2020/7/9 21:12:00  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1375/problem/B
* @Description:    
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

public class CF_1375B
{
    public static void main(String[] args) throws IOException
    {
        if (System.getProperty("ONLINE_JUDGE") == null)
        {
            //redirect stdin/stdout to local file
            System.setIn(new FileInputStream(new File("CF_1375B.in")));
            System.setOut(new PrintStream(new File("CF_1375B.out")));
        }

        Scanner in = new Scanner(System.in);
        PrintStream out = System.out;

        new CF_1375B_Solution().Solve(in, out);

        in.close();
        out.close();
    }
}


class CF_1375B_Solution
{
    public int maxX(int y, int x, int n, int m)
    {
        int ans = 4;

        if (y == 0 || y == n - 1)
        {
            ans = 3;
            if (x == 0 || x == m - 1)
            {
                ans = 2;
            }
        }

        if (x == 0 || x == m - 1)
        {
            ans = 3;
            if (y == 0 || y == n - 1)
            {
                ans = 2;
            }
        }

        return ans;
    }

    public void Solve(Scanner in, PrintStream out)
    {
        int tct = in.nextInt();
        for (int tcc = 1; tcc <= tct; ++tcc)
        {
            int n = in.nextInt(), m = in.nextInt();

            boolean flg = true;
            for (int y = 0; y <= n - 1; ++y)
            {
                for (int x = 0; x <= m - 1; ++x)
                {
                    int inX = in.nextInt();

                    if (inX > maxX(y, x, n, m))
                    {
                        flg = false;
                    }
                }
            }

            if (flg == false)
            {
                out.println("NO");
            }
            else
            {
                out.println("YES");
                for (int y = 0; y <= n - 1; ++y)
                {
                    for (int x = 0; x <= m - 1; ++x)
                    {
                        if (x > 0) out.print(' ');
                        out.print(maxX(y, x, n, m));
                    }
                    out.print('\n');
                }
            }
        }
    }
}


