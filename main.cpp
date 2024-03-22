#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h> 
#include"stdi0.h"
#include<unistd.h> //elle contient la fonction sleep() ;
#define cte 50

/////////////////////////////////////
int nonespace(char *ch) // ASCII (espace)=32
{ int z; 
  for(int i=0;i<strlen(ch);i++){
  z=ch[i] ;if(z==32) return 0 ;
}	return 1 ;	
}
/////////////////////////////////////
void wait(int n)
{ for(int i=1;i<=n;i++) {printf(". ");sleep(1);}
system("cls") ;
}
/////////////////////////////////////
int  estchaine(char* ch){ // est ce que ch de compose seulement des lettre (qlq soit miniscule ou majus)
int x=strlen(ch) ; int z,test=0 ;
	for(int i=0;i<x;i++){ z=ch[i];
	if( (z>96 && z<123) ||( z>64 && z<91)) test+=1;		   }
	if(test==x) return 1 ; else return 0 ;
}
//////////////////////////////////////
int chainecmp(char* ch1,char* ch2){ // miniscule ou majuscule ou les deux, exp "aZqQ"="AZqq"
	int x=strlen(ch1),y=strlen(ch2),z,h,test=0 ; 
	for(int i=0;i<x;i++){ z=ch1[i];h=ch2[i];
	if(z==h || z==h+32 || z==h-32) test+=1;       }  
	if(x==y && test== x )  return 1 ;	else return 0 ;	
}
//////////////////////////////////////
int verid_long50(char *ch,int min, int max)
{ if(min<max) { int x;
x=strlen(ch); if(x>=min ||x<=max) return 1; else return 0 ;	} else return 0 ;
}
//////////////////////////////////////
void wa9t(char c[cte],long long int *tot1){  // exp: c[]="Wed Jul 11 10:50:20 2011" ss cette forme
	char ch1[50]="",ch2[4]="",ch3[3]="",ch4[9]="",ch5[5]="" ;
    int x1,x2,x3,x4,x5,j,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12;  // le temp à partir de 2020 en minutes
       j=-1 ; 
	for(int i=4;i<7;i++) { j++; //Jul
		ch1[j]=c[i] ;
	}  j=-1;
	for(int i=8;i<10;i++) {j++; //11
		ch2[j]=c[i];
	} x2= atoi(ch2);j=-1;
	for(int i=11;i<13;i++) { j++; //10
		ch3[j]=c[i];
	} x3= atoi(ch3); j=-1;
	for(int i=14;i<16;i++) {j++;  //50
		ch4[j]=c[i];
	} x4= atoi(ch4); j=-1;
	for(int i=20;i<=23;i++) { j++; //2011
		ch5[j]=c[i];
	} x5= atoi(ch5);
	a1=strcmp(ch1,"Jan");a2=strcmp(ch1,"Feb");a3=strcmp(ch1,"Mar");a4=strcmp(ch1,"Apr");a5=strcmp(ch1,"May");a6=strcmp(ch1,"June");
	a7=strcmp(ch1,"Jul");a8=strcmp(ch1,"Aug");a9=strcmp(ch1,"Sep");a10=strcmp(ch1,"Oct");a11=strcmp(ch1,"Nov");a12=strcmp(ch1,"Dec");
    if(a1==0) x1=1; else if(a2==0) x1=2; else if(a3==0) x1=3; else if(a4==0) x1=4; else if(a5==0) x1=5; else if(a6==0) x1=6;
    else if(a7==0) x1=7; else if(a8==0) x1=8; else if(a9==0) x1=9; else if(a10==0) x1=10; else if(a11==0) x1=11; else if(a12==0) x1=12;
    else x1=0;  *tot1= x2*1440+x3*60+x4+x1*40320+(x5-2020)*483840 ;
}
//////////////////////////////////////
void ajout_adherant(FILE *f, FILE *p,FILE *pp,char* esm,int *depasse){ *depasse=1;
	int aux1,aux2,hell,i=-1,kk,x,hi=0,hii=0,hiii=0 ,wx; char ch[cte],ch1[cte*2],ch2[cte*2],ch3[cte*2],c[]="non" ,chaine[cte*20]; 
	rewind(p);
	fscanf(p,"%d ",&aux1) ; // aux= dernier num identifiant     |||||||||||
	fscanf(p,"%d ",&aux2) ;
	do{i+=1; fscanf(f," %s ",ch3) ; fgets(chaine,999,f); hell=strcmp(ch3,"fiin3finfinfzeANbBrty");
	}while(hell!=0); rewind(f); rewind(p);x=i; i=-1;
	struct etudiant	{ char nom[cte], prenom[cte*2],adresse[cte*2], type[cte], retardaire[5] ;     int identifiant, nbr_tot, nbr_curr , code1,code2, code3, code4 ;	} ;
	struct  etudiant t[x+1] ;
	do{ i+=1;   fscanf(f," %s %s %d %s %s %d %d %s %d %d %d %d ",t[i].nom,t[i].prenom,&t[i].identifiant,t[i].adresse,t[i].type,&t[i].nbr_tot,&t[i].nbr_curr,t[i].retardaire,&t[i].code1,&t[i].code2,&t[i].code3,&t[i].code4);
	}   while(i<x );rewind(f) ;         // double gets car il y a un probleme avec scanf!!!!!
	printf("\nNB:n\'utilisez pas \"l\'espace\"..Vous pouvez separer entre deux mots par\"-\"ou par \"/\"..TOUS caracteres apres l\'espace      s\'effaceront automatiquement! Merci pour  votre accord! \n");
	do{hi+=1;printf("\n%d:Nom de %s: ",hi,esm);gets(ch1);if(hi ==1)gets(ch1); wx=nonespace(ch1);}while(hi<3 && wx==0);if(hi>=3 && wx==0){printf(">> vous avez depasse le nombre maximal d\'essayes!\n");wait(3);*depasse=0;} hi=0;
	if(*depasse!=0){do{hii+=1;printf("\n%d:Prenom de %s: ",hii,esm);gets(ch);wx=nonespace(ch);}while(hii<3 && wx==0);if(hii>=3 && wx==0){printf(">> vous avez depasse le nombre maximal d\'essayes!\n");wait(3);*depasse=0;}hii=0;
	if(*depasse!=0){do{hiii+=1;printf("\n%d:Adresse de %s: ",hiii,esm);scanf("%s",ch2) ;wx=nonespace(ch2);}while(hiii<3 && wx==0);if(hiii>=3 && wx==0){printf(">> vous avez depasse le nombre maximal d\'essayes!\n");wait(3);*depasse=0;}hiii=0;
	fprintf(f," %s  %s  %d  %s  %s  %d  %d  %s  %d  %d  %d  %d \n",ch,ch1,aux1+1,ch2,esm,0,0,c,0,0,0,0) ; i=-1;
	do{ i+=1;
    fprintf(f," %s  %s  %d  %s  %s  %d  %d  %s  %d  %d  %d  %d \n",t[i].nom,t[i].prenom,t[i].identifiant,t[i].adresse,t[i].type,t[i].nbr_tot,t[i].nbr_curr,t[i].retardaire,t[i].code1,t[i].code2,t[i].code3,t[i].code4);
	}   while(i<x );rewind(f) ;
    //mise a jour de fichier information:
    rewind(p) ;
    fprintf(p," %d \n",aux1+1) ; 
    fprintf(p," %d \n",aux2  ) ;
    //Fin mise à jour de fichier information
    hell=strcmp("etudiant",esm);
    int u,v,w,r,s,q;
    if (hell ==0 ){
    rewind(pp); fscanf(pp,"%d %d %d %d %d %d ",&u,&v,&w,&r,&s,&q);
    rewind(pp); fprintf(pp,"%d \n%d \n%d \n%d \n%d \n%d ",u,v,w,r+1,s,q);rewind(pp);
    printf("\najout etudiant se termine avec succee! et code identifiant= %d ",aux1+1) ; } 
    else if(hell==-1){
    rewind(pp); fscanf(pp,"%d %d %d %d %d %d ",&u,&v,&w,&r,&s,&q);
    rewind(pp); fprintf(pp,"%d \n%d \n%d \n%d \n%d \n%d ",u,v,w,r,s,q+1);rewind(pp);
    printf("\najout visiteur se termine avec succee! et code identifiant= %d ",aux1+1) ;
	} else {
	rewind(pp); fscanf(pp,"%d %d %d %d %d %d ",&u,&v,&w,&r,&s,&q);
    rewind(pp); fprintf(pp,"%d \n%d \n%d \n%d \n%d \n%d ",u,v,w,r,s+1,q);rewind(pp);
    printf("\najout enseignant se termine avec succee! et code identifiant= %d ",aux1+1) ;
	}
    }}
}
//////////////////////////////////////
void ajout_livre(FILE *f, FILE *p ,FILE *pp,int *depasse){*depasse=1;
	int i=-1,fd,x,hell,final, aux1,aux2,cop,nbr,wx,hi=0,hii=0,hiii=0; char ch[cte],ch1[cte*2],ch2[cte*2],ch3[cte*2],ch4[cte*2],ch5[cte*2] ,*wa9t,chaine[cte*20];  time_t temp=time(0) ;
    wa9t=ctime(&temp) ; //never forget "&"temp  et wa9t de type char*
     do{final+=1;   
	}while(fgets(chaine,999,f)!=NULL ); rewind(f);
    rewind(p);
	fscanf(p,"%d ",&aux2) ;
	fscanf(p,"%d ",&aux1) ; // aux= dernier num identifiant etudiant   |||||||||||||||
	rewind(p); rewind(f);
		do{i+=1; fscanf(f," %s ",ch3) ; fgets(chaine,999,f); hell=strcmp(ch3,"fiin3finfinfzeANbBrty");
	}while(hell!=0 && i<final); rewind(f); rewind(p);x=i; i=-1;
	struct livre
	{ char type[cte], titre[cte*2],localisation[cte*2], nom_auteur[cte*2],nom_editeur[cte*2],ch0[cte], ch1[cte],ch2[cte],ch3[cte],ch4[cte] ;
      int code,nbr_cop,nbr_tot;
	} ;  struct  livre t[x+2] ;
	do{ i+=1; fd=i; fscanf(f,"%s %s %s %d %d %s %s %d %s %s %s %s %s ",t[i].type,t[i].titre,t[i].localisation,&t[i].code,&t[i].nbr_cop,t[i].nom_auteur,t[i].nom_editeur,&t[i].nbr_tot,t[i].ch0,t[i].ch1,t[i].ch2,t[i].ch3,t[i].ch4);
	  }while( i<x );rewind(f) ;
	printf("\nNB:n\'utilisez pas \"l\'espace\"..Vous pouvez separer entre deux mots par\"-\"ou par \"/\"..TOUS caracteres apres l\'espace      s\'effaceront automatiquement! Merci pour  votre accord! \n");
	                do{hi+=1;printf("\n%d:titre du livre   : ",hi);gets(ch); if(hi==1)gets(ch);wx=nonespace(ch);}while(hi<3 && wx==0);if(hi>=3 && wx==0){printf("vous avez depasse le nombre maximal d\'essayes!\n");wait(3);*depasse=0;} hi=0; 	
	if(*depasse!=0){do{hi+=1;printf("\n%d:localisation     : ",hi);gets(ch1) ;wx=nonespace(ch1);}while(hi<3 && wx==0);if(hi>=3 && wx==0){printf("vous avez depasse le nombre maximal d\'essayes!\n");wait(3);*depasse=0;} hi=0; 	
	if(*depasse!=0){do{hi+=1;printf("\n%d:nombre de copies : ",hi);scanf("%d",&cop) ;}while(hi<3 && cop<1);if(hi>=3 ){printf("vous avez depasse le nombre maximal d\'essayes!\n");wait(3);*depasse=0;} hi=0; 
	if(*depasse!=0){do{hi+=1;printf("\n%d:nom d\'auteur    : ",hi);gets(ch3);if(hi==1)gets(ch3);wx=nonespace(ch3);}while(hi<3 && wx==0);if(hi>=3 && wx==0){printf("vous avez depasse le nombre maximal d\'essayes!\n");*depasse=0;} hi=0; 	
	if(*depasse!=0){do{hi+=1;printf("\nnom d\'editeur   : ");gets(ch4) ;wx=nonespace(ch4);}while(hi<3 && wx==0);if(hi>=3 && wx==0){printf("vous avez depasse le nombre maximal d\'essayes!\n");*depasse=0;} hi=0; 	
	//le temp se met automatiquement
	rewind(f);
	fprintf(f,"%s %s %s %d %d %s %s %d  %s\n","livre",ch,ch1,aux1+1,cop,ch3,ch4,0,wa9t) ;i=-1;
	do{ i+=1; fd=i;
    fprintf(f,"%s %s %s %d %d %s %s %d %s %s %s %s %s \n",t[i].type,t[i].titre,t[i].localisation,t[i].code,t[i].nbr_cop,t[i].nom_auteur,t[i].nom_editeur,t[i].nbr_tot,t[i].ch0,t[i].ch1,t[i].ch2,t[i].ch3,t[i].ch4);
	}while( i<x );rewind(f) ; 
    //mise a jour de fichier information:(ligne 2)
    rewind(p) ;   fprintf(p," %d\n%d ",aux2,aux1+1) ;  
    //mise à jour de fichier information2
     int u,v,w,r,s,q;
    rewind(pp); fscanf(pp,"%d %d %d %d %d %d ",&u,&v,&w,&r,&s,&q);
    rewind(pp); fprintf(pp,"%d \n%d \n%d \n%d \n%d \n%d \n",u+cop,v,w,r,s,q);rewind(pp);
    printf("\najout de livre se termine avec succee! et code identifiant= %d ",aux1+1) ;
    }}}}
}
void ajout_magasine(FILE *f, FILE *p,FILE *pp,int *depasse){ *depasse=1;
	int i=-1,x,fd,hell,final=-1,aux1,aux2,cop,nbr,hi=0,wx ; char ch[cte],ch1[cte*2],ch2[cte*2],ch3[cte*2], *wa9t,chaine[cte*20];  time_t temp=time(0) ;
    wa9t=ctime(&temp) ;
     do{final+=1;   
	}while(fgets(chaine,999,f)!=NULL ); rewind(f);
    	do{i+=1; fscanf(f," %s ",ch3) ; fgets(chaine,999,f); hell=strcmp(ch3,"fiin3finfinfzeANbBrty");
	}while(hell!=0 && i<final); rewind(f); rewind(p);x=i; i=-1;
		struct magasine
	{ char type[cte], titre[cte*2],localisation[cte*2],ch0[cte], ch1[cte],ch2[cte],ch3[cte],ch4[cte] ;
     int code,nbr_cop,nbr_tot;
	} ;  struct  magasine t1[x+2]  ;
		do{ i+=1;
    fscanf(f,"%s %s %s %d %d %d %s %s %s %s %s",t1[i].type,t1[i].titre,t1[i].localisation,&t1[i].code,&t1[i].nbr_cop,&t1[i].nbr_tot,t1[i].ch0,t1[i].ch1,t1[i].ch2,t1[i].ch3,t1[i].ch4);
	} while( i<x );rewind(f) ; fd=i;i=-1; 
	fscanf(p,"%d ",&aux2) ;  	 fscanf(p,"%d ",&aux1) ; // aux= dernier num identifiant etudiant   |||||
	printf("\nNB:n\'utilisez pas \"l\'espace\"..Vous pouvez separer entre deux mots par\"-\"ou par \"/\"..TOUS caracteres apres l\'espace      s\'effaceront automatiquement! Merci pour  votre accord! \n");
	do{hi+=1;printf("\n%d:titre du magasine    : ",hi);gets(ch);if(hi==1)gets(ch); wx=nonespace(ch);}while(hi<3 && wx==0);if(hi>=3 && wx==0){printf("vous avez depasse le nombre maximal d\'essayes!\n");wait(3);*depasse=0;} hi=0;
	if(*depasse!=0){do{hi+=1;printf("\n%d:localisation         : ",hi);gets(ch1) ;wx=nonespace(ch1);}while(hi<3 && wx==0);if(hi>=3 && wx==0){printf("vous avez depasse le nombre maximal d\'essayes!\n");wait(3);*depasse=0;} hi=0;
	if(*depasse!=0){do{hi+=1;printf("\n%d:nombre de copies     : ",hi);scanf("%d",&cop) ;}while(hi<3 && cop<1);if(hi>=3  ){printf("vous avez depasse le nombre maximal d\'essayes!\n");wait(3);*depasse=0;} hi=0;
	//le temp se met automatiquement
	fprintf(f,"%s  %s  %s  %d  %d  %d  %s\n","magasine",ch,ch1,aux1+1,cop,0,wa9t) ;i=-1;
	do{ i+=1;  fprintf(f,"%s %s %s %d %d %d %s %s %s %s %s\n",t1[i].type,t1[i].titre,t1[i].localisation,t1[i].code,t1[i].nbr_cop,&t1[i].nbr_tot,t1[i].ch0,t1[i].ch1,t1[i].ch2,t1[i].ch3,t1[i].ch4);
	} while( i<x );rewind(f) ; fd=i;i=-1;
    //mise a jour de fichier information:(ligne 2)
    rewind(p) ;   fprintf(p," %d\n%d ",aux2,aux1+1) ;  
    int u,v,w,r,s,q;
    rewind(pp); fscanf(pp,"%d %d %d %d %d %d ",&u,&v,&w,&r,&s,&q);
    rewind(pp); fprintf(pp,"%d \n%d \n%d \n%d \n%d \n%d ",u,v+cop,w,r,s,q);rewind(pp);
    printf("\najout de magasine se termine avec succee! et code identifiant= %d ",aux1+1) ;
    }}
}
void ajout_article(FILE *f, FILE *p, FILE *pp,int *depasse){ *depasse=1;
	int i=-1,x,fd,hell,final=-1, aux1,aux2,cop,nbr,hi=0,wx ; char ch[cte],ch1[cte*2],ch2[cte*2],ch3[cte*2],ch4[cte*2],ch5[cte*2] ,*wa9t,chaine[cte*20];  time_t temp=time(0) ;
    wa9t=ctime(&temp) ;
    do{final+=1;   
	}while(fgets(chaine,999,f)!=NULL ); rewind(f);
    	do{i+=1; fscanf(f," %s ",ch3) ; fgets(chaine,999,f); hell=strcmp(ch3,"fiin3finfinfzeANbBrty");
	}while(hell!=0 && i<final ); rewind(f); rewind(p);x=i; i=-1;
		struct article
	{ char type[cte], titre[cte*2],localisation[cte*2],nom_auteur[cte*2] ,ch0[cte], ch1[cte],ch2[cte],ch3[cte],ch4[cte];
     int code,nbr_cop,nbr_tot;
	} ;  struct  article t2[x +2] ;
	do{ i+=1;   fscanf(f,"%s %s %s %d %d %s  %d %s %s %s %s %s ",t2[i].type,t2[i].titre,t2[i].localisation,&t2[i].code,&t2[i].nbr_cop,t2[i].nom_auteur,&t2[i].nbr_tot,t2[i].ch0,t2[i].ch1,t2[i].ch2,t2[i].ch3,t2[i].ch4);
	}   while( i<x );rewind(f) ; i=-1;    
	fscanf(p,"%d ",&aux2) ;
	fscanf(p,"%d ",&aux1) ; // aux= dernier num identifiant etudiant    |||||||||||
	printf("\nNB:n\'utilisez pas \"l\'espace\"..Vous pouvez separer entre deux mots par\"-\"ou par \"/\"..TOUS caracteres apres l\'espace      s\'effaceront automatiquement! Merci pour  votre accord! \n");
	do{hi+=1;printf("\n%d:titre du l\'article    : ",hi);gets(ch);if(hi==1)gets(ch); wx=nonespace(ch);}while(hi<3 && wx==0);if(hi>=3 && wx==0){printf("vous avez depasse le nombre maximal d\'essayes!\n");wait(3);*depasse=0;} hi=0; 	
	if(*depasse!=0){do{hi+=1;printf("\n%d:localisation           : ",hi);gets(ch1); wx=nonespace(ch1);}while(hi<3 && wx==0);if(hi>=3 && wx==0){printf("vous avez depasse le nombre maximal d\'essayes!\n");wait(3);*depasse=0;} hi=0; 	
	if(*depasse!=0){do{hi+=1;printf("\n%d:nombre de copies existe: ",hi);scanf("%d",&cop) ;}while(hi<3 && cop<1);if(hi>=3 ){printf("vous avez depasse le nombre maximal d\'essayes!\n");wait(3);*depasse=0;} hi=0; 	
	if(*depasse!=0){do{hi+=1;printf("\n%d:nom d\'auteur          : ",hi);gets(ch3); wx=nonespace(ch3);}while(hi<3 && wx==0);if(hi>=3 && wx==0){printf("vous avez depasse le nombre maximal d\'essayes!\n");wait(3);*depasse=0;} hi=0; 	 
	rewind(f) ; 
	fprintf(f,"%s  %s  %s  %d  %d  %s  %d   %s\n","article",ch,ch1,aux1+1,cop,ch3,0,wa9t) ;i=-1;
	do{ i+=1;  fprintf(f,"%s %s %s %d %d %s  %d %s %s %s %s %s \n",t2[i].type,t2[i].titre,t2[i].localisation,t2[i].code,t2[i].nbr_cop,t2[i].nom_auteur,t2[i].nbr_tot,t2[i].ch0,t2[i].ch1,t2[i].ch2,t2[i].ch3,t2[i].ch4);
	}   while(i<x );rewind(f) ; i=-1;
    //mise a jour de fichier information:(ligne 2)
    rewind(p) ;
    fprintf(p," %d\n%d ",aux2,aux1+1) ;  
     int u,v,w,r,s,q;
    rewind(pp); fscanf(pp,"%d %d %d %d %d %d ",&u,&v,&w,&r,&s,&q);
    rewind(pp); fprintf(pp,"%d \n%d \n%d \n%d \n%d \n%d ",u,v,w+cop,r,s,q);rewind(pp);
    printf("\najout de l\'article se termine avec succee! et code identifiant= %d ",aux1+1) ;
    }}}
}
//////////////////////////////////////
void recherche_adherant(FILE *f, int ident,int test,int *le){
	int a,b,c,d,e,ff,g,h,x=0,y=0 ; char ch1[cte*2],ch2[cte*2],ch3[cte*2],ch4[cte*2],ch5[cte*2],chaine[cte*50] ; 
    do{  x++;
	} while((fgets(chaine,2499,f))!=NULL);
	rewind(f) ;
	do{ y++;
    fscanf(f,"%s %s %d %s %s %d %d %s %d %d %d %d",ch1,ch2,&a,ch3,ch4,&b,&c,ch5,&d,&e,&ff,&g) ;	
    }   while(ident!=a && y<x ); *le=1 ;
	if(ident==a) {
		switch( test) {
	case 1 : printf("Prenom de l\'etudiant                 : %s\nNom de l\'etudiant                    : %s\nidentifiant                          : %d\nadresse                              : %s\nType                                 : %s\nnomre totale de documents effectues  : %d\nnombre de document en cours d\'emprunt :%d\nRetardaire?                           :%s\ncode de 1er document empruntee        : %d\ncode de 2eme document empruntee       : %d\n",ch1,ch2,a,ch3,ch4,b,c,ch5,d,e) ;break ;
	case 2 : printf("Prenom de l\'enseignant               : %s\nNom de l\'enseignant                  : %s\nidentifiant                          : %d\nadresse                              : %s\nType                                 : %s\nnomre totale de documents effectues  : %d\nnombre de document en cours d\'emprunt :%d\nRetardaire?                           :%s\ncode de 1er document empruntee        : %d\ncode de 2eme document empruntee       : %d\ncode de 3eme document empruntee       : %d\ncode de 4eme document empruntee       : %d\n",ch1,ch2,a,ch3,ch4,b,c,ch5,d,e,ff,g); break ;
	case 3 : printf("Prenom de visiteur                   : %s\nNom de visiteur                      : %s\nidentifiant                          : %d\nadresse                              : %s\nType                                 : %s\nnomre totale de documents effectues  : %d\nnombre de document en cours d\'emprunt :%d\nRetardaire?                           :%s\ncode de document empruntee            : %d\n",ch1,ch2,a,ch3,ch4,b,c,ch5,d); break ;
	default: printf("Choix non trouvee!\n"); break ;   } printf("\n\t\t*************\n");		
	} else *le=0;	
}
void limit(FILE *f,int *x){ *x=0;char chaine[cte*50] ; //deja existe
	do{  *x+=1;
	} while((fgets(chaine,2499,f))!=NULL);
}
 void recherche2_adherant(FILE *f, char *nom,int test,int *le){
	int a,b,c,d,e,ff,g,h,x=0,y=0,hell ; char ch1[cte*2],ch2[cte*2],ch3[cte*2],ch4[cte*2],ch5[cte*2],chaine[cte*50] ; 
    fscanf(f,"%s %s %d %s %s %d %d %s %d %d %d %d",ch1,ch2,&a,ch3,ch4,&b,&c,ch5,&d,&e,&ff,&g) ;hell=chainecmp(ch2,nom) ;
	if(hell==1) { *le+=1 ;
		switch( test) {
	case 1 : printf("Prenom  de   l\'etudiant              : %s\nNom  de   l\'etudiant                 : %s\nidentifiant                          : %d\nadresse                              : %s\nType                                 : %s\nnomre totale de documents effectues  : %d\nnombre de document en cours d\'emprunt :%d\nRetardaire?                           :%s\ncode de 1er document empruntee        : %d\ncode de 2eme document empruntee       : %d\n",ch1,ch2,a,ch3,ch4,b,c,ch5,d,e) ;break ;
	case 2 : printf("Prenom  de   l\'enseignant            : %s\nNom  de   l\'enseignant               : %s\nidentifiant                          : %d\nadresse                              : %s\nType                                 : %s\nnomre totale de documents effectues  : %d\nnombre de document en cours d\'emprunt :%d\nRetardaire?                           :%s\ncode de 1er document empruntee        : %d\ncode de 2eme document empruntee       : %d\ncode de 3eme document empruntee       : %d\ncode de 4eme document empruntee       : %d\n",ch1,ch2,a,ch3,ch4,b,c,ch5,d,e,ff,g); break ;
	case 3 : printf("Prenom  de   visiteur                : %s\nNom  de   visiteur                   : %s\nidentifiant                          : %d\nadresse                              : %s\nType                                 : %s\nnomre totale de documents effectues  : %d\nnombre de document en cours d\'emprunt :%d\nRetardaire?                           :%s\ncode de document empruntee            : %d\n",ch1,ch2,a,ch3,ch4,b,c,ch5,d); break ;
	default: printf("Choix non trouvee!\n"); break ;  }	printf("\n");				}	
}
//////////////////////////////////////
void recherche_document(FILE *f, int code,int test,int *le){	
	int a,b,c,d,e,ff,g,h,x=0,y=0 ; char ch1[cte*2],ch2[cte*2],ch3[cte*2],ch4[cte*2],ch5[cte*2],ch6[cte*2],ch7[cte*2],ch8[cte*2],ch9[cte*2],chaine[cte*50] ; 
    do{  x++;	} while((fgets(chaine,2499,f))!=NULL);	rewind(f) ;
	*le=1 ;
		switch( test) {
	case 1 : 	do{ y++; fscanf(f,"%s %s %s %d %d %s %s  %d ",ch1,ch2,ch3,&a,&b,ch4,ch5,&c) ;	fgets(chaine,2499,f); }   while(code!=a && y<x );
	if(code==a){ printf("Type                     : %s\nTitre                    : %s\nLocalisation             : %s\nCode de livre            : %d\nNombre de copies         : %d\nNom d\'auteur             : %s\nNom d\'editeur            : %s\nNombre d\'emprunt totale  : %d\nDate d\'edition           : %s\n\n\n",ch1,ch2,ch3,a,b,ch4,ch5,c,chaine) ;}
	else {*le=0;} break ;
    case 2 : 	do{ y++; fscanf(f,"%s %s %s %d %d %d ",ch1,ch2,ch3,&a,&b,&c) ;	fgets(chaine,2499,f); }   while(code!=a && y<x );
	if(code==a){ printf("Type                     : %s\nTitre                    : %s\nLocalisation             : %s\nCode de magasine         : %d\nNombre de copies         : %d\nNombre d\'emprunt totale  : %d\nDate d\'edition           : %s\n\n\n",ch1,ch2,ch3,a,b,c,chaine) ;}
	else *le=0; break ;
    case 3 : 	do{ y++; fscanf(f,"%s %s %s %d %d %s  %d ",ch1,ch2,ch3,&a,&b,ch4,&c) ;	fgets(chaine,2499,f); }   while(code!=a && y<x );
	if(code==a){ printf("Type                     : %s\nTitre                    : %s\nLocalisation             : %s\nCode de l\'article        : %d\nNombre de copies         : %d\nNom d\'auteur             : %s\nNombre d\'emprunt totale  : %d\nDate de publication      : %s\n\n\n",ch1,ch2,ch3,a,b,ch4,c,chaine) ;}
	else *le=0; break ;
	default: printf("Choix non trouvee!\n"); break ;
    }		
}
int chcmp(char* ch1,char* ch2){                    
	int x=strlen(ch1),y=strlen(ch2),z,h,test=0 ; 
	for(int i=0;i<x;i++){ z=ch1[i];h=ch2[i];
	    if(!( (z>96 && z<123) ||( z>64 && z<91))) { test+=1;continue ;}
		if(z==h || z==h+32 || z==h-32) test+=1;         }  
    	if(x==y && test>= x )  return 1 ;	else return 0 ;	
}
///////////////////////////////

