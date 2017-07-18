import java.util.Scanner;
import java.math.BigDecimal;

public class Main{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String str;
        str = scanner.next();
        BigDecimal n, result;
        n = new BigDecimal(str);
        while(true)
        {
            result = ((new BigDecimal(3)).multiply(n)).add(new BigDecimal(4));
            //println(result);
            result = result.multiply(n.subtract(new BigDecimal(1)));
            result = result.add(new BigDecimal(4));
            if (result.remainder(new BigDecimal(8)).compareTo(new BigDecimal(0)) == 0)
                break;
            n=n.add(new BigDecimal(1));
        }
        System.out.println(n);
    }

/*
        public static void main(String[] args) {   
        Scanner in = new Scanner(System.in);   
        String str, ors;   
        BigDecimal x, y, z;   
        while (in.hasNext()) {   
            ors = in.next();   
            str = ors.substring(ors.indexOf(".") + 1, ors.length());   
            z = new BigDecimal(0);   
            y = new BigDecimal(1);   
            for (int i = 0; i < str.length(); ++i) {   
                x = new BigDecimal(str.charAt(i) - '0');   
                y = y.multiply(new BigDecimal(8));   
                x = x.divide(y, str.length() * 3, RoundingMode.HALF_UP);   
                z = z.add(x);   
            }   
            System.out.println(ors + " [8] = " + z + " [10]");   
        }   
    }   */
}