#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <sys/types.h>
#include <string.h>

void triSelection( int * tab, int n){
    int max,i,j;
    i = n-1;
    while (i>0){
        max = 0;
        for(j=1; j<=i; j++){
            if (tab[j]>tab[max]){
                max = j;
            }
        }
        int perms;
        perms = tab[max];
        tab[max]=tab[i];
        tab[i]=perms;
        i=i-1;
    }
}

int triSelectionTest(int * tab1, int * tab2,int * tab3, int * tab4, int n){
    int r=0,i=0;
    triSelection(tab1,n);   
    triSelection(tab3,n);
    while(i<n && r==0){
        if(tab1[i] != tab2[i]){      //vérifie que tab1 = tab2 car tab2 est trié
        r=1;
        printf("Le tableau n'est pas trié");
        }
        i++;
    }
    while(i<n && r==0){
        if(tab3[i] != tab4[i]){ 
        r=1;
        printf("Le tableau n'est pas trié");
        }
        i++;
    }
    if(r==0)
    printf("Le tableau est trié");   // si r non modifier, tab1=tab2 et tab3=tab4
}


double triSelectionPerf(int * tab, int n){
    
    double tmpMoy = 0;
    for(int i = 0; i < 3; i++){
        int *temp=malloc(sizeof(int) * n);
        for(int j = 0; j < n; j++){
            temp[j] = tab[j];
    }
    clock_t start, end;
    start = clock();
    triSelection(tab,n);      
    end = clock();
    tmpMoy+=(double)(end-start)/CLOCKS_PER_SEC; 
    /* printf("temps d’exécution de la méthode triSelection: %f \n",(double)(end-start)/CLOCKS_PER_SEC ); */ // Si on souhaite une trace visuel
    free(temp);
    }
    return (tmpMoy/3);        //retourne une valeur moyenne de trois 3 données du temps d'excécution
}



/* ############################################################################################################ */
/* ############################################################################################################ */



void fusion(int tab[], int deb, int mid, int fin)
{
    int i, j, k;
    int n1 = mid - deb + 1;
    int n2 = fin - mid;
  
    
    int DEB[n1], FIN[n2];
  
    
    for (i = 0; i < n1; i++)
        DEB[i] = tab[deb + i];
    for (j = 0; j < n2; j++)
        FIN[j] = tab[mid + 1 + j];
  
    
    i = 0; 
    j = 0; 
    k = deb; 
    while (i < n1 && j < n2) {
        if (DEB[i] <= FIN[j]) {
            tab[k] = DEB[i];
            i++;
        }
        else {
            tab[k] = FIN[j];
            j++;
        }
        k++;
    }
  
    while (i < n1) {
        tab[k] = DEB[i];
        i++;
        k++;
    }
  

    while (j < n2) {
        tab[k] = FIN[j];
        j++;
        k++;
    }
}

void mergeSort(int * tab,int i, int j){
    if (i<j){
        mergeSort(tab, i, (i+j)/2 );
        mergeSort( tab, (i+j)/2+1, j);
        fusion(tab, i, (i+j)/2, j);
    }
} 

void triFusion(int *tab, int n){
    mergeSort(tab,0,n-1);
}

double triFusionPerf(int * tab, int n){
    
    
    double tmpMoy = 0;
    for(int i = 0; i < 3; i++){
        int *temp=malloc(sizeof(int) * n);
        for(int j = 0; j < n; j++){
            temp[j] = tab[j];
    }
    clock_t start, end;
    start = clock();
    triFusion(tab,n);      
    end = clock();
    tmpMoy+=(double)(end-start)/CLOCKS_PER_SEC;
    /* printf("temps d’exécution de la méthode triFusion: %f \n",(double)(end-start)/CLOCKS_PER_SEC ); */
    free(temp);
    }
    return (tmpMoy/3);
}

