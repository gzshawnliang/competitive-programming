import java.io.*;
import java.util.*;
import java.lang.Math;

/**
 * UVA 11254 Consecutive Integers
 * UVA 的类名一定要用Main，不能使用public，否则Runtime error
 * https://thesparkboy.wordpress.com/2016/11/01/runtime-error-in-uva-for-java-users/
 * https://uva.onlinejudge.org/data/p100.java.html
 */
public class MainUVA
{
    public static void main(String[] args) throws IOException
    {
        // 文件输入输出
        // Scanner in = new Scanner(new File("Main.in"));
        // PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("Main.out")));

        // 标准输入输出,Scanner比较慢,使用FastScanner: http://neerc.ifmo.ru/trains/information/Template.java
        Scanner in = new Scanner(System.in); 
        PrintWriter out = new PrintWriter(System.out, true);

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
                    // 0.210s
                    out.println(String.format("%s = %s + ... + %s", n, a, a + l - 1));

                    // 0.150s
                    // cout.print(n);
                    // cout.print(" = ");
                    // cout.print(a);
                    // cout.print(" + ... + ");
                    // cout.println(a + l - 1);
                    break;
                }
            }
        }
        in.close();
        out.close();
    }
}

