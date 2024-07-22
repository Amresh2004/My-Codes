import java.util.*;
public class forloopeven {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int i,n;
        System.out.println("Enter the number of elements in the array:");
        n=sc.nextInt();
        for(i=1;i<=n;i++)
        {
            if(i%2==0)
            {
                System.out.println(i);
            }
        }
    }
}
