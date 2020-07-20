/*
-------------------------------------------------------------------
* @Name:           1345C Hilbert's Hotel
* @Author:         Shawn
* @Create Time:    2020/7/21 0:20:47  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1345/problem/C
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

public class CF_1345C_HilbertsHotel
{
    public static void main(String[] args) throws IOException
    {
        boolean isLocal= System.getProperty("ONLINE_JUDGE") == null;
        long startTime = 0;
        if (isLocal)
        {
            startTime = System.currentTimeMillis();
            //redirect stdin/stdout to local file
            System.setIn(new FileInputStream(new File("CF_1345C_HilbertsHotel.in")));
            System.setOut(new PrintStream(new File("CF_1345C_HilbertsHotel.out")));
        }

        Scanner in = new Scanner(System.in);
        PrintStream out = System.out;

        new CF_1345C_HilbertsHotel_Solution().Solve(in, out);

        in.close();
        out.close();
        
        if (isLocal)
        {
            System.err.println("program exited after: " + (System.currentTimeMillis() - startTime) + "ms");
        }        
    }
}


class CF_1345C_HilbertsHotel_Solution
{
    public void Solve(Scanner In, PrintStream Out)
    {
        /*
        int n      = in.nextInt();        // read input as integer
        long k     = in.nextLong();       // read input as long
        double d   = in.nextDouble();     // read input as double
        String str = in.next();           // read input as String
        String s   = in.nextLine();       // read whole line as String
        */        
        
        int tct = In.nextInt();
        for (int tcc = 1; tcc <= tct; ++tcc)
        {
            int n = In.nextInt();

            boolean flg = true;
            var vis = new int[n];
            for (int i = 0; i <= n - 1; ++i)
            {
                int tmp = In.nextInt();

                int nxt = ((i + tmp) % n + n) % n;
                ++vis[nxt];
                if (vis[nxt] == 2) flg = false;
            }

            Out.println(flg ? "YES" : "NO");
        }
    }
}


