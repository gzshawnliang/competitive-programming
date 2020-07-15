/*
-------------------------------------------------------------------
* @Name:           
* @Author:         Thomas
* @Create Time:    2020/7/14 21:28:57  (UTC+08:00)
* @Url:            
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

public class EM_726242
{
    public static void main(String[] args) throws IOException
    {
        boolean isLocal= System.getProperty("ONLINE_JUDGE") == null;
        long startTime = 0;
        if (isLocal)
        {
            startTime = System.currentTimeMillis();
            //redirect stdin/stdout to local file
            System.setIn(new FileInputStream(new File("EM_726242.in")));
            //System.setOut(new PrintStream(new File("EM_726242.out")));
        }

        Scanner in = new Scanner(System.in);
        PrintStream out = System.out;

        new EM_726242_Solution().Solve(in, out);

        in.close();
        out.close();
        
        if (isLocal)
        {
            System.err.println("program exited after: " + (System.currentTimeMillis() - startTime) + "ms");
        }        
    }
}


class EM_726242_Solution
{
    public void Solve(Scanner in, PrintStream out)
    {
        //String c="a2342341";
        //out.println(c.hashCode());

        Integer a=100;
        Integer b=100;
        out.println(a ==b);



        Integer x=1000;
        Integer y=1000;

        out.println(x.intValue()==y.intValue());

        ArrayList<Integer> al=new ArrayList<>(5);

        var kk=0;

        for(int i=0, len=al.size();i<=len-1;++i)
        {
            out.println(al.get(i));
        }

        var myList=new ArrayList<ArrayList<Integer>>() ;
        myList.add(new ArrayList<Integer>(){{add(3);add(4);}});

        out.format("%f, %1$+020.10f %n", Math.PI);

        out.println(myList.get(0).get(0));

//        for(int i = 0,int length = al.size(); i <= length-1; ++i)
//        {
//            out.println(al.get(i));
//        }

        //for(int i)
    }
}

