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
    public static void main(final String[] args) throws IOException
    {
        final boolean isLocal= System.getProperty("ONLINE_JUDGE") == null;
        long startTime = 0;
        if (isLocal)
        {
            startTime = System.currentTimeMillis();
            //redirect stdin/stdout to local file
            System.setIn(new FileInputStream(new File("EM_726242.in")));
            //System.setOut(new PrintStream(new File("EM_726242.out")));
        }

        final Scanner in = new Scanner(System.in);
        final PrintStream out = System.out;

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
    public void Solve(final Scanner in, final PrintStream out)
    {
        //String c="a2342341";
        //out.println(c.hashCode());
        double do1=in.nextDouble();
        out.println(do1);

        final Integer a=100;
        final Integer b=100;
        out.println(a ==b);

        final Integer x=1000;
        final Integer y=1000;

        out.println(x.intValue()==y.intValue());

        final ArrayList<Integer> al=new ArrayList<>(Arrays.asList(1,2,3,4,5));

        for(int i=0, len=al.size();i<=len-1;++i)
        {
            out.format("%d ", al.get(i));
        }
        out.print('\n');

        al.forEach(v-> out.format("%d ", v));


        out.print('\n');

        al.forEach(v-> 
        {
            if(v==3)
                return;

            out.format("%d ", v);
        });

        out.print('\n');
        final var map1=  new HashMap<Integer, Integer>(Map.of(1,2, 3,4));
        map1.put(5,7);
        map1.forEach( (key,val) -> {
            out.format("%d->%d\n", key, val);
        } );

        var aa=new int[10];
        aa[9]=3;


        out.print('\n');

        final var myList=new ArrayList<ArrayList<Integer>>() ;
        myList.add(new ArrayList<Integer>(){{add(3);add(4);}});

        var pi2 = 3.67878;

        out.printf("%f, %1$+020.10f %n", pi2);
        
        out.printf(String.format("%2$s %1$s %n", "World", "Hello"));      // prints: "Hello World"

        //out.println("%2$s %1$s %n");                   // prints: "Hello World"
        
        out.println(myList.get(0).get(0));

//        for(int i = 0,int length = al.size(); i <= length-1; ++i)
//        {
//            out.println(al.get(i));
//        }

        //for(int i)
    }
}



