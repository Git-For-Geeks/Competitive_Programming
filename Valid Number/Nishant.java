import java.util.*;
class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String regex = "^[-+]?\d*(([.]+\d+)+)?(\d+[.])?([eE][-+]?\d+)?$";
        String number = "+9322.3e10";
        if(number.matches(regex)){
            System.out.println("true");
        }
        else{
            System.out.println("false");
        }
    }
}
