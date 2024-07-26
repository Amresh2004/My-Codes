import java.util.*;
import java.io.*;

public class SetA1 {
    int num;  
    
    public SetA1() {
        num = 0;
    } 
    
    public SetA1(int num) {
        this.num = num;
    }
    
    public static void main(String[] args) {
       SetA1 m1 = new SetA1();
       if(args.length > 0) {
            int n = Integer.parseInt(args[0]); 
            SetA1 m2 = new SetA1(n);
            System.out.println(m1.num);
            System.out.println(m2.num);
        } else {
          System.out.println("Insufficient arguments");
        }
     }
}
/*amresh2004@Amresh:~$ javac SetA1.java
amresh2004@Amresh:~$ javap -c SetA1
Compiled from "SetA1.java"
public class SetA1 {
  int num;

  public SetA1();
    Code:
       0: aload_0
       1: invokespecial #1                  // Method java/lang/Object."<init>":()V
       4: aload_0
       5: iconst_0
       6: putfield      #2                  // Field num:I
       9: return

  public SetA1(int);
    Code:
       0: aload_0
       1: invokespecial #1                  // Method java/lang/Object."<init>":()V
       4: aload_0
       5: iload_1
       6: putfield      #2                  // Field num:I
       9: return

  public static void main(java.lang.String[]);
    Code:
       0: new           #3                  // class SetA1
       3: dup
       4: invokespecial #4                  // Method "<init>":()V
       7: astore_1
       8: aload_0
       9: arraylength
      10: ifle          52
      13: aload_0
      14: iconst_0
      15: aaload
      16: invokestatic  #5                  // Method java/lang/Integer.parseInt:(Ljava/lang/String;)I
      19: istore_2
      20: new           #3                  // class SetA1
      23: dup
      24: iload_2
      25: invokespecial #6                  // Method "<init>":(I)V
      28: astore_3
      29: getstatic     #7                  // Field java/lang/System.out:Ljava/io/PrintStream;
      32: aload_1
      33: getfield      #2                  // Field num:I
      36: invokevirtual #8                  // Method java/io/PrintStream.println:(I)V
      39: getstatic     #7                  // Field java/lang/System.out:Ljava/io/PrintStream;
      42: aload_3
      43: getfield      #2                  // Field num:I
      46: invokevirtual #8                  // Method java/io/PrintStream.println:(I)V
      49: goto          60
      52: getstatic     #7                  // Field java/lang/System.out:Ljava/io/PrintStream;
      55: ldc           #9                  // String Insufficient arguments
      57: invokevirtual #10                 // Method java/io/PrintStream.println:(Ljava/lang/String;)V
      60: return
}
amresh2004@Amresh:~$/* */