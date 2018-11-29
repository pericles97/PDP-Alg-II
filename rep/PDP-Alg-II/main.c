#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <conio.h>  //clrscr

#define BUFFER 64

/* Estrutura da lista declarada para armazenar nossos dados. */
typedef struct lista {
        char *nome;
        int idade;
        int id;
        struct lista *proximo;
} Dados;

/* Prototipo das funcoes de manuseio dos dados. */
Dados *iniciaDados(char *nome, int idade, int id);
Dados *insereDados(Dados *dados, char *nome, int idade, int id);
void exibeDados(Dados *dados);
void buscaDados(Dados *dados, char *chave);
Dados *deletaDados(Dados *dados);
int checaVazio(Dados *dados);

/* Prototipo das funcoes do menu.*/
void insere(void);
void exibe(void);
void buscaPorNome(void);
void buscaOrdenada(void);
void deleta(void);
void buscaOrdenadaPorNome(void);
void buscaOrdenadaPorIdade(void);
                        		

/* Inicializa a estrutura de dados principal. */
Dados *principal = NULL;

/* Cria a nova lista apontando o proximo no para NULL. */
Dados *iniciaDados(char *nome, int idade, int id) {

        Dados *novo;

        novo = (Dados *)malloc(sizeof(Dados));
        novo->nome = (char *)malloc(strlen(nome)+1);
        strncpy(novo->nome, nome, strlen(nome)+1);
        novo->idade = idade;
        novo->id = id;
        novo->proximo = NULL;

        return novo;
}

/* Como a lista nao esta mais vazia, apontamos o proximo no para lista anterior. */
Dados *insereDados(Dados *dados, char *nome, int idade, int id) {

        Dados *novo;

        novo = (Dados *)malloc(sizeof(Dados));
        novo->nome = (char *)malloc(strlen(nome)+1);
        strncpy(novo->nome, nome, strlen(nome)+1);
        novo->idade = idade;
        novo->id = id;
        novo->proximo = dados;

        return novo;
}

/* Percorre todos os campos da lista e imprime ate o ponteiro proximo chegar em NULL. */
void exibeDados(Dados *dados) {

        fprintf(stdout, "Cadastro:\n\n");

        fprintf(stdout, "------------------------\n");

        for (; dados != NULL; dados = dados->proximo) {
        	    fprintf(stdout, "Id: %d\n", dados->id);
                fprintf(stdout, "Nome: %s\n", dados->nome);
                fprintf(stdout, "Idade: %d\n", dados->idade);
                fprintf(stdout, "------------------------\n ");
        }
        printf("Pressione uma tecla para continuar.");
        getch();
}

/* Percorre cada ponta comparando o nome com a chave. */
void buscaDados(Dados *dados, char *chave) {

        int achou = 0;

        fprintf(stdout, "Cadastro:\n\n");
        for (; dados != NULL; dados = dados->proximo) {
                if (strcmp(chave, dados->nome) == 0) {

                        fprintf(stdout, "------------------------\n");
                        fprintf(stdout, "Id: %d\n", dados->id);
                        fprintf(stdout, "Nome: %s\n", dados->nome);
                        fprintf(stdout, "Idade: %d\n", dados->idade);
                        fprintf(stdout, "------------------------\n");
                        achou++;
                }
        }

        if (achou == 0)
                fprintf(stdout, "Nenhum resultado encontrado.\nPressione uma tecla para continuar.\n");
        else
                fprintf(stdout, "Foram encontrados %d registros. \nPressione uma tecla para continuar.\n", achou);

        sleep(1);
        getch();
}

/* Deleta o ultimo registro inserido. */
Dados *deletaDados(Dados *dados) {

        Dados *novo;

        novo = dados->proximo;

        free(dados->nome);
        free(dados);

        fprintf(stdout, "O ultimo registro inserido foi deletado com sucesso.\n");
        sleep(1);

        return novo;
}

/* a pena checa se a lista e NULL ou nao. */
int checaVazio(Dados *dados) {

        if (dados == NULL) {
                fprintf(stdout, "Lista vazia!\n");
                sleep(1);
                return 1;
        } else
                return 0;
}

