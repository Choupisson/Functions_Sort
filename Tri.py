import random
import time 
import sys
import csv
from random import randint 

sys.setrecursionlimit(50000000) #définir une profondeur de récursivité plus élevée pour le triRapide sinon ne marche pas 


#####      #####     #####     #####      #####     #####     #####      #####     #####


def triSelection(liste):
    for i in range(len(liste)):
    # Trouver le min
       min = i
       for j in range(i+1, len(liste)):
           if liste[min] > liste[j]:
               min = j
                
       tmp = liste[i]
       liste[i] = liste[min]
       liste[min] = tmp
    return liste

def triSelectionPerf(liste):
    st = time.time()
    triSelection(liste)
    ''' print("Temps d'excécution de triSelection: %s" % (time.time() - st)) '''
    return (time.time()-st)


def triSelectionTest(tab1,tab2,tab3,tab4):
    triSelection(tab1)
    triSelection(tab3)
    
    if tab1 != tab2  :
        print("le Tableau n'est  pas trié")
    if tab3 != tab4  :
        print("le Tableau n'est  pas trié")
    else :
            print("tableau trié")  

    




#####      #####     #####     #####      #####     #####     #####      #####     #####

#####      #####     #####     #####      #####     #####     #####      #####     #####



def fusion(liste, deb, mid, fin):
    n1 = mid - deb + 1
    n2 = fin - mid
 
    # liste temporaire
    DEB = [0] * (n1)
    FIN = [0] * (n2)
 
    # Copie les listes dans L[] et R[]
    for i in range(0, n1):
        DEB [i] = liste[deb + i]
 
    for j in range(0, n2):
        FIN[j] = liste[mid + 1 + j]
    i = 0    
    j = 0    
    k = deb     
 
    while i < n1 and j < n2:
        if DEB [i] <= FIN[j]:
            liste[k] = DEB[i]
            i += 1
        else:
            liste[k] = FIN[j]
            j += 1
        k += 1
 
    #Copie les éléments de L si il y en a.
    while i < n1:
        liste[k] = DEB[i]
        i += 1
        k += 1
 
    # Pareil qu'avant mais pour R
    while j < n2:
        liste[k] = FIN[j]
        j += 1
        k += 1
 
 
def triFusion(liste, deb, fin):
    if deb < fin:
 
        # Identique à (l+r)//2, mais évite le débordement
        mid = deb+(fin-deb)//2
 
        # Trier les premières et deuxièmes moitiés
        triFusion(liste, deb, mid)
        triFusion(liste, mid+1, fin)
        fusion(liste, deb, mid, fin)
    

def triFusionPerf(liste):
    st = time.time()
    triFusion(liste,0,len(liste)-1)
    ''' print("Temps d'excécution de triFusion: %s" % (time.time() - st)) '''
    return (time.time()-st)

def triFusionTest(tab1,tab2,tab3,tab4):
    triSelection(tab1,0,len(tab1)-1)
    triSelection(tab3,0,len(tab1)-1)
    
    if tab1 != tab2  :
        print("le Tableau n'est  pas trié")
    if tab3 != tab4  :
        print("le Tableau n'est  pas trié")
    else :
            print("tableau trié")  

#####      #####     #####     #####      #####     #####     #####      #####     #####

#####      #####     #####     #####      #####     #####     #####      #####     #####


def triBulles (liste) :
    permutation = True
    n=len(liste)
     
    while permutation==True : #on répéte la procédure tant qu'on a trouvé une permutation (c-à-d L[i]>L[i+1] l'élément e de la liste est plus grand que l'élément qui le suit)
        permutation = False # on considère qu'il n'existe aucune permutation (c-à-d la liste est triée)
     
        for  i  in range(n-1) : # on parcour la liste pour chercher s'il y une permutation
            if liste[i] > liste[i+1] :
                permutation = True # permutation existe on change la variable permutation en True
                liste[i],liste[i+1]= liste[i+1],liste[i] # on met L[i] et L[i+1] en ordre
    return liste


def triBullesPerf(liste):
    st = time.time()
    triBulles(liste)
    ''' print("Temps d'excécution de triBulles: %s" % (time.time() - st)) '''
    return (time.time()-st)


def triBullesTest(tab1,tab2,tab3,tab4):
    triSelection(tab1)
    triSelection(tab3)
    
    if tab1 != tab2  :
        print("le Tableau n'est  pas trié")
    if tab3 != tab4  :
        print("le Tableau n'est  pas trié")
    else :
            print("tableau trié")  




#####      #####     #####     #####      #####     #####     #####      #####     #####

#####      #####     #####     #####      #####     #####     #####      #####     #####


