#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "function.h"

/* this array is for chane max_card to defult values */
void max_zero(int max_card[]){
    for (int i = 0; i < 4; i++)
    {
        max_card[i]=-1;
    }
}

/*for suffle the array */
void shuffle_card(int* card) {
    int i, r, temp;
    for (temp = 0, i = 0; temp < 44; i++, temp++)
        card[temp] = i;
    srand(time(NULL));
    for (i = 43; i > 0; i--) {
        r = rand() % i;
        temp = card[i];
        card[i] = card[r];
        card[r] = temp;
    }
}


/* this function is for calculating winner from max_card array */
int win_calculator(int hokm,int max_card[],int score[]){
    /* now we need to calculate bigest number of max_card array */
    int flag=-1;
    int t=-1;
    for (int i = 0; i < 4; i++)
    {
        if ((max_card[i]/11) == hokm)/* we need to calculate biggest of hokm */
        {
            if (flag < max_card[i]%11)
            {
                flag =max_card[i]%11;
                t=i;
            }
        }
    }
    if (t == (-1))
    {
        for (int i = 0; i < 4; i++)
        {
            if (flag < max_card[i]%11)
            {
                flag =max_card[i]%11;
                t=i;
            }
        }
    }
    if (t==0 || t==2)
    {
        score[0] += 1;
    }else{
        score[1] += 1;
    }
    return t;
        
}

/* this function is for choose with function of chech other cards.
partner_tern variable is for partner tern we have partner_tern value in max_cards */
int chooose(int bakhsh,int *first_card,int p[],int max_card[],int partner_tern){/*partner_tern = 0 , partner_tern=1 , partner_tern=3*/ 
    int flag,t;
    flag=1;
    for (int i = 0; i < 4; i++)/* in this loop we see that card of partner of player is biger than others or not */
    {
        if (max_card[i] != (-1))
        {
            if ((max_card[partner_tern]%11) < (max_card[i]%11)){
                flag = 0;
            }
        }
    }
    if (flag==1)/* it means partner card is bigest card */
    {
        flag=100;
        t=-1;
        for (int i = 0; i < 11; i++)/* we see we have that card type or not */
        {
            if (p[i]!= (-1))
            {
                if ((p[i]/11)== ((max_card[partner_tern])/11))
                {
                    if (flag > p[i]%11 )
                    {
                        flag=p[i]%11;
                        t=i;
                    }
                    
                }
                
            }
            
        }if (t!=(-1))
        {
            return t;/* we return last number of our card type */
        }else{/* we dont have that card type */
            flag=100;
            t=-1;
            for (int i = 0; i < 11; i++)
            {
                if (p[i]!= (-1))
                {
                    if ((p[i]/11) != bakhsh)/* we see that we dont use bakhsh card */
                    {
                        if (flag > (p[i]%11))
                        {
                            flag=(p[i]%11);
                            t=i;
                        }
                        
                    }
                    
                }
                
            }
            if (t!= (-1))
            {
                return t;/* we return smalest none bakhsh card */
            }else{/* we just have bakhsh card */
                flag=0;
                for (int i = 0; i < 11; i++)
                {
                    if (p[i] != (-1))
                    {
                        if ((p[flag]%11)>(p[i]%11))
                        {
                            flag=i;
                        }
                        
                    }
                    
                }
                return flag;
            }
        }
    }else
        { /* it means that we are not first player and we are normal */
        t = -1;

        /* if it played we have first card */
        int i;
        for (i = 0; i < 11; i++)
        {
            if (p[i] != (-1))
            {
                if ((p[i] / 11) == *first_card) /*if it run we have first card*/
                {
                    if (flag < p[i] % 11)
                    {
                        flag = p[i] % 11;
                        t = i;
                    }
                }
            }
        }
        if (t != (-1))
        {
            return t;
        }
        else
        {
            flag = -1;
            t = -1;
            for (i = 0; i < 11; i++)
            {
                if (p[i] != (-1))
                {
                    if ((p[i] / 11) == bakhsh) /*if it run we have first card*/
                    {
                        if (flag < p[i] % 11)
                        {
                            flag = p[i] % 11;
                            t = i;
                        }
                    }
                }
            }
            if (t != (-1))
            {

                return t;
            }
            else
            {
                flag = 100;
                t = 0;
                for (i = 0; i < 11; i++)
                {
                    if (p[i] != (-1))
                    {
                        if (flag > p[i] % 11)
                        {
                            flag = p[i] % 11;
                            t = i;
                        }
                    }
                }

                return t;
            }
        }
    }
    
}




