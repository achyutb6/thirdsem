#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void place_order(char cust_id[100]);
FILE *fc;
FILE *fq;

int main()
{
    char cust_id[100];
    int choice;
    while(1)
    {
        printf("What do you want to do?\n\t1.Place order\n\t2.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
         case 1:printf("Enter the customer id\n");
                scanf("%s",cust_id);
                fprintf(fq,"Name\tQuantity\n");
                place_order(cust_id);
                break;
         case 2:exit(1);
         default:printf("Invalid choice!");
        }
    return 0;
    }
}

void place_order(char cust_id[100])
{
    int choice,qty;
    strcat(cust_id,".txt");
    fc=fopen(cust_id,"a");
    fq=fopen("queue.txt","a");
    fprintf(fc,"Name\tQuantity\n");
    while(1)
    {
        printf("\n==================MENU==================\n");
        printf("\t1.a\tRs.x\n\t2.b\tRs.y\n\t3.c\tRs.z\n\t4.d\tRs.w\n\t5.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter the quantity\n");
                   scanf("%d",&qty);
                   fprintf(fq,"a\t%d\n",qty);
                   fprintf(fc,"a\t%d\n",qty);
                   break;
            case 2:printf("Enter the quantity\n");
                   scanf("%d",&qty);
                   fprintf(fc,"a\t%d\n",qty);
                   fprintf(fc,"b\t%d\n",qty);
                   break;
            case 3:printf("Enter the quantity\n");
                   scanf("%d",&qty);
                   fprintf(fc,"a\t%d\n",qty);
                   fprintf(fc,"c\t%d\n",qty);
                   break;
            case 4:printf("Enter the quantity\n");
                   scanf("%d",&qty);
                   fprintf(fc,"a\t%d\n",qty);
                   fprintf(fc,"d\t%d\n",qty);
                   break;
            case 5:main();
            default:printf("Invalid choice!");
        }

    }
}
