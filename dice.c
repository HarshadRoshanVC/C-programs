#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

int Dice(){


    return (rand()%6)+1;
}
int findMax(int *count){
    int max=0,iter;
    for(iter=0;iter<11;iter++,count++){
        if(max < *count){
            max=*count;
        }
    }
    return max;
}
int main()
{
    FILE *fp;
    char filename[20];
    int count[11],iter,iter2,choice,max_count,max_char=74,test=1,dice1,dice2,sumOfDice;
    srand(time(0));
    for(iter=0;iter<11;iter++){
        count[iter]=0;
    }
    do{

        printf("Enter number of rolls:");
        scanf("%d",&choice);
        if(choice<1){
            printf("Quitting!\n");
            break;
        }else{
            snprintf(filename,sizeof(filename),"test%d.csv",test);
            fp  = fopen (filename, "w");
            fprintf(fp,"Dice1,Dice2\n");
            for(iter=0;iter<choice;iter++){
                dice1=Dice();
                dice2=Dice();
                fprintf(fp,"%d,%d\n",dice1,dice2);
                sumOfDice=dice2+dice1;
                count[sumOfDice-2]++;
            }
            fclose(fp);
            for(iter=0;iter<11;iter++){
                printf("%ds: %d\n",iter+2,count[iter]);
            }
            max_count=findMax(count);
            for(iter=0;iter<11;iter++){
                count[iter]=round( ((float) count[iter]/max_count)*max_char);
            }
            printf("\nDice roll histogram:\n");
            for(iter=0;iter<11;iter++){
                if(iter<8)
                    printf(" ");
                printf("%ds: ",iter+2);
                for(iter2=0;iter2<count[iter];iter2++)
                    printf("*");
                printf("\n");
            }
        }
        test++;
    }while(choice);
    return 0;
}