int choose(int p[11], int bakhsh, int *first_card, int state,int max_card[])/*  */
{                  /* state is for see if it was first player or not */
    int flag = -1; /*thats for value of element*/
    int t = -1;
    
    if (state==5) /* it is the first player or not */
    {
        int i;
        flag=0;
        for (int i = 0; i < 11; i++)
        {
            if (p[i] != (-1)){
                if ((p[i]%11)==10 || (p[i]%11)==9)
                {
                    flag=1;
                }
                
            }
        }
        if (flag)
        {
            for (i = 0; i < 11; i++)
            {
                if (p[i] != -1)
                {
                    if ((p[i] / 11) != bakhsh)
                    {
                        if (flag < (p[i] % 11))
                        {
                            flag = (p[i] % 11);
                            t = i;
                        }
                    }
                }
            }
            if (t != -1) /* we get some bakhsh */
            {

                *first_card = p[t] / 11;

                return t;
            }
            else
            {
                flag = 0;
                for (int i = 0; i < 11; i++)
                {
                    if ((p[flag] % 11) < p[i] % 11)
                    {
                        flag = i;
                    }
                }
                *first_card = p[flag] / 11;

                return i;
            }
        }else{
            t=-1;
            flag=-1;
            for (int i = 1; i < 11; i++)
            {
                if (p[i]!=1)
                {
                    if ((p[i] / 11) != bakhsh)
                    {
                        if (flag < (p[i] % 11))
                        {
                            flag = (p[i] % 11);
                            t = i;
                        }
                    }
                    
                }
                
            }
            if (t != -1)
            {
                return t;
            }else{
                flag=0;
                
                for (int i = 1; i < 11; i++)
                {
                    if (p[i]!=1)
                    {
                        if ((p[flag]%11) < (p[i] % 11))
                        {
                            flag = i;
                            
                        }
                    }
                    
                }
                return flag;
            }
            
            
        }

        /* we return the number of element in game */
    }
    else if(state == 1){/* this means we need to calculate maxcard and choose defrent */
        return chooose(bakhsh,first_card,p,max_card,0);
    }
    else if(state == 2){/* this means we need to calculate maxcard and choose defrent */
        return chooose(bakhsh,first_card,p,max_card,1);
    }
    else if(state == 4){/* this means we need to calculate maxcard and choose defrent */
        return chooose(bakhsh,first_card,p,max_card,3);
    }
    else if(state==0)
    { /* it means that we are not first player and we are normal */
        t = -1;

        /* if it played we have first card */
        int i;
        for (i = 0; i < 11; i++)
        {
            if (p[i] != (-1))
            {
                if ((p[i] / 11) == *first_card) /*if it run we have first card*/
                {
                    if (flag < p[i] % 11)
                    {
                        flag = p[i] % 11;
                        t = i;
                    }
                }
            }
        }
        if (t != (-1))
        {
            return t;
        }
        else
        {
            flag = -1;
            t = -1;
            for (i = 0; i < 11; i++)
            {
                if (p[i] != (-1))
                {
                    if ((p[i] / 11) == bakhsh) /*if it run we have first card*/
                    {
                        if (flag < p[i] % 11)
                        {
                            flag = p[i] % 11;
                            t = i;
                        }
                    }
                }
            }
            if (t != (-1))
            {

                return t;
            }
            else
            {
                flag = 100;
                t = 0;
                for (i = 0; i < 11; i++)
                {
                    if (p[i] != (-1))
                    {
                        if (flag > p[i] % 11)
                        {
                            flag = p[i] % 11;
                            t = i;
                        }
                    }
                }

                return t;
            }
        }
    }
    return 0;
}



