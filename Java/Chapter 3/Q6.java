import java.util.*;


class bank
{
    int getInterest()
    {
        return 0;
    }
}

class SBI extends bank
{
    int getInterest()
    {
        return 10;
    }
}

class HDFC extends bank
{
    int getInterest()
    {
        return 20;
    }
}

class ICICI extends bank
{
    int getInterest()
    {
        return 30;
    }
}
public class Q6 {
    public static void main(String[] args) {
        bank b=new bank();
        b.getInterest();
        SBI s=new SBI();
        s.getInterest();
        HDFC h=new HDFC();
        h.getInterest();
        ICICI i=new ICICI();
        i.getInterest();
        System.out.println("Inteerest Rate of Bank is: "+ b.getInterest());
        System.out.println("Inteerest Rate of SBI is: "+ s.getInterest());
        System.out.println("Inteerest Rate of HDFC is: "+ h.getInterest());
        System.out.println("Inteerest Rate of ICICI is: "+ i.getInterest());

    }
}
