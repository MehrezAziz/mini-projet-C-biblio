#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h> //new new
#define cte 50
#include<unistd.h>
////////////////////////////////
void modif_adhe(FILE *f,int z,int ccod){ 
	int i=-1,ii=-1,x=0,hell,com,aux1,aux2,aux3,aux4,aux5,aux6,aux7,aux8,a; char ch1[cte*2],ch2[cte*2],ch3[cte*2],ch4[cte*2],ch5[cte*2],chaine[cte*50],c[]="non";
	do{  x++;fscanf(f,"%s",ch5);fgets(chaine,2499,f);hell=strcmp(ch5,"fiin3finfinfzeANbBrty");	} while(hell!=0);	rewind(f) ;	
	struct etudiant	{ char nom[cte], prenom[cte*2],adresse[cte*2], type[cte], retardaire[5] ;    int identifiant, nbr_tot, nbr_curr , code1,code2, code3, code4 ;	} ;
	struct  etudiant t[x+1] ;
	do{ i+=1;    fscanf(f,"%s %s %d %s %s %d %d %s %d %d %d %d",t[i].nom,t[i].prenom,&t[i].identifiant,t[i].adresse,t[i].type,&t[i].nbr_tot,&t[i].nbr_curr,t[i].retardaire,&t[i].code1,&t[i].code2,&t[i].code3,&t[i].code4);com=strcmp(t[i].nom,""); if (com==0) break;   aux1=t[i].identifiant;	}   while(z!=t[i].identifiant && i<x );rewind(f) ;
	do{ ii+=1;   fscanf(f,"%s %s %d %s %s %d %d %s %d %d %d %d",t[ii].nom,t[ii].prenom,&t[ii].identifiant,t[ii].adresse,t[ii].type,&t[ii].nbr_tot,&t[ii].nbr_curr,t[ii].retardaire,&t[ii].code1,&t[ii].code2,&t[ii].code3,&t[ii].code4);com=strcmp(t[ii].nom,""); if (com==0) break;	}   while( ii<x );rewind(f) ;
	if(z!=t[i].identifiant) { printf("choix non trouvee! \n");exit(404);}    char oui[]="oui" ; hell=strcmp(t[i].retardaire,oui);
    if(hell!=0 ){ 	strcpy(t[i].retardaire,oui) ;	rewind(f) ;	
    for(int m=0;m<x;m++){ 	fprintf(f,"%s %s %d %s %s %d %d %s %d %d %d %d\n",t[m].nom,t[m].prenom,t[m].identifiant,t[m].adresse,t[m].type,t[m].nbr_tot,t[m].nbr_curr,t[m].retardaire,t[m].code1,t[m].code2,t[m].code3,t[m].code4);}	printf("l\'adherant %s %s (%d:%s) DEVIENT retardaire! et le code de document empruntee est %d \n",t[i].nom,t[i].prenom,z,t[i].type,ccod);
		       } else 	printf("l\'adherant \"%s %s\" (%d:%s) RESTE retardaire! et le code de document empruntee est %d \n",t[i].nom,t[i].prenom,z,t[i].type,ccod);     
}
//////////////////////////////////////
void recherche_doc(FILE *f,FILE *k, int code,int test,int identif_a,int *tm){
	int a,b,c,d,e,ff,g,h,x=0,y=0 ;char *wa9t1,ch1[cte*2],ch2[cte*2],ch3[cte*2],ch4[cte*2],ch5[cte*2],ch6[cte*2],ch7[cte*2],ch8[cte*2],ch9[cte*2],chaine[cte*50] ; 
    time_t temp=time(0); wa9t1=ctime(&temp) ; 
	do{  x++;	} while((fgets(chaine,2000,f))!=NULL);	rewind(f) ;	
		switch( test) {
	case 1 : 	do{ y++; fscanf(f,"%s %s %s %d %d %s %s  %d ",ch1,ch2,ch3,&a,&b,ch4,ch5,&c) ;	fgets(chaine,2499,f); }   while(code!=a && y<x );
	if(code==a ){ if(b!=0){
    printf("Type                     : %s\nTitre                    : %s\nLocalisation             : %s\nCode de livre            : %d\nNombre de copies         : %d\nNom d\'auteur             : %s\nNom d\'editeur            : %s\nNombre d\'emprunt totale  : %d\nDate d\'edition           : %s\n",ch1,ch2,ch3,a,b,ch4,ch5,c,chaine) ;
    fprintf(k,"%d    %d   %s",a,identif_a,wa9t1) ;
     *tm=1;		printf("\nemprunt terminee avec succee!\n"); }else {printf("le nombre de copie est \"NULL\", emprunter un autre document si tu veut \2\n");*tm=0;}   }	else{ *tm=0;} break ;
    case 2 : 	do{ y++; fscanf(f,"%s %s %s %d %d %d ",ch1,ch2,ch3,&a,&b,&c) ;	fgets(chaine,2499,f); }   while(code!=a && y<x );
	if(code==a){  if(b!=0){	fprintf(k,"%d    %d   %s",a,identif_a,wa9t1) ;
	printf("Type                     : %s\nTitre                    : %s\nLocalisation             : %s\nCode de magasine         : %d\nNombre de copies         : %d\nNombre d\'emprunt totale  : %d\nDate d\'edition           : %s\n",ch1,ch2,ch3,a,b,c,chaine) ;
		printf("\nemprunt terminee avec succee!\n"); *tm=1;  }else {printf("le nombre de copie est \"NULL\", emprunter un autre document si tu veut \2\n");*tm=0;}	 }	else { *tm=0;} break ;
    case 3 : 	do{ y++; fscanf(f,"%s %s %s %d %d %s  %d ",ch1,ch2,ch3,&a,&b,ch4,&c) ;	fgets(chaine,2499,f); }   while(code!=a && y<x );
	if(code==a){  if(b!=0){	fprintf(k,"%d    %d   %s",a,identif_a,wa9t1) ;
	printf("Type                     : %s\nTitre                    : %s\nLocalisation             : %s\nCode de l\'article        : %d\nNombre de copies         : %d\nNom d\'auteur             : %s\nNombre d\'emprunt totale  : %d\nDate de publication      : %s\n",ch1,ch2,ch3,a,b,ch4,c,chaine) ;
		printf("\nemprunt terminee avec succee!\n");*tm=1;  }else {printf("le nombre de copie est \"NULL\", emprunter un autre document si tu veut \2\n");*tm=0;}	}	else{ *tm=0;} break ;
	default: printf("Choix non trouvee!\n"); break ;    }		
}                                                                                                        
void emprunter_document(FILE *f,FILE *k,FILE *ad,int test,int testt,int ccode,int *cd,int *tm){ // test 1:etudiant  2:enseignant  3:visiteur
	int i=-1 ,rech,com=-1,x,xx=0,hell,code,hell1,hi=0;  	char chaine[cte*20] ;
    int a,b,c,d,e,ff,g,h,y=0 ; char ch1[cte*2],ch2[cte*2],ch3[cte*2],ch4[cte*2],ch5[cte*2] ; 	rewind(k);	rewind(f);	rewind(ad);
	do{  xx++; } while((fgets(chaine,2499,ad))!=NULL);
	do{ y++; fscanf(f,"%s %s %d %s %s %d %d %s %d %d %d %d",ch1,ch2,&a,ch3,ch4,&b,&c,ch5,&d,&e,&ff,&g) ;	  }  while(ccode!=a && y<xx );   rewind(k);	rewind(f);	rewind(ad); 
		        switch(testt){
		        	case 1: do{hi+=1;printf("\ndonner  le  code  du  livre  : ");scanf("%d",&code);*cd=code; recherche_doc(f,k, code, testt,ccode,tm);}while(hi<3 && !*tm); if(hi==3 && *tm==0) printf("\nvous avez depasse le nombre maximale d\'essayes!\n"); break; hi=0;
		        	case 2: do{hi+=1;printf("\ndonner le code de la magasine: ");scanf("%d",&code);*cd=code; recherche_doc(f,k, code, testt,ccode,tm);}while(hi<3 && !*tm);if(hi==3 && *tm==0) printf("\nvous avez depasse le nombre maximale d\'essayes!\n"); break; hi=0;
		        	case 3: do{hi+=1;printf("\ndonner le code de l\'article  : ");scanf("%d",&code);*cd=code; recherche_doc(f,k, code, testt,ccode,tm);}while(hi<3 && !*tm);if(hi==3 && *tm==0) printf("\nvous avez depasse le nombre maximale d\'essayes!\n"); break; hi=0;
		        	default :printf("choix non trouvee!!!\n");system("cls"); break;	}	rewind(k);	rewind(f);	rewind(ad);
	}