/* this function print game chart */
void print(int score[],int p[],int max_card[4]){
    FILE *file;
    char c[151]; /*we define for store data*/
    file=fopen("chart.txt","r");
    char symbol[11]="qqqqqqqqqqq";
    int card_number[11];
    char maxc[4][4]={"   ","   ","   ","   "};/* برای چاپ کردن کارت های کاربر ما */
        
    for (int i = 0; i < 4; i++)
    {
        if (max_card[i]!=(-1))
        {
            if ((max_card[i]%11)>=9)
            {
                if ((max_card[i]/11) == 0)
                {
                    maxc[i][0]='A';
                    maxc[i][1]='0'+((max_card[i]%11 + 1)/10);
                    maxc[i][2]='0'+((max_card[i]%11 + 1)%10);
                }else if ((max_card[i]/11) == 1)
                {
                    maxc[i][0]='B';
                    maxc[i][1]='0'+((max_card[i]%11 + 1)/10);
                    maxc[i][2]='0'+((max_card[i]%11 + 1)%10);
                }else if ((max_card[i]/11) == 2)
                {
                    maxc[i][0]='C';
                    maxc[i][1]='0'+((max_card[i]%11 + 1)/10);
                    maxc[i][2]='0'+((max_card[i]%11 + 1)%10);
                }else if ((max_card[i]/11) == 3)
                {
                    maxc[i][0]='D';
                    maxc[i][1]='0'+((max_card[i]%11 + 1)/10);
                    maxc[i][2]='0'+((max_card[i]%11 + 1)%10);
                } 
            }else{
            
                if ((max_card[i]/11) == 0)
                {
                    maxc[i][0]='A';
                    maxc[i][1]='0'+(max_card[i]%11 + 1);
                }else if ((max_card[i]/11) == 1)
                {
                    maxc[i][0]='B';
                    maxc[i][1]='0'+(max_card[i]%11 + 1);
                }else if ((max_card[i]/11) == 2)
                {
                    maxc[i][0]='C';
                    maxc[i][1]='0'+(max_card[i]%11 + 1);
                }else if ((max_card[i]/11) == 3)
                {
                    maxc[i][0]='D';
                    maxc[i][1]='0'+(max_card[i]%11 + 1);
                }
            }
        }
        
    }
    
    









    /*first we need to calculate the gmae cards   for symbol and card_number variable  */
    for (int i = 0; i < 11; i++)
    {
        if (p[i] != -1 )
        {
            switch ((int)(p[i]/11))
            {
            case 0 :
                symbol[i]='A';
                break;
            case 1:
                symbol[i]='B';
                break;
            case 2 :
                symbol[i]='C';
                break;
            case 3 :
                symbol[i]='D';
                break;
            }
            card_number[i]=p[i]%11+1;
        }else{
            symbol[i]='-';
            card_number[i]= -1;
        }
    
    }
    









    /*start printing */
    fgets(c,150,file);
    fgets(c,150,file);
    printf("%s",c);
    /* for first line */
    printf("        ---------------------------------------------------------------------       Team 1: %d\n",score[0]);
    printf("        |                               %3s                                 |\n",maxc[2]);




    for (int i = 0; i < 9; i++)
    {
        fgets(c,150,file);
        printf("%s",c);
    }
    printf("     p2 | %3s                        %10s                         %3s | p4\n",maxc[1]," ",maxc[3]);

    for (int i = 0; i < 11; i++)
    {
        fgets(c,150,file);
        printf("%s",c);
    }
    printf("        |                               %3s                                 |\n",maxc[0]);
    printf("        ---------------------------------------------------------------------        Team 2: %d\n",score[1]);






    for (int i = 0; i < 2; i++)
    {
        fgets(c,150,file);
        printf("%s",c);
    }
    printf("   symbol |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  \n",symbol[0],symbol[1],symbol[2],symbol[3],symbol[4],symbol[5],symbol[6],symbol[7],symbol[8],symbol[9],symbol[10]);
        
    fgets(c,150,file);
    printf("%s",c);




    printf("   number | %2d  | %2d  | %2d  | %2d  | %2d  | %2d  | %2d  | %2d  | %2d  | %2d  | %2d  |\n",card_number[0],card_number[1],card_number[2],card_number[3],card_number[4],card_number[5],card_number[6],card_number[7],card_number[8],card_number[9],card_number[10]);
    for (int i = 0; i < 2; i++)
    {
        fgets(c,150,file);
        printf("%s",c);
    }
    
}


