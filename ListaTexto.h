
#define MAX 10

typedef struct _lista_texto {
  char *v[MAX];
  int ultimo;
} ListaTexto;

ListaTexto * cria_lista();

void destroi_lista(ListaTexto *l);

// adiciona ao final da lista
int adicionar_lista(ListaTexto *l, char *texto);

// insere em alguma posição da lista
int inserir_lista(ListaTexto *l, int posicao, char *texto);

// retornar o elemento na posição 'posicao'
char * acessar_lista(ListaTexto *l, int posicao);

// retornar o índice do texto buscado ou -1 caso não encontre
int buscar_lista(ListaTexto *l, char *buscado);

// remove um elemento da lista e retorna ele ou NULL caso a posição não exista na lista
char * remover_lista(ListaTexto *l, int posicao);

void imprimir_lista(ListaTexto *l);