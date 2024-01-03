#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#pragma warning ( disable : 4996 )
#define COMBO_A 10.00
#define COMBO_B 15.00
#define COMBO_C 18.00
#define COMBO_D 24.00
#define SST_RATE 10.00

//Function Declaration
void logo(void);
void menu(void);
int order(void);
int dailysalesreport(void);

//Global Variable
int customer, totalCust, quanA, quanB, quanC, quanD, salesAmount;
double SoldA, SoldB, SoldC, SoldD, totalTax, totalRM;

int main()
{
    //Local Variable
    char selection, again;
    int  numComA, numComB, numComC, numComD;
    double comboCharge, totalToPay, changeDue, amountPaid, totalComA, totalComB, totalComC, totalComD, tax, subTotal;

    //Display
    logo();
    menu();
    customer = 1; //To Display Customer Number
    printf("  Customer No : %d\n", customer);

    //Starting value
    comboCharge = 0;
    subTotal = 0;
    SoldA = 0;
    SoldB = 0;
    SoldC = 0;
    SoldD = 0;
    totalTax = 0;

    //Looping
    do
    {
        selection = order();//call function

        switch (toupper(selection))
        {
        case'A':
            printf("  Enter Quantity > ");
            scanf("%d", &numComA);
            totalComA = numComA * COMBO_A;
            printf("  Combo A : %d @ RM10 = RM%.2f\n\n", numComA, totalComA);
            subTotal += totalComA;
            quanA += numComA; //for dailysalesreport
            SoldA = quanA * COMBO_A;  //for dailysalesreport
            break;

        case'B':
            printf("  Enter Quantity > ");
            scanf("%d", &numComB);
            totalComB = numComB * COMBO_B;
            printf("  Combo B : %d @ RM15 = RM%.2f\n\n", numComB, totalComB);
            subTotal += totalComB;
            quanB += numComB; //for dailysalesreport
            SoldB = quanB * COMBO_B; //for dailysalesreport
            break;

        case'C':
            printf("  Enter Quantity > ");
            scanf("%d", &numComC);
            totalComC = numComC * COMBO_C;
            printf("  Combo C : %d @ RM18 = RM%.2f\n\n", numComC, totalComC);
            subTotal += totalComC;
            quanC += numComC; //for dailysalesreport
            SoldC = quanC * COMBO_C; //for dailysalesreport
            break;

        case'D':
            printf("  Enter Quantity > ");
            scanf("%d", &numComD);
            totalComD = numComD * COMBO_D;
            printf("  Combo D : %d @ RM24 = RM%.2f\n\n", numComD, totalComD);
            subTotal += totalComD;
            quanD += numComD; //for dailysalesreport
            SoldD = quanD * COMBO_D;  //for dailysalesreport
            break;

        case'Q':
            comboCharge += subTotal; //Total of all the combo selected

            tax = comboCharge * SST_RATE / 100;   //Calculate SST charge
            totalToPay = comboCharge + tax;       //Total amount with SST

            printf("            Combo Charges = RM %.2f\n", comboCharge);
            printf("            Add (10%%)SST  = RM %5.2f\n", tax);
            printf("            TOTAL TO PAY  = RM %.2f\n", totalToPay);

            printf(" Amount Paid   > RM ");  //Amount that customer paid
            scanf("%lf", &amountPaid);
            printf("            Amount Paid   = RM %.2f\n\n", amountPaid);

            if (amountPaid < totalToPay)
            {
                printf("Insufficient funds\n");
                printf("Enter amount again > RM ");
                scanf("%lf", &amountPaid);
                changeDue = amountPaid - totalToPay; //processing to change due
                printf("            Change Due    = RM %.2f\n", changeDue);
            }
            else
            {
                changeDue = amountPaid - totalToPay; //processing to change due
                printf("            Change Due    = RM %.2f\n", changeDue);
            }

            totalTax += tax; // for dailysalesreport

            printf("\nTHANK YOU FOR VISIT OUR RESTAURANT,HOPE CAN SEE U AGAIN! HAVE A NICE DAY!!!\n");
            break;

        default:
            printf("Invalid input,please select A,B,C,D for making order or Q to exit\n\n");

        }

    } while (toupper(selection) != 'Q');

        printf("Next customer? Y/N > ");
        scanf(" %c", &again);

        if (toupper(again) == 'Y')
        {
            menu();
            printf("  Customer No : %d\n", ++customer);
            selection = order();
        }
        else if (toupper(again) == 'N')
            dailysalesreport();
        else
        {
            printf("Invalid response,please select Y or N\n");
            printf("Next customer? Y/N > ");
            scanf("%c", &again);
        }

    system("pause");
    return 0;
}

//Function Definition
void logo(void)
{

    printf("                  ------=====----------------------=====------                          \n");
    printf("                     \\\/#\*****]|Jingex's Burgers|[*****#///                         \n");
    printf("                  ------=====----------------------=====------                          \n");

}

void menu(void)
{

    printf("                                   <MENU>                          \n");
    printf("  Combo A > 1x Chicken SuperDeluxe Burger & 1x French Fries & 1x Drink\n  Price : RM10.00\n\n");
    printf("  Combo B > 1x Chicken SuperDeluxe Burger & 1x Onion Ring & 1x Drink \n  Price : RM15.00\n\n");
    printf("  Combo C > 1x Ultra Instinct Burger & 1x French Fries & 1x Drink\n  Price : RM18.00\n\n");
    printf("  Combo D > 1x Ultra Instinct Burger & 1x Onion Ring & 1x Drink\n  Price : RM24.00\n\n");

}

int order(void)
{
    //Local variable
    char selection;

    //Customer selection
    printf("  Combo A,B,C,D (Q = exit) > ");
    scanf(" %c", &selection);

    return selection;
}

int dailysalesreport(void)
{
    //local variable
    int totalQuan;
    double totalSales;

    //starting value
    totalCust = 0;

    //process
    totalCust += customer;
    totalQuan = quanA + quanB + quanC + quanD;
    totalSales = SoldA + SoldB + SoldC + SoldD;
    totalRM = totalSales + totalTax;

    //output
    printf("\nDAILY SALES REPORT\n\n");
    printf("Total Number of Customers = %d\n\n", totalCust);
    printf("Combo Sales For Today\n\n");
    printf("Combo        Quantity Sold        Sales Amount\n");
    printf("-------------------------------------------------\n");
    printf(" %-6c%14d%20.2f\n", 'A', quanA, SoldA);
    printf(" %-6c%14d%20.2f\n", 'B', quanB, SoldB);
    printf(" %-6c%14d%20.2f\n", 'C', quanC, SoldC);
    printf(" %-6c%14d%20.2f\n", 'D', quanD, SoldD);
    printf("=================================================\n");
    printf("%-6s%15d%20.2f\n", "TOTALS", totalQuan, totalSales);
    printf("\n");
    printf("               TOTAL SST charges  =  %.2f\n", totalTax);
    printf("               TOTAL RM collected = %.2f\n", totalRM);

    printf("\n");
    printf("THE END! HOPE TOMMOROW IS A BETTER DAY!\n");
    system("pause");
    return 0;
}
