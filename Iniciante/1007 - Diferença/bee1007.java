// Beecrowd 1007 - Diferença
import java.io.IOException;
import java.util.Scanner;

public class bee1007 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int A = scan.nextInt();
        int B = scan.nextInt();
        int C = scan.nextInt();
        int D = scan.nextInt();

        int ans = (A * B - C * D);
        System.out.println("DIFERENCA = " + ans);
    }
}
