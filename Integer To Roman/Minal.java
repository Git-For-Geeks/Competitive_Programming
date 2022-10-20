import java.util.*;
class Minal {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("num= ");
        int num = sc.nextInt();
        String M[] = {"","M","MM","MMM"};
        String C[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        String X[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        String I[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        System.out.println(M[(num/1000)%10] + C[(num/100)%10] + X[(num/10)%10] + I[(num%10)]);
        
        
    }
}