int triFusionTest(int * tab1, int * tab2,int * tab3, int * tab4, int n){
    int r=0,i=0;
    triFusion(tab1,n);
    triFusion(tab3,n);
    while(i<n && r==0){
        if(tab1[i] != tab2[i]){ 
        r=1;
        printf("Le tableau n'est pas trié");
        }
        i++;
    }
    while(i<n && r==0){
        if(tab3[i] != tab4[i]){ 
        r=1;
        printf("Le tableau n'est pas trié");
        }
        i++;
    }
    if(r==0)
    printf("Le tableau est trié");
}


/* ############################################################################################################ */
/* ############################################################################################################ */



void triBulles(int * tab, int n) {
    int i = 0;
    int j = 0;
    int tmp;
    for (i = 0; i < n; i++) {   // boucle n fois - 1 par élément
        for (j = 0; j < n - i - 1; j++) { // les derniers éléments i sont déjà triés
            if (tab[j] > tab[j + 1]) {  // échanger si l'éléments suivant et plus petit 
                tmp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = tmp;
            }
        }
    }
}



double triBullesPerf(int * tab, int n){
    
    double tmpMoy = 0;
    for(int i = 0; i < 3; i++){
        int *temp=malloc(sizeof(int) * n);
        for(int j = 0; j < n; j++){
            temp[j] = tab[j];
    }
    clock_t start, end;
    start = clock();
    triBulles(tab,n);      
    end = clock();
    tmpMoy+=(double)(end-start)/CLOCKS_PER_SEC;
    /* printf("temps d’exécution de la méthode triBulles: %f \n",(double)(end-start)/CLOCKS_PER_SEC ); */
    free(temp);
    }
    return (tmpMoy/3);
}


int triBullesTest(int * tab1, int * tab2,int * tab3, int * tab4, int n){
    int r=0,i=0;
    triBulles(tab1,n);
    triBulles(tab3,n);
    while(i<n && r==0){
        if(tab1[i] != tab2[i]){ 
        r=1;
        printf("Le tableau n'est pas trié");
        }
        i++;
    }
    while(i<n && r==0){
        if(tab3[i] != tab4[i]){ 
        r=1;
        printf("Le tableau n'est pas trié");
        }
        i++;
    }
    if(r==0)
    printf("Le tableau est trié");
}


/* ############################################################################################################ */
/* ############################################################################################################ */


void echanger(int tab[], int i, int j)
     {
     int memoire;    
     memoire=tab[i];
     tab[i]=tab[j];
     tab[j]=memoire;
     }

int partitionner(int tab[], int deb, int fin){
    int cpt=deb,pivot=tab[deb],i;

    for(i=deb+1;i<=fin;i++)
        {
        if(tab[i]<pivot)
            {
            cpt++;
            echanger(tab,cpt,i);
            }
        }
    echanger(tab,cpt,deb);
    return(cpt);
    }

void triRapide(int tab[],int debut,int fin)
    {
    if(debut<fin)
        {
        int pivot=partitionner(tab,debut,fin);
        triRapide(tab,debut,pivot-1);
        triRapide(tab,pivot+1,fin);
        }
    }

double triRapidePerf(int * tab, int n){
    
    double tmpMoy = 0;
    for(int i = 0; i < 3; i++){
        int *temp=malloc(sizeof(int) * n);
        for(int j = 0; j < n; j++){
            temp[j] = tab[j];
    }
    clock_t start, end;
    start = clock();
    triRapide(tab,0,n);      
    end = clock();
    tmpMoy+=(double)(end-start)/CLOCKS_PER_SEC;
    /* printf("temps d’exécution de la méthode triRapide: %f \n",(double)(end-start)/CLOCKS_PER_SEC ); */
    free(temp);
    }
    return (tmpMoy/3);
}

int triRapideTest(int * tab1, int * tab2,int * tab3, int * tab4, int n){
    int r=0,i=0;
    triRapide(tab1,0,n);
    triRapide(tab3,0,n);
    while(i<n && r==0){
        if(tab1[i] != tab2[i]){ 
        r=1;
        printf("Le tableau n'est pas trié");
        }
        i++;
    }
    while(i<n && r==0){
        if(tab3[i] != tab4[i]){ 
        r=1;
        printf("Le tableau n'est pas trié");
        }
        i++;
    }
    if(r==0)
    printf("Le tableau est trié");
}


