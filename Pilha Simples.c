#include<stdlib.h>
#include<stdio.h>

//criação da estrutura da pilha, com o valor e um ponteiro para o anterior
typedef struct pilhao{

    int valor;

    struct pilhao *anterior;

}pilhao;

//criação do topo da pilha que se atualiza com a inserção
typedef struct toppilha
{
    pilhao *topo;
}toppilha;

//cria a pilha apontando o topo dela pra null, ou seja, vazia
void criarPilha(toppilha *p){

    p->topo = NULL;

}

//função para conferir se a pilha ta vazia, se esta recebendo null ele retorna 1 caso nao esteja vazia retorna 0
int pilhaVazia(toppilha *p){

    if(p->topo == NULL)
        return 1;
    else
        return 0;

}

//função para empilhar o elemento, recebe a pilha e o valor recebido la no main
void empilharElemento(toppilha *p, int valor){

    //cria um ponteiro do tipo pilhao
    pilhao *novo = malloc(sizeof(pilhao));

    //o novo que aponta para o valor dele vai receber o valor que recebe la no main
    novo->valor = valor;

    //o novo que aponta o anterior vai receber o p que aponta para o topo
    novo->anterior = p->topo;

    //p que aponta o topo vai receber o novo que acabei de criar
    p->topo = novo;

    //dou free no novo
    novo=NULL;
    free(novo);

}

//função para mostrar a pilha recebe apenas a pilha
void mostrarPilha(toppilha *p){

    //se a função pilhavazia retornou zero (tem elemento)
    if(pilhaVazia(p) == 0){
        //cria um auxiliar do tipo pilhao
        pilhao *aux;

        //o auxiliar vai receber o p que aponta pro topo
        aux = p->topo;

        //enquanto o auxiliar nao achar um null
        while (aux != NULL)
        {
            //printa o auxiliar setando valor
            printf("\n %d", aux->valor);

            //o auxiliar recebe o anterior dele
            aux = aux->anterior;
        }
        printf("\n\n");

    }
    else{
        printf("\n===Pilha vazia===\n");
    }
}

//função para desempilhar elemento
void  desempilha(toppilha *p){

    //cria um auxiliar do tipo pilhao
    pilhao *aux;

    //o auxiliar recebe o p que seta topo
    aux=p->topo;

    //o p que seta topo recebe o auxiliar que seta o anterior
    p->topo = aux->anterior;

    //o auxiliar que seta o anterior recebe o null
    aux->anterior=NULL;

    //da free o auxiliar
    free(aux);

}

//menu principal
int menu(){
    int opc;

    printf("\n\n1 - Pilha 1");
    printf("\n2 - Mostrar pilha");
    printf("\n0 - Sair");
    printf("\n-> ");

    fflush(stdin);
    scanf("%d", &opc);

    return opc;
}

//menu da pilha
int menuPilha(){

    int opc_pilha = 0;

    printf("\n\n1- Empilhar\n");
    printf("2- Desempilhar\n");
    printf("3- Voltar\n");
    printf("-> ");
    fflush(stdin);
    scanf("%d", &opc_pilha);

    return opc_pilha;

}

int main (){

    //aloca a pilha
    toppilha *pi1 = malloc(sizeof(pilhao));

    int opc = 0;
    int opc_pilha = 0;
    int valor = 0;

    //cria ela
    criarPilha(pi1);


    do{
        opc = menu();

        switch (opc)
        {
        case 1:
            opc_pilha = menuPilha();

            switch (opc_pilha)
            {
            case 1:
                printf("\nInsira o valor: ");
                fflush(stdin);
                scanf("%d", &valor);

                empilharElemento(pi1, valor);
                break;

            case 2:
                desempilha(pi1);
                break;

            default:
                break;
            }

            break;

        case 2:

            printf("\npilha 1 : ");
            mostrarPilha(pi1);


            break;



        }

    }while(opc != 0);

    return 0;
}