void recherche2_document(FILE *f,int limite, char *titre,int test,int *le){
	int a,b,c,d,e,ff,g,h,x=0,y=0,hell ; char ch1[cte*2],ch2[cte*2],ch3[cte*2],ch4[cte*2],ch5[cte*2],ch6[cte*2],ch7[cte*2],ch8[cte*2],ch9[cte*2],chaine[cte*50] ; 
		switch( test) {
	case 1 :  fscanf(f,"%s %s %s %d %d %s %s  %d ",ch1,ch2,ch3,&a,&b,ch4,ch5,&c) ;	fgets(chaine,2499,f); hell=chcmp(titre,ch2) ;
	if(hell==1){*le+=1; printf("\n       ************\nType                     : %s\nTitre                    : %s\nLocalisation             : %s\nCode de livre            : %d\nNombre de copies         : %d\nNom d\'auteur             : %s\nNom d\'editeur            : %s\nNombre d\'emprunt totale  : %d\nDate d\'edition           : %s\n\n\n",ch1,ch2,ch3,a,b,ch4,ch5,c,chaine) ;}	break ;
    case 2 :  fscanf(f,"%s %s %s %d %d %d ",ch1,ch2,ch3,&a,&b,&c) ;	fgets(chaine,2499,f);   hell=chcmp(titre,ch2) ;
	if(hell==1){*le+=1; printf("\n       ************\nType                     : %s\nTitre                    : %s\nLocalisation             : %s\nCode de magasine         : %d\nNombre de copies         : %d\nNombre d\'emprunt totale  : %d\nDate d\'edition           : %s\n\n\n",ch1,ch2,ch3,a,b,c,chaine) ;}	 break ;
    case 3 :  fscanf(f,"%s %s %s %d %d %s  %d ",ch1,ch2,ch3,&a,&b,ch4,&c) ;	fgets(chaine,2499,f);  hell=chcmp(titre,ch2) ;
	if(hell==1){*le+=1; printf("\n       ************\nType                     : %s\nTitre                    : %s\nLocalisation             : %s\nCode de l\'article        : %d\nNombre de copies         : %d\nNom d\'auteur             : %s\nNombre d\'emprunt totale  : %d\nDate de publication      : %s\n\n\n",ch1,ch2,ch3,a,b,ch4,c,chaine) ;}	break ;
	default: printf("Choix non trouvee!\n"); break ;
    }		
}
//////////////////////////////////////
void modifier_adherant(FILE *f,int test,int z,int *depasse){ *depasse=1;
	int i=-1,ii=-1,x=0,hell,com,aux1,aux2,aux3,aux4,aux5,aux6,aux7,aux8,a; char ch1[cte*2],ch2[cte*2],ch3[cte*2],ch4[cte*2],ch5[cte*2],chaine[cte*50],c[]="non";
	do{  x+=1;fscanf(f,"%s",ch5);fgets(chaine,2499,f);hell=strcmp(ch5,"fiin3finfinfzeANbBrty");	} while(hell!=0);	rewind(f) ;
	struct etudiant
	{ char nom[cte], prenom[cte*2],adresse[cte*2], type[cte], retardaire[5] ;
      int identifiant, nbr_tot, nbr_curr , code1,code2, code3, code4 ;
	} ;	struct  etudiant t[x+1] ; int hi,wx ;
	printf("\nNB:n\'utilisez pas \"l\'espace\"..Vous pouvez separer entre deux mots par\"-\"ou par \"/\"..TOUS caracteres apres l\'espace      s\'effaceront automatiquement! Merci pour  votre accord! \n");
switch( test) {
	case 1 : hi=0;rewind(f) ;
	do{ i+=1;    fscanf(f,"%s %s %d %s %s %d %d %s %d %d %d %d",t[i].nom,t[i].prenom,&t[i].identifiant,t[i].adresse,t[i].type,&t[i].nbr_tot,&t[i].nbr_curr,t[i].retardaire,&t[i].code1,&t[i].code2,&t[i].code3,&t[i].code4); aux1=t[i].identifiant;
   	  }   while(z!=t[i].identifiant );rewind(f) ;
	do{ ii+=1;   fscanf(f,"%s %s %d %s %s %d %d %s %d %d %d %d",t[ii].nom,t[ii].prenom,&t[ii].identifiant,t[ii].adresse,t[ii].type,&t[ii].nbr_tot,&t[ii].nbr_curr,t[ii].retardaire,&t[ii].code1,&t[ii].code2,&t[ii].code3,&t[ii].code4);
      }   while( ii<x );rewind(f) ; 
	if(z!=t[i].identifiant ) { printf("choix non trouvee! \n");sleep(1);system("cls");exit(123);}hi=0; // adherant existe ou non
	do             {hi+=1;	 printf("\nNouveau nom de l\'etudiant    : ");gets(t[i].nom)    ; if(hi==1) gets(t[i].nom);wx=nonespace(t[i].nom);}while(hi<3 && wx==0);if(hi>=3 && wx==0){printf("vous avez depasse le nombre maximal d\'essayes!\n");wait(2);*depasse=0;} hi=0; 
	if(*depasse!=0){do{hi+=1;printf("\nNouveau Prenom de l\'etudiant : ");gets(t[i].prenom) ; wx=nonespace(t[i].prenom);}while(hi<3 && wx==0);if(hi>=3 && wx==0){printf("vous avez depasse le nombre maximal d\'essayes!\n");wait(2);*depasse=0;} hi=0; 
	if(*depasse!=0){do{hi+=1;printf("\nNouveau Adresse de l\'etudiant: ");gets(t[i].adresse);wx=nonespace(t[i].adresse);}while(hi<3 && wx==0);if(hi>=3 && wx==0){printf("vous avez depasse le nombre maximal d\'essayes!\n");wait(2);*depasse=0;} hi=0; 
	rewind(f) ;	
    for(int m=0;m<x;m++){ 	fprintf(f,"%s %s %d %s %s %d %d %s %d %d %d %d\n",t[m].nom,t[m].prenom,t[m].identifiant,t[m].adresse,t[m].type,t[m].nbr_tot,t[m].nbr_curr,t[m].retardaire,t[m].code1,t[m].code2,t[m].code3,t[m].code4);}
    printf("\nla modification de l\'etudiant a terminee avec succee! et code identifiant= %d ",aux1) ; rewind(f) ;}}
	break ; 
	case 2 : hi=0; rewind(f) ;
	do{ i+=1;   fscanf(f,"%s %s %d %s %s %d %d %s %d %d %d %d",t[i].nom,t[i].prenom,&t[i].identifiant,t[i].adresse,t[i].type,&t[i].nbr_tot,&t[i].nbr_curr,t[i].retardaire,&t[i].code1,&t[i].code2,&t[i].code3,&t[i].code4);aux1=t[i].identifiant;
	}   while(z!=t[i].identifiant && i<x );rewind(f) ; 
	do{ ii+=1;  fscanf(f,"%s %s %d %s %s %d %d %s %d %d %d %d",t[ii].nom,t[ii].prenom,&t[ii].identifiant,t[ii].adresse,t[ii].type,&t[ii].nbr_tot,&t[ii].nbr_curr,t[ii].retardaire,&t[ii].code1,&t[ii].code2,&t[ii].code3,&t[ii].code4);
    }   while( ii<x );rewind(f) ;
	if(z!=t[i].identifiant ) { printf("choix non trouvee! \n");sleep(1);system("cls");exit(123);}hi=0; // adherant existe ou non
	do             {hi+=1;	 printf("\nNouveau nom de l\'enseignant    : ");gets(t[i].nom)    ; if(hi==1) gets(t[i].nom);wx=nonespace(t[i].nom);}while(hi<3 && wx==0);if(hi>=3 && wx==0){printf("vous avez depasse le nombre maximal d\'essayes!\n");wait(2);*depasse=0;} hi=0; 
	if(*depasse!=0){do{hi+=1;printf("\nNouveau Prenom de l\'enseignant : ");gets(t[i].prenom) ; wx=nonespace(t[i].prenom);}while(hi<3 && wx==0);if(hi>=3 && wx==0){printf("vous avez depasse le nombre maximal d\'essayes!\n");wait(2);*depasse=0;} hi=0; 
	if(*depasse!=0){do{hi+=1;printf("\nNouveau Adresse de l\'enseignant: ");gets(t[i].adresse);wx=nonespace(t[i].adresse);}while(hi<3 && wx==0);if(hi>=3 && wx==0){printf("vous avez depasse le nombre maximal d\'essayes!\n");wait(2);*depasse=0;} hi=0; 

	rewind(f) ;	
    for(int m=0;m<x;m++){ 	fprintf(f,"%s %s %d %s %s %d %d %s %d %d %d %d\n",t[m].nom,t[m].prenom,t[m].identifiant,t[m].adresse,t[m].type,t[m].nbr_tot,t[m].nbr_curr,t[m].retardaire,t[m].code1,t[m].code2,t[m].code3,t[m].code4);}
    printf("\nla modification de l\'enseignant a terminee avec succee! et code identifiant= %d ",aux1) ;}} 
	break ;
	case 3 : hi=0; rewind(f) ;
	do{ i+=1;   fscanf(f,"%s %s %d %s %s %d %d %s %d %d %d %d",t[i].nom,t[i].prenom,&t[i].identifiant,t[i].adresse,t[i].type,&t[i].nbr_tot,&t[i].nbr_curr,t[i].retardaire,&t[i].code1,&t[i].code2,&t[i].code3,&t[i].code4);  aux1=t[i].identifiant;
	  }   while(z!=t[i].identifiant && i<x );rewind(f) ;
	do{ ii+=1;   fscanf(f,"%s %s %d %s %s %d %d %s %d %d %d %d",t[ii].nom,t[ii].prenom,&t[ii].identifiant,t[ii].adresse,t[ii].type,&t[ii].nbr_tot,&t[ii].nbr_curr,t[ii].retardaire,&t[ii].code1,&t[ii].code2,&t[ii].code3,&t[ii].code4);
   	  }   while( ii<x );rewind(f) ; 
	if(z!=t[i].identifiant ) { printf("choix non trouvee! \n");sleep(1);system("cls");exit(123);}hi=0; // adherant existe ou non
    	do         {hi+=1;	 printf("\nNouveau nom du visiteur    : ");gets(t[i].nom)    ; if(hi==1) gets(t[i].nom);wx=nonespace(t[i].nom);}while(hi<3 && wx==0);if(hi>=3 && wx==0){printf("vous avez depasse le nombre maximal d\'essayes!\n");wait(2);*depasse=0;} hi=0; 
	if(*depasse!=0){do{hi+=1;printf("\nNouveau Prenom du visiteur : ");gets(t[i].prenom) ; wx=nonespace(t[i].prenom);}while(hi<3 && wx==0);if(hi>=3 && wx==0){printf("vous avez depasse le nombre maximal d\'essayes!\n");wait(2);*depasse=0;} hi=0; 
	if(*depasse!=0){do{hi+=1;printf("\nNouveau Adresse du visiteur: ");gets(t[i].adresse);wx=nonespace(t[i].adresse);}while(hi<3 && wx==0);if(hi>=3 && wx==0){printf("vous avez depasse le nombre maximal d\'essayes!\n");wait(2);*depasse=0;} hi=0; 
	rewind(f) ;	
    for(int m=0;m<x;m++){ 	fprintf(f,"%s %s %d %s %s %d %d %s %d %d %d %d\n",t[m].nom,t[m].prenom,t[m].identifiant,t[m].adresse,t[m].type,t[m].nbr_tot,t[m].nbr_curr,t[m].retardaire,t[m].code1,t[m].code2,t[m].code3,t[m].code4);}
    printf("\nla modification de visiteur a terminee avec succee! et code identifiant= %d ",aux1) ;}} break ;} rewind(f) ;	
}
//////////////////////////////////////
void modifier_document(FILE *f,int test,int z ,int *depasse){ *depasse=1; 
	int i=-1,ii=-1,x=0,hell,com,aux1; char ch5[cte*3],chaine[cte*50];
	rewind(f) ;
	switch(test){
		case 1: 			do{  x+=1;fscanf(f,"%s",ch5);fgets(chaine,2400,f);hell=strcmp(ch5,"fiin3finfinfzeANbBrty");	} while(hell!=0); 
    	rewind(f)  ;break;
		case 2:	        	do{  x+=1;fscanf(f,"%s",ch5);fgets(chaine,2400,f);hell=strcmp(ch5,"fiin3finfinfzeANbBrty");	} while(hell!=0);
	    rewind(f)  ;break;
		case 3:     		do{  x+=1;fscanf(f,"%s",ch5);fgets(chaine,2400,f);hell=strcmp(ch5,"fiin3finfinfzeANbBrty");	} while(hell!=0);
    	rewind(f)  ;break;	
	           }
	struct livre
	{ char type[cte], titre[cte*2],localisation[cte*2], nom_auteur[cte*2],nom_editeur[cte*2],ch0[cte], ch1[cte],ch2[cte],ch3[cte],ch4[cte] ;
      int code,nbr_cop,nbr_tot;	} ;  struct  livre t[x+1] ;
	struct magasine
	{ char type[cte], titre[cte*2],localisation[cte*2],ch0[cte], ch1[cte],ch2[cte],ch3[cte],ch4[cte] ;
     int code,nbr_cop,nbr_tot;	} ;  struct  magasine t1[x+1] ;
		struct article
	{ char type[cte], titre[cte*2],localisation[cte*2],nom_auteur[cte*2] ,ch0[cte], ch1[cte],ch2[cte],ch3[cte],ch4[cte];
     int code,nbr_cop,nbr_tot;	} ;  struct  article t2[x +1] ; int hi=0;
switch( test) {
	case 1 :
	rewind(f) ;
	do{ i+=1;  fscanf(f,"%s %s %s %d %d %s %s %d %s %s %s %s %s ",t[i].type,t[i].titre,t[i].localisation,&t[i].code,&t[i].nbr_cop,t[i].nom_auteur,t[i].nom_editeur,&t[i].nbr_tot,t[i].ch0,t[i].ch1,t[i].ch2,t[i].ch3,t[i].ch4);   aux1=t[i].code;
	  }   while(z!=t[i].code && i<x );rewind(f) ; //printf("\n pos de l\'element=  %d\n",i);
	do{ ii+=1;   fscanf(f,"%s %s %s %d %d %s %s %d %s %s %s %s %s ",t[ii].type,t[ii].titre,t[ii].localisation,&t[ii].code,&t[ii].nbr_cop,t[ii].nom_auteur,t[ii].nom_editeur,&t[ii].nbr_tot,t[ii].ch0,t[ii].ch1,t[ii].ch2,t[ii].ch3,t[ii].ch4);
      }  while( ii<x );rewind(f) ;
	if(z!=t[i].code ) { printf("choix non trouvee! \n");sleep(2);system("cls");exit(123);} hi=0;
    	printf("\nNouveau  titre  de  livre     : ");scanf("%s",t[i].titre) ;	
		printf("\nNouveau localisation de livre : ");scanf("%s",t[i].localisation) ; 
		printf("\nNom  d\'auteur  de  livre      : ");scanf("%s",t[i].nom_auteur) ; 
		printf("\nNom  d\'editeur  de  livre     : ");scanf("%s",t[i].nom_editeur) ;
	rewind(f) ;	
    for(int i=0;i<x;i++)  fprintf(f,"%s   %s   %s   %d   %d   %s   %s   %d   %s  %s  %s  %s  %s\n",t[i].type,t[i].titre,t[i].localisation,t[i].code,t[i].nbr_cop,t[i].nom_auteur,t[i].nom_editeur,t[i].nbr_tot,t[i].ch0,t[i].ch1,t[i].ch2,t[i].ch3,t[i].ch4);
    printf("\nla modification de livre \"%s\" a terminee avec succee! et sont code est %d \n",t[i].titre,aux1) ;
	 break ; 
	case 2 :
	do{ i+=1;   fscanf(f,"%s %s %s %d %d %d %s %s %s %s %s",t1[i].type,t1[i].titre,t1[i].localisation,&t1[i].code,&t1[i].nbr_cop,&t1[i].nbr_tot,t1[i].ch0,t1[i].ch1,t1[i].ch2,t1[i].ch3,t1[i].ch4); aux1=t1[i].code;
	  }   while(z!=t1[i].code && i<x );rewind(f) ;
	do{ ii+=1;  fscanf(f,"%s %s %s %d %d %d %s %s %s %s %s",t1[ii].type,t1[ii].titre,t1[ii].localisation,&t1[ii].code,&t1[ii].nbr_cop,&t1[ii].nbr_tot,t1[ii].ch0,t1[ii].ch1,t1[ii].ch2,t1[ii].ch3,t1[ii].ch4);
   	  }   while( ii<x );rewind(f) ; 
	if(z!=t1[i].code ) { printf("choix non trouvee! \n");sleep(2);system("cls");}hi=0; // adherant existe ou non: à changée à la fin
    	printf("\nNouveau titre de magasine        : ");scanf("%s",t1[i].titre) ;
		printf("\nNouveau localisation de magasine : ");scanf("%s",t1[i].localisation) ;
	rewind(f) ;	
    for(int i=0;i<x;i++)  fprintf(f,"%s   %s   %s   %d   %d   %d    %s   %s   %s   %s   %s\n",t1[i].type,t1[i].titre,t1[i].localisation,t1[i].code,t1[i].nbr_cop,t1[i].nbr_tot,t1[i].ch0,t1[i].ch1,t1[i].ch2,t1[i].ch3,t1[i].ch4);
    printf("\nla modification de magasine \"%s\" a terminee avec succee! et sont code est %d \n",t1[i].titre,aux1) ;
	 break ; 
	case 3 :	
	do{ i+=1;   fscanf(f,"%s %s %s %d %d %s  %d",t2[i].type,t2[i].titre,t2[i].localisation,&t2[i].code,&t2[i].nbr_cop,t2[i].nom_auteur,&t2[i].nbr_tot);
 	  }   while(z!=t2[i].code && i<x );rewind(f) ;
	do{ ii+=1;  fscanf(f,"%s   %s   %s   %d   %d    %s   %d %s %s %s %s %s ",t2[ii].type,t2[ii].titre,t2[ii].localisation,&t2[ii].code,&t2[ii].nbr_cop,t2[ii].nom_auteur,&t2[ii].nbr_tot,t2[ii].ch0,t2[ii].ch1,t2[ii].ch2,t2[ii].ch3,t2[ii].ch4);
      }   while( ii<x );rewind(f) ;
	if(z!=t2[i].code ) { printf("choix non trouvee! \n");sleep(1);system("cls");exit(123);}hi=0; // adherant existe ou non: à changée à la fin
    	printf("\nNouveau   titre  de  l\'article    : ");scanf("%s",t2[i].titre) ;
		printf("\nNouveau localisation de l\'article  : ");scanf("%s",t2[i].localisation) ;
		printf("\nNom   d\'auteur  de  l\'article     : ");scanf("%s",t2[i].nom_auteur) ;
	rewind(f) ;	
    for(int i=0;i<x;i++)  fprintf(f,"%s   %s   %s   %d   %d   %s    %d   %s  %s  %s   %s  %s\n",t2[i].type,t2[i].titre,t2[i].localisation,t2[i].code,t2[i].nbr_cop,t2[i].nom_auteur,t2[i].nbr_tot,t2[i].ch0,t2[i].ch1,t2[i].ch2,t2[i].ch3,t2[i].ch4);
    printf("\nla modification de l\'article \"%s\" a terminee avec succee! et sont code est %d \n",t2[i].titre,aux1) ;
	break ; 	}
}
//////////////////////////////////////
void supprimer_document(FILE *f, FILE *pp,int test,int z){ 
	int i=-1,fd,ii=-1,x=0,hell,com,aux1,hb; char ch5[cte*2],chaine[cte*50];	
	switch(test){
		case 1:		do{  x++;fscanf(f,"%s",ch5);fgets(chaine,2499,f);hell=strcmp(ch5,"fiin3finfinfzeANbBrty");   	} while(hell!=0);  
	rewind(f) ; break;
		case 2: 	do{  x++;fscanf(f,"%s",ch5);fgets(chaine,2499,f);hell=strcmp(ch5,"fiin3finfinfzeANbBrty");   	} while(hell!=0);
	rewind(f) ; break;
		case 3:	    do{  x++;fscanf(f,"%s",ch5);fgets(chaine,2499,f);hell=strcmp(ch5,"fiin3finfinfzeANbBrty");     	} while(hell!=0);
	rewind(f) ;	break;
            	}
		struct livre
	{ char type[cte], titre[cte*2],localisation[cte*2], nom_auteur[cte*2],nom_editeur[cte*2],ch0[cte], ch1[cte],ch2[cte],ch3[cte],ch4[cte] ;
      int code,nbr_cop,nbr_tot;	} ; 
	   struct  livre t[x+2] ;
		struct magasine
	{ char type[cte], titre[cte*2],localisation[cte*2],ch0[cte], ch1[cte],ch2[cte],ch3[cte],ch4[cte] ;
     int code,nbr_cop,nbr_tot;
	} ;  struct  magasine t1[x+2]  ;
		struct article
	{ char type[cte], titre[cte*2],localisation[cte*2],nom_auteur[cte*2] ,ch0[cte], ch1[cte],ch2[cte],ch3[cte],ch4[cte];
     int code,nbr_cop,nbr_tot;
	} ;  struct  article t2[x +2] ;	
	int r,s,q,u,v,w;
switch( test) {
	case 1 :rewind(f) ;	rewind(pp); fscanf(pp,"%d %d %d %d %d %d ",&u,&v,&w,&r,&s,&q);rewind(pp); 
	if (u>0){ 	
	do{ i+=1; fd=i;   fscanf(f,"%s %s %s %d %d %s %s %d %s %s %s %s %s ",t[i].type,t[i].titre,t[i].localisation,&t[i].code,&t[i].nbr_cop,t[i].nom_auteur,t[i].nom_editeur,&t[i].nbr_tot,t[i].ch0,t[i].ch1,t[i].ch2,t[i].ch3,t[i].ch4);	aux1=t[i].nbr_cop; 
	}while(z!=t[i].code && i<x );rewind(f) ;  
	do{ ii+=1;    fscanf(f,"%s %s %s %d %d %s %s %d %s %s %s %s %s ",t[ii].type,t[ii].titre,t[ii].localisation,&t[ii].code,&t[ii].nbr_cop,t[ii].nom_auteur,t[ii].nom_editeur,&t[ii].nbr_tot,t[ii].ch0,t[ii].ch1,t[ii].ch2,t[ii].ch3,t[ii].ch4);
   	}while( ii<x );rewind(f) ; 	
	if(z!=t[fd].code) { printf("choix non trouvee! \n");exit(404);} 
	u=u-aux1;fprintf(pp,"%d \n%d \n%d \n%d \n%d \n%d \n ",u,v,w,r,s,q);rewind(pp);
    for(int i=0;i<x;i++) { if(i==fd) continue ; 	 fprintf(f,"%s   %s   %s   %d   %d   %s   %s   %d   %s  %s  %s  %s  %s\n",t[i].type,t[i].titre,t[i].localisation,t[i].code,t[i].nbr_cop,t[i].nom_auteur,t[i].nom_editeur,t[i].nbr_tot,t[i].ch0,t[i].ch1,t[i].ch2,t[i].ch3,t[i].ch4);         }
    printf("\nla suppression de livre \"%s\" a terminee avec succee! \n",t[i].titre) ; }else printf("vous n'avez aucun livre de\'s le debut \2\n");
	break ; 
	case 2 :rewind(f) ; 	rewind(pp); fscanf(pp,"%d %d %d %d %d %d",&u,&v,&w,&r,&s,&q);rewind(pp);// printf("\nv=%d|||||||||||\n",v);
	if (v>0){
	do{ i+=1;   fscanf(f,"%s %s %s %d %d %d %s %s %s %s %s",t1[i].type,t1[i].titre,t1[i].localisation,&t1[i].code,&t1[i].nbr_cop,&t1[i].nbr_tot,t1[i].ch0,t1[i].ch1,t1[i].ch2,t1[i].ch3,t1[i].ch4);   hell=t1[i].nbr_cop; 
	}   while(z!=t1[i].code && i<x );rewind(f) ; fd=i;
	do{ ii+=1;  fscanf(f,"%s %s %s %d %d %d %s %s %s %s %s",t1[ii].type,t1[ii].titre,t1[ii].localisation,&t1[ii].code,&t1[ii].nbr_cop,&t1[ii].nbr_tot,t1[ii].ch0,t1[ii].ch1,t1[ii].ch2,t1[ii].ch3,t1[ii].ch4);
   	}   while( ii<x );rewind(f) ;
	if(z!=t1[i].code) { printf("choix non trouvee! \n");exit(404);} // adherant existe ou non: à changée à la fin
    v=v-hell;fprintf(pp,"%d \n%d \n%d \n%d \n%d \n%d \n",u,v,w,r,s,q);rewind(pp);
    for(int i=0;i<x;i++) { if (fd==i) continue;	fprintf(f,"%s   %s   %s   %d   %d   %d    %s   %s   %s   %s   %s\n",t1[i].type,t1[i].titre,t1[i].localisation,t1[i].code,t1[i].nbr_cop,t1[i].nbr_tot,t1[i].ch0,t1[i].ch1,t1[i].ch2,t1[i].ch3,t1[i].ch4);	}
    printf("\nla suppression de magasine \"%s\" a terminee avec succee! \n",t1[i].titre) ; } else printf("vous n'avez aucune magasine de\'s le debut \2\n");
	 break ; 
	case 3 : rewind(f) ; rewind(pp); fscanf(pp,"%d %d %d %d %d %d",&u,&v,&w,&r,&s,&q);rewind(pp); //printf("\nw=%d |||||||||||||\n",w);
	if(w>0){
	do{ i+=1;  fscanf(f,"%s %s %s %d %d %s  %d %s %s %s %s %s ",t2[i].type,t2[i].titre,t2[i].localisation,&t2[i].code,&t2[i].nbr_cop,t2[i].nom_auteur,&t2[i].nbr_tot,t2[i].ch0,t2[i].ch1,t2[i].ch2,t2[i].ch3,t2[i].ch4);   hb=t2[i].nbr_cop; 
	}   while(z!=t2[i].code && i<x );rewind(f) ; fd=i;
	do{ ii+=1;  fscanf(f,"%s   %s   %s   %d   %d    %s   %d %s %s %s %s %s ",t2[ii].type,t2[ii].titre,t2[ii].localisation,&t2[ii].code,&t2[ii].nbr_cop,t2[ii].nom_auteur,&t2[ii].nbr_tot,t2[ii].ch0,t2[ii].ch1,t2[ii].ch2,t2[ii].ch3,t2[ii].ch4); 
    }   while( ii<x );rewind(f) ;
	if(z!=t2[i].code) { printf("choix non trouvee! \n");exit(404);} // adherant existe ou non: à changée à la fin
    w=w-hb; fprintf(pp,"%d \n%d \n%d \n%d \n%d \n%d \n",u,v,w,r,s,q);rewind(pp);
    for(int i=0;i<x;i++) { if(i==fd) continue;	fprintf(f,"%s   %s   %s   %d   %d   %s    %d   %s  %s  %s   %s  %s\n",t2[i].type,t2[i].titre,t2[i].localisation,t2[i].code,t2[i].nbr_cop,t2[i].nom_auteur,t2[i].nbr_tot,t2[i].ch0,t2[i].ch1,t2[i].ch2,t2[i].ch3,t2[i].ch4);	}
    printf("\nla suppression de l\'article \"%s\" a terminee avec succee!  \n",t2[i].titre) ;}else printf("vous n'avez aucun article de\'s le debut \2\n");
	 break ; 	}
} 
//////////////////////////////////////
void supprimer_adherant(FILE *f,FILE *pp,int test,int z){ 
	int i=-1,ii=-1,x=0,hell,com,bn,aux1,aux2,aux3,aux4,aux5,aux6,aux7,aux8,a; char ch1[cte*2],ch2[cte*2],ch3[cte*2],ch4[cte*2],ch5[cte*2],chaine[cte*50],c[]="non";
		do{  x++; fscanf(f,"%s",ch5);  fgets(chaine,2499,f);       hell=strcmp(ch5,"fiin3finfinfzeANbBrty");	}while(hell!=0 && x<20000);	rewind(f) ;// printf("nbr de ligne: %d \n",x-1);	
	struct etudiant
	{ char nom[cte], prenom[cte*2],adresse[cte*2], type[cte], retardaire[5] ;
      int identifiant, nbr_tot, nbr_curr , code1,code2, code3, code4 ;	} ;
	struct  etudiant t[x+1] ; 	int u,v,w,r,s,q;
	do{ i+=1;
    fscanf(f,"%s %s %d %s %s %d %d %s %d %d %d %d",t[i].nom,t[i].prenom,&t[i].identifiant,t[i].adresse,t[i].type,&t[i].nbr_tot,&t[i].nbr_curr,t[i].retardaire,&t[i].code1,&t[i].code2,&t[i].code3,&t[i].code4);com=strcmp(t[i].nom,""); if (com==0) break;
    aux1=t[i].identifiant; 
	}   while(z!=t[i].identifiant && i<x );rewind(f) ;
	do{ ii+=1;
    fscanf(f,"%s %s %d %s %s %d %d %s %d %d %d %d",t[ii].nom,t[ii].prenom,&t[ii].identifiant,t[ii].adresse,t[ii].type,&t[ii].nbr_tot,&t[ii].nbr_curr,t[ii].retardaire,&t[ii].code1,&t[ii].code2,&t[ii].code3,&t[ii].code4);com=strcmp(t[ii].nom,""); if (com==0) break;
    }   while( ii<x );rewind(f) ; int hi=1 ;
switch( test) {
	case 1 :rewind(pp); fscanf(pp,"%d %d %d %d %d %d ",&u,&v,&w,&r,&s,&q);rewind(pp);
	if(r>0){   
	rewind(pp); 	fprintf(pp,"%d \n%d \n%d \n%d \n%d \n%d \n ",u,v,w,r-1,s,q);rewind(pp);
    for(int m=0;m<x;m++){ if(m==i) continue;		fprintf(f,"%s %s %d %s %s %d %d %s %d %d %d %d\n",t[m].nom,t[m].prenom,t[m].identifiant,t[m].adresse,t[m].type,t[m].nbr_tot,t[m].nbr_curr,t[m].retardaire,t[m].code1,t[m].code2,t[m].code3,t[m].code4);     }
    printf("\nla suppression de l\'etudiant\"%s %s\" se termine avec succee!  \n",t[i].nom,t[i].prenom) ; 
        	} else  printf("aucun etudiant existe dès le debut! \n"); 
	break ; 
	case 2 :hi=1; rewind(pp); fscanf(pp,"%d %d %d %d %d %d ",&u,&v,&w,&r,&s,&q);rewind(pp);
	if(s>0){
    rewind(pp); fprintf(pp,"%d \n%d \n%d \n%d \n%d \n%d \n ",u,v,w,r,s-1,q);rewind(pp);	rewind(f) ;	
    for(int m=0;m<x;m++){ if(m==i) continue;	fprintf(f,"%s %s %d %s %s %d %d %s %d %d %d %d\n",t[m].nom,t[m].prenom,t[m].identifiant,t[m].adresse,t[m].type,t[m].nbr_tot,t[m].nbr_curr,t[m].retardaire,t[m].code1,t[m].code2,t[m].code3,t[m].code4);}
    printf("\nla suppression de l\'enseignant \"%s %s\" se termine avec succee! \n",t[i].nom,t[i].prenom) ; 
           } else printf("aucun enseignant existe des le debut! \n");
	break ;
	case 3 :hi=1; rewind(pp); fscanf(pp,"%d %d %d %d %d %d ",&u,&v,&w,&r,&s,&q);rewind(pp);
	if(q>0){	
   	rewind(pp); fprintf(pp,"%d \n%d \n%d \n%d \n%d \n%d \n ",u,v,w,r,s,q-1);rewind(pp);	rewind(f) ;	
    for(int m=0;m<x;m++){ if(m==i) continue;	fprintf(f,"%s %s %d %s %s %d %d %s %d %d %d %d\n",t[m].nom,t[m].prenom,t[m].identifiant,t[m].adresse,t[m].type,t[m].nbr_tot,t[m].nbr_curr,t[m].retardaire,t[m].code1,t[m].code2,t[m].code3,t[m].code4);}
    printf("\nla suppression de visiteur \"%s %s\" se termine avec succee! \n",t[i].nom,t[i].prenom) ; 
           } else printf("aucun visiteur existe de\'s le debut! \n");
	break ; }	
}
///////////////////////////////////////
void adherant_retardaire(FILE *f, char *esm){
	int i=-1,x,hell,final,com=0,a,b,c,d,e,g,h ; 
	char chaine[cte*20],ch1[cte],ch2[cte],ch3[cte],ch4[cte],ch5[cte] ;
	do{i+=1;
	}while(fgets(chaine,999,f)!=NULL); final=i; i=-1 ;
	rewind(f) ;
	do{i+=1; fscanf(f," %s ",ch3) ; fgets(chaine,999,f); hell=strcmp(ch3,"fiin3finfinfzeANbBrty");
	  }while(hell!=0 && i<final); rewind(f); x=i; i=-1;
	do  {i+=1; fscanf(f,"%s %s %d %s %s %d %d %s %d %d %d %d ",ch1,ch2,&a,ch3,ch4,&b,&c,ch5,&d,&e,&g,&h) ;
	hell=strcmp(ch5,"oui"); if(hell==0) { com+=1;	printf("%s %s %s (%d) est RETARDAIRE! \nLe(s) code(s) de livre(s) qu\'il a empruntee: ",esm,ch1,ch2,a);
    if(d!=0) printf("%d",d);if(e!=0) printf(", %d",e);if(g!=0) printf(", %d",g);if(h!=0) printf(", %d ",h);printf("\n      ------------\n");   } 
    	}while(i<x); rewind(f);
	if(com==0)  printf("Liste Vide..\nPas des RETARDAIRE avec ce type! \n",esm); 	
}
///////////////////////////////////////
void doc_c_n(FILE *f,int test, doc *dc,int *deb){
	int a,b,c,d,e,ff,g,h,x=0,y=0 ,hell; char ch1[cte*2],ch2[cte*2],ch3[cte*2],ch4[cte*2],ch5[cte*2],ch6[cte*2],ch7[cte*2],ch8[cte*2],ch9[cte*2],chaine[cte*50] ; 
    do{  x++;	} while((fgets(chaine,2499,f))!=NULL);	rewind(f) ;
		switch( test) {
	case 1 : 	do{ y++; fscanf(f,"%s %s %s %d %d %s %s  %d ",ch1,ch2,ch3,&a,&b,ch4,ch5,&c) ;	fgets(chaine,2499,f);dc[*deb].code=a;dc[*deb].nb=c;strcpy(dc[*deb].type,ch1); *deb+=1;hell=strcmp(ch1,"fiin3finfinfzeANbBrty"); }	   while(hell!=0 && y<x );
	break;
    case 2 : 	do{ y++; fscanf(f,"%s %s %s %d %d %d ",ch1,ch2,ch3,&a,&b,&c) ;	fgets(chaine,2499,f);dc[*deb].code=a;dc[*deb].nb=c;strcpy(dc[*deb].type,ch1); *deb+=1; hell=strcmp(ch1,"fiin3finfinfzeANbBrty"); }	   while(hell!=0 && y<x );
	break ;
    case 3 : 	do{ y++; fscanf(f,"%s %s %s %d %d %s  %d ",ch1,ch2,ch3,&a,&b,ch4,&c) ;	fgets(chaine,2499,f);dc[*deb].code=a;dc[*deb].nb=c;strcpy(dc[*deb].type,ch1); *deb+=1; hell=strcmp(ch1,"fiin3finfinfzeANbBrty"); }	   while(hell!=0 && y<x );
	break ;
	default:  break ;   }		
}
///////////////////////////
void trie_doc(doc *dc,int n)
{ int i=-1,j=-1;do{ j++;do{i++;
  if(dc[i].nb<dc[i+1].nb) {
  	aax=dc[i];
  	dc[i]=dc[i+1];
  	dc[i+1]=aax;          }
}while(i<n-2) ;  }while(j==n) ; 	
}
////////////////////////////////////////
int main(int argc, char *argv[]) {
  FILE *kam,*f,*k ;int n,u,code,identif;long long int e1,e2;  
  char c[cte],chaine[cte*5],ch[cte*5],c1[cte],c2[cte]; time_t temp=time(0) ; char *cha=ctime(&temp) ;
  kam=fopen("fichiers/kam.txt","r");
  fscanf(kam,"%d",&n) ;fclose(kam); // nbr des documents empruntees
  printf("Mise a jour de logiciel..\n"); sleep(1); //seconds
  ////// *1*
  for(int i=0;i<=n;i++){u=i ; sprintf(c,"%d",u) ; char ct[cte*5]="" ;
  strcpy(ct,"fichiers/dossier-emprunt/etudiant/") ;
				 strcat(ct,c);
				 strcat(ct,".txt");
	             k=fopen(ct,"r");
    if(k!= NULL){
  	fscanf(k,"%d %d ",&code,&identif) ; fgets(chaine,1000,k) ;
  	wa9t(cha,&e1); wa9t(chaine,&e2) ; 
  	if((e1-e2 )>(10080*2)) { 
	                   f=fopen("fichiers/etudiant.txt","r+");
  	                   modif_adhe(f,identif,code) ; fclose(f) ;
  	                   strcpy(ch,"fichiers/adherant-retardaire/etudiant/");
  	                   sprintf(c1,"%d",identif);sprintf(c2,"%d",code);strcat(c1,c2) ;strcat(ch,c1) ;strcat(ch,".txt") ;
  	                   f=fopen(ch,"w") ; fclose(f) ;
	                       }  }else{printf("fichier n\'existe pas! "); fclose(k) ;	} } 	
 /////// *2*
 for(int i=0;i<=n;i++){u=i ; sprintf(c,"%d",u) ; char ct[cte*5]="" ;
  strcpy(ct,"fichiers/dossier-emprunt/enseignant/") ;
				 strcat(ct,c);
				 strcat(ct,".txt");
	             k=fopen(ct,"r");
  if(k!= NULL){
  	fscanf(k,"%d %d ",&code,&identif) ; fgets(chaine,1000,k) ;
  	wa9t(cha,&e1); wa9t(chaine,&e2) ; 
  	if((e1-e2 )>(10080*4)) { 
	                   f=fopen("fichiers/enseignant.txt","r+");
  	                   modif_adhe(f,identif,code) ; fclose(f) ;
  	                   strcpy(ch,"fichiers/adherant-retardaire/enseignant/");
  	                   sprintf(c1,"%d",identif);sprintf(c2,"%d",code);strcat(c1,c2) ;strcat(ch,c1) ;strcat(ch,".txt") ;
  	                   f=fopen(ch,"w") ; fclose(f) ;
	                       }                } fclose(k) ;	  	                      }
 /////// *3*
 for(int i=0;i<=n;i++){u=i ; sprintf(c,"%d",u) ; char ct[cte*5]="" ;
  strcpy(ct,"fichiers/dossier-emprunt/visiteur/") ;
				 strcat(ct,c);
				 strcat(ct,".txt");
	             k=fopen(ct,"r");
  if(k!= NULL){
  	fscanf(k,"%d %d ",&code,&identif) ; fgets(chaine,1000,k) ;
  	wa9t(cha,&e1); wa9t(chaine,&e2) ; 
  	if((e1-e2 )>(10080)) { 
	                   f=fopen("fichiers/visiteur.txt","r+");
  	                   modif_adhe(f,identif,code) ; fclose(f) ;
  	                   strcpy(ch,"fichiers/adherant-retardaire/visiteur/");
  	                   sprintf(c1,"%d",identif);sprintf(c2,"%d",code);strcat(c1,c2) ;strcat(ch,c1) ;strcat(ch,".txt") ;
  	                   f=fopen(ch,"w") ; fclose(f) ;
	                       }  } fclose(k) ;	  	
                       }	
 /////// fin mise à jour /////////
  system("cls");					  	
  jump:
 printf("1-ajouter un adherant:\n2-ajouter un document:\n3-rechercher un adherant:\n4-rechercher un document:\n");
 
 printf("5-liste des adhrants retardataires:\n6-liste des documents emprunts:\n7-supprimer un adherant:\n8-supprimer un document:\n");
 printf("9-modifier un adherant:\n10-modifier un document:\n11-emprunter un document:\n12-retourner un document:\n13-Quitter!\nVOTRE CHOIX: ");
 int choixx;scanf("%d",&choixx); system("cls") ;
                                //+++++++++++++++
         if(choixx==1){         
 jum1:        FILE *p,*f,*pp;int test,test2,depasse ;
p=fopen("fichiers/information.txt","r+");
pp=fopen("fichiers/information2.txt","r+");
if (pp==NULL) { printf("Un erreur se produit!\n..fichier information2 non trouvee! \n"); exit(404) ; }
if (p==NULL) { printf("Un erreur se produit!\n..fichier information non trouvee! \n"); exit(404) ; }  int hi=0;
do{hi+=1; printf("(%d):1-1: ajouter un etudiant: \n    1-2: ajouter un enseignant: \n    1-3: ajouter un visiteur: \n    1-4:Retour: \n",hi);scanf("%d",&test) ;system("cls");}while((test<1 || test>4 )&& hi<3); if(hi>=3 && (test<1 || test>4 )) {printf("vous avez depasse le nombre d\'essayés!\n");wait(3);system("cls");goto jump ;}
 char etu[]="etudiant", ens[]="enseignant", vis[]="visiteur" ;
switch( test) {
	case 1 :f=fopen("fichiers/etudiant.txt","r+");ajout_adherant(f,p,pp,etu,&depasse);if(depasse==0) {system("cls");goto jum1;} break ;
	case 2 :f=fopen("fichiers/enseignant.txt","r+");ajout_adherant(f,p,pp,ens,&depasse);if(depasse==0) {system("cls");goto jum1;} break ;
	case 3 :f=fopen("fichiers/visiteur.txt","r+");ajout_adherant(f,p,pp,vis,&depasse) ;if(depasse==0) {system("cls");goto jum1;} break ;
	default:wait(2); system("cls");goto jump; break ; }
fclose(f);fclose(p) ; fclose(pp);
int ijaba; printf("\n\n1   - Revient a la page principale: \n2   - Retour : \nelse- Quitter: \n");scanf("%d",&ijaba);if(ijaba==1){system("cls"); goto jump;} else if(ijaba==2){ system("cls") ; goto jum1;} else {wait(2);system("cls");printf("\t\t\t\t~MERCI P\3UR VOTRE ATTENTI\3N !~ \n\nAu revoir..");exit(010);} 
 	                           
								 //+++++++++++++++
 }  else if(choixx==2){        
jum2:  FILE *p,*f,*pp;int test,test2,hi=0 ,depasse;
p=fopen("fichiers/information.txt","r+");
pp=fopen("fichiers/information2.txt","r+");
if (pp==NULL) { printf("Un erreur se produit!\n..fichier information2 non trouvee! \n"); exit(404) ; }
if (p ==NULL) { printf("Un erreur se produit!\n..fichier information non trouvee! \n"); exit(404) ; }  
do{hi+=1;printf("(%d):2-1: ajouter un livre: \n    2-2: ajouter une magasine: \n    2-3: ajouter un article: \n    2-4:Retour: \n",hi);scanf("%d",&test) ;system("cls");}while((test<1 || test>4 )&& hi<3); if(hi>=3 && (test<1 || test>4 )) {printf("vous avez depassee le nombre d\'essayes!\n");wait(3);system("cls");goto jump ;}
switch( test) {	
	case 1 :f=fopen("fichiers/livre.txt","r+");ajout_livre(f,p,pp,&depasse);if(depasse==0) {system("cls");goto jum2;} break ;
	case 2 :f=fopen("fichiers/magasine.txt","r+");ajout_magasine(f,p,pp,&depasse);if(depasse==0) {system("cls");goto jum2;} break ;
	case 3 :f=fopen("fichiers/article.txt","r+");ajout_article(f,p,pp,&depasse) ;if(depasse==0) {system("cls");goto jum2;} break ;
	default: wait(2); system("cls");goto jump; break ;}
fclose(f);fclose(p) ;fclose(pp);
int ijaba; printf("\n\n1   - Revient a la page principale: \n2   - Retour : \nelse- Quitter: \n");scanf("%d",&ijaba);if(ijaba==1){system("cls"); goto jump;} else if(ijaba==2){ system("cls") ; goto jum2;} else {wait(2);system("cls");printf("\t\t\t\t~MERCI P\3UR VOTRE ATTENTI\3N !~ \n\nAu revoir..");exit(010);} 

 	                            //+++++++++++++++
 }  else if(choixx==3){
jum3: 	FILE *f;int test,test2,code,me=0,mee=0,meee=0,limite1 ,hi=0 ; char nom[cte*2] ;

do{ hi+=1;printf("(%d):3-1-recherche avec le code identifiant:\n    3-2-recherche avec le \"nom\" de l\'adherant: \n    3-3-Retour: \n",hi);scanf("%d",&test2) ;system("cls");}while((test2<1 || test2>3 )&& hi<3); if(hi>=3 && (test2<1 || test2>3 )) {printf("vous avez depassee le nombre d\'essayes!\n");wait(3);system("cls");goto jump ;}
if(test2==1){ int ho=0;
do{ho+=1; printf("%d:donner leur code identifiant: \n",ho);scanf("%d",&code); system("cls");
f=fopen("fichiers/etudiant.txt","r");recherche_adherant(f,code,1,&me);fclose(f) ;
f=fopen("fichiers/enseignant.txt","r");recherche_adherant(f,code,2,&mee) ;fclose(f) ;
f=fopen("fichiers/visiteur.txt","r");recherche_adherant(f,code,3,&meee); fclose(f) ;
  }while(me==0 && mee==0 && meee==0 && ho<3);ho--; if((me==0 && mee==0 && meee==0 && ho<3)){ printf("\nCe adherant n\'existe pas!\n")  ;wait(2);goto jum3; }       
            }
else if(test2==2){ int ho=0;
    do{ho+=1; printf("%d:donner le \"nom\" de l\'adherant: \n",ho);scanf("%s",nom); system("cls");
	f=fopen("fichiers/etudiant.txt","r");	if (f == NULL) {printf("fichier etudiant non trouvee!\n"); exit(404) ;}	rewind(f); limit(f,&limite1) ; rewind(f) ;
	for(int i=0;i<=limite1;i++) recherche2_adherant(f,nom,1,&me);fclose(f) ;
	f=fopen("fichiers/enseignant.txt","r");	if (f == NULL) {printf("fichier etudiant non trouvee!\n"); exit(404) ;}	rewind(f); limit(f,&limite1) ; rewind(f) ;
	for(int i=0;i<=limite1;i++) recherche2_adherant(f,nom,2,&mee) ;fclose(f) ;
	f=fopen("fichiers/visiteur.txt","r"); 	if (f == NULL) {printf("fichier etudiant non trouvee!\n"); exit(404) ;}	rewind(f); limit(f,&limite1) ; rewind(f) ;
	for(int i=0;i<=limite1;i++) recherche2_adherant(f,nom,3,&meee); fclose(f) ;
	}while(meee==0 && mee==0 && me==0 && ho<3); ho--; if((me==0 && mee==0 && meee==0 && ho<3)){printf("\nCe adherant n\'existe pas!\n")  ;wait(2) ;system("cls");goto jum3; }
} else {wait(2); system("cls");goto jump;}
int ijaba; printf("\n\n1   - Revient a la page principale: \n2   - Retour : \nelse- Quitter: \n");scanf("%d",&ijaba);if(ijaba==1){system("cls"); goto jump;} else if(ijaba==2){ system("cls") ; goto jum3;} else {wait(2);system("cls");printf("\t\t\t\t~MERCI P\3UR VOTRE ATTENTI\3N !~ \n\nAu revoir..");exit(010);} 

 	                             //+++++++++++++++
 }  else if(choixx==4){
jum4: 	FILE *f;int test,code,hi=0, le=0,lee=0,leee=0,test2,limite ;char titre[cte*2] ;
	do{hi+=1; printf("\n(%d):4-1-recherche avec le code de document:\n    4-2-recherche avec le \"titre\" : \n    4-3-Retour: \n",hi) ;scanf("%d",&test2) ;system("cls");}while((test2<1 || test2>3 ) && hi<3); if( hi>=3 && (test2<1 || test2>3 ) ) {printf("vous avez depasse le nombre d\'essayés!\n");wait(3);system("cls");goto jump ;}
  if(test2==1){ int ho=0;do{ ho+=1;
    printf("%d:donner leur code identifiant: ",ho);scanf("%d",&code); system("cls");
	f=fopen("fichiers/livre.txt","r");	if (f == NULL) {printf("fichier livre non trouvee!\n"); exit(404) ;}recherche_document(f,code,1,&le); fclose(f) ;
	f=fopen("fichiers/magasine.txt","r");if (f == NULL) {printf("fichier magasine non trouvee!\n"); exit(404) ;}recherche_document(f,code,2,&lee) ;fclose(f) ; 
	f=fopen("fichiers/article.txt","r");if (f == NULL) {printf("fichier article non trouvee!\n"); exit(404) ; }recherche_document(f,code,3,&leee);fclose(f) ;
    }while(leee==0 && lee==0 && le==0 && ho<3); ho--; if(le==0 && lee==0 && leee==0 && ho<3) {printf("\ndocument non trouvee!\n")  ;wait(2);goto jum4; }
    }else if(test2==2){  int ho=0;do{ho+=1;	printf("%d:donner le titre de document: ",ho);scanf("%s",titre); system("cls");
  	    f=fopen("fichiers/livre.txt","r");		if (f == NULL) {printf("fichier livre non trouvee!\n"); exit(404) ;}	rewind(f); limit(f,&limite) ; rewind(f) ;
	for(int i=0; i<=limite;i++){	recherche2_document(f,limite,titre,1,&le);}  fclose(f) ;
	  	f=fopen("fichiers/magasine.txt","r");		if (f == NULL) {printf("fichier livre non trouvee!\n"); exit(404) ;}	rewind(f); limit(f,&limite) ; rewind(f) ;
	for(int i=0; i<=limite;i++){	recherche2_document(f,limite,titre,2,&lee);	}  fclose(f) ;
		f=fopen("fichiers/article.txt","r");		if (f == NULL) {printf("fichier livre non trouvee!\n"); exit(404) ;}	rewind(f); limit(f,&limite) ; rewind(f) ;
	for(int i=0; i<=limite;i++){	recherche2_document(f,limite,titre,3,&leee);	}  fclose(f) ;
  	}while(leee==0 && lee==0 && le==0 && ho<3); ho--; if(le==0 && lee==0 && leee==0 && ho<3) {printf("\ndocument non trouve\1!\n")  ;wait(2);goto jum4; }
  } else { wait(2); system("cls");goto jump;}
  int ijaba; printf("\n\n1   - Revient a la page principale: \n2   - Retour : \nelse- Quitter: \n");scanf("%d",&ijaba);if(ijaba==1){system("cls"); goto jump;} else if(ijaba==2){ system("cls") ; goto jum4;} else {wait(2);system("cls");printf("\t\t\t\t~MERCI P\3UR VOTRE ATTENTI\3N !~ \n\nAu revoir..");exit(010);} 
 	                             //+++++++++++++++
 }  else if(choixx==5){
jum5: 	FILE *f;int test,test2 ,hi=0,ijaba;
//RQ: il faut mettre c'est paramétre comme ça!!!!!!!!!!!
char cc[]="L\'etudiant", vv[]="L\'enseignant", xx[]="Le visiteur" ;
do{hi+=1;printf("(%d):5-1: Etudiant(s) Retardaire(s): \n    5-2: Enseignant(s) Retardaire(s): \n    5-3: Visiteur(s) Retardaire(s): \n    5-4:Retour: \n",hi);scanf("%d",&test) ;system("cls");}while((test<1 || test>4 ) && hi<3); if(hi>=3 && (test<1 || test>4 )) {printf("vous avez depasse le nombre d\'essayés!\n");wait(3);system("cls");goto jump ;}
switch( test) {
	case 1 :f=fopen("fichiers/etudiant.txt","r+");adherant_retardaire(f,cc);
	    printf("\n\n1- Revient a la page principale: \n2- Retour : \nelse-Quitter: \n");scanf("%d",&ijaba);if(ijaba==1){system("cls"); goto jump;} else if(ijaba==2){ system("cls") ; goto jum5;} else {system("cls");printf("\t\t\t\t~MERCI P\3UR VOTRE ATTENTI\3N !~ \n\nAu revoir..");exit(010);} break ;
	case 2 :f=fopen("fichiers/enseignant.txt","r+");adherant_retardaire(f,vv); 
		printf("\n\n1- Revient a la page principale: \n2- Retour : \nelse-Quitter: \n");scanf("%d",&ijaba);if(ijaba==1){system("cls"); goto jump;} else if(ijaba==2){ system("cls") ; goto jum5;} else {system("cls");printf("\t\t\t\t~MERCI P\3UR VOTRE ATTENTI\3N !~ \n\nAu revoir..");exit(010);} break ;
	case 3 :f=fopen("fichiers/visiteur.txt","r+");adherant_retardaire(f,xx) ; 
		printf("\n\n1- Revient a la page principale: \n2- Retour : \nelse-Quitter: \n");scanf("%d",&ijaba);if(ijaba==1){system("cls"); goto jump;} else if(ijaba==2){ system("cls") ; goto jum5;} else {system("cls");printf("\t\t\t\t~MERCI P\3UR VOTRE ATTENTI\3N !~ \n\nAu revoir..");exit(010);} break ;
	default:wait(2); system("cls");goto jump; break ;
} fclose(f);   
int iijaba; printf("\n\n1   - Revient a la page principale: \n2   - Retour : \nelse- Quitter: \n");scanf("%d",&iijaba);if(iijaba==1){system("cls"); goto jump;} else if(iijaba==2){ system("cls") ; goto jum5;} else {wait(2);system("cls");printf("\t\t\t\t~MERCI P\3UR VOTRE ATTENTI\3N !~ \n\nAu revoir..");exit(010);} 

 	                             //+++++++++++++++
 }  else if(choixx==6){
jum6:	FILE *f;
     int n,hi=0,naw3[cte*50],ops,test,test2,taille1,taille2,taille3,tailletot,ijaba; n=-1 ; rec tq[cte*50] ;char cxh[cte] ; doc ttc[cte*50] ;
	 do{hi+=1;printf("(%d):6-1-afficher la liste des documents sorties:\n    6-2-afficher la liste des document qu\'ils sont depasse la date limite:\n    6-3-afficher la liste de tous les documents empruntee triee:\n    6-4-Retour: \n",hi); scanf("%d",&test); }while((test<1 || test>4 )&& hi<3); if(hi>=3 && (test<1 || test>4 )){printf("vous avez depasse le nombre d\'essayés!\n");wait(3);system("cls");goto jump ;}
	 if(test==4) {wait(2); system("cls");goto jump;}
	 f=fopen("fichiers/etudiant.txt","r") ;
	 aff_liste_doc(f,tq,&n,test) ; fclose(f)  ;        
	 f=fopen("fichiers/enseignant.txt","r") ;
     aff_liste_doc(f,tq,&n,test) ; fclose(f) ;    
	 f=fopen("fichiers/visiteur.txt","r");
	 aff_liste_doc(f,tq,&n,test) ; fclose(f) ;	 
	 f=fopen("fichiers/livre.txt","r");	if (f == NULL) {printf("fichier non trouvee!\n"); exit(404) ;}
     for(int i=0;i<n;i++){
	 effectuer_document(f,tq[i].co,1,cxh,&ops);   ;if(ops==1) strcpy(tq[i].ty,cxh) ;}
	 fclose(f) ;
	 f=fopen("fichiers/magasine.txt","r");if (f == NULL) {printf("fichier non trouvee!\n"); exit(404) ;} 
	 for(int i=0;i<n;i++){
	 effectuer_document(f,tq[i].co,2,cxh,&ops);   ;if(ops==1) strcpy(tq[i].ty,cxh) ;}	 fclose(f) ;	 
	 f=fopen("fichiers/article.txt","r");if (f == NULL) {printf("fichier non trouvee!\n"); exit(404) ; }
	 for(int i=0;i<n;i++){	 effectuer_document(f,tq[i].co,3,cxh,&ops);   ;if(ops==1) strcpy(tq[i].ty,cxh) ;}
	 fclose(f) ;	 remove_recurrence(tq,&n) ;
     if(test==1 || test==2){ if(test==1) 	 printf("les code des documents empruntees (en cours): \n");
                             else 	 printf("le(s) code(s) de(s) document(s) qu\'ils ont depassee la date limite: \n");
     printf("<code>:<nbr d\'emprunt>:<type>\n");
	 for(int i=0;i<n;i++){	 if(tq[i].co>=5000 && tq[i].co<21000)	printf("<%d>:<      %d      >:<  %s > \n",tq[i].co,tq[i].nb,tq[i].ty) ;	 } int ijaba;
	printf("\n\n1   - Revient a la page principale: \n2   - Retour : \nelse- Quitter: \n");scanf("%d",&ijaba);if(ijaba==1){system("cls"); goto jump;} else if(ijaba==2){ system("cls") ; goto jum6;} else {wait(2);system("cls");printf("\t\t\t\t~MERCI P\3UR VOTRE ATTENTI\3N !~ \n\nAu revoir..");exit(010);} 
    } else if(test==3){   doc dc[cte*50] ; int ddb=0 ; int ijaba;
	f=fopen("fichiers/livre.txt","r");	if (f == NULL) {printf("fichier non trouvee!\n"); exit(404) ;} doc_c_n(f,1,dc,&ddb); fclose(f) ; ddb--;
	f=fopen("fichiers/magasine.txt","r");if (f == NULL) {printf("fichier non trouvee!\n"); exit(404) ;}doc_c_n(f,2,dc,&ddb);fclose(f) ; ddb--;
	f=fopen("fichiers/article.txt","r");if (f == NULL) {printf("fichier non trouvee!\n"); exit(404) ; }doc_c_n(f,3,dc,&ddb);fclose(f) ;ddb--;
    trie_doc(dc,ddb) ; printf("\nles documents triees selon le nombre d\'emprunt totale: \ncode :: nombre :: type \n");
    for(int i=0; i<ddb;i++) printf("%d ::   %d   :: %s\n",dc[i].code,dc[i].nb,dc[i].type) ;
	} 	   printf("\n\n1   - Revient a la page principale: \n2   - Retour : \nelse- Quitter: \n");scanf("%d",&ijaba);if(ijaba==1){system("cls"); goto jump;} else if(ijaba==2){ system("cls") ; goto jum6;} else {wait(2);system("cls");printf("\t\t\t\t~MERCI P\3UR VOTRE ATTENTI\3N !~ \n\nAu revoir..");exit(010);} 

 	                            //++++++++++++++++
 }  else if(choixx==7){
jum7: 	FILE *f,*pp;int hi=0,test ;
pp=fopen("fichiers/information2.txt","r+");
do{hi+=1; printf("Vous avez choisi \"supprimer adherant\".\n\n(%d):1:Retour: \n    2:continuer: \n    CHOIX: ",hi);scanf("%d",&test) ;system("cls");}while((test<1 || test>11 )&& hi<3); if(hi==3 && (test<1 || test>11 )) {printf("vous avez depasse le nombre d\'essayés!\n");wait(2);system("cls");goto jum7;}hi=0;
if(test==1) goto jump; else{system("cls") ; }
int ho=0,code,me,mee,meee;
do{ho+=1; printf("%d:Donner leur code identifiant: \n",ho);scanf("%d",&code); system("cls");
f=fopen("fichiers/etudiant.txt","r");recherche_adherant(f,code,1,&me);fclose(f) ;
f=fopen("fichiers/enseignant.txt","r");recherche_adherant(f,code,2,&mee) ;fclose(f) ;
f=fopen("fichiers/visiteur.txt","r");recherche_adherant(f,code,3,&meee); fclose(f) ;
  }while(me==0 && mee==0 && meee==0 && ho<3);ho--; if((me==0 && mee==0 && meee==0 && ho<3)){ printf("\nCe adherant n\'existe pas!\n")  ;wait(2);goto jum7; }       
      if(me==1) test=4; else if(mee==1) test=2 ;else test=3 ;
printf("\n\n1   -retour:\nelse-continuer:\nVOTRE CHOIX: ");int nfd;scanf("%d",&nfd);
if(nfd==1) {system("cls"); goto jum7;} else{ wait(2);system("cls");
switch( test) {
	case 4 :f=fopen("fichiers/etudiant.txt","r+");supprimer_adherant(f,pp,1,code); break ;
	case 2 :f=fopen("fichiers/enseignant.txt","r+");supprimer_adherant(f,pp,2,code); break ;
	case 3 :f=fopen("fichiers/visiteur.txt","r+");supprimer_adherant(f,pp,3,code) ; break ;
	default: printf("choix non trouvee\1\1!\n"); goto jum7; break ;
} fclose(f); fclose(pp);}
int ijaba; printf("\n\n1   - Revient a la page principale: \n2   - Retour : \nelse- Quitter: \n");scanf("%d",&ijaba);if(ijaba==1){system("cls"); goto jump;} else if(ijaba==2){ system("cls") ; goto jum7;} else {wait(2);system("cls");printf("\t\t\t\t~MERCI P\3UR VOTRE ATTENTI\3N !~ \n\nAu revoir..");exit(010);} 
                               //+++++++++++++++++
 }  else if(choixx==8){
jum8: 	FILE *f,*pp;int test,le,lee,leee,code,test2,hi=0 ;
pp=fopen("fichiers/information2.txt","r+");
do{hi+=1; printf("Vous avez choisi \"supprimer document\".\n\n(%d):1:Retour: \n    2:continuer: \n    CHOIX: ",hi);scanf("%d",&test2) ;system("cls");}while((test2<1 || test2>11 )&& hi<3); if(hi==3 && (test2<1 || test2>11 )) {printf("vous avez depasse le nombre d\'essayés!\n");wait(2);system("cls");goto jum8;}hi=0;
if(test2==1) goto jump; else{system("cls") ; }
int ho=0;do{ ho+=1;
    printf("%d:Donner le code identifiant du document à supprimee: ",ho);scanf("%d",&code); system("cls");
	f=fopen("fichiers/livre.txt","r");	if (f == NULL) {printf("fichier livre non trouvee!\n"); exit(404) ;}recherche_document(f,code,1,&le); fclose(f) ;
	f=fopen("fichiers/magasine.txt","r");if (f == NULL) {printf("fichier magasine non trouvee!\n"); exit(404) ;}recherche_document(f,code,2,&lee) ;fclose(f) ; 
	f=fopen("fichiers/article.txt","r");if (f == NULL) {printf("fichier article non trouvee!\n"); exit(404) ; }recherche_document(f,code,3,&leee);fclose(f) ;
    }while(leee==0 && lee==0 && le==0 && ho<3); ho--; if(le==0 && lee==0 && leee==0 && ho<3) {printf("\ndocument non trouvee!\n")  ;wait(2);goto jum8; }
if(le==1) test=4; else if(lee==1) test=2 ;else test=3 ;
printf("\n\n1   -retour:\nelse-continuer:\nVOTRE CHOIX: ");int nfd;scanf("%d",&nfd);
if(nfd==1) {system("cls"); goto jum8;} else{ wait(2);system("cls");

switch( test) {
	case 4 :f=fopen("fichiers/livre.txt","r+");supprimer_document(f,pp,1,code); break ;
	case 2 :f=fopen("fichiers/magasine.txt","r+");supprimer_document(f,pp,2,code); break ;
	case 3 :f=fopen("fichiers/article.txt","r+");supprimer_document(f,pp,3,code) ; break ;
	default: printf("choix non trouvee!!\n"); break ;
} fclose(f); fclose(pp);}
int ijaba; printf("\n\n1   - Revient a la page principale: \n2   - Retour : \nelse- Quitter: \n");scanf("%d",&ijaba);if(ijaba==1){system("cls"); goto jump;} else if(ijaba==2){ system("cls") ; goto jum8;} else {wait(2);system("cls");printf("\t\t\t\t~MERCI P\3UR VOTRE ATTENTI\3N !~ \n\nAu revoir..");exit(010);} 

 	                            //+++++++++++++++++
 }  else if(choixx==9){
jum9: 	FILE *f;int test,test2,ho=0,depasse ,hi=0;
do{hi+=1; printf("Vous avez choisi \"Modifier adherant\".\n\n(%d):1:Retour: \n    2:continuer: \n    CHOIX: ",hi);scanf("%d",&test2) ;system("cls");}while((test2<1 || test2>11 )&& hi<3); if(hi==3 && (test2<1 || test2>11 )) {printf("vous avez depasse le nombre d\'essayes!\n");wait(2);system("cls");goto jum9;}hi=0;
if(test2==1) goto jump; else{system("cls") ; }

int code,me,mee,meee;
do{ho+=1; printf("%d:Donner le code identifiant de l\'adherant: \n",ho);scanf("%d",&code); system("cls");
f=fopen("fichiers/etudiant.txt","r");recherche_adherant(f,code,1,&me);fclose(f) ;
f=fopen("fichiers/enseignant.txt","r");recherche_adherant(f,code,2,&mee) ;fclose(f) ;
f=fopen("fichiers/visiteur.txt","r");recherche_adherant(f,code,3,&meee); fclose(f) ;
  }while(me==0 && mee==0 && meee==0 && ho<3);ho--; if((me==0 && mee==0 && meee==0 && ho<3)){ printf("\nCe adherant n\'existe pas!\n")  ;wait(2);goto jum9; }       
      if(me==1) test=4; else if(mee==1) test=2 ;else test=3 ;
printf("\n\n1   -retour:\nelse-continuer:\nVOTRE CHOIX: ");int nfd;scanf("%d",&nfd);
if(nfd==1) {system("cls"); goto jum9;} else{ wait(2);system("cls");

switch( test) {
	case 4 :f=fopen("fichiers/etudiant.txt","r+");modifier_adherant(f,1,code,&depasse); if(depasse==0){system("cls");goto jum9;} break ;
	case 2 :f=fopen("fichiers/enseignant.txt","r+");modifier_adherant(f,test,code,&depasse);if(depasse==0){system("cls");goto jum9;} break ;
	case 3 :f=fopen("fichiers/visiteur.txt","r+");modifier_adherant(f,test,code,&depasse)  ;if(depasse==0){system("cls");goto jum9;} break ;
	default: printf("choix non trouvee!\n"); break ;
} fclose(f);}
int ijaba; printf("\n\n1   - Revient a la page principale: \n2   - Retour : \nelse- Quitter: \n");scanf("%d",&ijaba);if(ijaba==1){system("cls"); goto jump;} else if(ijaba==2){ system("cls") ; goto jum9;} else {wait(2);system("cls");printf("\t\t\t\t~MERCI P\3UR VOTRE ATTENTI\3N !~ \n\nAu revoir..");exit(010);} 

 	                             //++++++++++++++++++ 
 }  else if(choixx==10){
jum10: 	 FILE *f;int test,le,lee,leee,test2,code,depasse ,hi=0;
do{hi+=1; printf("Vous avez choisi \"Modifier document\".\n\n(%d):1:Retour: \n    2:continuer: \n    CHOIX: ",hi);scanf("%d",&test2) ;system("cls");}while((test2<1 || test2>11 )&& hi<3); if(hi==3 && (test2<1 || test2>11 )) {printf("vous avez depasse le nombre d\'essayes!\n");wait(2);system("cls");goto jum10;}hi=0;
if(test2==1) goto jump; else{system("cls") ; }
int ho=0;do{ ho+=1;
    printf("%d:donner le code identifiant de document à modifiee: ",ho);scanf("%d",&code); system("cls");
	f=fopen("fichiers/livre.txt","r");	if (f == NULL) {printf("fichier livre non trouvee!\n"); exit(404) ;}recherche_document(f,code,1,&le); fclose(f) ;
	f=fopen("fichiers/magasine.txt","r");if (f == NULL) {printf("fichier magasine non trouvee!\n"); exit(404) ;}recherche_document(f,code,2,&lee) ;fclose(f) ; 
	f=fopen("fichiers/article.txt","r");if (f == NULL) {printf("fichier article non trouvee!\n"); exit(404) ; }recherche_document(f,code,3,&leee);fclose(f) ;
    }while(leee==0 && lee==0 && le==0 && ho<3); ho--; if(le==0 && lee==0 && leee==0 && ho<3) {printf("\ndocument non trouvee!\n")  ;wait(2);goto jum10; }
if(le==1) test=4; else if(lee==1) test=2 ;else test=3 ;
printf("\n\n1   -retour:\nelse-continuer:\nVOTRE CHOIX: ");int nfd;scanf("%d",&nfd);
if(nfd==1) {system("cls"); goto jum10;} else{ wait(2);system("cls");

switch( test) {
	case 4 :f=fopen("fichiers/livre.txt","r+");modifier_document(f,1,code,&depasse);if(depasse==0){system("cls");goto jum10;} break ;
	case 2 :f=fopen("fichiers/magasine.txt","r+");modifier_document(f,test,code,&depasse);if(depasse==0){system("cls");goto jum10;} break ;
	case 3 :f=fopen("fichiers/article.txt","r+");modifier_document(f,test,code,&depasse) ;if(depasse==0){system("cls");goto jum10;} break ;
	default: printf("choix non trouvee!\n"); break ;
} fclose(f);}
int ijaba; printf("\n\n1   - Revient a la page principale: \n2   - Retour : \nelse- Quitter: \n");scanf("%d",&ijaba);if(ijaba==1){system("cls"); goto jump;} else if(ijaba==2){ system("cls") ; goto jum9;} else {wait(2);system("cls");printf("\t\t\t\t~MERCI P\3UR VOTRE ATTENTI\3N !~ \n\nAu revoir..");exit(010);} 
 	                             //++++++++++++++++++
 }  else if(choixx==11){ 
jum11: 	int test,test2,testt,dech,ccode,what,hi=0,ho=0;
    FILE *f,*k,*kam,*ad;
    kam=fopen("fichiers/kam.txt","r");
    printf("Vous avez choisi \"emprunter un document\".\n        ********\n");
	char chcode[cte],tot[cte*5],notot[cte*5],dechh[cte];int maw,maww,mawww;hi=0;
	do{hi+=1;printf("\nPresser \"1\" pour Retourner:\n\n(%d):Ou bien Donner le \"numero identifiant\" de ce adherant : ",hi);scanf("%d",&ccode);system("cls");
	if(ccode==1) {system("cls");goto jump;} 
   ad=fopen("fichiers/etudiant.txt","r+");if(ad==NULL) {printf("\nfichier non trouvee!\n");exit(404);}recherche_adherant(ad,ccode,1,&maw); fclose(ad);
   ad=fopen("fichiers/enseignant.txt","r+");if(ad==NULL)  {printf("\nfichier non trouvee!\n");exit(404);}recherche_adherant(ad,ccode,2,&maww);fclose(ad);
   ad=fopen("fichiers/visiteur.txt","r+");if(ad==NULL)  {printf("\nfichier non trouvee!\n");exit(404);}recherche_adherant(ad,ccode,3,&mawww);fclose(ad);
   if(maw==1) {ad=fopen("fichiers/etudiant.txt","r+");test=1;} else if(maww==1){
   ad=fopen("fichiers/enseignant.txt","r+");test=2;
   }else {ad=fopen("fichiers/visiteur.txt","r+");test=3;} ;
	}while(hi<3 && (maw==0 && maww==0 && mawww==0) )	;	
	if(hi==3 && (maw==0 && maww==0 && mawww==0) ) {printf("\nvous avez depasse le nombre d\'essayes!\n");wait(2);system("cls");goto jump;}hi=0;
    int a,b,c,d,e,ff,xx=0,g,h,y=0 ; char ch1[cte*2],ch2[cte*2],ch3[cte*2],ch4[cte*2],ch5[cte*2] ,chaine[cte*50] ;                          
	rewind(ad);                       //
	do{  xx++; } while((fgets(chaine,2499,ad))!=NULL); rewind(ad);
	do{ y++;                          //
    fscanf(ad,"%s %s %d %s %s %d %d %s %d %d %d %d",ch1,ch2,&a,ch3,ch4,&b,&c,ch5,&d,&e,&ff,&g) ;	
    }while(ccode!=a && y<xx );        //                        
	rewind(ad); interm:   	int hgf;char ccc[]="non";
	hgf=strcmp(ch5,ccc); 
	int cd,tm ;
	switch(test)
	{   case 1:                                         
	             
	             if((d==0 || e==0) && (hgf==0) ){   int ho=0;
	             do{ho+=1;printf("\n(%d):1-emprunter un livre  :\n    2-emprunter une magasine: \n    3-emprunter un article: \n    4-retour:\n    CHOIX: ",ho);scanf("%d",&testt);system("cls");}while((testt<1 || testt>4 )&& ho<3); if(ho==3 && (testt<1 || testt>4 )) {printf("\nVous avez depassee le nombre d\'essayes!\n");wait(2);system("cls");goto jump;}
	             if(testt==4) {system("cls");goto jum11;}hi=0;
				 rewind(kam);fscanf(kam,"%s",dechh) ;rewind(kam);fscanf(kam,"%d",&dech);fclose(kam);
	             kam=fopen("fichiers/kam.txt","w");
				 fprintf(kam,"%d",dech+1);rewind(kam);
				 strcpy(notot,"fichiers/dossier-emprunt/etudiant/") ;
				 strcat(notot,dechh);
				 strcat(notot,".txt");
	             k=fopen(notot,"w");
				 switch(testt)
	             {  case 1:f=fopen("fichiers/livre.txt","r+") ;emprunter_document(f,k,ad,test, testt,ccode,&cd,&tm);if(tm==1) {modifier_ad(ad,test,ccode,cd);modifier_doc(f,cd,testt);} else{printf("\nlivre n\'existe pas!\n");wait(2);system("cls");goto interm;}break;
	             	case 2:f=fopen("fichiers/magasine.txt","r+") ;emprunter_document(f,k,ad,test, testt,ccode,&cd,&tm);if(tm==1){ modifier_ad(ad,test,ccode,cd);modifier_doc(f,cd,testt);} else{printf("\nmagasine n\'existe pas!\n");wait(2);system("cls");goto interm;} break;
	             	case 3:f=fopen("fichiers/article.txt","r+") ;emprunter_document(f,k,ad,test, testt,ccode,&cd,&tm);if(tm==1){ modifier_ad(ad,test,ccode,cd);modifier_doc(f,cd,testt);} else{printf("\narticle n\'existe pas!\n");wait(2);system("cls");goto interm;} break;
	             	default: printf("\nchoix non trouvee!\n");system("cls"); goto jump ; break;				 } 
	             		hi=0;	 do{hi+=1; printf("\n\n(%d):1-Retour: \n    2-revient a la page principale: \n    3-Quitter:\n    CHOIX: ",hi);scanf("%d",&test2) ;system("cls");}while((test2<1 || test2>3 )&& hi<3); if(hi==3 && (test2<1 || test2>3 )) {printf("vous avez depasse le nombre d\'essayes!\n");wait(2);system("cls");goto jump;}hi=0;
                 system("cls");if(test2==1) goto interm; else if(test2==2) {goto jump; } else if(test2==3) 	goto fin;
			     } else { printf("\nvous avez depassee le nombre maximal de l\'emprunt qui est 2 !\nou bien vouz avez retardataire..\n    ********\n"); system("pause");system("cls");goto jum11;}
				 break;
	    case 2: 
		         if((d==0 || e==0 || ff==0 || g==0) && (hgf==0) ){   int ho=0;                                   
	             do{ho+=1;printf("\n(%d):1-emprunter un livre  :\n    2-emprunter une magasine: \n    3-emprunter un article: \n    4-retour:\n    CHOIX: ",ho);scanf("%d",&testt);system("cls");}while((testt<1 || testt>4 )&& ho<3); if(ho==3 && (testt<1 || testt>4 )) {printf("\nVous avez depassee le nombre d\'essayes!\n");wait(2);system("cls");goto jump;}
	             if(testt==4) {system("cls");goto jum11;}hi=0;
				 rewind(kam);fscanf(kam,"%s",dechh) ;rewind(kam);fscanf(kam,"%d",&dech);fclose(kam);
	             kam=fopen("fichiers/kam.txt","w");
				 fprintf(kam,"%d",dech+1);rewind(kam);
				 strcpy(notot,"fichiers/dossier-emprunt/enseignant/") ;
				 strcat(notot,dechh);
				 strcat(notot,".txt");
	             k=fopen(notot,"w");		
				 switch(testt)
	             {  case 1:f=fopen("fichiers/livre.txt","r+") ;emprunter_document(f,k,ad,test, testt,ccode,&cd,&tm);if(tm==1) {modifier_ad(ad,test,ccode,cd);modifier_doc(f,cd,testt);}else{printf("& livre n\'existe pas!\n");wait(2);system("cls");goto interm;}break;
	             	case 2:f=fopen("fichiers/magasine.txt","r+") ;emprunter_document(f,k,ad,test, testt,ccode,&cd,&tm);if(tm==1) {modifier_ad(ad,test,ccode,cd);modifier_doc(f,cd,testt);}else{printf("& magasine n\'existe pas!\n");wait(2);system("cls");goto interm;}break;
	             	case 3:f=fopen("fichiers/article.txt","r+") ;emprunter_document(f,k,ad,test, testt,ccode,&cd,&tm);if(tm==1) {modifier_ad(ad,test,ccode,cd);modifier_doc(f,cd,testt);}else{printf("& article n\'existe pas!\n");wait(2);system("cls");goto interm;}break;
	             	default: printf("\nchoix non trouvee!\n");system("cls"); goto jump ; break;				 }  
	             		hi=0;	 do{hi+=1; printf("\n\n(%d):1-Retour: \n    2-revient a la page principale: \n    3-Quitter:\n    CHOIX: ",hi);scanf("%d",&test2) ;system("cls");}while((test2<1 || test2>3 )&& hi<3); if(hi==3 && (test2<1 || test2>3 )) {printf("vous avez depasse le nombre d\'essayes!\n");wait(2);system("cls");goto jump;}hi=0;
                 system("cls");if(test2==1) goto interm; else if(test2==2) {goto jump; } else if(test2==3) 	goto fin;
			     } else{ printf("\nvous avez depassee le nombre maximal de l\'emprunt qui est 4 !\nou bien vouz avez retardataire..\n     **********\n");system("pause");system("cls");goto jum11;}
				 break;
	    case 3: 
		         if((d==0 ) && (hgf==0) ){  int ho=0;                                  
	             do{ho+=1;printf("\n(%d):1-emprunter un livre  :\n    2-emprunter une magasine: \n    3-emprunter un article: \n    4-retour:\n    CHOIX: ",ho);scanf("%d",&testt);system("cls");}while((testt<1 || testt>4 )&& ho<3); if(ho==3 && (testt<1 || testt>4 )) {printf("\nVous avez depassee le nombre d\'essayes!\n");wait(2);system("cls");goto jump;}
	             if(testt==4) {system("cls");goto jum11;}hi=0;
				 rewind(kam);fscanf(kam,"%s",dechh) ;rewind(kam);fscanf(kam,"%d",&dech);fclose(kam);
	             kam=fopen("fichiers/kam.txt","w");
				 fprintf(kam,"%d",dech+1);rewind(kam);
				 strcpy(notot,"fichiers/dossier-emprunt/visiteur/") ;
				 strcat(notot,dechh);
				 strcat(notot,".txt");
	             k=fopen(notot,"w");			
				 switch(testt)
	             {  case 1:f=fopen("fichiers/livre.txt","r+") ;emprunter_document(f,k,ad,test, testt,ccode,&cd,&tm);if(tm==1) {modifier_ad(ad,test,ccode,cd);modifier_doc(f,cd,testt);}else{printf("\nlivre n\'existe pas!\n");wait(2);system("cls");goto interm;}break;
	             	case 2:f=fopen("fichiers/magasine.txt","r+") ;emprunter_document(f,k,ad,test, testt,ccode,&cd,&tm);if(tm==1) {modifier_ad(ad,test,ccode,cd);modifier_doc(f,cd,testt);}else{printf("\nmagasine n\'existe pas!\n");wait(2);system("cls");goto interm;}break;
	             	case 3:f=fopen("fichiers/article.txt","r+") ;emprunter_document(f,k,ad,test, testt,ccode,&cd,&tm);if(tm==1) {modifier_ad(ad,test,ccode,cd);modifier_doc(f,cd,testt);}else{printf("\narticle n\'existe pas!\n");wait(2);system("cls");goto interm;}break;
	             	default: printf("\nchoix non trouvee!\n");system("cls"); goto jum11 ; break; 	}
					 	hi=0;	 do{hi+=1; printf("\n\n(%d):1-Retour: \n    2-revient a la page principale: \n    3-Quitter:\n    CHOIX: ",hi);scanf("%d",&test2) ;system("cls");}while((test2<1 || test2>3 )&& hi<3); if(hi==3 && (test2<1 || test2>3 )) {printf("vous avez depasse le nombre d\'essayes!\n");wait(2);system("cls");goto jump;}hi=0;
                 system("cls");if(test2==1) goto interm; else if(test2==2) {goto jump; } else if(test2==3) 	goto fin;			  
			     } else { printf("\nvous avez depassee le nombre maximal de l\'emprunt qui est 1 !\nou bien vouz avez retardataire..\n      ***********\n");system("pause");system("cls");goto jum11;}
				 break;
	    default : printf("\n..choix non trouvee!\n"); wait(5) ; system("cls");goto jump; break;	
	
	} fclose(k);fclose(ad);fclose(kam);fclose(f);   
                                 //++++++++++++++++++	
 }  else if(choixx==12){
jum12: 	int test,test2,testt,dech,ccode,hi=0,ho=0;
    FILE *f,*ar,*ad;
        printf("Vous avez choisi \"retourner un document\".\n        ********\n");
	char chcode[cte],tot[cte*5],notot[cte*5],dechh[cte];int maw,maww,mawww;hi=0;
	do{hi+=1;printf("\n    Presser \"1\" pour  Retourner  a  la  page  precedante  :\n\n(%d):Ou bien Donner le \"numero identifiant\" de  l\'adherant : ",hi);scanf("%d",&ccode);system("cls");
	if(ccode==1) {system("cls");goto jump;} 
   ad=fopen("fichiers/etudiant.txt","r+");if(ad==NULL) {printf("\nfichier non trouvee!\n");exit(404);}recherche_adherant(ad,ccode,1,&maw); fclose(ad);
   ad=fopen("fichiers/enseignant.txt","r+");if(ad==NULL)  {printf("\nfichier non trouvee!\n");exit(404);}recherche_adherant(ad,ccode,2,&maww);fclose(ad);
   ad=fopen("fichiers/visiteur.txt","r+");if(ad==NULL)  {printf("\nfichier non trouvee!\n");exit(404);}recherche_adherant(ad,ccode,3,&mawww);fclose(ad);
   if(maw==1) {ad=fopen("fichiers/etudiant.txt","r+");test=1;} else if(maww==1){
   ad=fopen("fichiers/enseignant.txt","r+");test=2;
   }else {ad=fopen("fichiers/visiteur.txt","r+");test=3;} ;
	}while(hi<3 && (maw==0 && maww==0 && mawww==0) );	
	if(hi==3 && (maw==0 && maww==0 && mawww==0) ) {printf("\nvous avez depasse le nombre d\'essayes!\n");wait(2);system("cls");goto jump;}hi=0;
	int a,b,c,d,e,ff,xx=0,g,h,y=0 ; char ch1[cte*2],ch2[cte*2],ch3[cte*2],ch4[cte*2],ch5[cte*2] ,chaine[cte*50] ;                          		
	rewind(ad);    xx=0;y=0;                   
	do{  xx++; } while((fgets(chaine,2000,ad))!=NULL); rewind(ad);
	do{ y++;                          
    fscanf(ad,"%s %s %d %s %s %d %d %s %d %d %d %d",ch1,ch2,&a,ch3,ch4,&b,&c,ch5,&d,&e,&ff,&g) ;	
    }while(ccode!=a && y<xx );     
	rewind(ad); inte:
	////////////////////////////////////
	char chcod[cte],decc[cte]; 	char ccc[]="non";ho=0;		int cd,tm ;       
	switch(test)
	{   case 1:
	             if(ccode==a) { int hi=0;
	              do{hi+=1;printf("\n(%d):1-retourner un livre  :\n    2-retourner une magasine: \n    3-retourner un article:\n    4-retour:\n    CHOIX: ",hi);scanf("%d",&testt);system("cls");}while((testt<1 || testt>4 )&& hi<3); if(hi==3 && (testt<1 || testt>4 )) {printf("vous avez depasse le nombre d\'essayes!\n");wait(2);system("cls");goto jump;}
				 if(testt==4) {system("cls");goto jum12;}  
				 switch(testt)
	             {  case 1:f=fopen("fichiers/livre.txt","r+") ;retourner_document(f,ad,test, testt,ccode,&cd,&tm);if(tm==1) {modifier_adh(ad,test,ccode,cd);modifier_docu(f,cd,testt);}else{printf("\nlivre n\'existe pas!\n");wait(2);system("cls");goto inte;};break;
	             	case 2:f=fopen("fichiers/magasine.txt","r+") ;retourner_document(f,ad,test, testt,ccode,&cd,&tm);if(tm==1){ modifier_adh(ad,test,ccode,cd);modifier_docu(f,cd,testt);}else{printf("\nmagasine n\'existe pas!\n");wait(2);system("cls");goto inte;};break;
	             	case 3:f=fopen("fichiers/article.txt","r+") ;retourner_document(f,ad,test, testt,ccode,&cd,&tm);if(tm==1){ modifier_adh(ad,test,ccode,cd);modifier_docu(f,cd,testt);}else{printf("\narticle n\'existe pas!\n");wait(2);system("cls");goto inte;};break;
	             	default: printf("\nchoix non trouvee!\n"); system("cls");goto jum12 ; break;  } 
				 } else { printf("\n..code n\'existe pas!\n");system("cls");goto jump;}
				 do{hi+=1; printf("\n\n(%d):1-Retour: \n    2-revient a la page principale: \n    3-Quitter:\n    CHOIX: ",hi);scanf("%d",&test2) ;system("cls");}while((test2<1 || test2>3 )&& hi<3); if(hi==3 && (test2<1 || test2>3 )) {printf("vous avez depasse le nombre d\'essayes!\n");wait(2);system("cls");goto jump;}hi=0;
                 system("cls");if(test2==1) goto inte; else if(test2==2) {goto jump; }else if(test2==3) 	goto fin;			
				 if(tm==1){
				 strcpy(tot,"fichiers/adherant-retardaire/etudiant/") ;
				 sprintf(decc,"%d",cd);   sprintf(chcod,"%d",ccode ) ;
				 strcat(tot,chcod); strcat(tot,decc);
				 strcat(tot,".txt"); //printf("cd=%d; ccode=%d ; decc=%s ; chcode=%s ;\ntot= %s \n",cd,ccode,decc,chcod,tot) ;
	             ar=fopen(tot,"r"); fclose(ar) ;
	             if(ar!=NULL ) { remove(tot)  ; printf("\nremove(file) se termine avec succe!\nmodifier_adh_r se termine avec succee!\nl\'enregistrement des donnees se termine avec succee!\n"); } 	                      }
				 break;
	    case 2:  if(ccode==a) {  hi=0;
	             do{hi+=1;printf("\n(%d):1-retourner un livre  :\n    2-retourner une magasine: \n    3-retourner un article:\n    4-retour:\n    CHOIX: ",hi);scanf("%d",&testt);system("cls");}while((testt<1 || testt>4 )&& hi<3); if(hi==3 && (testt<1 || testt>4 )) {printf("vous avez depasse le nombre d\'essayes!\n");wait(2);system("cls");goto jump;}
				 switch(testt)
	             {  case 1:f=fopen("fichiers/livre.txt","r+") ;retourner_document(f,ad,test, testt,ccode,&cd,&tm);if(tm==1) {modifier_adh(ad,test,ccode,cd);modifier_docu(f,cd,testt);}else{printf("\nlivre n\'existe pas!\n");wait(2);system("cls");goto inte;};break;
	             	case 2:f=fopen("fichiers/magasine.txt","r+") ;retourner_document(f,ad,test, testt,ccode,&cd,&tm);if(tm==1) {modifier_adh(ad,test,ccode,cd);modifier_docu(f,cd,testt);}else{printf("\nmagasine n\'existe pas!\n");wait(2);system("cls");goto inte;};break;
	             	case 3:f=fopen("fichiers/article.txt","r+") ;retourner_document(f,ad,test, testt,ccode,&cd,&tm);if(tm==1) {modifier_adh(ad,test,ccode,cd);modifier_docu(f,cd,testt);}else{printf("\narticle n\'existe pas!\n");wait(2);system("cls");goto inte;};break;
	             	default: system("cls");goto jum12; break; 				 }  
				 } else { printf("\n..numero identifiant n\'existe pas!\n");goto jump;}		
				 do{hi+=1; printf("\n\n(%d):1-Retour: \n    2-revient a la page principale: \n    3-Quitter:\n    CHOIX: ",hi);scanf("%d",&test2) ;system("cls");}while((test2<1 || test2>3 )&& hi<3); if(hi==3 && (test2<1 || test2>3 )) {printf("vous avez depasse le nombre d\'essayes!\n");wait(2);system("cls");goto jump;}hi=0;
                 system("cls");if(test2==1) goto inte; else if(test2==2) {goto jump; }else if(test2==3) 	goto fin;					 
				 if(tm==1){
				 strcpy(tot,"fichiers/adherant-retardaire/enseignant/") ;
				 sprintf(decc,"%d",cd);   sprintf(chcod,"%d",ccode ) ;
				 strcat(tot,chcod); strcat(tot,decc);
				 strcat(tot,".txt"); //printf("cd=%d; ccode=%d ; decc=%s ; chcode=%s ;\ntot= %s \n",cd,ccode,decc,chcod,tot) ;
	             ar=fopen(tot,"r"); fclose(ar) ;
	             if(ar!=NULL ) { remove(tot) ;  printf("\nremove(file) se termine avec succe!\nmodifier_adh_r se termine avec succee!\n");  } 	                      }
				 break;
	    case 3:  if(ccode==a) {  hi=0;
	             do{hi+=1;printf("\n(%d):1-retourner un livre  :\n    2-retourner une magasine: \n    3-retourner un article:\n    4-retour:\n    CHOIX: ",hi);scanf("%d",&testt);system("cls");}while((testt<1 || testt>4 )&& hi<3); if(hi==3 && (testt<1 || testt>4 )) {printf("vous avez depasse le nombre d\'essayes!\n");wait(2);system("cls");goto jump;}
				 switch(testt)
	             {  case 1:f=fopen("fichiers/livre.txt","r+") ;retourner_document(f,ad,test, testt,ccode,&cd,&tm);if(tm==1) {modifier_adh(ad,test,ccode,cd);modifier_docu(f,cd,testt);}else{printf("\nlivre n\'existe pas!\n");wait(2);system("cls");goto inte;};break;
	             	case 2:f=fopen("fichiers/magasine.txt","r+") ;retourner_document(f,ad,test, testt,ccode,&cd,&tm);if(tm==1) {modifier_adh(ad,test,ccode,cd);modifier_docu(f,cd,testt);}else{printf("\nmagasine n\'existe pas!\n");wait(2);system("cls");goto inte;};break;
	             	case 3:f=fopen("fichiers/article.txt","r+") ;retourner_document(f,ad,test, testt,ccode,&cd,&tm);if(tm==1) {modifier_adh(ad,test,ccode,cd);modifier_docu(f,cd,testt);}else{printf("\narticle n\'existe pas!\n");wait(2);system("cls");goto inte;};break;
	             	default: system("cls"); goto jum12 ; break;				 } 
	             } else { printf("\n..numero identifiant n\'existe pas!\n");system("cls");goto jump;}
	             do{hi+=1; printf("\n\n(%d):1-Retour: \n    2-revient a la page principale: \n    3-Quitter:\n    CHOIX: ",hi);scanf("%d",&test2) ;system("cls");}while((test2<1 || test2>3 )&& hi<3); if(hi==3 && (test2<1 || test2>3 )) {printf("vous avez depasse le nombre d\'essayes!\n");wait(2);system("cls");goto jump;}hi=0;
                 system("cls");if(test2==1) goto inte; else if(test2==2) {goto jump; }else if(test2==3) 	goto fin;			
	             if(tm==1){
				 strcpy(tot,"fichiers/adherant-retardaire/visiteur/") ;
				 sprintf(decc,"%d",cd);   sprintf(chcod,"%d",ccode ) ;
				 strcat(tot,chcod); strcat(tot,decc);
				 strcat(tot,".txt"); //printf("cd=%d; ccode=%d ; decc=%s ; chcode=%s ;\ntot= %s \n",cd,ccode,decc,chcod,tot) ;
	             ar=fopen(tot,"r"); fclose(ar) ;
	             if(ar!=NULL ) { remove(tot) ;  printf("\nremove(file) se termine avec succe!\nmodifier_adh_r se termine avec succee!\n"); }                      }
				 break;
	    default : printf("\n..choix non trouvee!\n"); wait(5) ;system("cls");goto jump;	break;hi=0;
		
	} 	fclose(ad);	fclose(f);	fclose(ar);
 	                            //++++++++++++++++++
 }  else if(choixx!=13){printf("choix NON trouvee! \n");wait(2); system("cls");goto jump;	}
    else { fin: sleep(1); system("cls");printf("\t\t\t\t~MERCI P\3UR VOTRE ATTENTI\3N !~ \n\nAu revoir..");}
    
	return 55;
}
