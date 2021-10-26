/*
===========================================================
* @Name:           1375A Sign Flipping
* @Author:         Thomas
* @Create Time:    2020/7/8 19:11:04  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1375/problem/A
* @Description:    
===========================================================
*/
import java.io.*;
import java.util.*;

public class CF_1375A_SignFlipping
{
    public static void main(String[] args) throws IOException
    {
        boolean isLocal= System.getProperty("ONLINE_JUDGE") == null;
        long startTime = 0;

        if (isLocal)
        {
            startTime = System.currentTimeMillis();
            System.setIn(new FileInputStream(new File("CF_1375A_SignFlipping.in")));    //redirect stdin to local file
            System.setOut(new PrintStream(new File("CF_1375A_SignFlipping.out")));      //redirect stdout to local file
            
        }

        Scanner in = new Scanner(System.in);
        PrintStream out = System.out;

        new CF_1375A_SignFlipping_Solution().Solve(in, out);

        in.close();
        out.close();

        if (isLocal)
        {
            System.err.println("program exited after: " + (System.currentTimeMillis() - startTime) + "ms");
        }
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

                    out.print((i % 2 != 0) ? Math.abs(in.nextInt()) :-Math.abs(in.nextInt()));
                    out.print(' ');
                }
                out.print('\n');
            }
            else
            {
                break;
            }
        }
    }
}