/*
-------------------------------------------------------------------
* @Name:           1385F Removing Leaves
* @Author:         Thomas
* @Create Time:    2020/7/24 13:19:01  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1385/problem/F
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

public class CF_1385F_RemovingLeaves
{
    public static void main(String[] args) throws IOException
    {
        boolean isLocal= System.getProperty("ONLINE_JUDGE") == null;
        long startTime = 0;
        if (isLocal)
        {
            startTime = System.currentTimeMillis();
            //redirect stdin/stdout to local file
            System.setIn(new FileInputStream(new File("CF_1385F_RemovingLeaves.in")));
            System.setOut(new PrintStream(new File("CF_1385F_RemovingLeaves.out")));
        }

        FastReader in = new FastReader(System.in);
        PrintStream out = System.out;

        new Solution(in, out).Solve();

        out.close();
        
        if (isLocal)
        {
            System.err.println("program exited after: " + (System.currentTimeMillis() - startTime) + "ms");
        }        
    }

    private static class FastReader
    {
        private BufferedReader reader;
        private StringTokenizer tokenizer;
    
        public FastReader(InputStream input)
        {
            reader = new BufferedReader(new InputStreamReader(input));
            tokenizer = new StringTokenizer("");
        }
    
        public String next()
        {
            while (!tokenizer.hasMoreTokens())
            {
                // TODO add check for eof if necessary
                try
                {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e)
                {
                    e.printStackTrace();
                }
                
            }
            return tokenizer.nextToken();
        }
    
        public int nextInt()
        {
            return Integer.parseInt(next());
        }

        public long nextLong()
        {
            return Long.parseLong(next());
        }
    
        public double nextDouble()
        {
            return Double.parseDouble(next());
        }

        String nextLine()
        { 
            String str = ""; 
            try
            { 
                str = reader.readLine(); 
            } 
            catch (IOException e) 
            { 
                e.printStackTrace(); 
            } 
            return str; 
        }         
    }    

    private static class Solution
    {
        private FastReader In;
        private PrintStream Out;

        public Solution(FastReader in, PrintStream out)
        {
            this.In = in;
            this.Out = out;
        }

        public void Solve()
        {
            Out.println("OK");
        }
    }
}



