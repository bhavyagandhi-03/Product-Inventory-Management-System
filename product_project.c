#include<stdio.h>
#include<string.h>
#include"crud_op.h"
int main()
{
int ch;
do
{
    printf("\t<><><><><><><><><><><><><><><><><><><>\n");
    printf("\t<>\t1.Add new product\n");
    printf("\t<>\t2.Display product\n");
    printf("\t<>\t3.Search\n");
    printf("\t<>\t4.Sort\n");
    printf("\t<>\t5.Update\n");
    printf("\t<>\t6.Delete\n");
    printf("\t<>\t7.Transfer godown to shop\n");
    printf("\t<>\t8.Purchase stock\n");
    printf("\t<>\t9.Admin login\n");
    printf("\t<>\t10.Low Stock\n");
    printf("\t<>\t11.Add to cart\n");
    printf("\t<>\t12.Exit\n");
    printf("\t<><><><><><><><><><><><><><><><><><><>\n");
    printf("enter choice\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        insert();
        break;
        case 2:
        display();
        break;
        case 3:
        search();
        break;
        case 4:
        sort();
        break;
        case 5:
        update();
        break;
        case 6:
        deleterec();
        break;
        case 7:
        transfer();
        break;
        case 8:
        purchase();
        break;
        case 9:
        profit();
        break;
        case 10:
        lowstock();
        break;
        case 11:
        bill();
        break;
        default :
        printf("Invalid choice\n");
    }
} while(ch!=12);
}