import java.io.*;
import java.util.*;

public class CF_1382C2_PrefixFlipHardVersion
{
    public static void main(String[] args) throws IOException
    {
        boolean isLocal= System.getProperty("ONLINE_JUDGE") == null;
        long startTime = 0;
        if (isLocal)
        {
            startTime = System.currentTimeMillis();
            //redirect stdin/stdout to local file
            System.setIn(new FileInputStream(new File("CF_1382C2_PrefixFlipHardVersion.in")));
            System.setOut(new PrintStream(new File("CF_1382C2_PrefixFlipHardVersion.out")));
        }

        Scanner in = new Scanner(System.in);
        PrintStream out = System.out;

        new CF_1382C2_PrefixFlipHardVersion_Solution().Solve(in, out);

        in.close();
        out.close();
        
        if (isLocal)
        {
            System.err.println("program exited after: " + (System.currentTimeMillis() - startTime) + "ms");
        }        
    }
}


class CF_1382C2_PrefixFlipHardVersion_Solution
{
    public void Solve(Scanner In, PrintStream Out)
    {
        int tct = In.nextInt();
        for (int tcc = 1; tcc <= tct; ++tcc)
        {
            int n = In.nextInt();
            String tmpA = In.next();
            String tmpB = In.next();

            var a = new int[n];
            var b = new int[n];
            
            for (int i = 0; i <= n - 1; ++i) a[i] = ((tmpA.charAt(i) == '1') ? 1 : 0);
            for (int i = 0; i <= n - 1; ++i) b[i] = ((tmpB.charAt(i) == '1') ? 1 : 0);

            var ans0 = new ArrayList<Integer>();
            for (int i = 0; i <= n - 1; ++i)
            {
                if (i == n - 1)
                {
                    if (a[i] == 1) ans0.add(i + 1);
                }
                else
                {
                    if (a[i] != a[i + 1]) ans0.add(i + 1);
                }
            }

            var ans1 = new ArrayList<Integer>();
            for (int i = 0; i <= n - 1; ++i)
            {
                if (i == n - 1)
                {
                    if (b[i] == 1) ans1.add(i + 1);
                }
                else
                {
                    if (b[i] != b[i + 1]) ans1.add(i + 1);
                }
            }

            Out.println(ans0.size() + ans1.size());
            for (var x:ans0)
            {
                Out.print(x); Out.print(' ');
            }

            int siz = ans1.size();
            for (int i = siz - 1; i >= 0; --i)
            {
                if (i < siz - 1) Out.print(' ');
                Out.print(ans1.get(i));
            }
            Out.print('\n');
        }
    }
}
