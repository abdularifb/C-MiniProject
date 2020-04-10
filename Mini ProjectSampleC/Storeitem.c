#include<stdio.h>

typedef struct storeitem
{
	int itemcode;
	char itemname[31];
	
}STOREITEM;

char filename[]="./storeitem.dat";

void Menu();
void Writerecord();
void Listrecord();

int main()
{
	Menu();
}

void Menu()
{
	int opt;
	while(1)
	{
		system("cls");
		printf("\n1.Add item");
		printf("\n2.List item");
		printf("\n3.Exit");
		printf("\nEnter your choice:");
		scanf("%d",&opt);
		fflush(stdin);
		
		switch(opt)
		{
			case 1:
				Writerecord();
				break;
			case 2:
				Listrecord();
				break;
			case 3:
				return;
				break;
			default:
				printf("\nEnter the valid choice");
				break;
		}
		
		printf("\nPress a key to continue");
		getch();
	}
}

void Writerecord()
{
	FILE *f;
	STOREITEM item;
	
	printf("\nEnter the Itemcode:");
	scanf("%d",&item.itemcode);
	fflush(stdin);
	
	printf("\nEnter the Itemname:");
	gets(item.itemname);
	
	f=fopen(filename,"ab");
	
	fwrite(&item,sizeof(STOREITEM),1,f);
	
	fclose(f);	  
}

void Listrecord()
{
	
	FILE *f;
	STOREITEM item;
	
	f=fopen(filename,"rb");
	
	while(fread(&item,sizeof(STOREITEM),1,f))
	{
		printf("\n%d %s",item.itemcode,item.itemname);
	}
	
	fclose(f);	  
	
}

