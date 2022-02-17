///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Seridó                     ///
///               Departamento de Computação e Tecnologia                   ///
///                  Disciplina DCT1106 -- Programação                      ///
///                Projeto: Sistema de Controle de Contas Bancárias         ///
///     Copyright © 2021 Vitor Daniel - Todos os direitos reservados        ///
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "relatorios.h"
#include "validators.h"

typedef struct cli Cli; //STRUCT INSPIRADO POR @flgorgoni

////// Funções do Módulo de Relatórios
void moduloRelatorios(void) {
    char opcao;
    Cli *lista;
    lista = NULL;
    do {
        opcao = telaRelatorios();
        switch(opcao) {
            case '1':   clientesOrdemAlfabetica(&lista);
                        telaClientesOrdemAlfabetica(lista);
                        free(lista);
                        break;
        }
    } while (opcao != '0');
}

char telaRelatorios(void) {
    system("clear||cls");
    char escolha;
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Universidade Federal do Rio Grande do Norte                 ///\n");
    printf("///                 Centro de Ensino Superior do Seridó                     ///\n");
    printf("///               Departamento de Computação e Tecnologia                   ///\n");
    printf("///                  Disciplina DCT1106 -- Programação                      ///\n");
    printf("///               Projeto Sistema de Controle de Contas Bancárias           ///\n");
    printf("///     Copyright © 2021 Vitor Daniel - Todos os direitos reservados        ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///       = = = = = Sistema de Controle de Contas Bancárias = = = = =       ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Lista de Clientes por ordem alfabética                    ///\n");
    printf("///            2. Lista de Clientes por ordem alfabética decrescente        ///\n");
    printf("///            0. Voltar ao menu anterior                                   ///\n");
    printf("///                                                                         ///\n");
    printf("///            Escolha a opção desejada: ");                                
    scanf("%c", &escolha);
    getchar();
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    return escolha;
}

void apagarLista(Cli **lista)
{
    Cli *cl;
    
    while (*lista != NULL){
        cl = *lista;
        *lista = (*lista)->prox;
        free(cl);
    }
    //printf("Lista excluida com sucesso! \n");    
}

void clientesOrdemAlfabetica(Cli **lista)
{
    FILE *fp;
    Cli *cl;
    
    apagarLista(&(*lista));
    *lista = NULL;
    fp = fopen("clientes.dat","rb");
    if (fp == NULL)
    {
        printf("O programa não conseguiu abrir o arquivo! \n");
        exit(1);
    }
    else{
        cl = (Cli *) malloc(sizeof(Cli));
        while (fread(cl, sizeof(Cli), 1, fp)){
            if ((*lista == NULL) || (strcmp(cl->nome, (*lista)->nome) < 0)) {
                cl->prox = *lista;
                *lista = cl;
            }else{
                Cli* ant = *lista;    
                Cli* atu = (*lista)->prox;
                while ((atu != NULL) && (strcmp(atu->nome, cl->nome) < 0)) {
                    ant = atu;
                    atu = atu->prox;
                }
                ant->prox = cl;
                cl->prox = atu;
            }
            cl = (Cli *) malloc(sizeof(Cli));
        }
        free(cl);
        printf("Arquivo recuperado com sucesso! \n");
    }   
    fclose(fp); 
}

void telaClientesOrdemAlfabetica(Cli *aux)
{
  printf("\n\n");
  printf("****************************************\n");
    printf("*** Relatorio dos Clientes Cadastrados ***\n");
  printf("****************************************\n");
    printf("Cliente\n");
  printf("\n");
    while (aux != NULL)
    {
        printf("%s\n",aux->nome);
        aux = aux->prox;
    }
    printf("\nFim da Lista! \n\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

