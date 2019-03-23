
/*
===========================================================
 * @名称:		11790 - Murcia's Skyline
 * @作者:		Thomas Liang 
 * @创建时间:   2019-03-22 15:59:39 
 * @修改人:     Thomas Liang 
 * @修改时间:   2019-03-22 15:59:39 
 * @备注:		
 * @题目来源： https://uva.onlinejudge.org/external/117/11790.pdf
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
        System.setIn(new FileInputStream(new File("SkyLine.in")));
        System.setOut(new PrintStream(new File("SkyLine.out")));

        Scanner in = new Scanner(System.in);
        PrintStream out = System.out;

        new SkyLineArray().Solve(in, out);

        in.close();
        out.close();
    }
}

//0.81s
class SkyLineArray
{
    public void Solve(Scanner in, PrintStream out)
    {
        int totalCase = in.nextInt();
        for (int c = 1; c <= totalCase; ++c)
        {
            int n = in.nextInt();
            int[] h = new int[n];
            int[] w = new int[n];

            for (int i = 0; i <= n - 1; ++i)
            {
                h[i] = in.nextInt();
            }
            for (int i = 0; i <= n - 1; ++i)
            {
                w[i] = in.nextInt();
            }

            int[] dpI = new int[n];
            int[] dpD = new int[n];

            for (int i = 0; i <= n - 1; ++i)
            {
                dpI[i] = w[i];
                dpD[i] = w[i];

                for (int j = 0; j <= i - 1; ++j)
                {
                    if (h[i] > h[j])
                    {
                        dpI[i] = Math.max(dpI[i], dpI[j] + w[i]);
                    } else if (h[i] < h[j])
                    {
                        dpD[i] = Math.max(dpD[i], dpD[j] + w[i]);
                    }
                }
            }

            int ans1 = Arrays.stream(dpI).max().getAsInt();
            int ans2 = Arrays.stream(dpD).max().getAsInt();
            
            // int ans1 = IntStream.of(dpI).max().getAsInt();
            // int ans2 = IntStream.of(dpD).max().getAsInt();
            String ans = "Case " + c + ". ";
            if (ans1 >= ans2)
            {
                ans += "Increasing (" + ans1 + "). Decreasing (" + ans2 + ").\n";
            } else
            {
                ans += "Decreasing (" + ans2 + "). Increasing (" + ans1 + ").\n";
            }
            out.print(ans);
        }
    }
}

// Time limit
class SkyLineArrayList
{
    public void Solve(Scanner in, PrintStream out)
    {
        int totalCase = in.nextInt();
        for (int c = 1; c <= totalCase; ++c)
        {
            int n = in.nextInt();
            int[] h = new int[n];
            int[] w = new int[n];

            for (int i = 0; i <= n - 1; ++i)
            {
                h[i] = in.nextInt();
            }
            for (int i = 0; i <= n - 1; ++i)
            {
                w[i] = in.nextInt();
            }

            ArrayList<Integer> dpI = new ArrayList<Integer>(Collections.nCopies(n, 0));
            ArrayList<Integer> dpD = new ArrayList<Integer>(Collections.nCopies(n, 0));

            for (int i = 0; i <= n - 1; ++i)
            {
                dpI.set(i, w[i]);
                dpD.set(i, w[i]);

                for (int j = 0; j <= i - 1; ++j)
                {
                    if (h[i] > h[j])
                    {
                        dpI.set(i, Math.max(dpI.get(i), dpI.get(j) + w[i]));
                    } else if (h[i] < h[j])
                    {
                        dpD.set(i, Math.max(dpD.get(i), dpD.get(j) + w[i]));
                    }
                }
            }

            int ans1 = Collections.max(dpI);
            int ans2 = Collections.max(dpD);
            ;

            String ans = "Case " + c + ". ";
            if (ans1 >= ans2)
            {
                ans += "Increasing (" + ans1 + "). Decreasing (" + ans2 + ").\n";
            } else
            {
                ans += "Decreasing (" + ans2 + "). Increasing (" + ans1 + ").\n";
            }
            out.print(ans);
        }
    }
}

// Time limit
class SkyLineVector
{
    public void Solve(Scanner in, PrintStream out)
    {
        int totalCase = in.nextInt();
        for (int c = 1; c <= totalCase; ++c)
        {
            int n = in.nextInt();
            int[] h = new int[n];
            int[] w = new int[n];

            for (int i = 0; i <= n - 1; ++i)
            {
                h[i] = in.nextInt();
            }
            for (int i = 0; i <= n - 1; ++i)
            {
                w[i] = in.nextInt();
            }

            Vector<Integer> dpI = new Vector<Integer>(Collections.nCopies(n, 0));
            Vector<Integer> dpD = new Vector<Integer>(Collections.nCopies(n, 0));

            for (int i = 0; i <= n - 1; ++i)
            {
                dpI.set(i, w[i]);
                dpD.set(i, w[i]);

                for (int j = 0; j <= i - 1; ++j)
                {
                    if (h[i] > h[j])
                    {
                        dpI.set(i, Math.max(dpI.get(i), dpI.get(j) + w[i]));
                    } else if (h[i] < h[j])
                    {
                        dpD.set(i, Math.max(dpD.get(i), dpD.get(j) + w[i]));
                    }
                }
            }

            int ans1 = Collections.max(dpI);
            int ans2 = Collections.max(dpD);

            String ans = "Case " + c + ". ";
            if (ans1 >= ans2)
            {
                ans += "Increasing (" + ans1 + "). Decreasing (" + ans2 + ").\n";
            } else
            {
                ans += "Decreasing (" + ans2 + "). Increasing (" + ans1 + ").\n";
            }
            out.print(ans);
        }
    }
}