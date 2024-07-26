

    import java.util.Scanner;

public class SetA3 
{
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        int choice;

        do {
            System.out.println("\nMenu:");
            System.out.println("1. Calculate the volume of cylinder");
            System.out.println("2. Find the factorial of a given number");
            System.out.println("3. Check if a number is Armstrong or not");
            System.out.println("4. Exit");
            System.out.print("Enter your choice (1-4): ");
            
            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    Volume();
                    break;
                case 2:
                    Factorial();
                    break;
                case 3:
                    ArmstrongNumber();
                    break;
                case 4:
                    System.out.println("Exiting the program. Goodbye!");
                    break;
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        } while (choice != 4);

        scanner.close();
    }

    private static void Volume() 
    {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the radius of the cylinder: ");
        double radius = scanner.nextDouble();
        System.out.print("Enter the height of the cylinder: ");
        double height = scanner.nextDouble();

        double volume = Math.PI * radius * radius * height;
        System.out.printf("The volume of the cylinder is: %.2f\n", volume);
    }

    private static void Factorial() 
    {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a number to calculate its factorial: ");
        int num = scanner.nextInt();

        long factorial = 1;
        for (int i = 1; i <= num; i++) 
        {
            factorial *= i;
        }

        System.out.println("The factorial of " + num + " is: " + factorial);
    }

    private static void ArmstrongNumber() 
    {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a number to check if it's an Armstrong number: ");
        int num = scanner.nextInt();

        int originalNum = num;
        int sum = 0;
        int digits = String.valueOf(num).length();

        while (num > 0) 
        {
            int digit = num % 10;
            sum += Math.pow(digit, digits);
            num /= 10;
        }

        if (sum == originalNum) 
        {
            System.out.println(originalNum + " is an Armstrong number.");
        } 
        else 
        {
            System.out.println(originalNum + " is not an Armstrong number.");
        }
    }
}