/* Obtem os dados necessarios para chamar as funcoes de manuseio de dados. */
void insere(void) {

        char *nome;
        int idade;
        int id;

        nome = (char *)malloc(BUFFER);
		
		system("cls");
		printf("\t Cadastro\n\n");
		
        fprintf(stdout, "Digite o Id: ");
        scanf("%d", &id);
        fprintf(stdout, "\n");

        fprintf(stdout, "\nDigite o Nome: ");
        scanf("%s", nome);
        fprintf(stdout, "\n");

        fprintf(stdout, "Digite a Idade: ");
        scanf("%d", &idade);
        fprintf(stdout, "\n");

        if (principal == NULL){
             principal = iniciaDados(nome, idade, id);
		}
        else{
             principal = insereDados(principal, nome, idade, id);
		}
}

void exibe(void) {

        if (!checaVazio(principal))
                exibeDados(principal);

}

void buscaOrdenadaPorNome(void){
	Dados vet[100];
    int op=0,soma=0,i,j;
    char temp[30];
    
    //ordena
    for(i = 1; i < soma; i++){
         for (j = 0; j < soma-1; j++){
                       
              if(strcmp(vet[j].nome,vet[j+1].nome) > 0){
                 strcpy(temp,vet[j].nome);
                 strcpy(vet[j].nome,vet[j+1].nome);
                 strcpy(vet[j+1].nome,temp);}                               
            }      
     }
}

void buscaOrdenadaPorIdade(void){
	
}

void ordenarPeloCodigo(void) { 
	Dados *p; 
	if (principal == NULL) 
	{ 
	 printf("--- fim da lista ---\n\n"); 
	} 
	// Caso a lista nao esteja vazia 
	p = principal; 
	while (p !=NULL)  
	{ 
	 printf("\n\nId = %d\n",p->id);
	 printf("\nNome = %s\n",p->nome);
	 printf("\nIdade  = %d\n",p->idade); 
	 p = p->proximo; 
	} 
	printf("--- fim da lista ---\n\n"); 
}

void buscaPorNome(void) {
    char *chave;

    if (!checaVazio(principal)) {

            chave = (char *)malloc(BUFFER);

            fprintf(stdout, "Digite o nome para buscar: ");
            scanf("%s", chave);

            buscaDados(principal, chave);
            getch();
    }
}

void deleta(void) {

    if (!checaVazio(principal))
            principal = deletaDados(principal);
}

int main(void) {


        char escolha;

        do {
                system("cls"); 
                fprintf(stdout, "\n\t Cadastro de Visitantes\n\n");
                fprintf(stdout, "1 - Cadastrar visitante\n");
                fprintf(stdout, "2 - Listar todos os visitantes\n");
                fprintf(stdout, "3 - Buscar por Nome\n");
                fprintf(stdout, "4 - Deleta visitante\n");
                fprintf(stdout, "5 - Listar Nomes ord\n");
                fprintf(stdout, "6 - Listar Idades ord\n");
                fprintf(stdout, "7 - Sair\n\n");
                

                fprintf(stdout, "Escolha uma opcao: ");
                scanf("%c", &escolha);

                switch(escolha) {
                        case '1':
                                insere();
                                break;

                        case '2':
                                exibe();
                                break;

                        case '3':
                                buscaPorNome();
                                break;

                        case '4':
                                deleta();
                                break;

                        case '5':
                        		buscaOrdenadaPorNome();
                        		break;
                        		
                    	case '6':
                        		buscaOrdenadaPorIdade();
                        		break;
                        		
                        case '7':
                                exit(0);
                                break;

                        default:
                                fprintf(stderr,"Digite uma opcao valida!\n");
                                sleep(1);
                                break;
                }

                //getchar(); /* E para impedir sujeira na entrada da escolha. Nao lembro de nada melhor tambem.   */
        }

        while (escolha > 0); /* Loop Principal. */



        return 0;
}
