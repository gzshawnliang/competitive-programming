/*
-------------------------------------------------------------------
* @Name:           512B Fox And Jumping
* @Author:         Shawn
* @Create Time:    2020/7/14 23:28:43  (UTC+08:00)
* @Url:            https://codeforces.com/contest/512/problem/B
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

public class CF_512B_FoxAndJumping
{
    public static void main(String[] args) throws IOException
    {
        boolean isLocal= System.getProperty("ONLINE_JUDGE") == null;
        long startTime = 0;
        if (isLocal)
        {
            startTime = System.currentTimeMillis();
            //redirect stdin/stdout to local file
            System.setIn(new FileInputStream(new File("CF_512B_FoxAndJumping.in")));
            System.setOut(new PrintStream(new File("CF_512B_FoxAndJumping.out")));
        }

        Scanner in = new Scanner(System.in);
        PrintStream out = System.out;

        new CF_512B_FoxAndJumping_Solution().Solve(in, out);

        in.close();
        out.close();
        
        if (isLocal)
        {
            System.err.println("program exited after: " + (System.currentTimeMillis() - startTime) + "ms");
        }        
    }
}


class CF_512B_FoxAndJumping_Solution
{
    public int gcd(int a, int b)
    {
        return (b > 0) ? gcd(b,a % b) : a;
    }

    public void Solve(Scanner in, PrintStream out)
    {
        /*
        int n      = in.nextInt();        // read input as integer
        long k     = in.nextLong();       // read input as long
        double d   = in.nextDouble();     // read input as double
        String str = in.next();           // read input as String
        String s   = in.nextLine();       // read whole line as String
        */        

        int n = in.nextInt();

        var l = new int[n];
        for (int i = 0; i <= n - 1; ++i) l[i] = in.nextInt();

        var c = new int[n];
        for (int i = 0; i <= n - 1; ++i) c[i] = in.nextInt();

        var f = new HashMap<Integer, Integer>();

        for (int i = 0; i <= n - 1; ++i)
        {
            if (f.containsKey(l[i]) ) f.put(l[i], Math.min(f.get(l[i]), c[i]));
            else                      f.put(l[i], c[i]);

            var f2 = new HashMap<Integer, Integer>();
            f2.putAll(f);

//            var it=f.entrySet().iterator();
//            while (it.hasNext())
//            {
//                var item = it.next();
//                int key = item.getKey();
//                int val = item.getValue();
//
//                int nxt = gcd(key, l[i]);
//
//                if (f2.containsKey(nxt))    f2.put(nxt, Math.min(f2.get(nxt), val + c[i]));
//                else                        f2.put(nxt, val + c[i]);
//            }

//            for(var item : f.entrySet())
//            {
//                int key = item.getKey();
//                int val = item.getValue();
//
//                int nxt = gcd(key, l[i]);
//
//                if (f2.containsKey(nxt))    f2.put(nxt, Math.min(f2.get(nxt), val + c[i]));
//                else                        f2.put(nxt, val + c[i]);
//            }

            //Lambda Version
            int curr=i;
            f.forEach((key,val)->
            {
                int nxt = gcd(key, l[curr]);

                if (f2.containsKey(nxt))    f2.put(nxt, Math.min(f2.get(nxt), val + c[curr]));
                else                        f2.put(nxt, val + c[curr]);
            });


            f.clear();
            f.putAll(f2);
        }


        if (f.containsKey(1)) out.println(f.get(1));
        else                  out.println(-1);
    }
}


