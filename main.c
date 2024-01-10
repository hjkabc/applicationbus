#include <stdio.h>
#include <stdlib.h>
struct voyageur{
           char nom[20];
           int age;
           char datedeb[10];
           }voyageur;
struct reserv{
           int num;
           int numbus;
           char nom[20];
           char datedeb[10];
           struct reserv *next;
           }reserv;
struct bus{
           int num;
           int nbremax;
           struct bus *next;
          }bus ;
struct description {
           char Marque[20],energie[20],couleur[20],etat[20],classe[20];
            float compteur;
            int Num,puissance;
           }description;
           
void ajouterbus() {
    struct bus newbus;
    FILE *f = fopen("bus.txt", "a");
    if (f == NULL) {
        printf("Error opening file.\n");
        return;
    }

    printf("\nEntrer le num du bus: ");
    int numbar;
    scanf("%d", &numbur);
    fflush(stdin);

    while (rech(numbus) == 1) {
        printf("\nCe numero existe deja. Entrer un autre: ");
        scanf("%d", &NumCar);
        fflush(stdin);
    }
    newbus.num = numbus;

    printf("Entrer le nombre maximal de places dans le bus: \n");
    scanf("%d", newbus.nbremax);
    printf("Registration successful.\n");

    fprintf(f, "%d;%d\n", newbus.num, newbus.nbremax);
    fclose(f);
}

