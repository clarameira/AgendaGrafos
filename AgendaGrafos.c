#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CONTATOS 32
#define DIGITOSCEL 2

//Estrutura de um vértice em um grafo (representando um contato)
struct Vertice{
    char nome[50];
    char celular[20];
    char email[50];
};

//Função para criar um novo grafo (lista de adjacência)
struct Vertice* grafo[CONTATOS];
int numVertices = 0;

//Função para adicionar um vértice (contato) ao grafo
void adicionarVertice(char *nome, char *celular, char *email){
    if (numVertices < CONTATOS){
        struct Vertice* novoContato = (struct Vertice*)malloc(sizeof(struct Vertice));
        strncpy(novoContato->nome, nome, sizeof(novoContato->nome));
        strncpy(novoContato->celular, celular, sizeof(novoContato->celular));
        strncpy(novoContato->email, email, sizeof(novoContato->email));
        
        grafo[numVertices++] = novoContato;
    }else{
        printf("Limite máximo de contatos atingido.\n");
    }
}

//Função para verificar se os dois primeiros dígitos do número de celular são iguais, as arestas.
int verificarRelacao(char *nomeContato1, char *nomeContato2){
    int indiceContato1;
    int indiceContato2;
    indiceContato1 = -1;
    indiceContato2 = -1;

    //Encontrar os índices dos contatos pelos nomes
    for(int i = 0; i < numVertices; i++){
        if(strcmp(grafo[i]->nome, nomeContato1) == 0){
            indiceContato1 = i;
        }
        if(strcmp(grafo[i]->nome, nomeContato2) == 0){
            indiceContato2 = i;
        }
    }

    if(indiceContato1 != -1 && indiceContato2 != -1){ // Verificar se os dois primeiros dígitos dos números de celular são iguais, ou seja, o "DDD".
        if(strncmp(grafo[indiceContato1]->celular, grafo[indiceContato2]->celular, DIGITOSCEL) == 0){
            return (1); //Relação encontrada
        }
    }
     return (0); //Sem relação encontrada
}