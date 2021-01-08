#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


typedef struct no n;
struct no{
    int x;
    int y;
    n * prox;
};

n * criar(){
    n * novo=(n*) malloc(sizeof(n));
    novo->x=1;
    novo->y=1;
    novo->prox=NULL;
    return novo;
}

n * inserir(n * fila,int x,int y){
    n * temp=fila;
    n * novo=(n*) malloc(sizeof(n));
    novo->x=x;
    novo->y=y;
    novo->prox=NULL;

        while(temp->prox!=NULL){
            temp=temp->prox;
        }
        temp->prox=novo;


    return fila;

}
void exibir(n * fila){
    while(fila!=NULL){
        printf(" (%i,%i) ",fila->x,fila->y);
        fila=fila->prox;
    }
}

int main(){

    n * Novo=criar();
    int i=0,j=0;
    int x=0,y=0,chave=0;
    int count=0;


 int vetor[10][10]={
    /*0 - linha*/   { 0, 0,-1,-1, 0, 0, 0, 0, 0, 0},
    /*1 - linha*/   { 0,-1, 0, 0, 0,-1, 0,-1,-1,-1},
    /*2 - linha*/   { 0, 0, 0,-1, 0, 0, 0,-1, 0,-1},
    /*3 - linha*/   {-1,-1, 0,-1, 0,-1, 0, 0, 0, 0},
    /*4 - linha*/   {-1, 0, 0, 0,-1, 0, 0, 0,-1, 0},
    /*5 - linha*/   { 0, 0, 0,-1,-1,-1,-1, 0, 0,-1},
    /*6 - linha*/   {-1, 0, 0, 0, 0, 0, 0, 0,-1,-1},
    /*7 - linha*/   { 0, 0,-1, 0, 0,-1, 0, 0, 0, 0},
    /*8 - linha*/   { 0, 0, 0,-1,-1,-1, 0, 0,-1, 0},
    /*9 - linha*/   {-1,-1, 0, 0, 0, 0,-1, 0, 0, 0}
    };

    for(;;){
        for(i=0;i<10;i++){
            for(j=0;j<10;j++){
                if(vetor[i][j] >= 0){
                    printf("  %i ",vetor[i][j]);
                }else if(vetor[i][j]<0){
                    printf(" %i ",vetor[i][j]);
                }
            }
            printf("\n");
        }        
        if(x==9 && y==9 ){
            if(vetor[x][y]==0){
                if(vetor[x-1][y]==3 || vetor[x][y-1]==3){
                    vetor[x][y]=3;
                    Novo=inserir(Novo,x+1,y+1);
                    break;
                }else{
                    x--;
                    y--;
                }
            }           
        }
        printf("\n\n\n");
  //    printf("OBSERVE COMO A FORMIGA ENXERGA O LABIRINTO : \n");
        printf("valor atual do vetor :%i \n",vetor[x][y]);
        printf("valor x-1:%i \n",vetor[x-1][y]);
        printf("valor y-1:%i \n",vetor[x][y-1]);
        printf("valor x+1:%i \n",vetor[x+1][y]);
        printf("valor y+1:%i \n",vetor[x][y+1]);
        printf("posicao X:%i posicao Y:%i \n",x,y);
    //  printf("OBS: VALORES DE MEMORIAS SAO NO CASO DO X OU Y = 0 - 1 ESSE CASO NAO CONTA NA EXECULSAO\n OU SEJA Y OU X =0-1 E 0 \n");
    printf("\n\n\n");
        if(x==0 && y==0){
             if(vetor[x][y]!=3){
                vetor[x][y]=3;
                x++;
            }
           
           
        }else if(x>0 && y==0 && vetor[x][y]==0 && vetor[x-1][y]==3){
            Novo=inserir(Novo,x+1,y+1);
            vetor[x][y]=3;
            x++;
        }else if(x==0 && y>0 && vetor[x][y]==0){
            if(vetor[x][y-1]==3 && vetor[x][y+1]==0){
                Novo=inserir(Novo,x+1,y+1);
                vetor[x][y]=3;
                y++;
            }else if(vetor[x+1][y]== 3  && vetor[x][y+1]==0){
                Novo=inserir(Novo,x+1,y+1);
                vetor[x][y]=3;
                y++;

            }

        }
     
        if(x>0 && y>0 && vetor[x][y]==0){
            if(vetor[x][y+1]==0 && vetor[x][y-1]==3){
                Novo=inserir(Novo,x+1,y+1);
                vetor[x][y]=3;
                y++;
            }else if(vetor[x][y+1]==3 && vetor[x-1][y]==0){
                Novo=inserir(Novo,x+1,y+1);
                vetor[x][y]=3;
                x++;
            }else if(vetor[x][y-1]==3 && vetor[x+1][y]==0){
                Novo=inserir(Novo,x+1,y+1);
                vetor[x][y]=3;
                x++;
            }else if(vetor[x][y-1]==3 && vetor[x][y+1]==0){
                Novo=inserir(Novo,x+1,y+1);
                vetor[x][y]=3;
                y++;
            }else if(vetor[x-1][y]==3 && vetor[x+1][y]==0){
                Novo=inserir(Novo,x+1,y+1);
                vetor[x][y]=3;
                x++;
            }else if(vetor[x-1][y]==3 && vetor[x][y+1]==0){
                Novo=inserir(Novo,x+1,y+1);
                vetor[x][y]=3;
                y++;
            }else if(vetor[x][y-1]==3  && vetor[x-1][y]==0){
                Novo=inserir(Novo,x+1,y+1);
                vetor[x][y]=3;
                x--;
            }else if(vetor[x+1][y]== 3  && vetor[x][y+1]==0){
                Novo=inserir(Novo,x+1,y+1);
                vetor[x][y]=3;
                if(x>0)x--;
            }else if(vetor[x-1][y]== 3  && vetor[x][y+1]==0){
                Novo=inserir(Novo,x+1,y+1);
                vetor[x][y]=3;
                if(x>0)x--;            
			}else if(vetor[x][y+1]== 3 && vetor[x][y-1]==0){
                Novo=inserir(Novo,x+1,y+1);
                vetor[x][y]=3;
                if (vetor[x][y+1]==0){
                    y++;
                }else{
                    y--;
                }                 
			}else if(vetor[x-1][y]== 3  && vetor[x][y-1]==0){
                Novo=inserir(Novo,x+1,y+1);
                vetor[x][y]=3;
                y--;    
			}else if(vetor[x][y+1]== 3 && vetor[x+1][y]==0){
                Novo=inserir(Novo,x+1,y+1);
                vetor[x][y]=3;                
                x++;
			}else{            
                if(y>9){
                	x++;
                	y=0;
				}
                y++;               
            }
        }else if(vetor[x][y]==-1 && x>0 && y==0){	
            if(x>=9 && y<9){
                x=0;
            }
            y++;			
        }else{
            y++;
        }
        if(y>9 && x==0){
            y=0;
            x++;
        }else if(y>9 && x<9 &&x>0){
            y=0;
            x++;
        }

       
        if(x>9 && y+1==9){x--;}
        if(y>9 && x+1==9){y--;}
      //if(x==9 && y<9)x--;
        if(x>9)x--;
        if(y>9)y--;   
        
       
       
       
      //sleep(1);
    }
    system("cls");
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            if(vetor[i][j] == -1 ){
                printf(" -1 ");
                }else if(vetor[i][j] == 3){
                    printf("  F ");
                }else{
                     printf("  0 ");
                }
            }
            printf("\n");
        }
    printf("\n\nA ROTA QUE A FORMIGA PERCOREU ATE ENCONTRA A CASA 1 X 1 PARA A CASA 10 X 10!\n ");
    exibir(Novo);

    return 0;
}

