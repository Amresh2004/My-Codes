import java.awt.*;

public class bdemo extends Frame 
{
    public static void main(String[] args) 
    {
        bdemo b= new bdemo();
        b.setLayout(new FlowLayout());
        Button O,C;

        O= new Button("OK");
        C= new Button("CANCEL");

        b.add(O);
        b.add(C);

        b.setTitle("BUTTON DEMO");
        b.setSize(400,150);
        b.setVisible(true); 
    }
}
