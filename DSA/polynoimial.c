#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coeff;
    int power;
    struct Node * next;
}*newnode,*head1,*head2,*head3,*last1,*last2,*last3,*temp1,*temp2,*temp3,*temp4,*tempX;

void CreatePolynomials(int terms1, int terms2)
{
    int i = 1,j = 0;

    while(i != 3)
    {
        if(i == 1)          //for 1st polynomial
        {
            printf("Enter first polynomial :\n");

            for(j = 1;j <= terms1;j++)
            {
                newnode = (struct Node *)malloc(sizeof(struct Node));
                newnode->next = NULL;

                printf("Enter coefficient : ");
                scanf("%d",&newnode->coeff);
                printf("Enter power : ");
                scanf("%d",&newnode->power);

                if(head1 == NULL)
                {
                    head1 = last1 = newnode;
                }
                else
                {
                    last1->next = newnode;
                    last1 = newnode;
                }
            }
        }
        else        //for 2nd polynomial
        {
            printf("\nEnter second polynomial :\n");

            for(j = 1;j <= terms2;j++)
            {
                newnode = (struct Node *)malloc(sizeof(struct Node));
                newnode->next = NULL;

                printf("Enter coefficient : ");
                scanf("%d",&newnode->coeff);
                printf("Enter power : ");
                scanf("%d",&newnode->power);

                if(head2 == NULL)
                {
                    head2 = last2 = newnode;
                }
                else
                {
                    last2->next = newnode;
                    last2 = newnode;
                }
            }
        }
        i++;
    }
}

void AddPolynomials()
{
    temp1 = head1;
    temp2 = head2;

    while(temp1 != NULL)
    {
        
        while(temp2 != NULL)
        {
            
            if(temp1->power > temp2->power)        //1st polynomial power is greater
            {
                newnode = (struct Node *)malloc(sizeof(struct Node));

                newnode->next = NULL;

                newnode->coeff = temp1->coeff;
                newnode->power = temp1->power;

                if(head3 == NULL)
                {
                    head3 = last3 = newnode;
                }
                else
                {
                    last3->next = newnode;
                    last3 = newnode;
                }

                temp1 = temp1->next;

            }
            else if(temp1->power < temp2->power)        //2nd polynomial power is greater
            {
                newnode = (struct Node *)malloc(sizeof(struct Node));

                newnode->next = NULL;
                if(head3 == NULL)
                {
                    head3 = last3 = newnode;
                }
                else
                {
                    last3->next = newnode;
                    last3 = newnode;
                }
                newnode->coeff = temp2->coeff;
                newnode->power = temp2->power;

                temp2 = temp2->next;

            }
            else if(temp1->power == temp2->power)            //same power
            {
                newnode = (struct Node *)malloc(sizeof(struct Node));

                newnode->next = NULL;

                newnode->coeff = temp1->coeff + temp2->coeff;
                newnode->power = temp1->power;
                
                if(newnode->coeff == 0)
                {
                    free(newnode);
                }

                if(head3 == NULL)
                {
                    head3 = last3 = newnode;
                }
                else
                {
                    last3->next = newnode;
                    last3 = newnode;
                }
                
                temp1 = temp1->next;                
                temp2 = temp2->next;
            }
        }
    }
}


void MultiplyPolynomials()
{
    temp1 = head1;
    temp2 = head2;

    while(temp1 != NULL)
    {
        while(temp2 != NULL)
        {
            newnode = (struct Node *)malloc(sizeof(struct Node));
            newnode->next = NULL;

            newnode->coeff = temp1->coeff * temp2->coeff;
            newnode->power = temp1->power + temp2->power;

            if(head3 == NULL)
            {
                head3 = last3 = newnode;
            }
            else
            {
                last3 -> next = newnode;
                last3 = newnode;
            }
            temp2 = temp2->next;
        }
        temp2 = head2;
        temp1 = temp1->next;
    }

}


void Display()
{
    temp3 = head3;

    while(temp3 != NULL)
    {
        if(temp3->coeff < 0)
        {
            printf("%dx^%d",temp3->coeff,temp3->power);
        }
        else if(temp3->coeff > 0)
        {
            printf("+%dx^%d",temp3->coeff,temp3->power);
        }
        temp3 = temp3->next;
    }
    printf("\n");
}

int main()
{
    int terms1 = 0,terms2 = 0;
    printf("Enter number of terms in first polynomial : ");
    scanf("%d",&terms1);

    printf("Enter number of terms in second polynomial : ");
    scanf("%d",&terms2);
    printf("\n");

    CreatePolynomials(terms1,terms2);

    MultiplyPolynomials();
    AddPolynomials();

    printf("\n Multiply polynomial is : \n");
    printf("\n Addition polynomial is : \n");
    Display();

    return 0;
}
