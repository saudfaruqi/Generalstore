

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


 struct item
{
	char productname[40],c;
	int productid;
	float price;
	int Qnt;
}st;

struct item*p;

int shop();
int menu();
float bill();
void cart();
void admin();
int dcart();
void add_item();
void deleteproduct();
void search_item();
void read_item();
void edit_item();




void main()
{
	int num,id;
    char name[20],phone[11];

	
	printf("\n\n\t\t\t ***********************\n");
	printf("\t\t\t * WELCOME TO THE MART *\n");
	printf("\t\t\t ***********************\n\n\n");

	printf("USER INFORMATION\n\n");
	
	printf("Name: \n");
	gets(name);
	
	
	printf("Number: \n");
    gets(phone);	
	
	printf("ID only in numbers: \n");
	scanf("%d",&id);
	
   while(1)
   {
	
	switch(shop())
	{
	case 1: menu();
	        break;
	case 2: bill();
	        break;
	case 3: cart();
	        break;
	case 4: admin();
	        break;
	case 5: printf("\n Thanks for using it. Bye !\n");
	}
   }
}

int shop()
{
 char str[5];
 int choose;
 printf("\n1. MAIN MENU \n");
 printf("2. BILLING \n");
 printf("3. SHOPPING CART \n");
 printf("4. ADMIN PANEL \n");
 printf("5. EXIT \n");
 printf(" Please select the corresponding number 1--5");
 
 while(1)
 {
    fflush(stdin);
    gets(str);
    choose=atoi(str);
	
  if(choose<1 || choose>5)
    printf(" INPUT ERROR PLEASE TRY AGAIN :");
  else
    break;
 }
 return choose;
 
}


int menu()
{
  int choice;

printf("\n\n<<<<<<<<<<<<<<<<<Welcome To Product Detail Management System>>>>>>>>>>>>>>>>\n\n");
	
printf("\n\t\tPress <1> Search Products");
printf("\n\t\tPress <2> Read Items");
printf("\n\t\tPress <3> Exit!\n");	
	
printf("\n\t\tEnter your choice[1-3]");
scanf("%i", &choice);
	
	
	switch(choice)	
	{
	case 1:
	    search_item() ;
		break;
	case 2:
	    read_item() ;
		break;	
	case 3:
		printf("System Exit") ;
	    break;
   default:
	    printf("Invalid Choice! System Exit\n");
		getch();
	}
	
}

void search_item()
{
  char target[40];
  int found=0;
  FILE *f;
	f=fopen("Nextf.txt","r");
	printf("\nEnter name to search:");
	fflush(stdin);
	gets(target);
	target[0]=toupper(target[0]);
	
  while (!feof(f) && found==0)
	{
		fscanf(f,"%s %f %d %d", st.productname, &st.price, &st.productid,&st.Qnt);
	  if(strcmp(target, st.productname)==0)
	   {
		found=1;		
	   }
	}
	
    if(found)
    {
printf("\n Record found");
printf("\nProduct Name\t\t:%s \nProduct Price\t\t:%f \nProduct ID\t\t:%d \nProduct Quantity\t:%d",
st.productname, st.price, st.productid, st.Qnt);
	
	}
	else 
		printf("Noo Record found");
		fclose(f);
		printf("\nPress any key to go to Main Menu!");
		while((st.c = getch()) =='\r');
		menu();
}

void read_item()
{
 	FILE *f;
	int q;
	if((f=fopen("Nextf.txt","r"))==NULL)
	{
		printf("NO RECORDS");
		printf("\n\t\tPress any key to go back to Menu.");
		getch();
		menu();
	}
	else
	{
		printf("----------------------------------------------------------------");
		
		printf("\nProduct Name\t");
		printf("Product Price\t");
		printf("Product ID\t");
		printf("Product Quantity\t\t");
		
		
		printf("----------------------------------------------------------------\n");
		
    while(fscanf(f,"%s %f %d %d\n", st.productname, &st.price, &st.productid,&st.Qnt)!=EOF)
	{
		printf("%s\t\t",st.productname);
		printf("%f\t",st.price);
		printf("%d\t",st.productid);
		printf("%d\n",st.Qnt);
	
		q++;
    }
	}
	fclose(f);
	
	printf("\nPress any key to go to Main Menu!");
		getch();
		menu();
}


