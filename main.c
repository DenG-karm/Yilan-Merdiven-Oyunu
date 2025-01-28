#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int rolldie() {
    return rand() % 6 +1;
}
int player1=0 , player2=0;
void printboard() {
    int board[101];
    for(int i=0;i<=100;i++) {
        board[i]=i;
    }
    int alt=0;
    int iterlr=101;
    int iterrl=80;
    int val=100;
    while (val--) {
        if (alt ==0) {
            iterlr--;
            if (iterlr==player1) {
                printf("#P   ");
            }
            else if (iterlr==player2) {
                printf("#P2   ");
            }
            else{
                printf("%d  ", board[iterlr]);
            }
            if (iterlr%10==1) {
                printf("\n\n");
                alt=1;
                iterlr-=10;
            }
        }
        else {
            iterrl++;
            if (iterrl==player1) {
                printf("#P   ");
            }
            else if (iterrl==player2) {
                printf("#P2   ");
            }
            else{
                printf("%d  ", board[iterrl]);
            }
            if (iterrl%10==0) {
                printf("\n\n");
                alt=0;
                iterrl-=30;
            }
        }
        if (iterrl==10) {
            break;
        }
        printf("\n");
    }
}
    int moveplayer(int currentplayer , int roll){
        int newposition = currentplayer+roll;
    int snakesandladers[101];
    for(int i=0;i<=100  ;i++) {
        snakesandladers[i]=0;
    }
    snakesandladers[6]=40;
    snakesandladers[23]=-10;
    snakesandladers[45]=-7;
    snakesandladers[61]=-18;
    snakesandladers[65]=-8;
    snakesandladers[77]=5;
    snakesandladers[98]=-10;

    int newsquare = newposition + snakesandladers[newposition];
if (newsquare >100){
return currentplayer;
}
    return newsquare;



    }
int main() {
    srand(time(0));
    int currentplayer =1;
    int won = 0;
    printf("Snakes and ladder game\n");
    while (!won) {
        printf("\n Player %d, press Enter to roll die...",currentplayer);
        getchar();
        int roll=rolldie();
        printf("You rolled a %d.\n",roll);
        if (currentplayer==1) {
            player1 = moveplayer(player1,roll);
            printf("Player 1 is now at square %d.\n\n",player1);
            printboard();
            if (player1==100) {
                printf("Player 1 is wins!\n");
                won=1;
            }
        }
        else {
            player2 = moveplayer(player2,roll);
            printf("Player 2 is now at square %d.\n\n",player2);
            printboard();
            if (player2==100) {
                printf("Player 2 is wins!\n");
                won=1;
            }
        }
currentplayer = (currentplayer==1) ? 2 : 1;
    }
    return 0;
}

