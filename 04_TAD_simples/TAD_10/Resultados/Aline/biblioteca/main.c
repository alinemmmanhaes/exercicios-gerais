#include "livro.h"
#include "biblioteca.h"
#include <stdio.h>

int main(){
    int n, op, i;
    tBiblioteca bibli;
    tLivros livro;
    char titulo[100];

    scanf("%d", &n);
    printf("Lista de operacoes:\n1 - Cadastrar livros.\n2 - Remover livros.\n3 - Listar todos os livros cadastrados.\n\n");
    bibli = inicializarBiblioteca();

    for(i=0; i<n; i++){
        scanf("%d", &op);
        if(op == 1){
            livro = lerLivro();
            bibli = adicionarLivroNaBiblioteca(bibli, livro);
        }
        else if(op == 2){
            scanf("%s", titulo);
            bibli = removerLivroDaBiblioteca(bibli, titulo);
        }
        else if(op == 3){
            listarLivrosDaBiblioteca(bibli);
        }
        else{
            printf("Operacao invalida!\n");
            return 1;
        }
    }
    return 0;
}