float bill()
{
	int x,q;
    float total=1,gtotal=0;
    FILE *f;
    f=fopen("Nextf.txt","r+b");
    rewind(f);
    system("cls");
    printf("enter  \"end\" to finish input\n\n");
	
		printf("\nenter item ID:");
        scanf("%d",&x);
	
        printf("\nenter quantity:");
        scanf("%d",&q);
		

        printf("\nPRODUCT NAME = %s\n",st.productname);
        printf("QUANTITY = %d\n",st.Qnt);
        printf("PRICE = %f\n",st.price);
		total=st.price*q;
        printf("%f\n",total);
		gtotal=gtotal+total;
		printf("\nTOTAL AMOUNT = Rs. %f\n",gtotal);
        
		
    fclose(f);
    getch();
    shop();
    
}  

void cart()
{
	char str [4];
    int select;  
	    printf("\nPlease select operation\n");  
	    printf("-----------------------\n") ;  
	    printf("1.Display the current shopping list\n");  
	    printf("2.Exit\n");  
	    printf("-----------------------\n\n");  
	if(select=1)  
	{
    dcart();
    }
    else
		printf("error");
}

int dcart()
{
	FILE *f;
	int p;
	
	f=fopen("Nextf.txt","r");
   if(f==NULL)
   {
    printf(" Empty shopping cart \n");
    return ;
   }
 
while(fscanf(f,"%s %f %d %d\n", st.productname, &st.price, &st.productid,&st.Qnt)!=EOF)
   {
printf(" product name  \t    product price  \t product ID  \t  product quantity \t\t\n");
printf("%s \t\t %f \t\t %d \t\t %d\n",st.productname,st.price,st.productid,st.Qnt);
p+=p;
   }
   return;
   fclose(f);
   cart();
 
}


void admin()
{
	int choice;
	
	printf("\n\t\tPress <1> Add Products");
	printf("\n\t\tPress <2> Delete Products");
    printf("\n\t\tPress <3> Edit Items");
	printf("\n\t\tPress <4> Exit!");
	printf("\n\t\tEnter your choice[1-4]");
	scanf("%i", &choice);
	
	switch(choice)	
	{
	case 1:
	    add_item() ;
		break;
	case 2:
	    deleteproduct() ;
		break;
    case 3:
	    edit_item();
		break;			
	case 4:
		printf("System Exit") ;
	    break;
			
	default:
	    printf("Invalid Choice! System Exit\n");
		getch();
		menu();
	}
}

void add_item()
{
	int index, valid;
	char c;
	int a=0;

	FILE *f;
	

	do
	{
	system("cls");
	printf("============ Enter Product Detail ============");
	int ID;
	f = fopen("Nextf.txt","a+");
	
	if((f = fopen("Nextf.txt","a+"))!=NULL)
	{
	I:
	printf("\nProduct ID\t :");
	scanf("%i",&ID);
	
while(fscanf(f,"%s %f %d %d", st.productname, &st.price, &st.productid,&st.Qnt)!=EOF)
	{
		if(ID == st.productid)
		{
		 printf("\n\tTHE PRODUCT ID ALREADY EXIST.\n");
		 goto I;
		}
	}
		 st.productid = ID;
	}
		else
		{
		 printf("\nProduct ID\t :");
		 scanf("%d",&st.productid);
		}
		
	do
	{	
		fflush(stdin);
		printf("Product Name\t :");
		gets(st.productname);
		st.productname[0]=toupper(st.productname[0]);
			
		for (index=0; index<strlen(st.productname); index++)
		{	
		if(isalpha(st.productname[index]))
		valid = 1;
		
		else
		{
		valid = 0;
		break;
		}
		}
			
		if (!valid)
		{
		printf("\n Name contain invalid character. Please 'Enter' again");
		getch();
		}
	}while(!valid);
		
		
	do
	{
		printf("\nPrice [10-5000] Rupees:");
		scanf("%f",&st.price);
			
		if(st.price<10 || st.price>5000)
		{
		printf("\n\tYou Cannot Enter the price limit [10-5000].Re-Enter.");
		}
	}while(st.price<10 || st.price>5000);
			
	do
	{
		printf("\nQuantity [1-500]\t:");
		scanf("%d",&st.Qnt);
				
		if(st.Qnt<1 || st.Qnt>500)
		{
		printf("\n\tEnter Quantity[1-500] only.Re-Enter.");
		}
	}while(st.Qnt<1 || st.Qnt>500);
	
        printf("\nProduct Price\t :");
        scanf("%f", &st.price);
        printf("\nProduct ID\t :");
	    scanf("%d", &st.productid);
        printf("\nProduct Quantity :");
        scanf("%d",&st.Qnt);
		
f=fopen("Nextf.txt","a");
fprintf(f,"\n%s %f %d %d", st.productname,st.price, st.productid,st.Qnt);
fclose(f);
		
printf("\nPress 'Enter' to add more item and any other key to go to main menu");
		
	}
	while((c = getch()) =='\r');
	admin();
}


