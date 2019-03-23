/*
===========================================================
 * @名称:		105 The Skyline Problem
 * @作者:		Thomas Liang 
 * @创建时间:   2019-03-22 15:59:39 
 * @修改人:     Thomas Liang 
 * @修改时间:   2019-03-22 15:59:39 
 * @备注:		
 * @题目来源： https://uva.onlinejudge.org/external/1/105.pdf
===========================================================
*/
import java.io.*;
import java.util.*;
import java.lang.Math;

class Main
{
    public static void main(String[] args) throws IOException
    {
        // 重新定向到文件输入/输出
        System.setIn(new FileInputStream(new File("SkyLineProblem.in")));
        System.setOut(new PrintStream(new File("SkyLineProblem.out")));

        Scanner in = new Scanner(System.in);
        PrintStream out = System.out;

        new SkyLineProblem().Solve(in, out);

        in.close();
        out.close();
    }
}


class SkyLineProblem
{
    public void Solve(Scanner in, PrintStream out)
    {
        int L = 20002;
        int R = 0;
        int[] a = new int[L];

        while (in.hasNext())
        {
            int l = in.nextInt();
            int h = in.nextInt();
            int r = in.nextInt();

            l *= 2;
            r *= 2;

            for (int i = l; i <= r; ++i)
            {
                a[i] = Math.max(a[i], h);
            }

            L = Math.min(L, l);
            R = Math.max(R, r);
        }
        ++R;

        Boolean first = false;
        int i = L;

        while (i <= R)
        {
            if (first == true)
                out.print(' ');

            first = true;

            if (a[i] < a[i - 1])
            {
                out.print((i - 1) / 2);
            } else
            {
                out.print(i / 2);
            }
            out.print(' ');
            out.print(a[i]);

            int now = a[i];
            while (i <= R && a[i] == now)
            {
                ++i;
            }
        }
        out.print('\n');
    }
}
