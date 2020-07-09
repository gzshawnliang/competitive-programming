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
        if (System.getProperty("ONLINE_JUDGE") == null)
        {
            //redirect stdin/stdout to local file
            System.setIn(new FileInputStream(new File("{fileNameNoExtension}.in")));
            System.setOut(new PrintStream(new File("{fileNameNoExtension}.out")));
        }

        Scanner in = new Scanner(System.in);
        PrintStream out = System.out;

        new {fileNameNoExtension}_Solution().Solve(in, out);

        in.close();
        out.close();
    }
}


class {fileNameNoExtension}_Solution
{
    public void Solve(Scanner in, PrintStream out)
    {
        out.println("OK");
    }
}

