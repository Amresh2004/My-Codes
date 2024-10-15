import java.awt.*;

public class listdemo extends Frame 
{
    public static void main(String[] args) 
    {
        listdemo ld= new listdemo();
        ld.setLayout(new FlowLayout());

        Panel p=new Panel();
        List l=new List(3);

        l.add("FY");
        l.add("SY");
        l.add("TY");
        l.add("MSC-I");
        l.add("MSC-II");

        p.add(l);
        ld.add(p);

        ld.setTitle("LIST DEMO");
        ld.setSize(400,150);
        ld.setVisible(true);    
    }
}
