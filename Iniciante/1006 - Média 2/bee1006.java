import java.io.IOException;
import java.util.Scanner;
// Beecrowd 1006 - Média 2

public class bee1006 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        double n1 = scan.nextDouble();
        double n2 = scan.nextDouble();
        double n3 = scan.nextDouble();

        double ans = (n1*.2 + n2*.3 + n3*.5);
        System.out.printf("MEDIA = %.1f%n", ans);
    }
}