def partitionner(liste, deb, fin):
    i = (deb-1)         # le + petit éléments
    pivot = liste[fin]   
 
    for j in range(deb, fin):
 
        # Si l'élément est plus petit ou égal au pivot 
        if liste[j] <= pivot:
 
            #incrémentation du plus petit élément
            i = i+1
            liste[i], liste[j] = liste[j], liste[i]
 
    liste[i+1], liste[fin] = liste[fin], liste[i+1]
    return (i+1)
 

 
def triRapide(liste, deb, fin):
    if len(liste) == 1:    #cas un peu inutile car si notre liste fait cette taille -> aucun interêt pour l'étude mener
        return liste       #mais on le laisse car cas possible..
    if deb < fin:
        #emplacement -> indice de partitionnernement 
        emplacement = partitionner(liste, deb, fin)
        #Trier les éléments séparément avant partitionner et après partitionner
        triRapide(liste, deb, emplacement-1)
        triRapide(liste, emplacement+1, fin)


# def echange(T,i,j):
#     T[i],T[j]=T[j],T[i]
    
# def partition(T,g,d):
    
#     #choix pivot
#     m=randint(g,d-1)
#     p=T[m]
#     #On place pivot à gauche au depart
#     echange(T,g,m)
#     m=g
#     for i in range (g+1,d):
#         if T[i]<p:
#             echange(T,i,m+1)
#             m=m+1
#     echange(T,g,m)
#     return m

# def triRapide(T,g,d):
#     if g<d-1 :
#         m=partition(T,g,d)
#         triRapide(T,g,m)
#         triRapide(T,m+1,d)


        
def triRapidePerf(liste):
    n=len(liste)-1
    st = time.time()
    triRapide(liste,0,n)
    ''' print("Temps d'excécution de triRapide: %s" % (time.time() - st)) '''
    return (time.time()-st)


def triRapideTest(tab1,tab2,tab3,tab4):
    triSelection(tab1,0,len(tab1)-1)
    triSelection(tab3,0,len(tab1)-1)
    
    if tab1 != tab2  :
        print("le Tableau n'est  pas trié")
    if tab3 != tab4  :
        print("le Tableau n'est  pas trié")
    else :
            print("tableau trié")  
            
            
            
            
            
    
#####      #####     #####     #####      #####     #####     #####      #####     #####

#####      #####     #####     #####      #####     #####     #####      #####     #####






def benchmarkGlobal():
    fichier=open("infoPYTHON.csv","w")
    liste = [random.randint(0, 9) for p in range(0,30001)] # créer une liste aléatoire de nb entre 0-9 d'une range de 30001
    liste1= liste
    
    fichier.write("taille tableau,")
    fichier.write("triSelection,")
    fichier.write("triFusion,")
    fichier.write("triBulles,")
    fichier.write("triRapide \n")
    
    for i in range(0,30001,5000):
        print(i)
        fichier.write(str(i)+",")
        # fichier.write(str(triSelectionPerf(liste1[:i]))+",")
        liste1=liste
        
        # fichier.write(str(triFusionPerf(liste1[:i]))+",")
        liste1=liste
        
        # fichier.write(str(triBullesPerf(liste1[:i]))+",")
        liste1=liste
        
        fichier.write(str(triRapidePerf(liste1[:i]))+"\n")
        
    fichier.close();
     
 
 
if __name__ == '__main__':  
    
    
    #//*******TABLEAU DE TEST*******//#

    tab1=[1,6,2,7,9,3,0]
    tab2=[0,1,2,3,6,7,9];
    tab3=[0,0,0,0,0,0,0];
    tab4=[0,0,0,0,0,0,0];

    #//*******TABLEAU DE TEST*******//#
    
    
    #//*******APPEL DES TEST*******//#
    
    # triSelectionTest(tab1,tab2,tab3,tab4)
    # triFusionTest(tab1,tab2,tab3,tab4)
    # triBullesTest(tab1,tab2,tab3,tab4)
    # triRapideTest(tab1,tab2,tab3,tab4)
    
    #//*******APPEL DES TEST*******//#
    
    
    #//*******AFFICHE LE TABLEAU GENERER, PUIS CELUI-CI UNE FOIS TRIER PAR UNE FONCTION DE NOTRE CHOIX *******//#
    
    # liste = [random.randint(0, 9) for p in range(0,10)] #génère une liste de 0 à 10, uniquement avec des chiffres de 0 à 9
    # print(liste)
    # triSelection(liste)                         //Fonction de notre choix 
    # print(liste)
    
    #//*******AFFICHE LE TABLEAU GENERER, PUIS CELUI-CI UNE FOIS TRIER PAR UNE FONCTION DE NOTRE CHOIX *******//#
    
    
     #//*******CALCUL DU TEMPS DE TOUTES LES FONCTIONS TRIS AVEC UN PAS DONNER, ENVOIE DONNER DANS UN FICHIER CSV*******//#
    
    
    benchmarkGlobal()