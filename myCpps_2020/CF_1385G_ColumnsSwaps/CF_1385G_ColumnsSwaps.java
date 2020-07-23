/*
-------------------------------------------------------------------
* @Name:           1385G Columns Swaps
* @Author:         Shawn
* @Create Time:    2020/7/23 22:07:16  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1385/problem/G
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

public class CF_1385G_ColumnsSwaps
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

        Scanner in = new Scanner(System.in);
        PrintStream out = System.out;

        new CF_1385G_ColumnsSwaps_Solution().Solve(in, out);

        in.close();
        out.close();
        
        if (isLocal)
        {
            System.err.println("program exited after: " + (System.currentTimeMillis() - startTime) + "ms");
        }        
    }
}


class CF_1385G_ColumnsSwaps_Solution
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
        Out.println("OK");
    }
}


