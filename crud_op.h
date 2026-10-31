#ifndef CRUD_OP_H_
#define CRUD_OP_H_
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct product
{
	int pid,qshop,qgodown,price;
	char name[20];
};
void insert();
void display();
void search();
void searchbyid();
void searchbyname();
void searchbyrange();
void profit();
int admin();
int isvalid(int);
int countrec();
void sort();
void sortbyid();
void sortbyname();
void sortbyprice();
void lowstock();
void update();
void updatename();
void updateprice();
void updateqshop();
void deleterec();
void transfer();
void bill();
void purchase();
void purchaseshop();
void purchasegodown();
void insert()
{
	FILE *fp;
	fp=fopen("product","a");
	if(fp==NULL)
	{
		printf("file do not open");
		exit(-1);
	}
	struct product p;
	printf("enter product id");
	scanf("%d",&p.pid);
	if(isvalid(p.pid)==0)
	{
		printf("Product ID is already exist\n");
		exit(-1);
	}
	printf("enter product name");
	scanf(" %[^\n]s",p.name);
	printf("enter product quantity at shop");
	scanf("%d",&p.qshop);
	printf("enter product quantity at godown");
	scanf("%d",&p.qgodown);
	printf("enter product price");
	scanf("%d",&p.price);
	fwrite(&p,sizeof(p),1,fp);
	fclose(fp);
}
void display()
{
	FILE *fp;
	struct product p;
	fp=fopen("product","r");
	if(fp==NULL)
	{
		printf("file do not open");
		exit(-1);
	}
	printf("%-10s %-20s %-10s %-12s %-10s\n","ID","NAME","SHOP_QTY","GODOWN_QTY","PRICE");
	while(fread(&p,sizeof(p),1,fp))
	{
		printf("%-10d %-20s %-10d %-12d %-10d\n",p.pid,p.name,p.qshop,p.qgodown,p.price);
	}
	printf("--%d record found--\n",countrec());
	fclose(fp);
}
void search()
{
    int ch;
	printf("1.Search by product id\n");
	printf("2.Search by name\n");
	printf("3.Search by price range\n");
	printf("enter choice\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			searchbyid();
			break;
		case 2:
			searchbyname();
			break;
		case 3:
			searchbyrange();
			break;
		default:
			printf("invalid choice\n");
	}
}
void searchbyid()
{
	FILE *fp;
	struct product p;
	int sid,count=0;
	fp=fopen("product","r");
	if(fp==NULL)
	{
		printf("file do not open");
		exit(-1);
	}
	printf("enter id for search");
	scanf("%d",&sid);
	printf("%-10s %-20s %-10s %-12s %-10s\n","ID","NAME","SHOP_QTY","GODOWN_QTY","PRICE");
	while(fread(&p,sizeof(p),1,fp))
	{
		if(sid==p.pid)
		{
			printf("%-10d %-20s %-10d %-12d %-10d\n",p.pid,p.name,p.qshop,p.qgodown,p.price);
			count++;
		}
	}
	if(count==0)
	{
		printf("This Product ID doesn't exist\n");
	}
	printf("---%d record found---\n",count);
	fclose(fp);
}
void searchbyname()
{
	FILE *fp;
	struct product p;
	char sname[20];
	int count=0;
	fp=fopen("product","r");
	if(fp==NULL)
	{
		printf("file do not open");
		exit(-1);
	}
	printf("enter product name for search");
	scanf(" %[^\n]s",sname);
	printf("%-10s %-20s %-10s %-12s %-10s\n","ID","NAME","SHOP_QTY","GODOWN_QTY","PRICE");
	while(fread(&p,sizeof(p),1,fp))
	{
		if(strcmp(sname,p.name)==0)
		{
			printf("%-10d %-20s %-10d %-12d %-10d\n",p.pid,p.name,p.qshop,p.qgodown,p.price);
			count++;
		}
	}
	if(count==0)
	{
		printf("This Product Name doesn't exist\n");
	}
	printf("---%d record found---\n",count);
	fclose(fp);
}
void searchbyrange()
{
	FILE *fp;
	struct product p;
	int lower,upper;
	int count=0;
	fp=fopen("product","r");
	if(fp==NULL)
	{
		printf("file do not open");
		exit(-1);
	}
	printf("enter lower price and upper price for search");
	scanf("%d %d",&lower,&upper);
	printf("%-10s %-20s %-10s %-12s %-10s\n","ID","NAME","SHOP_QTY","GODOWN_QTY","PRICE");
	while(fread(&p,sizeof(p),1,fp))
	{
		if(p.price>=lower && p.price<=upper)
		{
			printf("%-10d %-20s %-10d %-12d %-10d\n",p.pid,p.name,p.qshop,p.qgodown,p.price);
			count++;
		}
	}
	if(count==0)
	{
		printf("This Price Range doesn't exist\n");
	}
	printf("---%d record found---\n",count);
	fclose(fp);
}
int admin()
{
	char b[10];
	char a[10]="admin123";
	printf("enter Password");
	scanf("%s",b);
	if(strcmp(a,b)==0)
	{
		printf("##Login Successful##\n");
		return 0;
	}
	else
	{
		printf("--Enter correct Password--\n");
		return 1;
	}
}
void profit()
{
	FILE *fp;
	int ch;
	fp=fopen("product","r");
	if(fp==NULL)
	{
		printf("file do not open");
		exit(-1);
	}
	printf("Your FEB 2026 revenue is 40 lac Rs\n");
	if(admin()==0)
	{
		do{
			printf("1.Whole year Revenue\n");
			printf("2.Last 3 year Revenue\n");
			printf("3.Total Expenses\n");
			printf("4. Total Investment\n");
			printf("5.Exit\n");
			printf("enter choice");
			scanf("%d",&ch);
			switch(ch)
			{
				case 1:
					printf("--Total Revenue of current year is 1.02cr Rs--\n");
					break;
				case 2:
					printf("--Revenue of year 2022-2023 is 96lac Rs--\n");
					printf("--Revenue of year 2023-2024 is 1.20cr Rs--\n");
					printf("--Revenue of year 2024-2025 is 90lac Rs--\n");
					break;
				case 3:
					printf("--Total Expense of current year is 55lac Rs--\n");
					break;
				case 4:
				{
					char y[20]="abc123";
					char l[20];
					printf("enter security code");
					scanf("%s",l);
					if(strcmp(y,l)==0)
					{
						printf("Login successful");
						printf("--Investment in Finance Sector is 50lac Rs--\n");
						printf("--Investment in Pharma Sector is 15lac Rs--\n");
						printf("--Investment in Defense Sector is 30lac Rs--\n");
						printf("--Investment in other Sector is 25lac Rs--\n");
						printf("Total Investment= 1.20cr Rs\n");
						break;
					}
					else
					{
						printf("--wrong security code--\n");
						break;
					}
				}
				case 5:
					printf("exit\n");
					break;
				default:
					printf("invalid choice\n");
			}
		}while(ch!=5);
	}
	fclose(fp);
}
int isvalid(int id)
{
	FILE *fp;
	struct product p;
	fp=fopen("product","r");
	if(fp==NULL)
	{
		printf("file do not open");
		exit(-1);
	}
	while(fread(&p,sizeof(p),1,fp))
	{
		if(p.pid==id)
		{
			fclose(fp);
			return 0;
		}
	}
	fclose(fp);
	return 1;
}
void sort()
{
    int ch;
	printf("1.Sort by product id\n");
	printf("2.Sort by name\n");
	printf("3.Sort by price\n");
	printf("enter choice\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			sortbyid();
			break;
		case 2:
			sortbyname();
			break;
		case 3:
			sortbyprice();
			break;
		default:
			printf("Invalid choice\n");
	}
}
void sortbyid()
{
	FILE *fp;
	struct product p,temp;
	fp=fopen("product","r");
	int n=countrec();
	if(fp==NULL)
	{
		printf("file do not open");
		exit(-1);
	}
	struct product p1[n];
	int i=0;
	while(fread(&p,sizeof(p),1,fp))
	{
		p1[i]=p;
		i++;
	}
	for(i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(p1[i].pid>p1[j].pid)
			{
				temp=p1[i];
				p1[i]=p1[j];
				p1[j]=temp;
			}
		}
	}
	printf("%-10s %-20s %-10s %-12s %-10s\n","ID","NAME","SHOP_QTY","GODOWN_QTY","PRICE");
	for(int i=0;i<n;i++)
	{
		printf("%-10d %-20s %-10d %-12d %-10d\n",p1[i].pid,p1[i].name,p1[i].qshop,p1[i].qgodown,p1[i].price);
	}
	fclose(fp);
}
int countrec()
{
	FILE *fp;
	struct product p;
	fp=fopen("product","r");
	int count=0;
	while(fread(&p,sizeof(p),1,fp))
	{
		count++;
	}
    fclose(fp);
    return count;
}
void sortbyprice()
{
	FILE *fp;
	int n=countrec();
	fp=fopen("product","r");
	if(fp==NULL)
	{
		printf("file do not open");
		exit(-1);
	}
	struct product p[n],tem;
	for(int i=0;i<n;i++)
	{
		fread(&p[i],sizeof(tem),1,fp);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(p[i].price<p[j].price)
			{
				tem=p[i];
				p[i]=p[j];
				p[j]=tem;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		printf("%-10d %-20s %-10d %-12d %-10d\n",p[i].pid,p[i].name,p[i].qshop,p[i].qgodown,p[i].price);
	}
	fclose(fp);
}
void sortbyname()
{
	FILE *fp;
	fp=fopen("product","r");
	if(fp==NULL)
	{
		printf("file do not open");
		exit(-1);
	}
	int n=countrec();
	struct product p[n],t;
	for(int i=0;i<n;i++)
	{
		fread(&p,sizeof(p),1,fp);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(strcmp(p[i].name,p[j].name)<0)
			{
				t=p[i];
				p[i]=p[j];
				p[j]=t;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		printf("\t\t%-10d %-20s %-10d %-12d %-10d\n",p[i].pid,p[i].name,p[i].qshop,p[i].qgodown,p[i].price);
	}
	fclose(fp);
}
void lowstock()
{
	FILE *fp;
	struct product p;
	int count=0;
	fp=fopen("product","r");
	if(fp==NULL)
	{
		printf("file do not open");
		exit(-1);
	}
	printf("%-10s %-20s %-10s %-12s %-10s\n","ID","NAME","SHOP_QTY","GODOWN_QTY","PRICE");
	while(fread(&p,sizeof(p),1,fp))
	{
		if(p.qshop<5)
		{
			printf("%-10d %-20s %-10d %-12d %-10d\n",p.pid,p.name,p.qshop,p.qgodown,p.price);
			count++;
		}
	}
	if(count==0)
	{
		printf("---0 LOW STOCK---\n");
	}
	else
	{
		printf("---%d LOW STOCK---\n",count);
	}
	fclose(fp);
}
void update()
{;
	int ch;
	printf("1.Update product name\n");
	printf("2.Update product price\n");
	printf("3.Update product by quantity at shop\n");
	printf("enter choice\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			updatename();
			break;
		case 2:
			updateprice();
			break;
		case 3:
			updateqshop();
			break;
		default:
			printf("invalid choice\n");
	}
}
void updatename()
{
	FILE *fp,*tem;
	struct product p;
	fp=fopen("product","r");
	tem=fopen("tem","w");
	char temp[20],new[20];
	if(fp==NULL || tem==NULL)
	{
		printf("file do not open");
		exit(-1);
	}
	printf("enter name for update");
	scanf(" %[^\n]s",temp);
	printf("enter new update name");
	scanf(" %[^\n]s",new);
	while(fread(&p,sizeof(p),1,fp))
	{
		if(strcmp(temp,p.name)==0)
		{
			strcpy(p.name,new);
			printf("Updated successfully\n");
		}
		fwrite(&p,sizeof(p),1,tem);
	}
	fclose(fp);
	fclose(tem);
	fp=fopen("product","w");
	tem=fopen("tem","r");
	if(fp==NULL || tem==NULL)
	{
		printf("file do not open");
		exit(-1);
	}
	while(fread(&p,sizeof(p),1,tem))
	{
		fwrite(&p,sizeof(p),1,fp);
	}
	fclose(fp);
	fclose(tem);
}
void updateprice()
{
	FILE *fp,*tem;
	struct product p;
	fp=fopen("product","r");
	tem=fopen("tem","w");
	char temp[20];
	int new;
	if(fp==NULL || tem==NULL)
	{
		printf("file do not open");
		exit(-1);
	}
	printf("enter name for update");
	scanf(" %[^\n]s",temp);
	printf("enter new price");
	scanf("%d",&new);
	while(fread(&p,sizeof(p),1,fp))
	{
		if(strcmp(temp,p.name)==0)
		{
			p.price=new;
			printf("Updated successfully\n");
		}
		fwrite(&p,sizeof(p),1,tem);
	}
	fclose(fp);
	fclose(tem);
	fp=fopen("product","w");
	tem=fopen("tem","r");
	if(fp==NULL || tem==NULL)
	{
		printf("file do not open");
		exit(-1);
	}
	while(fread(&p,sizeof(p),1,tem))
	{
		fwrite(&p,sizeof(p),1,fp);
	}
	fclose(fp);
	fclose(tem);
}
void updateqshop()
{
	FILE *fp,*tem;
	struct product p;
	fp=fopen("product","r");
	tem=fopen("tem","w");
	char temp[20];
	int new;
	if(fp==NULL || tem==NULL)
	{
		printf("file do not open");
		exit(-1);
	}
	printf("enter name for update");
	scanf(" %[^\n]s",temp);
	printf("enter new quantity at shop");
	scanf("%d",&new);
	while(fread(&p,sizeof(p),1,fp))
	{
		if(strcmp(temp,p.name)==0)
		{
			p.qshop=new;
			printf("Updated successfully\n");
		}
		fwrite(&p,sizeof(p),1,tem);
	}
	fclose(fp);
	fclose(tem);
	fp=fopen("product","w");
	tem=fopen("tem","r");
	if(fp==NULL || tem==NULL)
	{
		printf("file do not open");
		exit(-1);
	}
	while(fread(&p,sizeof(p),1,tem))
	{
		fwrite(&p,sizeof(p),1,fp);
	}
	fclose(fp);
	fclose(tem);
}
void deleterec()
{
	FILE *fp,*temp;
	struct product p;
	fp=fopen("product","r");
	temp=fopen("temp","w");
	if(fp==NULL || temp==NULL)
	{
		printf("file do not open");
		exit(-1);
	}
	int n,count=0;
	printf("enter id for delete");
	scanf("%d",&n);
	while(fread(&p,sizeof(p),1,fp))
	{
		if(n!=p.pid)
		{
			fwrite(&p,sizeof(p),1,temp);
		}
		else
		{
			count++;
		}
	}
	fclose(fp);
	fclose(temp);
	fp=fopen("product","w");
	temp=fopen("temp","r");
	if(fp==NULL || temp==NULL)
	{
		printf("file do not open");
	}
	while(fread(&p,sizeof(p),1,temp))
	{
		fwrite(&p,sizeof(p),1,fp);
	}
	if(count==0)
	{
		printf("---no record found---\n");
		return;
	}
	else
	{
		printf("---%d record deleted---\n",count);
	}
	fclose(fp);
	fclose(temp);
	return;
}
void transfer()
{
	FILE *fp,*temp;
	struct product p;
	int found=0;
	char d[20];
	printf("enter name for transfer: ");
	scanf(" %[^\n]s",d);
	fp=fopen("product","r");
	temp=fopen("temp","w");
	if(fp==NULL || temp==NULL)
	{
		printf("file error\n");
		return;
	}
	while(fread(&p,sizeof(p),1,fp))
	{
		if(strcmp(d,p.name)==0)
		{
			found=1;
			int m;
			printf("how many quantity you want to transfer:\n");
			scanf("%d",&m);
			if(m>p.qgodown)
			{
				printf("not enough quantity\n");
			}
			else
			{
				p.qgodown-=m;
				p.qshop+=m;
			}
		}
		fwrite(&p,sizeof(p),1,temp);
	}
	fclose(fp);
	fclose(temp);
	temp=fopen("temp","r");
	fp=fopen("product","w");
	while(fread(&p,sizeof(p),1,temp))
	{
		fwrite(&p,sizeof(p),1,fp);
	}
	fclose(fp);
	fclose(temp);
	if(found==1)
	{
		printf("record updated\n");
	}
	else
	{
		printf("record not found\n");
	}
	return;
}
void bill()
{
	FILE *fp;
	fp=fopen("product","r");
	struct product p;
	if(fp==NULL)
	{
		printf("file do not open");
		exit(-1);
	}
	int l,q,price,found=0;
	printf("Enter pid to add to cart");
	scanf("%d",&l);
	while(fread(&p,sizeof(p),1,fp))
	{
		if(l==p.pid)
		{
			found=1;
			printf("\t\t%-10d %-20s %-10d %-12d %-10d\n",p.pid,p.name,p.qshop,p.qgodown,p.price);
			printf("how many quantity do you want");
			scanf("%d",&q);
			if(q<=p.qshop)
			{
				printf("added to cart sucesfully\n");
				price=q*p.price;
				p.qshop-=q;
				printf("your bill is %d\n",price);
				printf("Remaining stock: %d\n",p.qshop);
			}
			else
			{
				printf("only %d quantity available\n",p.qshop);
			}
			break;
		}
	}
	if(found==0)
	{
		printf("pid does not exist");
		exit(-1);
	}
	fclose(fp);
	return;
}
void purchase()
{
	int n;
	printf("1.Purchase stock store in shop\n");
	printf("2.Purchase stock store in godown\n");
	printf("enter choice\n");
	scanf("%d",&n);
	switch(n)
	{
		case 1:
			purchaseshop();
			break;
		case 2:
			purchasegodown();
			break;
		default:
			printf("Invalid choice");
	}
}
void purchaseshop()
{
	FILE *fp,*temp;
	struct product p;
	fp=fopen("product","r");
	temp=fopen("temp","w");
	if(fp==NULL || temp==NULL)
	{
		printf("file do not open");
		exit(-1);
	}
	int k,m,found=0;
	printf("enter product id which you buy\n");
	scanf("%d",&k);
	while(fread(&p,sizeof(p),1,fp))
	{
		if(k==p.pid)
		{
			found=1;
			printf("how many quantity you want to buy\n");
			scanf("%d",&m);
			p.qshop+=m;
			printf("purchase successful\n");
		}
		fwrite(&p,sizeof(p),1,temp);
	}
	fclose(fp);
	fclose(temp);
	fp=fopen("product","w");
	temp=fopen("temp","r");
	if(fp==NULL || temp==NULL)
	{
		printf("file do not open");
		exit(-1);
	}
	while(fread(&p,sizeof(p),1,temp))
{
	fwrite(&p,sizeof(p),1,fp);
}
fclose(fp);
fclose(temp);
if(found==1)
{
	printf("record updated\n");
}
else
{
	printf("record not found\n");
}
}
void purchasegodown()
{
	FILE *fp,*temp;
	struct product p;
	fp=fopen("product","r");
	temp=fopen("temp","w");
	if(fp==NULL || temp==NULL)
	{
		printf("file do not open");
		exit(-1);
	}
	int k,m,found=0;
	printf("enter product id which you buy\n");
	scanf("%d",&k);
	while(fread(&p,sizeof(p),1,fp))
	{
		if(k==p.pid)
		{
			found=1;
			printf("how many quantity you want to buy\n");
			scanf("%d",&m);
			p.qgodown+=m;
			printf("purchase successful\n");
		}
		fwrite(&p,sizeof(p),1,temp);
	}
	fclose(fp);
	fclose(temp);
	fp=fopen("product","w");
	temp=fopen("temp","r");
	if(fp==NULL || temp==NULL)
	{
		printf("file do not open");
		exit(-1);
	}
	while(fread(&p,sizeof(p),1,temp))
	{
		fwrite(&p,sizeof(p),1,fp);
	}
	fclose(fp);
	fclose(temp);
	if(found==1)
	{
		printf("record updated\n");
	}
	else
	{
		printf("record not found\n");
	}
}
#endif /* CRUD_OP_H_ */