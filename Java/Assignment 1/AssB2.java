public class AssB2 {
    private int number;

    public AssB2() {
        this.number = 0;
    }

    public AssB2(int number) {
        this.number = number;
    }

    public boolean isNegative() {
        return this.number < 0;
    }

    public boolean isPositive() {
        return this.number > 0;
    }

    public boolean isZero() {
        return this.number == 0;
    }

    public boolean isOdd() {
        return this.number % 2 != 0;
    }

    public boolean isEven() {
        return this.number % 2 == 0;
    }

    public static void main(String[] args) {
        AssB2 myNum;

        if (args.length > 0) {
            try {
                int value = Integer.parseInt(args[0]);
                myNum = new AssB2(value);
            } catch (NumberFormatException e) {
                System.out.println("Invalid input. Using default constructor.");
                myNum = new AssB2();
            }
        } else {
            System.out.println("No argument provided. Using default constructor.");
            myNum = new AssB2();
        }

        System.out.println("Number is negative: " + myNum.isNegative());
        System.out.println("Number is positive: " + myNum.isPositive());
        System.out.println("Number is zero: " + myNum.isZero());
        System.out.println("Number is odd: " + myNum.isOdd());
        System.out.println("Number is even: " + myNum.isEven());
    }
}

/*
javac AssB2.java
java AssB2 5
javadoc -d doc AssB2.java */