void ajoutervoy() {
    struct voyageur voy ;
    FILE *f = fopen("voyageur.txt", "a+");
    if (f == NULL) {
        printf("Error opening file.\n");
        return;
    }

    printf("\nEntrer le numero de la nouvelle bus: ");
    scanf("%s",nom);
    fflush(stdin);

    while (rechvoy(nom) == 1) {
        printf("\nCe nom existe deja.Entrer un autre: ");
        scanf("%s",nom) ;
        fflush(stdin);
    }

void ajouterdes() {
    int numbus;
    struct description des ;
    FILE *f = fopen("description1.txt", "a+");
    if (f == NULL) {
        printf("Error opening file.\n");
        return;
    }

    printf("\nEntrer le numero de la nouvelle bus: ");
    scanf("%d", &numbus);
    fflush(stdin);

    while (rechdes(numbus) == 1) {
        printf("\nCe numero existe deja.Entrer un autre: ");
        scanf("%d", &numbus);
        fflush(stdin);
    }
    des.Num = NumCar;

    printf("Entrer La Marque: ");
    gets(des.Marque);

    printf("Entrer L'energie: ");
    gets(des.energie);

    printf("Entrer La couleur: ");
    gets(des.couleur);

    printf("Entrer l'etat de la voiture: ");
    gets(des.etat);

    printf("Entrer Classe de la voiture: ");
    gets(des.classe);

    printf("Entrer la puissance de la voiture: ");
    scanf("%d", &des.puissance);

    printf("Entrer le compteur de la voiture: ");
    scanf("%f", &des.compteur);

    printf("Registration successful.\n");

    fprintf(f, "%d;%s;%s;%s;%s;%s;%d;%f\n", des.num, des.Marque, des.energie,
            des.couleur, des.etat, des.classe, des.puissance, des.compteur);
    fclose(f);
}

void Affich_des() {
    int NumR;
    printf("Enter the car number: ");
    scanf("%d", &NumR);

void ajouterres() {
    int num
    struct reservation res ;
    FILE *f = fopen("reservation.txt", "a+");
    if (f == NULL) {
        printf("Error opening file.\n");
        return;
    }

    printf("\nEntrer le numero de la nouvelle reservation : ");
    scanf("%d",num);
    fflush(stdin);

    while (rechres(num) == 1) {
        printf("\nCe nom existe deja.Entrer un autre: ");
        scanf("%s",nom) ;
        fflush(stdin);
    }
    res.num = num;

    printf("Entrer le numero de bus correspndant   ");
    gets(res.numbus);
    printf("Entrer le nom du voyageur guide correspndant   ");
    gets(res.nom);
    printf("Entrer la date de la reservation");
    gets(res.datedeb);
    fclose(f);
}

int rechbus(int numbus) {
    FILE *f = fopen("bus.txt", "r");
    if (f == NULL) {
        printf("Error opening file.\n");
        return -1;
    }

    while (fscanf(f, "%d;%d\n", &bus.num, &bus.nbremax) != EOF) {
        if (bus.num == numbus) {
            fclose(f);
            return 1;
        }
    }

    fclose(f);
    return -1;
}           

int rechdes(int numbus) {
    FILE *f = fopen("description1.txt", "r");
    if (f == NULL) {
        printf("Error opening file.\n");
        return -1;
    }

    while (fscanf(f, "%d;%[^;];%[^;];%[^;];%[^;];%[^;];%d;%f\n",
                  &des.Num, des.Marque, des.energie, des.couleur,
                  des.etat, des.classe, &des.puissance, &des.compteur) != EOF) {
        if (des.num == numbus) {
            fclose(f);
            return 1;
        }
    }

    fclose(f);
    return -1;
}

int rechres(int num) {
    struct reservation res;
    FILE *f = fopen("reservation.txt", "r");
    if (f == NULL) {
        printf("Error opening file.\n");
        return -1;
    }

    while (fscanf(f, "%d;%d;%[^;];%[^;];%f\n",
                  &res.num,&res.numbus,res.nom,res,datedeb)!= EOF) {
        if (res.num == num) {
            fclose(f);
            return 1;
        }
    }

    fclose(f);
    return -1;
}

int rechvoy(char nom[20]) {
    struct voyageur voy;
    FILE *f = fopen("voyageur.txt", "r");
    if (f == NULL) {
        printf("Error opening file.\n");
        return -1;
    }

    while (fscanf(f, "%[^;];%d,%[^;];%f\n",
                  voy.nom,&voy.age,voy.datedeb)!= EOF) {
        if (voy.nom == nom) {
            fclose(f);
            return 1;
        }
    }

    fclose(f);
    return -1;
}

void affichertousbus() {
    FILE *f = fopen("bus.txt", "r");
    if (f == NULL) {
        printf("Error opening file.\n");
        return;
    }

    while (fscanf(f, "%d;%d\n", &car.num,&car.nbremax) != EOF) {
        printf("---DISPLAYING ALL CARS---\n");
        printf("NUMBER:\t%d\t", car.num);
        printf("MAX_NUMBER:\t%d\n", car.nbremax);
    }

    fclose(f);
}

void affichertoutesdes() {
    FILE *f = fopen("description.txt", "r");
    if (f == NULL) {
        printf("Error opening file.\n");
        return;
    }
    struct description des;
     while (fscanf(f, "%d;%[^;];%[^;];%[^;];%[^;];%[^;];%d;%f\n",
                  &des.Num, des.Marque, des.energie, des.couleur,
                  des.etat, des.classe, &des.puissance, &des.compteur) != EOF) {
         printf("---DISPLAYING Description---\n");
                printf("Num:\t%d\t", des.Num);
                printf("Marque:\t%s\t", des.Marque);
                printf("Energie:\t%s\t", des.energie);
                printf("Coleur:\t%s\t", des.couleur);
                printf("Etat:\t%s\t", des.etat);
                printf("Class:\t%s\t", des.classe);
                printf("Puissance:\t%d\t", des.puissance);
                printf("Compteur:\t%f\n", des.compteur);
       
    }

    fclose(f);
}

void modifierres() {
    int num;
    char rep = 'n';
    struct reservation ;
    printf("\nEntrer le numero de la reservation: ");
    scanf("%d", &num);
    fflush(stdin);

    if (rechres(num) == 1) {
        printf("\nVoulez Vous vraiment Modifier cette reservation? (o/n): ");
        scanf("%c", &rep);
        fflush(stdin);

        if (rep == 'o' || rep == 'O') {
            FILE *f = fopen("reservation.txt", "r");
            FILE *fich = fopen("texte2.txt", "a");
            if (f == NULL || fich == NULL) {
                printf("Error opening file.\n");
                return;
            }

            while (fscanf(f, "%d;%d;%[^;];%[^;];%[^;];\n",
                          &res.num, &res.numbus, res.nom,res.datedeb) != EOF) {
                if (num == res.Num) {
                    res.Num = num;
                    printf("Entrer le nouveau numero de bus: ");
                    gets(res.numbus);

                    printf("Entrer le nouveau nom de voyageur: ");
                    gets(res.nom);

                    printf("Entrer la nouvelle date du voyage: ");
                    gets(res.datedeb);
                    printf("\nModification successful.\n");
                }
                fprintf(fich, "%d;%d;%s;%s\n", res.num, res.numbus,
                        res.nom, res.datedeb);
            }

            fclose(f);
            fclose(fich);
            remove("reservation.txt");
            rename("texte2.txt", "reservation.txt");
            printf("Modification successful.\n");
        }

    }else printf("la description de cette reservation n'existe pas");
}


int main() {
    int choix;
    char rep;
    do {
        system("cls");
        printf("*************MENU************* \n");
        printf("1-Ajouter Un bus \n");
        printf("2-Verifier si un bus valable \n");
        printf("3-Afficher les details de tous les bus \n");
        printf("4-Ajouter un nouveau voyageur \n");
        printf("5-Verifier si un voyageur participe \n");
        printf("6-Ajouter une description d'un bus \n");
        printf("7-Verifier si une description existe  \n");
        printf("8-Afficher toutes les descriptions \n");
        printf("9-Ajouter une reservation \n");
        printf("10-Verifier si une reservation est validee \n");
        printf("11-Modifier une reservation  \n");
        printf("12-Quitter \n");
        do {
            printf("\n Entrer votre choix: ");
            scanf("%d", &choix);
        } while (choix < 1 || choix > 12);

        switch (choix) {
            case 1:
                ajouterbus();
                break;
            case 2:
                int num;
                printf("entrer le numero de bus recherchee:");
                scanf("%d",num);
                rechbus(num);
                break;
            case 3:
                affichertousbus();
                break;
            case 4:
                ajoutervoy();
                break;
            case 5:
                char nom[20];
                printf("donner le nom du voyageur recherche");
                scanf("%s",nom);
                rechvoy(nom);
                break;
            case 6:
                ajouterdes();
                break;
            case 7: 
                int num;
                printf("donner le numero de bus correspondant");
                scanf("%d",num);
                rechres(num);
                break;
            }
            case 8:
                affichertoutesdes();
                break;
            case 9:
                ajouterres();
                break;
            case 10:
                modifierres();
                break;
            case 11:
                break;
        }
        printf("\n Voulez vous continuer O/N:");
        scanf(" %c", &rep);
        fflush(stdin);
    } while (rep == 'o' || rep == 'O');
    return 0;
}