/* ############################################################################################################ */
/* ############################################################################################################ */

void genTab(int * tab, int n){  
    srand(time(NULL));
    for (int i=0; i<=n;i++) {
        tab[i]= rand() % 10;
        
    }
}

void affiche(int * tab, int n){
    for (int i=0; i<n;i++){    //Parcourir le tableau 1 à 1
        printf("%d ",tab[i]);
    }
    
}

/* ############################################################################################################ */
/* ############################################################################################################ */


void copy(int * tab,int n,int * tabBackup){
    for (int i=0;i<n;i++){
        tabBackup[i] = tab[i];    
    }
}


void benchmarkGlobal(int n, int pas){
    FILE *outputFile=NULL;
    outputFile = fopen("infoC.csv","w+");

    //Première ligne : nom des tris + taille tableau
    fprintf(outputFile,"%s","taille du tableau,");
    fprintf(outputFile,"%s","triSelection,");
    fprintf(outputFile,"%s","triFusion,");
    fprintf(outputFile,"%s","triBulles,");
    fprintf(outputFile,"%s","triRapide \n");


    for(int i=0;i<=n;pas){ 
        int * tab = malloc(sizeof(int)*n); 
        int * tabBackup = malloc(sizeof(int)*n); 

        genTab(tab,n);
        printf("%d \n",i);
        //valeur de "i" qui représente la taille du tableau à chaque itération de la boucle 
        fprintf(outputFile,"%d,",i);

        copy(tab,n,tabBackup);
        fprintf(outputFile,"%f,",triSelectionPerf(tab,i));
       



        copy(tabBackup,n,tab);
        fprintf(outputFile,"%f,",triFusionPerf(tab,i));
        

        copy(tabBackup,n,tab);
        fprintf(outputFile,"%f,",triBullesPerf(tab,i));
        

        copy(tabBackup,n,tab);
        fprintf(outputFile,"%f \n",triRapidePerf(tab,i));
       

        
        i+=pas;
        free(tab);
        free(tabBackup);
    }
}









int main()
{
    //*******TABLEAU POUR LES TEST*******//

    int tab1[]={1,6,2,7,9,3,0};
    int tab2[]={0,1,2,3,6,7,9};

    int tab3[]={0,0,0,0,0,0,0};
    int tab4[]={0,0,0,0,0,0,0};

    //*******TABLEAU POUR LES TEST*******//
    
    //*******APPEL TEST*******//

/*     triSelectionTest(tab1,tab2,tab3,tab4,7);
    triFusionTest(tab1,tab2,tab3,tab4,7);
    triBullesTest(tab1,tab2,tab3,tab4,7);
    triRapideTest(tab1,tab2,tab3,tab4,7); */

    //*******APPEL TEST*******//


    
    /* ############################################################ */
    /* ############################################################ */



    //*******SI ON SOUHAITE AFFICHE LE TABLEAU GENERER, PUIS CELUI-CI UNE FOIS TRIER*******//

/*     int * tab = malloc(sizeof(int)*10); 
    genTab(tab,10);
    affiche(tab,10);
    printf("\n");
    triFusion(tab,7);                           //Mettre tableau de votre choix 
    affiche(tab,7); */
 
    //*******SI ON SOUHAITE AFFICHE LE TABLEAU GENERER, PUIS CELUI-CI UNE FOIS TRIER*******//



    /* ############################################################ */
    /* ############################################################ */
 
    
    //*******CALCUL DU TEMPS DE TOUTES LES FONCTIONS TRIS AVEC UN PAS DONNER, ENVOIE DONNER DANS UN FICHIER CSV*******//



    benchmarkGlobal(20000,5000);  

    
    return 0;
}