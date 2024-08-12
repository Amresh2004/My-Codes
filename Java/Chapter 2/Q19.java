public class Q19 {
    static int count;
    int item_no;
    String item_name;
    double item_price;
    Q19()
    {
        item_no=100;
        item_name="pen";
        item_price=10;
        count++;
    }
    Q19(int item_no,String item_name,double item_price)
    {
        this.item_no=item_no;
        this.item_name=item_name;
        this.item_price=item_price;
        count++;
    }
    void display()
    {
        System.out.println("item no is:- "+item_no);
        System.out.println("item name is:- "+item_name);
        System.out.println("iitem price is:- "+item_price);
        System.out.println("The count of object is:- "+count);
    }
    public static void main(String[] args) {
        Q19 i=new Q19();
        i.display();
        Q19 i1[]=new Q19[2];
        i1[0]=new Q19(101,"pencil",5);
        i1[0].display();
        i1[1]=new Q19(102,"RTX Geforec",199999);
        i1[1].display();
    }
}
