import java.io.*;
import java.util.*;
import java.lang.Math;

/**
 * UVA 的类名一定要用Main，不能使用public，否则Runtime error
 * https://thesparkboy.wordpress.com/2016/11/01/runtime-error-in-uva-for-java-users/
 * https://uva.onlinejudge.org/data/p100.java.html
 */
class Main 
{
    public static void main(String[] args) throws IOException 
    {

        // 文件输入输出
        // File inFile = new File("Main.in");
        // Scanner cin = new Scanner(inFile);
        // PrintWriter cout = new PrintWriter(new BufferedWriter(new FileWriter("Main.out")));

        // 标准输入输出
        Scanner cin = new Scanner(System.in);
        PrintWriter cout = new PrintWriter(System.out, true);

        while (true) 
        {
            int n = cin.nextInt();
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
                    cout.println(String.format("%s = %s + ... + %s", n, a, a + l - 1));

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
        cin.close();
        cout.close();
    }
}