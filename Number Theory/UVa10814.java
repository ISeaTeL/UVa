import java.math.BigInteger;
import java.util.Scanner;


public class UVa10814 {
    public static BigInteger gcd(BigInteger s1, BigInteger s2) {
        while ((!s1.equals(BigInteger.ZERO)) && (!s2.equals(BigInteger.ZERO))) {
            s1 = s1.mod(s2);
            if (s1.equals(BigInteger.ZERO))
                break;
            s2 = s2.mod(s1);
            if (s2.equals(BigInteger.ZERO))
                break;
        }
        return s1.add(s2);
    }
    public static void main(String[] args) {
        int t;
        Scanner scanner = new Scanner(System.in);
        t = scanner.nextInt();
        while ((t--) > 0) {
            BigInteger s1 = new BigInteger(scanner.next());
            String div = scanner.next();
            BigInteger s2 = new BigInteger(scanner.next());
            BigInteger gcdInt = gcd(s1, s2);
            System.out.println(s1.divide(gcdInt).toString() + " / " + s2.divide(gcdInt).toString());
        }
    }
}
