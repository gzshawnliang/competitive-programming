/*
-------------------------------------------------------------------
* @Name:           1114D Flood Fill
* @Author:         Shawn
* @Create Time:    2020/7/13 23:00:41  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1114/problem/D
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

public class CF_1114D_FloodFill
{
    public static void main(String[] args) throws IOException
    {
        boolean isLocal= System.getProperty("ONLINE_JUDGE") == null;
        long startTime = 0;
        if (isLocal)
        {
            startTime = System.currentTimeMillis();
            //redirect stdin/stdout to local file
            System.setIn(new FileInputStream(new File("CF_1114D_FloodFill.in")));
            System.setOut(new PrintStream(new File("CF_1114D_FloodFill.outj")));
        }
        

        Scanner in = new Scanner(System.in);
        PrintStream out = System.out;

        new CF_1114D_FloodFill_Solution().Solve(in, out);

        in.close();
        out.close();
        
        if (isLocal)
        {
            //System.err.println("program exited after: " + (System.currentTimeMillis() - startTime) + "ms");
        }        
    }
}


class CF_1114D_FloodFill_Solution
{
    public void Solve(Scanner in, PrintStream out)
    {
        int n = in.nextInt();

        ArrayList<Integer> a = new ArrayList<Integer>();

        for (int c = 1; c <= n; ++c)
        {
            int tmp = in.nextInt();

            if (c == 1)                           a.add(tmp);
            else if (a.get(a.size() - 1) != tmp)  a.add(tmp);
        }

        int siz = a.size();
        int f[][] = new int[siz][siz];
        for (int len = 1; len <= siz; len++)
        {
            for (int i = 0; i <= siz - 1; i++)
            {
                int j = i + len - 1;
                if (j > siz - 1) break;

                if (len == 1) 
                {
                    f[i][j] = 1;
                }
                else if (len == 2)
                {
                    if (a.get(i).intValue() == a.get(j).intValue()) f[i][j] = 2;
                    else                      f[i][j] = 1;
                }
                else
                {
                    if (i == 8 && j == 14)
                    {
                        for (int __s = 0; __s == 0; ++__s);
                    }                      
                    f[i][j] = Math.max(f[i][j], f[i + 1][j]);
                    f[i][j] = Math.max(f[i][j], f[i][j - 1]);

                    if (a.get(i).intValue() == a.get(j).intValue())
                    {
                        f[i][j] = Math.max(f[i][j], f[i + 1][j - 1] + 2);
                    } 
                }

                if (i == 8 && j == 14)
                {
                    for (int __s = 0; __s == 0; ++__s);
                }  

                // out.print(i);
                // out.print('-');
                // out.print(j);
                // out.print(':');
                // out.print(f[i][j]);
                // out.print(' ');
            }
            //out.print('\n');
        }

        out.println(siz - (f[0][siz - 1] + 1) / 2);
    }
}


