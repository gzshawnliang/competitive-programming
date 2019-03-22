
import java.io.*;
import java.util.*;
import java.lang.Math;

class Main2
{
    public static void main(String[] args) throws IOException
    {
        // 重新定向到文件输入/输出
        System.setIn(new FileInputStream(new File("ConsecutiveIntegers2.in")));
        System.setOut(new PrintStream(new File("ConsecutiveIntegers2.out")));

        Scanner in = new Scanner(System.in);
        PrintStream out = System.out;

        new ConsecutiveIntegers2().Solve(in, out);

        in.close();
        out.close();
    }
}


class ConsecutiveIntegers2
{
    public void Solve(Scanner in, PrintStream out) 
    {
        while (true)
        {
            int n = in.nextInt();
            if (n == -1)
            {
                break;
            }

            for (int l = (int) Math.sqrt(2 * n); l >= 1; l--)
            {
                int a = (2 * n + l - l * l) / (2 * l);
                if ((2 * a + l - 1) * l == 2 * n)
                {
                    out.print(String.format("%s = %s + ... + %s\n", n, a, a + l - 1));
                    break;
                }
            }
        }
    }
}

