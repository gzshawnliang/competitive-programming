import java.io.*;
import java.util.*;
import java.lang.Math;

public class ConsecutiveSimple
{
    public static void main(String[] args) 
    {
        Scanner in = new Scanner(System.in);
        PrintStream out = System.out;
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
                    String s = String.format("%s = %s + ... + %s", n, a, a + l - 1);
                    out.println(s);
                    break;
                }
            }
        }
        in.close();
        out.close();
    }
}