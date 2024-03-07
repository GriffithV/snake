#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
    //satır,sütun ve yemeksayısını al 
    int rows;
    int colons;
    int foodcount;
    int i,j;
    printf("Satir sayisini giriniz : ");
    scanf("%d",&rows);
    printf("Sutun sayisini giriniz : ");
    scanf("%d",&colons);
    printf(" Yemek sayisini giriniz : ");
    scanf("%d",&foodcount);
    int flag=0;
    while(flag==0){
        if(foodcount<(rows*colons)){
            flag=1;
        }
        else{
            printf(" Uygun bir yemek sayisi giriniz : ");
            scanf("%d",&foodcount);

        }
    }
    char board[100][100];
    int n,m;
    
    for(n=0;n<rows;n++){
        for(m=0;m<colons;m++){
            board[n][m] = '_';
        }
    }
   
   

    //yılan ve yemekğin konumu için rastgele değerler üret 

    srand(time(NULL));
    char snake='1';
    int snakeR = rand() % rows;
    int snakeC = rand() % colons;
    board[snakeR][snakeC]=snake;
    i=0;
    while(i<foodcount){
        int foodR = rand() % rows;
        int foodC = rand() % colons;
        if(board[foodR][foodC]=='_'){
            board[foodR][foodC]='0';
            i++;
        }
    } 

    for(i =0;i<rows;i++){
          for(j=0;j<colons;j++){
            printf("%c ",board[i][j]);
          }
          printf("\n");
        }


    int run=1;
    
    // oyunun başlaması ve hareket etmesi

    int kalanyemek=foodcount;
    int hamlesayi=0;
    char snakes[50];
    snakes[0]='1';
    int size=1;
       
    while(run==1){
        printf("Bir hamle giriniz :  'u','d','r,'l'  : ");
        char direction[3];
        scanf("%s",&direction[0]);
        
       
                //YUKARI HAREKET 
        if(direction[0] =='u'){
            hamlesayi++;
            int oldR = snakeR;
            int oldC = snakeC;
            int newR = snakeR-1;
            if(board[newR][snakeC]=='0'){
                kalanyemek--;
                size+=1;
                snakes[size-1]='1'+(size-1);
                snakeR = newR;
                
                int count=1;
                for(i=0;i<rows;i++){
                  for(j=0;j<colons;j++){
                    if((board[i][j]==snakes[size-1-count])&&(size-1-count>=0)){
                        
                        board[i][j]=snakes[size-count];
                        count++;
                        i=0;
                        j=-1;
                        
                     }
                   }
                }
                board[newR][snakeC]=snakes[0];
                
                 
                
            }
            else if(size>1){
            snakeR = newR;
            snakes[size]='_';
            int count=1;
                for(i=0;i<rows;i++){
                  for(j=0;j<colons;j++){
                    if((board[i][j]==snakes[size-count])&&(size-count>=0)){
                        
                        board[i][j]=snakes[size+1-count];
                        count++;
                        i=0;
                        j=-1;
                        
                     }
                   }
                }
                board[newR][snakeC]=snakes[0];
            }
            else{
                snakeR = newR;
                board[newR][snakeC]=snakes[0];
                board[oldR][oldC]='_';
                
            }
        }
            //AŞAĞI HAREKET
        else if(direction[0] =='d'){
            hamlesayi++;
            int oldR = snakeR;
            int oldC = snakeC;
            int newR = snakeR+1;
            if(board[newR][snakeC]=='0'){
                kalanyemek--;
                size+=1;
                snakes[size-1]='1'+(size-1);
                snakeR = newR;
                
                int count=1;
                for(i=0;i<rows;i++){
                  for(j=0;j<colons;j++){
                    if((board[i][j]==snakes[size-1-count])&&(size-1-count>=0)){
                        
                        board[i][j]=snakes[size-count];
                        count++;
                        i=0;
                        j=-1;
                        
                     }
                   }
                }
                board[newR][snakeC]=snakes[0];
                
                 
                
            }
            else if(size>1){
            snakeR = newR;
            snakes[size]='_';
            int count=1;
                for(i=0;i<rows;i++){
                  for(j=0;j<colons;j++){
                    if((board[i][j]==snakes[size-count])&&(size-count>=0)){
                        
                        board[i][j]=snakes[size+1-count];
                        count++;
                        i=0;
                        j=-1;
                        
                     }
                   }
                }
                board[newR][snakeC]=snakes[0];
            }
            else{
                snakeR = newR;
                board[newR][snakeC]=snakes[0];
                board[oldR][oldC]='_';
                
            }
        }

        //SAĞA HARAKET 
        else if(direction[0] == 'r'){
            hamlesayi++;
            int oldR = snakeR;
            int oldC = snakeC;
            int newC = snakeC+1;
               if(board[snakeR][newC]=='0'){
                kalanyemek--;
                size+=1;
                snakes[size-1]='1'+(size-1);
                snakeC = newC;
                
                int count=1;
                for(i=0;i<rows;i++){
                  for(j=0;j<colons;j++){
                    if((board[i][j]==snakes[size-1-count])&&(size-1-count>=0)){
                        
                        board[i][j]=snakes[size-count];
                        count++;
                        i=0;
                        j=-1;
                        
                     }
                   }
                }
                board[snakeR][newC]=snakes[0];
                
                 
                
            }
            else if(size>1){
            snakeC = newC;
            snakes[size]='_';
            int count=1;
                for(i=0;i<rows;i++){
                  for(j=0;j<colons;j++){
                    if((board[i][j]==snakes[size-count])&&(size-count>=0)){
                        
                        board[i][j]=snakes[size+1-count];
                        count++;
                        i=0;
                        j=-1;
                        
                     }
                   }
                }
                board[snakeR][newC]=snakes[0];
            }
            else{
                snakeC = newC;
                board[snakeR][newC]=snakes[0];
                board[oldR][oldC]='_';
                
            }

        //SOLA HAREKET

        }
        else if(direction[0] == 'l'){
            hamlesayi++;
            int oldR = snakeR;
            int oldC = snakeC;
            int newC = snakeC-1;
              if(board[snakeR][newC]=='0'){
                kalanyemek--;
                size+=1;
                snakes[size-1]='1'+(size-1);
                snakeC = newC;
                
                int count=1;
                for(i=0;i<rows;i++){
                  for(j=0;j<colons;j++){
                    if((board[i][j]==snakes[size-1-count])&&(size-1-count>=0)){
                        
                        board[i][j]=snakes[size-count];
                        count++;
                        i=0;
                        j=-1;
                        
                     }
                   }
                }
                board[snakeR][newC]=snakes[0];
                
                 
                
            }
            else if(size>1){
            snakeC = newC;
            snakes[size]='_';
            int count=1;
                for(i=0;i<rows;i++){
                  for(j=0;j<colons;j++){
                    if((board[i][j]==snakes[size-count])&&(size-count>=0)){
                        
                        board[i][j]=snakes[size+1-count];
                        count++;
                        i=0;
                        j=-1;
                        
                     }
                   }
                }
                board[snakeR][newC]=snakes[0];
            }
            else{
                snakeC = newC;
                board[snakeR][newC]=snakes[0];
                board[oldR][oldC]='_';
                
            }
            

        }

         //Hamle sonrası Tahtanın Yeniden basılması 

        system("cls");
        for(i=0;i<rows;i++){
            for(j=0;j<colons;j++){
                printf("%c ",board[i][j]);
            }
            printf("\n");
        }

        // Kazanma Kaybetme Koşulları

        if(snakeR<0||snakeC<0){
            printf("Kaybettin!    Kalan yemek :%d  ",kalanyemek);
            run=0;

        }
        if(snakeR>rows-1||snakeC>colons-1){
            printf("Kaybettin!    Kalan yemek :%d  ",kalanyemek);
            run=0;
        }
        if(size>foodcount){
            printf("Kazandin!  Hamle sayisi :%d   Kalan yemek :%d  ",hamlesayi,kalanyemek);
            run=0;
        }
        if(size-1<foodcount){
            printf("Yapilan Hamle sayisi :%d \n",hamlesayi);
        }

       


        

    }

 
    
}