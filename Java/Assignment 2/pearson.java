/*import java.io.*;
import java.util.*;
class pearson
{
 String pname,pan,adhar;
 pearson(String pname, String pan , String adhar)
  {
 this.pname= pname;
 this.pan = pan;
 this.adhar= adhar;
  }
 void display()
   {
 System.out.println("Pearson name is" +pname + "\n Pearson pan card number is" +pan + "\n Pearson adhar card number is " +adhar);
   }
 public static void main(String args[])
 {
 int i;
 String pname,pan,adhar;
 pearson p[] = new pearson[5];
 Scanner sc =new Scanner(System.in);
 for(i=0;i<5;i++)
 {
 System.out.println("Enter the " +(i+1) + " person information\n");
 System.out.println("Enter the name of pearson\n");
 pname = sc.next();
 System.out.println("Enter the pan number of pearson\n");
 pan = sc.next();
 System.out.println("Enter the adhar card number of pearson\n");
 adhar = sc.next();
 p[i]=new pearson(pname,pan,adhar);
 }
 System.out.println("\n********* pearson Information*********");
 for(i=0;i<5;i++)
 p[i].display();
 }
}*/

import java.io.*;
import java.util.*;

class Pearson 
{
    String pname, pan, adhar;

    Pearson(String pname, String pan, String adhar) 
    {
        this.pname = pname;
        this.pan = pan;
        this.adhar = adhar;
    }

    void display() 
    {
        System.out.println("Person name is: " + pname
                + "\nPerson PAN card number is: " + pan
                + "\nPerson Aadhaar card number is: " + adhar);
    }

    public static void main(String[] args) 
    {
        int i;
        String pname, pan, adhar;
        Pearson[] p = new Pearson[5];
        Scanner sc = new Scanner(System.in);

        for (i = 0; i < 5; i++) 
	{
            System.out.println("Enter the information for person " + (i + 1) + ":");
            System.out.print("Enter the name of person: ");
            pname = sc.next();
            System.out.print("Enter the PAN number of person: ");
            pan = sc.next();
            System.out.print("Enter the Aadhaar card number of person: ");
            adhar = sc.next();
            p[i] = new Pearson(pname, pan, adhar);
        }

        System.out.println("\n********* Person Information *********");
        for (i = 0; i < 5; i++) {
            p[i].display();
        }
    }
}

