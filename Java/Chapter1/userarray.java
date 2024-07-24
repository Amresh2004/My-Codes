import java.util.*;
public class userarray {
    public static void main(String[] args) {
        int i,n;
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the number of elements");
        n=sc.nextInt();
        int a[]=new int[n];
        System.out.println("Enter the elements");
        for(i=0;i<n;i++)
        {
            a[i]=sc.nextInt();
        }
        System.out.println("The array elemets are: ");
        for(i=0;i<n;i++)
        {
            System.out.println(a[i]);
        }
    }
}
