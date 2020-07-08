/*
-------------------------------------------------------------------
* @Name:           1375A Sign Flipping
* @Author:         Thomas
* @Create Time:    2020/7/8 18:52:41  (UTC+08:00)
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

public class CF_1375A_SignFlipping
{
    public static void main(String[] args) throws IOException
    {
        if (System.getProperty("ONLINE_JUDGE") == null)
        {
            //redirect stdin/stdout to local file
            System.setIn(new FileInputStream(new File("CF_1375A_SignFlipping.in")));
            System.setOut(new PrintStream(new File("CF_1375A_SignFlipping.out")));
        }

        Scanner in = new Scanner(System.in);
        PrintStream out = System.out;

        new CF_1375A_SignFlipping_Solution().Solve(in, out);

        in.close();
        out.close();
    }
}

class CF_1375A_SignFlipping_Solution
{
    public void Solve(Scanner in, PrintStream out)
    {
        int t = in.nextInt();
        while (true)
        {
            --t;
            if(t>=0)
            {
                int n = in.nextInt();
                for(int i=0;i<=n-1;++i)
                {
                    if (i % 2 == 0)
                        out.print(Math.abs(in.nextInt()));
                    else
                        out.print(-Math.abs(in.nextInt()));

                    out.print(" ");
                }
                out.print("\n");
            }
            else
            {
                break;
            }
        }
    }
}