void modifier_ad(FILE *ad,int test,int ccode,int code){ 
	int i=-1,ii=-1,x=0,z,hell,com,aux1,aux2,aux3,aux4,aux5,aux6,aux7,aux8,a; char ch1[cte*2],ch2[cte*2],ch3[cte*2],ch4[cte*2],ch5[cte*2],chaine[cte*50],c[]="non";
	do{  x++;fscanf(ad,"%s",ch5);fgets(chaine,2499,ad);hell=strcmp(ch5,"fiin3finfinfzeANbBrty");	 } while(hell!=0 && x<=30000); if(x==30000) exit(9090) ;	rewind(ad) ;	
	struct etudiant	{ char nom[cte], prenom[cte*2],adresse[cte*2], type[cte], retardaire[5]    ;     int identifiant, nbr_tot, nbr_curr , code1,code2, code3, code4 ;	} ;
	struct  etudiant t[x+1] ;
switch( test) {
	case 1 :z=ccode; do{ i+=1;   fscanf(ad,"%s %s %d %s %s %d %d %s %d %d %d %d",t[i].nom,t[i].prenom,&t[i].identifiant,t[i].adresse,t[i].type,&t[i].nbr_tot,&t[i].nbr_curr,t[i].retardaire,&t[i].code1,&t[i].code2,&t[i].code3,&t[i].code4);com=strcmp(t[i].nom,""); if (com==0) break;   aux1=t[i].identifiant;	}   while(z!=t[i].identifiant && i<x );rewind(ad) ;
	do{ ii+=1;   fscanf(ad,"%s %s %d %s %s %d %d %s %d %d %d %d",t[ii].nom,t[ii].prenom,&t[ii].identifiant,t[ii].adresse,t[ii].type,&t[ii].nbr_tot,&t[ii].nbr_curr,t[ii].retardaire,&t[ii].code1,&t[ii].code2,&t[ii].code3,&t[ii].code4);com=strcmp(t[ii].nom,""); if (com==0) break;      	}   while( ii<x );rewind(ad) ;
	if(z!=t[i].identifiant) { printf("identifiant non trouvee! \n");exit(404);} 	t[i].nbr_tot+=1; t[i].nbr_curr+=1; if(t[i].code1==0) t[i].code1=code; else if(t[i].code2==0) t[i].code2=code; else printf("vous avez depasse le nombre maximal de l\'emprunt qui est 2 !\n");	rewind(ad) ;	
    for(int m=0;m<x;m++){ 	fprintf(ad,"%s %s %d %s %s %d %d %s %d %d %d %d\n",t[m].nom,t[m].prenom,t[m].identifiant,t[m].adresse,t[m].type,t[m].nbr_tot,t[m].nbr_curr,t[m].retardaire,t[m].code1,t[m].code2,t[m].code3,t[m].code4);}  printf("\nla modification de l\'etudiant a terminee avec succee! \n") ;	 break ; 
	case 2 :z=ccode; do{ i+=1;   fscanf(ad,"%s %s %d %s %s %d %d %s %d %d %d %d",t[i].nom,t[i].prenom,&t[i].identifiant,t[i].adresse,t[i].type,&t[i].nbr_tot,&t[i].nbr_curr,t[i].retardaire,&t[i].code1,&t[i].code2,&t[i].code3,&t[i].code4);com=strcmp(t[i].nom,""); if (com==0) break;  aux1=t[i].identifiant;	}   while(z!=t[i].identifiant && i<x );rewind(ad) ;
	do{ ii+=1; fscanf(ad,"%s %s %d %s %s %d %d %s %d %d %d %d",t[ii].nom,t[ii].prenom,&t[ii].identifiant,t[ii].adresse,t[ii].type,&t[ii].nbr_tot,&t[ii].nbr_curr,t[ii].retardaire,&t[ii].code1,&t[ii].code2,&t[ii].code3,&t[ii].code4);com=strcmp(t[ii].nom,""); if (com==0) break;  	}   while( ii<x );rewind(ad) ;
	if(z!=t[i].identifiant) { printf("identifiant non trouvee! \n");exit(404);}  	t[i].nbr_tot+=1; t[i].nbr_curr+=1; if(t[i].code1==0) t[i].code1=code; else if(t[i].code2==0) t[i].code2=code;  	else  if(t[i].code3==0) t[i].code3=code;  else if(t[i].code4==0) t[i].code4=code; else {printf("vous avez depasse le nombre maximal de l\'emprunt qui est 4 !\n");}	rewind(ad) ;	
    for(int m=0;m<x;m++){ 	fprintf(ad,"%s %s %d %s %s %d %d %s %d %d %d %d\n",t[m].nom,t[m].prenom,t[m].identifiant,t[m].adresse,t[m].type,t[m].nbr_tot,t[m].nbr_curr,t[m].retardaire,t[m].code1,t[m].code2,t[m].code3,t[m].code4);}   printf("\nla modification de l\'enseignant a terminee avec succee! \n") ; 	break ;
	case 3 :z=ccode; do{ i+=1;   fscanf(ad,"%s %s %d %s %s %d %d %s %d %d %d %d",t[i].nom,t[i].prenom,&t[i].identifiant,t[i].adresse,t[i].type,&t[i].nbr_tot,&t[i].nbr_curr,t[i].retardaire,&t[i].code1,&t[i].code2,&t[i].code3,&t[i].code4);com=strcmp(t[i].nom,""); if (com==0) break;   aux1=t[i].identifiant;	}   while(z!=t[i].identifiant && i<x );rewind(ad) ;
	do{ ii+=1;     fscanf(ad,"%s %s %d %s %s %d %d %s %d %d %d %d",t[ii].nom,t[ii].prenom,&t[ii].identifiant,t[ii].adresse,t[ii].type,&t[ii].nbr_tot,&t[ii].nbr_curr,t[ii].retardaire,&t[ii].code1,&t[ii].code2,&t[ii].code3,&t[ii].code4);com=strcmp(t[ii].nom,""); if (com==0) break;      	}   while( ii<x );rewind(ad) ;
	if(z!=t[i].identifiant) { printf("identifiant non trouvee! \n");exit(404);} 	t[i].nbr_tot+=1; t[i].nbr_curr+=1; if(t[i].code1==0) t[i].code1=code; else printf("vous avez depasse le nombre maximal de l\'emprunt qui est 2 !\n");	rewind(ad) ;	
    for(int m=0;m<x;m++){ 	fprintf(ad,"%s %s %d %s %s %d %d %s %d %d %d %d\n",t[m].nom,t[m].prenom,t[m].identifiant,t[m].adresse,t[m].type,t[m].nbr_tot,t[m].nbr_curr,t[m].retardaire,t[m].code1,t[m].code2,t[m].code3,t[m].code4);}    printf("\nla modification de visiteur a terminee avec succee! \n") ; break ; }	
}
void modifier_doc(FILE *f,int z,int test) 
{	int i=-1,ii=-1,x=0,hell,com,aux1; char ch5[cte*2],chaine[cte*50];	rewind(f) ;
	switch(test){
	case 1:  	  do{  x++;fscanf(f,"%s",ch5);fgets(chaine,2499,f);hell=strcmp(ch5,"fiin3finfinfzeANbBrty");	} while(hell!=0); 	rewind(f) ;;break;
	case 2:	      do{  x++;fscanf(f,"%s",ch5);fgets(chaine,2499,f);hell=strcmp(ch5,"fiin3finfinfzeANbBrty");	} while(hell!=0);	rewind(f) ;	 ;break;
	case 3:	  	  do{  x++;fscanf(f,"%s",ch5);fgets(chaine,2499,f);hell=strcmp(ch5,"fiin3finfinfzeANbBrty");	} while(hell!=0);	rewind(f) ;break;	  }
	struct livre	{ char type[cte], titre[cte*2],localisation[cte*2], nom_auteur[cte*2],nom_editeur[cte*2],ch0[cte], ch1[cte],ch2[cte],ch3[cte],ch4[cte] ;     int code,nbr_cop,nbr_tot;	} ;  struct  livre t[x+1] ;
	struct magasine	{ char type[cte], titre[cte*2],localisation[cte*2],ch0[cte], ch1[cte],ch2[cte],ch3[cte],ch4[cte] ;   int code,nbr_cop,nbr_tot;	} ;  struct  magasine t1[x+1] ;
	struct article 	{ char type[cte], titre[cte*2],localisation[cte*2],nom_auteur[cte*2] ,ch0[cte], ch1[cte],ch2[cte],ch3[cte],ch4[cte];    int code,nbr_cop,nbr_tot;	} ;  struct  article t2[x +1] ; 
switch( test) {	 
	case 1 : do{ i+=1;   fscanf(f,"%s %s %s %d %d %s %s %d %s %s %s %s %s ",t[i].type,t[i].titre,t[i].localisation,&t[i].code,&t[i].nbr_cop,t[i].nom_auteur,t[i].nom_editeur,&t[i].nbr_tot,t[i].ch0,t[i].ch1,t[i].ch2,t[i].ch3,t[i].ch4);   aux1=t[i].code;	}   while(z!=t[i].code && i<x );rewind(f) ; //printf("\n pos de l\'element=  %d\n",i);
	do  { ii+=1;  fscanf(f,"%s %s %s %d %d %s %s %d %s %s %s %s %s ",t[ii].type,t[ii].titre,t[ii].localisation,&t[ii].code,&t[ii].nbr_cop,t[ii].nom_auteur,t[ii].nom_editeur,&t[ii].nbr_tot,t[ii].ch0,t[ii].ch1,t[ii].ch2,t[ii].ch3,t[ii].ch4);    	}   while( ii<x );rewind(f) ;
	if(z!=t[i].code) { printf("choix non trouvee! \n");exit(494);} 	t[i].nbr_cop-=1;t[i].nbr_tot+=1; 	rewind(f) ;	
    for(int i=0;i<x;i++)  fprintf(f,"%s   %s   %s   %d   %d   %s   %s   %d   %s  %s  %s  %s  %s\n",t[i].type,t[i].titre,t[i].localisation,t[i].code,t[i].nbr_cop,t[i].nom_auteur,t[i].nom_editeur,t[i].nbr_tot,t[i].ch0,t[i].ch1,t[i].ch2,t[i].ch3,t[i].ch4);  printf("\nla modification de livre a terminee avec succee! \n") ;sleep(2);	 break ; 	
	case 2 : do{ i+=1;  fscanf(f,"%s %s %s %d %d %d %s %s %s %s %s",t1[i].type,t1[i].titre,t1[i].localisation,&t1[i].code,&t1[i].nbr_cop,&t1[i].nbr_tot,t1[i].ch0,t1[i].ch1,t1[i].ch2,t1[i].ch3,t1[i].ch4);   aux1=t1[i].code;	}   while(z!=t1[i].code && i<x );rewind(f) ;
	do{ ii+=1; fscanf(f,"%s %s %s %d %d %d %s %s %s %s %s",t1[ii].type,t1[ii].titre,t1[ii].localisation,&t1[ii].code,&t1[ii].nbr_cop,&t1[ii].nbr_tot,t1[ii].ch0,t1[ii].ch1,t1[ii].ch2,t1[ii].ch3,t1[ii].ch4);       	}   while( ii<x );rewind(f) ;
	if(z!=t1[i].code) { printf("choix non trouvee! \n");exit(404);}   	t1[i].nbr_cop-=1; t1[i].nbr_tot+=1 ;	rewind(f) ;	
    for(int i=0;i<x;i++)  fprintf(f,"%s   %s   %s   %d   %d   %d    %s   %s   %s   %s   %s\n",t1[i].type,t1[i].titre,t1[i].localisation,t1[i].code,t1[i].nbr_cop,t1[i].nbr_tot,t1[i].ch0,t1[i].ch1,t1[i].ch2,t1[i].ch3,t1[i].ch4);   printf("\nla modification de magasine a terminee avec succee! \n") ;sleep(2);	 break ; 
	case 3 : do{ i+=1;  fscanf(f,"%s %s %s %d %d %s  %d",t2[i].type,t2[i].titre,t2[i].localisation,&t2[i].code,&t2[i].nbr_cop,t2[i].nom_auteur,&t2[i].nbr_tot);com=strcmp(t2[i].type,""); if (com==0) break;   aux1=t2[i].code;	}   while(z!=t2[i].code && i<x );rewind(f) ;
	do{ ii+=1;  fscanf(f,"%s   %s   %s   %d   %d    %s   %d %s %s %s %s %s ",t2[ii].type,t2[ii].titre,t2[ii].localisation,&t2[ii].code,&t2[ii].nbr_cop,t2[ii].nom_auteur,&t2[ii].nbr_tot,t2[ii].ch0,t2[ii].ch1,t2[ii].ch2,t2[ii].ch3,t2[ii].ch4);      	}   while( ii<x );rewind(f) ;
	if(z!=t2[i].code) { printf("choix non trouvee! \n");exit(404);}   	t2[i].nbr_cop-=1; t2[i].nbr_tot+=1;	rewind(f) ;	
    for(int i=0;i<x;i++)  fprintf(f,"%s   %s   %s   %d   %d   %s    %d   %s  %s  %s   %s  %s\n",t2[i].type,t2[i].titre,t2[i].localisation,t2[i].code,t2[i].nbr_cop,t2[i].nom_auteur,t2[i].nbr_tot,t2[i].ch0,t2[i].ch1,t2[i].ch2,t2[i].ch3,t2[i].ch4);    printf("\nla modification de l\'article a terminee avec succee! \n") ;sleep(2);	 break ; 	}
}
/////////////////////////////////////
void recherche_docu(FILE *f, int code,int test,int identif_a,int *tm){
	int a,b,c,d,e,ff,g,h,x=0,y=0 ;char *wa9t1,ch1[cte*2],ch2[cte*2],ch3[cte*2],ch4[cte*2],ch5[cte*2],ch6[cte*2],ch7[cte*2],ch8[cte*2],ch9[cte*2],chaine[cte*50] ;    time_t temp=time(0); wa9t1=ctime(&temp) ; 
	do{  x++;	} while((fgets(chaine,2499,f))!=NULL);	rewind(f) ;
		switch( test) {
	case 1 : 	do{ y++; fscanf(f,"%s %s %s %d %d %s %s  %d ",ch1,ch2,ch3,&a,&b,ch4,ch5,&c) ;	fgets(chaine,2499,f); }   while(code!=a && y<x );
	if(code==a ){  *tm=1;			    system("pause"); 				printf("\nfichier existe!\n"); 			   }	else{ *tm=0;} break ;
    case 2 : 	do{ y++; fscanf(f,"%s %s %s %d %d %d ",ch1,ch2,ch3,&a,&b,&c) ;	fgets(chaine,2499,f); }   while(code!=a && y<x );
	if(code==a){  *tm=1; 	system("pause") ;	printf("\nfichier existe!\n"); 	 }	else { *tm=0;} break ;
	case 3 : 	do{ y++; fscanf(f,"%s %s %s %d %d %s  %d ",ch1,ch2,ch3,&a,&b,ch4,&c) ;	fgets(chaine,2499,f); }   while(code!=a && y<x );
	if(code==a){  	system("pause");    printf("\nfichier existe!\n"); *tm=1;  	}	else{ *tm=0;} break ;	default: printf("\nChoix non trouvee!\n"); break ;  }		
}
void modifier_adh(FILE *ad,int test,    int ccode,       int code){ 
	int i=-1,ii=-1,x=0,z,hell,com,aux1,aux2,aux3,aux4,aux5,aux6,aux7,aux8,a; char ch1[cte*2],ch2[cte*2],ch3[cte*2],ch4[cte*2],ch5[cte*2],chaine[cte*50],c[]="non";
	do{  x++;fscanf(ad,"%s",ch5);fgets(chaine,2499,ad);hell=strcmp(ch5,"fiin3finfinfzeANbBrty");	} while(hell!=0 && x<=30000); if(x==30000) exit(9090) ;	rewind(ad) ;	
	struct etudiant	{ char nom[cte], prenom[cte*2],adresse[cte*2], type[cte], retardaire[10] ;     int identifiant, nbr_tot, nbr_curr , code1,code2, code3, code4 ;	} ;
	struct  etudiant t[x+1] ; 	char oui[10]="oui",non[10]="non" ;
switch( test) {
	case 1 :z=ccode;do{ i+=1;  fscanf(ad,"%s %s %d %s %s %d %d %s %d %d %d %d",t[i].nom,t[i].prenom,&t[i].identifiant,t[i].adresse,t[i].type,&t[i].nbr_tot,&t[i].nbr_curr,t[i].retardaire,&t[i].code1,&t[i].code2,&t[i].code3,&t[i].code4);  aux1=t[i].identifiant;	}   while(z!=t[i].identifiant && i<x );rewind(ad) ;
	do{ ii+=1;  fscanf(ad,"%s %s %d %s %s %d %d %s %d %d %d %d",t[ii].nom,t[ii].prenom,&t[ii].identifiant,t[ii].adresse,t[ii].type,&t[ii].nbr_tot,&t[ii].nbr_curr,t[ii].retardaire,&t[ii].code1,&t[ii].code2,&t[ii].code3,&t[ii].code4);	}   while( ii<x );rewind(ad) ;
	if(z!=t[i].identifiant) { printf("choix non trouvee! \n");exit(404);} 	hell=strcmp(t[i].retardaire,oui) ;
	if(hell==0) { strcpy(t[i].retardaire,non) ; }   t[i].nbr_curr=t[i].nbr_curr -1  ; if(t[i].code1==code) t[i].code1=0; else if(t[i].code2==code) t[i].code2=0; else{ printf("\nVous n\'avez pas emprunter un document avec se code la! \n"); exit(333);}	rewind(ad) ;	
    for(int m=0;m<x;m++){ 	fprintf(ad,"%s %s %d %s %s %d %d %s %d %d %d %d\n",t[m].nom,t[m].prenom,t[m].identifiant,t[m].adresse,t[m].type,t[m].nbr_tot,t[m].nbr_curr,t[m].retardaire,t[m].code1,t[m].code2,t[m].code3,t[m].code4);}
    printf("\nla modification de l\'etudiant  a terminee avec succee! \n") ;	 break ; 
	case 2 :z=ccode; do{ i+=1;   fscanf(ad,"%s %s %d %s %s %d %d %s %d %d %d %d",t[i].nom,t[i].prenom,&t[i].identifiant,t[i].adresse,t[i].type,&t[i].nbr_tot,&t[i].nbr_curr,t[i].retardaire,&t[i].code1,&t[i].code2,&t[i].code3,&t[i].code4);   aux1=t[i].identifiant;	}   while(z!=t[i].identifiant && i<x );rewind(ad) ;
	do{ ii+=1;   fscanf(ad,"%s %s %d %s %s %d %d %s %d %d %d %d",t[ii].nom,t[ii].prenom,&t[ii].identifiant,t[ii].adresse,t[ii].type,&t[ii].nbr_tot,&t[ii].nbr_curr,t[ii].retardaire,&t[ii].code1,&t[ii].code2,&t[ii].code3,&t[ii].code4);	}   while( ii<x );rewind(ad) ;
	if(z!=t[i].identifiant) { printf("choix non trouvee! \n");exit(404);}  	hell=strcmp(t[i].retardaire,oui) ;
	if(hell==0) { strcpy(t[i].retardaire,non) ; } t[i].nbr_curr=t[i].nbr_curr -1; if(t[i].code1==code) t[i].code1=0; else if(t[i].code2==code) t[i].code2=0;  	else  if(t[i].code3==code) t[i].code3=0;  else if(t[i].code4==code) t[i].code4=0;  else{ printf("\nVous n\'avez pas emprunter un document avec se code la! \n"); exit(333);}	rewind(ad) ;	
    for(int m=0;m<x;m++){ 	fprintf(ad,"%s %s %d %s %s %d %d %s %d %d %d %d\n",t[m].nom,t[m].prenom,t[m].identifiant,t[m].adresse,t[m].type,t[m].nbr_tot,t[m].nbr_curr,t[m].retardaire,t[m].code1,t[m].code2,t[m].code3,t[m].code4);}  printf("\nla modification de l\'enseignant a terminee avec succee! \n") ; 	break ;
	case 3 :z=ccode; do{ i+=1;   fscanf(ad,"%s %s %d %s %s %d %d %s %d %d %d %d",t[i].nom,t[i].prenom,&t[i].identifiant,t[i].adresse,t[i].type,&t[i].nbr_tot,&t[i].nbr_curr,t[i].retardaire,&t[i].code1,&t[i].code2,&t[i].code3,&t[i].code4);   aux1=t[i].identifiant;	}   while(z!=t[i].identifiant && i<x );rewind(ad) ;
	do{ ii+=1;    fscanf(ad,"%s %s %d %s %s %d %d %s %d %d %d %d",t[ii].nom,t[ii].prenom,&t[ii].identifiant,t[ii].adresse,t[ii].type,&t[ii].nbr_tot,&t[ii].nbr_curr,t[ii].retardaire,&t[ii].code1,&t[ii].code2,&t[ii].code3,&t[ii].code4);	}   while( ii<x );rewind(ad) ;
	if(z!=t[i].identifiant) { printf("choix non trouvee! \n");exit(404);}  	hell=strcmp(t[i].retardaire,oui) ;	if(hell==0) { strcpy(t[i].retardaire,non) ; }   t[i].nbr_curr=t[i].nbr_curr -1; if(t[i].code1==code) t[i].code1=0;  else{ printf("\nVous n\'avez pas emprunter un document avec se code la! \n"); exit(333);}	rewind(ad) ;	
    for(int m=0;m<x;m++){ 	fprintf(ad,"%s %s %d %s %s %d %d %s %d %d %d %d\n",t[m].nom,t[m].prenom,t[m].identifiant,t[m].adresse,t[m].type,t[m].nbr_tot,t[m].nbr_curr,t[m].retardaire,t[m].code1,t[m].code2,t[m].code3,t[m].code4);}   printf("\nla modification de visiteur a terminee avec succee! \n") ; break ;}	
}
void modifier_docu(FILE *f,int z,int test)
{	int i=-1,ii=-1,x=0,hell,com,aux1; char ch5[cte*2],chaine[cte*50];rewind(f) ;
	switch(test){		 	
	case 1: do{  x++;fscanf(f,"%s",ch5);fgets(chaine,2499,f);hell=strcmp(ch5,"fiin3finfinfzeANbBrty");	} while(hell!=0); 	rewind(f) ;;break;			
	case 2: do{  x++;fscanf(f,"%s",ch5);fgets(chaine,2499,f);hell=strcmp(ch5,"fiin3finfinfzeANbBrty");	} while(hell!=0);	rewind(f) ;	 ;break;	
	case 3: do{  x++;fscanf(f,"%s",ch5);fgets(chaine,2499,f);hell=strcmp(ch5,"fiin3finfinfzeANbBrty");	} while(hell!=0);	rewind(f) ;;break;	    }
	struct livre	{ char type[cte], titre[cte*2],localisation[cte*2], nom_auteur[cte*2],nom_editeur[cte*2],ch0[cte], ch1[cte],ch2[cte],ch3[cte],ch4[cte] ;     int code,nbr_cop,nbr_tot;	} ;  struct  livre t[x+1] ;
	struct magasine	{ char type[cte], titre[cte*2],localisation[cte*2],ch0[cte], ch1[cte],ch2[cte],ch3[cte],ch4[cte] ;     int code,nbr_cop,nbr_tot;	} ;  struct  magasine t1[x+1] ;
	struct article	{ char type[cte], titre[cte*2],localisation[cte*2],nom_auteur[cte*2] ,ch0[cte], ch1[cte],ch2[cte],ch3[cte],ch4[cte];    int code,nbr_cop,nbr_tot;} ;  struct  article t2[x +1] ; 
switch( test) {
	case 1 :do{ i+=1;     fscanf(f,"%s %s %s %d %d %s %s %d %s %s %s %s %s ",t[i].type,t[i].titre,t[i].localisation,&t[i].code,&t[i].nbr_cop,t[i].nom_auteur,t[i].nom_editeur,&t[i].nbr_tot,t[i].ch0,t[i].ch1,t[i].ch2,t[i].ch3,t[i].ch4);com=strcmp(t[i].type,""); if (com==0) break;    aux1=t[i].code; 	}   while(z!=t[i].code && i<x );rewind(f) ; 
	do  { ii+=1;   fscanf(f,"%s %s %s %d %d %s %s %d %s %s %s %s %s ",t[ii].type,t[ii].titre,t[ii].localisation,&t[ii].code,&t[ii].nbr_cop,t[ii].nom_auteur,t[ii].nom_editeur,&t[ii].nbr_tot,t[ii].ch0,t[ii].ch1,t[ii].ch2,t[ii].ch3,t[ii].ch4);com=strcmp(t[ii].type,""); if (com==0) break;       	}   while( ii<x );rewind(f) ;
	if(z!=t[i].code) { printf("choix non trouvee! \n");exit(494);}     	t[i].nbr_cop+=1;  	rewind(f) ;	
    for(int i=0;i<x;i++)  fprintf(f,"%s   %s   %s   %d   %d   %s   %s   %d   %s  %s  %s  %s  %s\n",t[i].type,t[i].titre,t[i].localisation,t[i].code,t[i].nbr_cop,t[i].nom_auteur,t[i].nom_editeur,t[i].nbr_tot,t[i].ch0,t[i].ch1,t[i].ch2,t[i].ch3,t[i].ch4);   printf("\nla modification de livre a terminee avec succee! \n") ;	 break ; 
	case 2 :do{ i+=1;   fscanf(f,"%s %s %s %d %d %d %s %s %s %s %s",t1[i].type,t1[i].titre,t1[i].localisation,&t1[i].code,&t1[i].nbr_cop,&t1[i].nbr_tot,t1[i].ch0,t1[i].ch1,t1[i].ch2,t1[i].ch3,t1[i].ch4);com=strcmp(t1[i].type,""); if (com==0) break;   aux1=t1[i].code;	}   while(z!=t1[i].code && i<x );rewind(f) ;
	do{ ii+=1;  fscanf(f,"%s %s %s %d %d %d %s %s %s %s %s",t1[ii].type,t1[ii].titre,t1[ii].localisation,&t1[ii].code,&t1[ii].nbr_cop,&t1[ii].nbr_tot,t1[ii].ch0,t1[ii].ch1,t1[ii].ch2,t1[ii].ch3,t1[ii].ch4);com=strcmp(t1[ii].type,""); if (com==0) break;       	}   while( ii<x );rewind(f) ;
	if(z!=t1[i].code) { printf("choix non trouvee! \n");exit(404);}    	t1[i].nbr_cop+=1;  	rewind(f) ;	
    for(int i=0;i<x;i++)  fprintf(f,"%s   %s   %s   %d   %d   %d    %s   %s   %s   %s   %s\n",t1[i].type,t1[i].titre,t1[i].localisation,t1[i].code,t1[i].nbr_cop,t1[i].nbr_tot,t1[i].ch0,t1[i].ch1,t1[i].ch2,t1[i].ch3,t1[i].ch4);   printf("\nla modification de magasine a terminee avec succee! \n") ; break ; 
	case 3 :do{ i+=1;   fscanf(f,"%s %s %s %d %d %s  %d",t2[i].type,t2[i].titre,t2[i].localisation,&t2[i].code,&t2[i].nbr_cop,t2[i].nom_auteur,&t2[i].nbr_tot);com=strcmp(t2[i].type,""); if (com==0) break;    aux1=t2[i].code;	}   while(z!=t2[i].code && i<x );rewind(f) ;
	do{ ii+=1;  fscanf(f,"%s   %s   %s   %d   %d    %s   %d %s %s %s %s %s ",t2[ii].type,t2[ii].titre,t2[ii].localisation,&t2[ii].code,&t2[ii].nbr_cop,t2[ii].nom_auteur,&t2[ii].nbr_tot,t2[ii].ch0,t2[ii].ch1,t2[ii].ch2,t2[ii].ch3,t2[ii].ch4);com=strcmp(t[ii].type,""); if (com==0) break;      	}   while( ii<x );rewind(f) ;
	if(z!=t2[i].code) { printf("choix non trouvee! \n");exit(404);}   	t2[i].nbr_cop+=1; 	rewind(f) ;	
    for(int i=0;i<x;i++)  fprintf(f,"%s   %s   %s   %d   %d   %s    %d   %s  %s  %s   %s  %s\n",t2[i].type,t2[i].titre,t2[i].localisation,t2[i].code,t2[i].nbr_cop,t2[i].nom_auteur,t2[i].nbr_tot,t2[i].ch0,t2[i].ch1,t2[i].ch2,t2[i].ch3,t2[i].ch4);   printf("\nla modification de l\'article a terminee avec succee! \n") ;	 break ; 	}
}
void retourner_document(FILE *f,FILE *ad,int test,int testt,int ccode,int *cd,int *tm){ 
	int i=-1 ,rech,com=-1,x,xx=0,hell,code,hell1,hi=0;	char chaine[cte*20] ;    int a,b,c,d,e,ff,g,h,y=0 ; char ch1[cte*2],ch2[cte*2],ch3[cte*2],ch4[cte*2],ch5[cte*2] ; 		rewind(f);	rewind(ad); 
		        switch(testt){
		        	case 1: do{ hi+=1;printf("\ndonner  le  code  du  livre  : ");scanf("%d",&code);*cd=code; recherche_docu(f, code, testt,ccode,tm);}while(hi<3 && *tm==0); if(*tm==0) printf("\nVous avez depassee le nombre maximale d\'essayes!");break;hi=0;
		        	case 2: do{ hi+=1;printf("\ndonner le code de la magasine: ");scanf("%d",&code);*cd=code; recherche_docu(f, code, testt,ccode,tm);}while(hi<3 && *tm==0); if(*tm==0) printf("\nVous avez depassee le nombre maximale d\'essayes!");break; hi=0;
		        	case 3: do{ hi+=1;printf("\ndonner le code de l\'article  : ");scanf("%d",&code);*cd=code; recherche_docu(f, code, testt,ccode,tm);}while(hi<3 && *tm==0); if(*tm==0) printf("\nVous avez depassee le nombre maximale d\'essayes!");break;hi=0;
		        	default :printf("choix non trouvee!\n"); break;				}	rewind(f);	rewind(ad);	
}
struct rec { int co,nb;  char ty[cte] ;   } ;
struct doc {int code,nb; char type[cte] ; }aax;
void remove_recurrence(rec *ts ,int *n ) //le tableau ne contient pas des zeros initialement
{  int x=-1; rec retour[*n+1] ;
 for(int i=0; i<*n;i++ ) ts[i].nb=1 ;
 for(int i=0; i<*n;i++ ){	for(int j=i+1;j<*n;j++){ 	if(ts[i].co==ts[j].co ) { ts[j].co=0 ;ts[i].nb+=1 ;} 	}    }
 for(int i=0;i<*n;i++){      if(ts[i].co!=0){ x+=1;retour[x].co=ts[i].co ;retour[x].nb=ts[i].nb;}  } 	*n=x+1 ;
 for(int i=0;i<*n;i++){ 	 ts[i].co=retour[i].co ; ts[i].nb=retour[i].nb; }	 
 }