/* this function is for bradcasting card in to arrays 
=> status is for 5 or 4 or 2
*/
void bradcast(int arr[] ,int p1[],int p2[],int p3[],int p4[],int status,int fstatus){/*fstatus is for state of choose hokm name in game*/
    int i=0,j=0;
    if (status == 0)
    {
        if (fstatus==0)
        {
            for ( i = 0; i < 5; i++)
            {
                p1[i]=arr[i];
            }
            
        }else if (fstatus==1)
        {
            for (j=0,i = 5; i < 10; i++,j++)
            {
                p2[j]=arr[i];
            }
            for (j=0,i = 10; i < 15; i++,j++)
            {
                p3[j]=arr[i];
            }
            for (j=0,i = 15; i < 20; i++,j++)
            {
                p4[j]=arr[i];
            }
            
        }else{
            for ( i = 0; i < 5; i++)
            {
                p1[i]=arr[i];
            }
            for (j=0,i = 5; i < 10; i++,j++)
            {
                p2[j]=arr[i];
            }
            for (j=0,i = 10; i < 15; i++,j++)
            {
                p3[j]=arr[i];
            }
            for (j=0,i = 15; i < 20; i++,j++)
            {
                p4[j]=arr[i];
            }
        }
        
        
    }else if(status==1){
        for (j=5, i = 20; i < 24; i++,j++)
        {
            p1[j]=arr[i];
        }
        for (j=5,i = 24; i < 28; i++,j++)
        {
            p2[j]=arr[i];
        }
        for (j=5,i = 28; i < 32; i++,j++)
        {
            p3[j]=arr[i];
        }
        for (j=5,i = 32; i < 36; i++,j++)
        {
            p4[j]=arr[i];
        }
    }else if(status==2){
        for (j=9, i = 36; i < 38; i++,j++)
        {
            p1[j]=arr[i];
        }
        for (j=9,i = 38; i < 40; i++,j++)
        {
            p2[j]=arr[i];
        }
        for (j=9,i = 40; i < 42; i++,j++)
        {
            p3[j]=arr[i];
        }
        for (j=9,i = 42; i <= 43; i++,j++)
        {
            p4[j]=arr[i];
        }
    }
    
    
}



void get_input(int p1[],int *first_card , int hokm , int *char_hokm ,int max_card[],int *ans,int score[]){

        /* باید چک کنیم که کارت شروع را بازیکن اول دارد یا نه؟ */
        int flag=0 ;
        for (int i = 0; i < 11; i++)
        {
            if (p1[i] != (-1))
            {
                if ((p1[i]/11) == *first_card)
                {
                    flag=1;
                }
                
            }
            
        }
        if (flag)
        {
            do/* برای چک کردن و مقاوم سازی */
            {
                print(score,p1,max_card);
                printf("enter your card :    hokm : %c\n",*char_hokm);
                scanf("%d",ans);
                printf("\033[2J\033[1;1H");/* برای پاک کردن */
            } while (*ans>=11 || *ans<0 || (p1[*ans]/11) != *first_card || (p1[*ans]) == -1 );
        }else{
            do/* برای چک کردن و مقاوم سازی */
            {
                print(score,p1,max_card);
                printf("enter your card :    hokm : %c\n",*char_hokm);
                scanf("%d",ans);
                printf("\033[2J\033[1;1H");/* برای پاک کردن */
            } while (*ans>=11 || *ans<0 || (p1[*ans]) == -1 );
        }
        
}