void deleteproduct()
{
	char target[40]; 
	int found=0;
	FILE *f, *tf;
	   f=fopen("Nextf.txt","r");
	   tf=fopen("TempFile.txt","w+");
	printf("\n Enter name to Delete: ");
	   fflush(stdin);
	scanf("%s",target);
	   target[0]=toupper(target[0]);
while (fscanf(f,"%s %f %d %d\n",st.productname,&st.price,&st.productid,&st.Qnt)!=EOF)
{
	if(strcmp(target,st.productname)==0)
	{
		found=1;
	}
	else
	{
	fprintf(tf,"%s %f %d %d\n", st.productname,st.price,st.productid,st.Qnt);
	}
}
	if(!found)
	{
	printf("\n Record not Found");
	getch();
	menu();
	}
	else
	{
	printf("\n Record deleted");	
	}
	fclose(f);
	fclose(tf);
	remove("Nextf.txt");
	rename("TempFile.txt","Nextf.txt");
			
	printf("\nPress any key to go to Main Menu!");
			
	while((st.c = getch()) =='\r');
admin();
}

void edit_item()
{
    int index, valid,id;
	char target[40],edit;
	FILE *f, *rp;
	int a=0;
	
	if((f=fopen("Nextf.txt","r+"))==NULL)
	{
		printf("NO RECORD ADDED.");
		menu();
	}
	else
	{
		rp = fopen("TempFile.txt","a");
		system("cls");
		printf("Enter Product Code for edit:");
		scanf("%i",&id);
		fflush(stdin);
		
while(fscanf(f,"%s %f %d %d\n", st.productname,&st.price, &st.productid,&st.Qnt)!=EOF)
{
		
if(id==st.productid)
{
				
	a=1;
	printf("\n\t*****  Record Found  *****");
	printf("\nProduct Name\t\t: %s",st.productname);
	printf("\nProduct Code\t\t: %i",st.productid);
	printf("\nProduct Quantity\t:%i",st.Qnt);
			
	printf("\n\n\t*** New Record ***");
		
 do
 {
					
	fflush(stdin);
	printf("\nNew Product Name\t\t: ");
	gets(st.productname);
	st.productname[0]=toupper(st.productname[0]);
					
  for (index=0; index<strlen(st.productname); ++index)
  {
	if(isalpha(st.productname[index]))
		valid = 1;
	else
	{
	valid = 0;
	break;
	}
  }
	if (!valid)
	{
	printf("\n Name contain invalid character. Please 'Enter' again");
	getch();					
	}
			
 }while(!valid);
					
 do
 {
	printf("\nNew Price [10-5000]Rupees:");
	scanf("%f",&st.price);
	
	if(st.price<10 || st.price>5000)
	{
	printf("\n\tYou Cannot Enter the price limit [10-5000].Re-Enter.");
	}
 }while(st.price<10 || st.price>5000);
			
	printf("\nEnter New Product Code\t\t:");
	scanf("%d",&st.productid); 
				
 do
 {
	printf("\nNew Quantity [1-500]\t:");
	scanf("%d",&st.Qnt);
	
	if(st.Qnt<1 || st.Qnt>500)
	{
	printf("\n\tEnter New Quantity[1-500] only.Re-Enter.");
	}
	
 }while(st.Qnt<1 || st.Qnt>500);
				
				
	printf("Press 'y' to edit the existing record or any key to cancel...");
	edit=getche();
	
	if(edit=='y' || edit=='Y')
	{
	fprintf(rp,"%s %f %d %d\n", st.productname,st.price, st.productid,st.Qnt);
	fflush(stdin);
	printf("\n\n\t\tYOUR RECORD IS SUCCESSFULLY EDITED!!!");
	}
}
	else
	{
	fprintf(rp,"%s %f %d %d\n", st.productname,st.price, st.productid,st.Qnt);
	fflush(stdin);
	}
			
}
	if(!a)
    {
    printf("\n\nTHIS PRODUCT DOESN'T EXIST!!!!");
    }
	fclose(rp);
    fclose(f);
    remove("Nextf.txt");
	rename("TempFile.txt","Nextf.txt");
	getch();
	admin();
}
}