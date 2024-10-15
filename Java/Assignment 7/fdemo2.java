import java.awt.*;

public class fdemo2 extends Frame 
{
    public static void main(String[] args) 
    {
       fdemo2 f= new fdemo2();
       f.setLayout(new GridLayout(2,2));
       Button E,W,S,N;
       
       E= new Button("ONE");
       W= new Button("TWO");
       S= new Button("THREE");
       N= new Button("FOUR");

       f.add(E);
       f.add(W);
       f.add(S);
       f.add(N);

       f.setTitle("Grid Layout Demo");
       f.setSize(400,150);
       f.setVisible(true);
    }
}
