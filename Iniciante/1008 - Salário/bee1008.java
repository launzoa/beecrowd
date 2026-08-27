// Beecrowd 1008 - Salário
import java.util.Scanner;

public class bee1008 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int n = scan.nextInt();
        int Hrs = scan.nextInt();
        double Sal = scan.nextDouble();
        double total = Hrs*Sal;
        System.out.println("NUMBER = " + n);
        System.out.printf("SALARY = U$ %.2f%n", total);

    }
}
