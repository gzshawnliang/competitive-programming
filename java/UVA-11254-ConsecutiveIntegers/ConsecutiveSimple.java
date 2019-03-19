import java.io.*;
import java.util.*;
import java.lang.Math;

public class ConsecutiveSimple
{
    public static void main(String[] args) throws IOException
    {
        Scanner in = new Scanner(System.in); 
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
                    System.out.println(String.format("%s = %s + ... + %s", n, a, a + l - 1));
                    break;
                }
            }
        }
        in.close();
        System.out.close();
    }
}