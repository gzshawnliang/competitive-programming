/*
-------------------------------------------------------------------
* @Name:           {Name}
* @Author:         {Author}
* @Create Time:    {CreateTime}
* @Url:            {Url}
* @Description:    {Description}
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

public class {fileNameNoExtension}
{
    public static void main(String[] args) throws IOException
    {
        boolean isLocal= System.getProperty("ONLINE_JUDGE") == null;
        long startTime = 0;
        if (isLocal)
        {
            startTime = System.currentTimeMillis();
            //redirect stdin/stdout to local file
            System.setIn(new FileInputStream(new File("{fileNameNoExtension}.in")));
            System.setOut(new PrintStream(new File("{fileNameNoExtension}.out")));
        }

        Scanner in = new Scanner(System.in);
        PrintStream out = System.out;

        new {fileNameNoExtension}_Solution().Solve(in, out);

        in.close();
        out.close();
        
        if (isLocal)
        {
            System.err.println("program exited after: " + (System.currentTimeMillis() - startTime) + "ms");
        }        
    }
}


class {fileNameNoExtension}_Solution
{
    public void Solve(Scanner in, PrintStream out)
    {
        /*
        int n      = in.nextInt();        // read input as integer
        long k     = in.nextLong();       // read input as long
        double d   = in.nextDouble();     // read input as double
        String str = in.next();           // read input as String
        String s   = in.nextLine();       // read whole line as String
        */        
        out.println("OK");
    }
}

