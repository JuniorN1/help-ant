#include<stdio.h>
#include<stdlib.h>

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
    int i,j;
    int x,y,chave=0;
    int count=0;
    int vetor[10][10]={
        {0,0,-1,-1,0,0,0,0,0,0},
        {0,-1,0,0,0,-1,0,-1,-1,-1},
        {0,0,0,-1,0,0,0,-1,0,-1},
        {-1,-1,0,-1,0,-1,0,0,0,0},
        {-1,0,0,0,-1,0,0,0,-1,0},
        {0,0,0,-1,-1,-1,-1,0,0,-1},
        {-1,0,0,0,0,0,0,0,-1,-1},
        {0,0,-1,0,0,-1,0,0,0,0},
        {0,0,0,-1,-1,-1,0,0,-1,0},
        {-1,-1,0,0,0,0,-1,0,0,0}

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
        printf("\n");
        printf("REGRAS : \n");
        printf(" Em cada passo, a formiga so pode se deslocar para uma casa livre que esteja adjacente. \n\n");
        printf("AJUDE A FORMIGA DA CORDENADA 1X1  A IR PARA 10 X 10 !!\n ");
        printf("DIGITE A CORDENADA QUE A FORMIGA PODE ANDAR:");
        scanf("%i %i",&x,&y);
        x-=1;
        y-=1;
        if(vetor[x][y] == 3 ){       
            system("cls");
            printf("ESSAS CORDENADAS JA FORAM ESCOLHIDDAAS,CUIDADO PARA NAO SE PERDE NO CAMINHO HAHAA!\n\n");
            system("pause");           
       
        }else if(x== 0 && y == 0){  
            Novo=criar();
            vetor[x][y]=3;
        }else  if(x== 0 && y>=0 && vetor[x][y] == 0){  
            if(vetor[x][y-1] == 3&& vetor[x][y+1] == 0 || vetor[x+1][y] == 0 ){
                chave=1;
                vetor[x][y]=3;         
            }
        }else if(x >=0 && y==0 && vetor[x][y] == 0 ){
            if(vetor[x-1][y] == 3 ){
                if(vetor[x+1][y] == 0 || vetor[x][y+1] == 0){
                    chave=1;
                    vetor[x][y]=3;
                }
            }   
        
           
        }else if(x>0 && y>0 && vetor[x][y]==0 ){     
            if(vetor[x-1][y] == 3 || vetor[x][y-1] == 3 || vetor[x+1][y] == 3 ||vetor[x][y+1] == 3 ){   
                if(vetor[x+1][y] == 0 ||vetor[x][y+1] == 0 || x==9 && y==9){                
                    chave=1;        
                    vetor[x][y]=3;
                }
           }
        }
        if(chave == 1){
            Novo=inserir(Novo,x+1,y+1);            
            chave=0;
            if(x == 9 && y == 9){
                break;
            }
        }       
        system("cls");
    }
    system("cls");
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){    
            if(vetor[i][j] == -1 ){
                printf(" -1 ");
                }else{
                    printf("  F  ");
                }

            }
        
            printf("\n");
        }
    printf("\n\nPARABENS VOCE GANHOU , AJUDANDO A FORMIGA IR DA CASA 1 X 1 A CASA 10 X 10!\n ");
    exibir(Novo);
  
    return 0;
}