void  aff_liste_doc(FILE *f, rec *t,int *zid,int cl) //cl=1: doc en cours  ; cl=2 doc dep la date limite
{   int a,b,c,d,e,ff,g,h,hell,x=0,y=0,z=*zid ; //initialement *zid doit etre egal -1
    char ch1[cte*2],ch2[cte*2],ch3[cte*2],ch4[cte*2],ch5[cte*2],chaine[cte*50],oui[]="oui" ;   
	do{  x++; 	} while((fgets(chaine,2499,f))!=NULL); 	rewind(f) ;
	if(cl==1){
	do{ y++;   fscanf(f,"%s %s %d %s %s %d %d %s %d %d %d %d",ch1,ch2,&a,ch3,ch4,&b,&c,ch5,&d,&e,&ff,&g) ;	    if(d!=0){ z+=1; t[z].co = d; } if(e!=0){ z+=1; t[z].co = e; } if(ff!=0){ z+=1; t[z].co = ff; } if(g!=0){ z+=1; t[z].co = g; } *zid=z+1 ;   }   while( y<x );
             } else   do{ y++; fscanf(f,"%s %s %d %s %s %d %d %s %d %d %d %d",ch1,ch2,&a,ch3,ch4,&b,&c,ch5,&d,&e,&ff,&g) ;	hell=strcmp(ch5,oui) ;   if(d!=0 && hell==0){ z+=1; t[z].co = d; } if(e!=0 && hell==0){ z+=1; t[z].co = e; } if(ff!=0 && hell==0){ z+=1; t[z].co = ff; } if(g!=0 && hell==0){ z+=1; t[z].co = g; } *zid=z+1 ;    }   while( y<x );           
}
void effectuer_document(FILE *f, int code,int test,char *le,int *ops){
	int a,b,c,d,e,ff,g,h,x=0,y=0 ; char ch1[cte*2],ch2[cte*2],ch3[cte*2],ch4[cte*2],ch5[cte*2],ch6[cte*2],ch7[cte*2],ch8[cte*2],ch9[cte*2],chaine[cte*50] ; 
    do{  x++; 	} while((fgets(chaine,2499,f))!=NULL);
	rewind(f) ; *ops=1; 	char livre[]="livre",mag[]="magasine",arti[]="article" ;
	switch( test) {
	case 1 : 	do{ y++; fscanf(f,"%s %s %s %d %d %s %s  %d ",ch1,ch2,ch3,&a,&b,ch4,ch5,&c) ;	fgets(chaine,2499,f); }while(code!=a && y<x ); 	if(code==a)   strcpy(le,livre); else *ops=0;	 break ;
    case 2 : 	do{ y++; fscanf(f,"%s %s %s %d %d %d ",ch1,ch2,ch3,&a,&b,&c) ;	fgets(chaine,2499,f); }   while(code!=a && y<x ); if(code==a)  strcpy(le,mag); else *ops=0;       	break ;
    case 3 : 	do{ y++; fscanf(f,"%s %s %s %d %d %s  %d ",ch1,ch2,ch3,&a,&b,ch4,&c) ;	fgets(chaine,2499,f); }   while(code!=a && y<x ); if(code==a)  strcpy(le,arti); else *ops=0; break ;
	default: printf("Choix non trouvee!\n"); break ;   }rewind(f ) ;		
}
