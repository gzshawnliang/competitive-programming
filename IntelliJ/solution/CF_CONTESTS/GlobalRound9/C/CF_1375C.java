/*
-------------------------------------------------------------------
* @Name:           1375C Element Extermination
* @Author:         Shawn
* @Create Time:    2020/7/9 21:12:00  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1375/problem/C
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

public class CF_1375C
{
    public static void main(String[] args) throws IOException
    {
        if (System.getProperty("ONLINE_JUDGE") == null)
        {
            //redirect stdin/stdout to local file
            System.setIn(new FileInputStream(new File("CF_1375C.in")));
            System.setOut(new PrintStream(new File("CF_1375C.out")));
        }

        Scanner in = new Scanner(System.in);
        PrintStream out = System.out;

        new CF_1375C_Solution().Solve(in, out);

        in.close();
        out.close();
    }
}


class CF_1375C_Solution
{
    public void Solve(Scanner in, PrintStream out)
    {
        int tct = in.nextInt();
        for (int tcc = 1; tcc <= tct; ++tcc)
        {
            int n = in.nextInt();

            int[] a= new int[n];
            for (int i = 0; i <= n - 1; ++i) a[i] = in.nextInt();


            out.println((a[0] < a[n - 1]) ? "YES" : "NO");
        }
    }
}


