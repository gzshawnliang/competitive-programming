/*
-------------------------------------------------------------------
* @Name:           1375D Replace by MEX
* @Author:         Shawn
* @Create Time:    2020/7/9 21:12:00  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1375/problem/D
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

public class CF_1375D
{
    public static void main(String[] args) throws IOException
    {
        if (System.getProperty("ONLINE_JUDGE") == null)
        {
            //redirect stdin/stdout to local file
            System.setIn(new FileInputStream(new File("CF_1375D.in")));
            System.setOut(new PrintStream(new File("CF_1375D.out")));
        }

        Scanner in = new Scanner(System.in);
        PrintStream out = System.out;

        new CF_1375D_Solution().Solve(in, out);

        in.close();
        out.close();
    }
}


class CF_1375D_Solution
{
    public void Solve(Scanner in, PrintStream out)
    {
        out.println("OK");
    }
}


