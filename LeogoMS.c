#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

int row=25;
int column=80;
int  numberbomb=200; /// I added a lot of number of the bombs so the user can easily win the game.
int  numsuperbomb =20; /// number of superbombs
char superbomb='*';
char bomb='o';
char empty='_';
int i=0, j=0;


char gridfront[25][80];
char gridback[25][80];
void blankgridboard();
void genrandombomb();
void playgame();
void gotoxy();
void displaygotoxy();

int main(){
    blankgridboard();
    genrandombomb();
    playgame();
    getch();

    return 0;
}


void blankgridboard(){
    ///stores every matrix or the whole grid as empty

    for(i=0; i<row; i++){
        for(j=0; j<column; j++){
            gridback[i][j]= empty;
        }
    }
}
void genrandombomb(){
    /// generate random bomb

srand(time(0));
    for(i=0; i<numberbomb; i++){
        int x = rand() % row;
        int y = rand() % column;

        gridback[x][y]= bomb; /// stores in gridback
        printf("BOMBS HINTS: ");
        printf("%d \t %d\n", x,y); /// prints the coordination of the bombs

           }

     /// generate super bomb and stores in gridback
    for(i=0; i<numsuperbomb; i++){
        int sx = rand() % row;
        int sy = rand() % column;

        gridback[sx][sy]= superbomb;
        printf("SUPER BOMBS: ");
        printf("%d \t %d \n", sx, sy);

           }
        }

void displaygridfront(){

    /// The coordinates that the user inputted will show.

    for(i=0; i<row; i++){
      printf("%c",gridfront[i][j]);
    for(j=0; j<column; j++){
    printf("%c", gridfront[i][j]);
        }
        printf("\n");
    }
}
void displaygridback(){

    /// all the stored data where it will show the whole coordinates of bombs and empty.

    for(i=0; i<row; i++){
        printf("%c",gridback[i][j]);
        for(j=0; j<column; j++){
        printf("%c", gridback[i][j]);
        }
            printf("\n");
    }
}

void playgame() {
    int x,y, attempts=0, lives =8, score=0;


    getch();
    system("cls");

   while(1){
        printf("\t YOU ONLY HAVE TO FIND 10 BOMBS TO WIN.. BEWARE OF SUPERBOMBS!! ***\n");
        printf("\n Your Score is: %d ",score);
        printf("\n Tries: %d", attempts);
        printf("\n \nYou have %d lives left", lives);
        printf("\n Enter x (0- 25): ");
        scanf("%i",&x);
        printf("Enter y (0-80): ");
        scanf("%i",&y);

        system("cls");

        attempts++;
        if(x <row && y<column){
         gridfront[x][y]=gridback[x][y]; /// since the gridfront is just an emptyrow, it will now show the chosen data from the gridback.
//
//
         displaygridfront();
        }
        else{
           printf("\n Enter a correct coordinate");

        }

        if(gridfront[x][y]==bomb){
                score++;}

        if(gridfront[x][y]==superbomb){
                printf("\n YOU HIT A SUPERBOMB!"); ///hitting a superbomb means you will instantly lose the game
                system("cls");

                displaygridback();

                printf("\n \n  ****  Y O U   L O S E ! ***** ");
                printf("\n     ^^^^^ Y O U   H I T   A  S U P E R B O M B ");
                exit(0);
        }
        if(gridfront[x][y]==empty){
            lives--;
        }


        if(score==10){
            system("cls");
            printf("\n \n Y O U  W O N \n"); /// you will win if you reach the winning points of 10.

            displaygridback(); ///display the whole game
            exit(0);

        }


        if(lives==0){
            system("cls");

            displaygridback();

            printf("\n \n  Y O U   L O S E !");
            exit(0);


        }

    }

system("cls");
}
