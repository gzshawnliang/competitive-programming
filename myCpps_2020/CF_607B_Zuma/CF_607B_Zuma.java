/*
-------------------------------------------------------------------
* @Name:           607B Zuma
* @Author:         Shawn
* @Create Time:    2020/7/15 22:53:56  (UTC+08:00)
* @Url:            https://codeforces.com/contest/607/problem/B
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

public class CF_607B_Zuma
{
    public static void main(String[] args) throws IOException
    {
        boolean isLocal= System.getProperty("ONLINE_JUDGE") == null;
        long startTime = 0;
        if (isLocal)
        {
            startTime = System.currentTimeMillis();
            //redirect stdin/stdout to local file
            System.setIn(new FileInputStream(new File("CF_607B_Zuma.in")));
            System.setOut(new PrintStream(new File("CF_607B_Zuma.out")));
        }

        Scanner in = new Scanner(System.in);
        PrintStream out = System.out;

        new CF_607B_Zuma_Solution().Solve(in, out);

        in.close();
        out.close();
        
        if (isLocal)
        {
            System.err.println("program exited after: " + (System.currentTimeMillis() - startTime) + "ms");
        }        
    }
}


class CF_607B_Zuma_Solution
{
    private int inf = Integer.MAX_VALUE / 2;

    public void Solve(Scanner In, PrintStream Out)
    {
        /*
        int n      = in.nextInt();        // read input as integer
        long k     = in.nextLong();       // read input as long
        double d   = in.nextDouble();     // read input as double
        String str = in.next();           // read input as String
        String s   = in.nextLine();       // read whole line as String
        */        

        int n = In.nextInt();

        var a = new int[n];
        for (int i = 0; i <= n - 1; ++i) a[i] = In.nextInt();

        var f = new int[n][n];

        for (int i = 0; i <= n - 1; ++i)
            for (int j = 0; j <= n - 1; ++j)
                f[i][j] = inf;

        for (int len = 1; len <= n; ++len)
        {
            for (int i = 0; i <= n - 1; ++i)
            {
                int j = i + len - 1;
                if (j >= n) break;

                if (len == 1)      f[i][j] = 1;
                else if (len == 2) f[i][j] = (a[i] == a[j]) ? 1 : 2;
                else
                {
                    if (a[i] == a[j]) f[i][j] = Math.min(f[i][j], f[i + 1][j - 1]);

                    for (int k = i; k + 1 <= j; ++k)
                        f[i][j] = Math.min(f[i][j], f[i][k] + f[k + 1][j]);
                }
            }
        }

        Out.println(f[0][n - 1]);
    }
}


