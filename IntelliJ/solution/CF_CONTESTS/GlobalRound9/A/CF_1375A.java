/*
-------------------------------------------------------------------
* @Name:           1375A Sign Flipping
* @Author:         Shawn
* @Create Time:    2020/7/9 21:12:00  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1375/problem/A
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

public class CF_1375A
{
    public static void main(String[] args) throws IOException
    {
        boolean isLocal= System.getProperty("ONLINE_JUDGE") == null;
        long startTime = 0;

        if (isLocal)
        {
            //redirect stdin/stdout to local file
            startTime = System.currentTimeMillis();
            System.setIn(new FileInputStream(new File("CF_1375A.in")));
            System.setOut(new PrintStream(new File("CF_1375A.out")));
        }

        Scanner in = new Scanner(System.in);
        PrintStream out = System.out;

        new CF_1375A_Solution().Solve(in, out);
        //CF_1375A_Solution2.Solve(in, out);



        in.close();
        out.close();
        if (isLocal)
        {
            System.err.println("program exited after: " + (System.currentTimeMillis() - startTime) + "ms");
        }
    }
}


class CF_1375A_Solution
{
    public void Solve(Scanner in, PrintStream out)
    {
        //int n=in.nextInt();
        //out.println("OK");

        int tct = in.nextInt();
        for (int tcc = 1; tcc <= tct; ++tcc)
        {
            int n = in.nextInt();
            for (int c = 1; c <= n; ++c)
            {
                if (c > 1) out.print(' ');
                int x = Math.abs(in.nextInt());
                out.print(x * (c % 2 == 1 ? 1 : -1));
            }
            out.print('\n');
        }
    }
}

//class CF_1375A_Solution2
//{
//    public static void Solve(Scanner in, PrintStream out)
//    {
//        //int n=in.nextInt();
//        out.println("OK2");
//    }
//}



