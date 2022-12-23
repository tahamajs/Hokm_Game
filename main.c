#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "function.h"




int main(){

    printf("\033[2J\033[1;1H");
    int arr[44];/* is for shuffles array */
    int p[4][11]={{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}};    /*is for card of players  the defult id -1 */
    int max_card[4]={-1,-1,-1,-1};
    int hokm =0;/*is for main card of our game */
    int first_card ;/*it is for main card*/
    int score[2]={0,0};/* for main score of game */
    int ans;/* this is for anser of scanf function */
    int win = -1;/* we put winer in hear */
    int win_copy = win;/* متغیری است برای فرستادن متغیر به تابع */

    shuffle_card(arr);/* for shuffle cards */
    bradcast(arr,p[0],p[1],p[2],p[3],0,0);/* در حالت شروع کننده من و فقط ۵ تای اول    پخش ۵ تایی اول */



    /* get hokm from user */
    do/* مقاوم سازی برای بخش نامه */
    {
        print(score,p[0],max_card);
        printf("please enter hokm : \n");
        scanf("%d",&ans);
        printf("\033[2J\033[1;1H");
    } while (ans>=5 || ans<0);
    hokm=p[0][ans]/11;/* put ans in hokm variable */



    /* برای ادامه ی پخش کردن کارت ها */
    bradcast(arr,p[0],p[1],p[2],p[3],0,1);/*ادامه ی پخش پنج تایی*/
    bradcast(arr,p[0],p[1],p[2],p[3],1,2);/* پخش چهار تایی */
    bradcast(arr,p[0],p[1],p[2],p[3],2,2);/* پخش دوتایی */

    
    win=play(score,p[0],p[1],p[2],p[3],arr,0,&first_card,hokm,max_card);/* first round of game */
    print(score,p[0],max_card);
    printf("player %d  win the round    enter to continue\n",win+1);/* this line is for show player which player win */
    win_copy=win;


    //while (getchar()!='\n'){}/* for enter */


    /* this line is for change max_card array to defult */
    max_zero(max_card);

    /* game will start from hear */
    while (score[0]<6 && score[1]<6)
    {
        while (getchar()!='\n'){}
        while (getchar()!='\n'){}
        printf("\033[2J\033[1;1H");
        /* this line is for change max_card array to defult */
        max_zero(max_card);
        win=play(score,p[0],p[1],p[2],p[3],arr,win_copy,&first_card,hokm,max_card);
        printf("\033[2J\033[1;1H");
        print(score,p[0],max_card);
        win_copy=win;
        printf("player %d  win the round   enter to continue\n",win+1);
    }


    /* calculating scores and show player witch team win ? */
    if (score[0]==6)
    {
        printf("\033[2J\033[1;1H");
        printf("team 1 win the gmae .\n thank you .\n");
    }else{
        printf("\033[2J\033[1;1H");
        printf("team 2 win the gmae .\n  thank you .\n");
    }

}