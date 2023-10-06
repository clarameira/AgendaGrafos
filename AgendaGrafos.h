#include "AgendaGrafos.c"

struct Vertice* grafo[CONTATOS];

void adicionarVertice(char *nome, char *celular, char *email);

int verificarRelacao(char *nomeContato1, char *nomeContato2);