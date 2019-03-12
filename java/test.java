public class test {
    public static void main(String[] args) {
        int a = 525;
        long b = 12456545645L;

        String binaryA = Integer.toString(a, 2);
        System.out.println("Binary representation" + " of A : " + binaryA);
        String binaryB = Long.toString(b, 2);
        System.out.println("Binary representation" + " of B : " + binaryB);
        String octalA = Integer.toString(a, 8);
        System.out.println("Octal representation" + " of A : " + octalA);
        String octalB = Long.toString(b, 8);
        System.out.println("Octal representation" + " of B : " + octalB);

        String decB = Long.toString(b, 10);
        System.out.println("Octal representation" + " of B : " + decB);

        int a1=10;
        int b1=12;
        int c=113;
        int d=-34;
        int e= Math.max(a1, b1);


    }
}