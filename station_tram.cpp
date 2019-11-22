#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

typedef struct{
	char nom[20] ; //NOM STATION
	int dure ; 
	int correspandance ;
}station;

void ajouter(void)
{
	FILE* f = fopen("youssef.txt","a+b");
	station s;
	
	printf("\n\tENTER LE NOM DE LA STATION  : ");
	fflush(stdin);
	gets(s.nom);
	printf("\n\tENTER LA DUREE QUI LA SEPARE DE LA STATION SUIVANTE  : ");
	fflush(stdin);
	scanf("%d",&s.dure);
	printf("\n\tVEILLEZ SAISIRE (1) SI LA STATION EST CORRESPONDANCE SINO (0)  : ");
	fflush(stdin);
	scanf("%d",&s.correspandance);
	fwrite(&s,sizeof(station),1,f);
	
	rewind(f);
	while(!feof(f))
	{
		fread(&s,sizeof(station),1,f);
		if(feof(f))
			break;
		puts(s.nom);
		printf("%d\n",s.dure);
		printf("%d\n",s.correspandance);
	}
	
	fclose(f);
}

void recherche(void)
{
	FILE* f = fopen("youssef.txt","r+b");
	station s;
	int aide=0 ;
	
	while(!feof(f))
	{
		fread(&s,sizeof(station),1,f);
		if(feof(f))
			break;
		if(aide < s.dure)
			aide = s.dure ;
	}
	rewind(f);
	while(!feof(f))
	{
		fread(&s,sizeof(station),1,f);
		if(feof(f))
			break;
		if(aide == s.dure)
		{
			printf("%s\n",s.nom);
		}	
	}
	
	fclose(f);
}

void correspondance(void)
{
	FILE* f = fopen("youssef.txt","r+b");
	station s;
	while(!feof(f))
	{
		fread(&s,sizeof(station),1,f);
		if(feof(f))
			break;
		if(s.correspandance == 1)
		{
			printf("%s\n",s.nom);
		}	
	}
	
	fclose(f);
}

void recherche_pos(void)
{
	char ch[20] ;
	int cpt=0 , bol=0 ;
	printf("\n\tENTER LE NOM DE LA STATION A RECHERCHER  : ");
	fflush(stdin);
	gets(ch);
	FILE* f = fopen("youssef.txt","r+b");
	station s;
		
	while(!feof(f))
	{
		fread(&s,sizeof(station),1,f);
		if(feof(f))
			break;
		cpt++;
		if(strcmp(ch,s.nom) == 0)
		{
			printf("\n\tLA POS DE LA STATION %s DANS L ENREGISTREMENT EST %d ",s.nom,cpt);
			fclose(f);
			bol=1;
			break;
		}
	}
	if(bol == 0)
		printf("\n\tAUCUNE STATION -1 ");
	fclose(f);
}

void taille(void)
{
	int n;
	FILE* f = fopen("youssef.txt","r+b");
	station s;
	fseek(f,0,2);
	n = ftell(f);
	printf("\n\tLA TAILLE DU FICHIER EST %d",n);
	fclose(f);
}

void permut(void)
{
	FILE* f = fopen("youssef.txt","r+b");
	station s[3];
	char ch1[20] , ch2[20] ;
	int stat=0;
	while(!feof(f))
	{
		fread(&s,sizeof(station),1,f);
		if(feof(f))
			break;
		puts(s[0].nom);
		printf("%d\n",s[0].dure);
		printf("%d\n",s[0].correspandance);
	}
	rewind(f);
	printf("\n--------------------------------------\n");
	printf("\n\tENTER LE NOM DE LA STATION 1  : ");
	fflush(stdin);
	gets(ch1);
	printf("\n\tENTER LE NOM DE LA STATION 2  : ");
	fflush(stdin);
	gets(ch2);
	
	while(!feof(f))
	{
		fread(&s[0],sizeof(station),1,f);
		if(feof(f))
			break;
		if(strcmp(ch1,s[0].nom) == 0 || strcmp(ch2,s[0].nom) == 0)
			stat++;
	}
	rewind(f);
	int cpt1=0 , cpt2=0 , cpt=0 ;
	if(stat == 2)
	{
		while(!feof(f))
		{
			fread(&s[0],sizeof(station),1,f);
			if(feof(f))
				break;
			cpt++;
			if(strcmp(ch1,s[0].nom) == 0)
			{
				cpt1 = cpt;
				printf("%d",cpt1);
				getch();
				s[1] = s[0] ;
			}
			if(strcmp(ch2,s[0].nom) == 0)
			{
				cpt2 = cpt;
					printf("%d",cpt2);
				getch();
				s[2] = s[0] ;
			}
		}
		rewind(f);
		fseek(f,0,cpt1);
		s[0] = s[1] ;
		s[1] = s[2] ;
		rewind(f);
		fseek(f,0,cpt2);
		s[2] = s[0] ;
	}
	rewind(f);
	printf("\n--------------------------------------\n");
	while(!feof(f))
	{
		fread(&s,sizeof(station),1,f);
		if(feof(f))
			break;
		puts(s[0].nom);
		printf("%d\n",s[0].dure);
		printf("%d\n",s[0].correspandance);
	}
	fclose(f);
}

main()
{
//	ajouter();
//	recherche();
//	correspondance();
//	recherche_pos();
//	taille();
	permut();
}
