#include "AgendaGrafos.h"

int main(){

    FILE* arquivo;
    arquivo = fopen("contatos/contatos.csv", "r");

    if (arquivo == NULL){
        printf("Não foi possível abrir o arquivo 'contatos.csv'.\n");
        return (1);
    }

    char nome = (char)malloc(sizeof(char));
    char celular = (char)malloc(sizeof(char));
    char email = (char)malloc(sizeof(char));


     fscanf(arquivo, "%[^;];%[^;];%[^;];%[^\n]\n");

    while (fscanf(arquivo, " %99[^;];%99[^;];%99[^;\n];\n", nome, celular, email) == 3) {
        adicionarVertice(nome, celular, email);
    }

    fclose(arquivo);

    int continuar = 1; //Variável para controlar o loop

    while (continuar){

        printf("\n---------------------------------------------------------------------------\n");
        printf("\nDigite os nomes de dois contatos para verificar o se são do mesmo estado:\n");
        printf("---------------------------------------------------------------------------\n");

        char nomeContato1[50];
        char nomeContato2[50];

        printf("Nome do primeiro contato: ");
        scanf("%s", nomeContato1);
        fflush(stdin);

        printf("Nome do segundo contato: ");
        scanf("%s", nomeContato2);
        fflush(stdin);

        int indiceContato1 = -1;
        int indiceContato2 = -1;
        int i;
        //Encontrar os índices dos contatos pelos nomes
        for ( i = 0; i < numVertices; i++){
            if (strcmp(grafo[i]->nome, nomeContato1) == 0){
                indiceContato1 = i;
            }
            if (strcmp(grafo[i]->nome, nomeContato2) == 0){
                indiceContato2 = i;
            }
        }

        if (indiceContato1 != -1 && indiceContato2 != -1){ //Verificação se os contatos são do mesmo estado através dos dois primeiros dígitos, o "DDD".
            if (verificarRelacao(nomeContato1, nomeContato2)){
                printf("---------------------------------------------------------------------------\n");
                printf("%s e %s são do mesmo estado!\n", nomeContato1, nomeContato2);
                printf("Celular de %s: %s\n", nomeContato1, grafo[indiceContato1]->celular);
                printf("Celular de %s: %s\n", nomeContato2, grafo[indiceContato2]->celular);
                printf("---------------------------------------------------------------------------\n");
            } else{
                printf("---------------------------------------------------------------------------\n");
                printf("Esses contatos não são do mesmo estado.\n");
                printf("---------------------------------------------------------------------------\n");
            }
        }else{
            printf("Algum dos contatos não foi encontrado.\n");
        }
        printf("\nDeseja continuar verificando (tecle 1 para sim, 0 para sair)? ");
        scanf("%d", &continuar);
    }

    return (0);
}