/* this function returns number of player that need to start next time.
and it play one round */
int play(int score[],int p1[],int p2[],int p3[],int p4[],int arr[],int num_starter,int *first_card,int hokm,int max_card[]){/* state is for who is starter of game 0,1,2,3 */    
    int ans=0;/* this is for the input of scanf */
    int p;/* this variable is for save data of choose function */
    int char_hokm;/*for printing in evry round*/


    /* this function is for calculating hokm charecter in char_hokm variable */
    switch (hokm)
    {
    case 0:
        char_hokm ='A';
        break;
    case 1:
        char_hokm ='B';
        break;
    case 2:
        char_hokm ='C';
        break;
    case 3:
        char_hokm ='D';
        break;
    }
    
    
    if (num_starter == 0)/* it means me is starting game */
    {

        do/* برای چک کردن و مقاوم سازی */
        {
            print(score,p1,max_card);
            printf("enter your card :    hokm : %c\n",char_hokm);
            scanf("%d",&ans);
            printf("\033[2J\033[1;1H");/* برای پاک کردن */
        } while (ans>=11 || ans<0 || (p1[ans]) == -1 );
        *first_card = p1[ans]/11;/* it contain the first card */
        
        
        max_card[0]=p1[ans];
        p1[ans]=-1;

        /* now need to play player 2 */
        p=choose(p2,hokm ,first_card,0,max_card);
        max_card[1]=(p2[p]);
        p2[p]=-1;
        
        /* now need to play player 3 */
        p=choose(p3,hokm ,first_card,1,max_card);
        max_card[2]=(p3[p]);
        p3[p]=-1;

        /* now need to play player 4 */
        p=choose(p4,hokm ,first_card,2,max_card);
        max_card[3]=(p4[p]);
        p4[p]=-1;

        return win_calculator(hokm,max_card,score);/* وضعیت فرد برنده */


        /* finaly one round finished */

    }else if (num_starter == 1)/* start from player 2 */
    {
        p=choose(p2,hokm ,first_card,5,max_card);/*player 2 tern*/
        max_card[1]=p2[p];
        p2[p]=-1;


        p=choose(p3,hokm ,first_card,0,max_card);/*player 3 tern*/
        max_card[2]=p3[p];
        p3[p]=-1;


        p=choose(p4,hokm ,first_card,2,max_card);/*player 4 tern*/
        max_card[3]=p4[p];
        p4[p]=-1;



        get_input(p1,first_card,hokm,&char_hokm,max_card,&ans,score);
        max_card[0]=p1[ans];
        p1[ans]=-1;


        return win_calculator(hokm,max_card,score);/* وضعیت فرد برنده */





        
    }else if (num_starter == 2)/* start from player 3 */
    {
        p=choose(p3,hokm ,first_card,5,max_card);/*player 3 tern*/
        max_card[2]=p3[p];
        p3[p]=-1;


        p=choose(p4,hokm ,first_card,0,max_card);/*player 4 tern*/
        max_card[3]=p4[p];
        p4[p]=-1;


        get_input(p1,first_card,hokm,&char_hokm,max_card,&ans,score);

        max_card[0]= (p1[ans]);
        p1[ans]=-1;


        p=choose(p2,hokm ,first_card,4,max_card);/*player 2 tern*/
        max_card[1]=p2[p];
        p2[p]=-1;





        return win_calculator(hokm,max_card,score);/* وضعیت فرد برنده */




        
    }else if (num_starter == 3)/* start from player 4 */
    {

        p=choose(p4,hokm ,first_card,5,max_card);/*player 4 tern*/
        max_card[3]=p4[p];
        p4[p]=-1;


        /* now is my round */
        
        get_input(p1,first_card,hokm,&char_hokm,max_card,&ans,score);

        max_card[0]= (p1[ans]);
        p1[ans]=-1;


        p=choose(p2,hokm ,first_card,4,max_card);/*player 2 tern*/
        max_card[1]=p2[p];
        p2[p]=-1;


        p=choose(p3,hokm ,first_card,1,max_card);/*player 3 tern*/
        max_card[2]=p3[p];
        p3[p]=-1;





        return win_calculator(hokm,max_card,score);/* وضعیت فرد برنده */


        
    }
    return 0;

}
