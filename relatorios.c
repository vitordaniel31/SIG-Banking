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
#include "administrador.h"
#include "relatorios.h"
#include "validators.h"

////// Funções do Módulo de Relatórios
void moduloRelatorios(void) {
    char opcao;
    Cliente *lista;
    lista = NULL;
    do {
        opcao = telaRelatorios();
        switch(opcao) {
            case '1':   clientesOrdemAlfabetica(&lista);
                        telaClientesOrdemAlfabetica(lista);
                        free(lista);
                        break;
            case '2':   clientesOrdemAlfabeticaDecrescente(&lista);
                        telaClientesOrdemAlfabeticaDecrescente(lista);
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

void apagarLista(Cliente **lista){ //ESSA FUNÇÃO FOI COPIADA DO GITHUB DE @flgorgonio
    Cliente *cl;
    
    while (*lista != NULL){
        cl = *lista;
        *lista = (*lista)->prox;
        free(cl);
    }
    //printf("Lista excluida com sucesso! \n");    
}

void clientesOrdemAlfabetica(Cliente **lista)
{
    FILE *fp;
    Cliente *cl;
    
    apagarLista(&(*lista));
    *lista = NULL;
    fp = fopen("clientes.dat","rb");
    if (fp == NULL)
    {
        printf("Erro! O sistema não  conseguiu encontrar o arquivo de dados dos clientes\n!"); //criar tela de erro
        exit(1);
    }
    else{
        cl = (Cliente *) malloc(sizeof(Cliente));
        while (fread(cl, sizeof(Cliente), 1, fp)){
            if ((*lista == NULL) || (strcmp(cl->nome, (*lista)->nome) < 0)) {
                cl->prox = *lista;
                *lista = cl;
            }else{
                Cliente* ant = *lista;    
                Cliente* atu = (*lista)->prox;
                while ((atu != NULL) && (strcmp(atu->nome, cl->nome) < 0)) {
                    ant = atu;
                    atu = atu->prox;
                }
                ant->prox = cl;
                cl->prox = atu;
            }
            cl = (Cliente *) malloc(sizeof(Cliente));
        }
        free(cl);
    }   
    fclose(fp); 
}

void telaClientesOrdemAlfabetica(Cliente *aux)
{    
    int count = 0;

    system("clear||cls");
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
    printf("///             LISTA DE CLIENTES (N0ME E CPF) - ORDEM ALFABÉTICA           ///\n");
    printf("///                                                                         ///\n");
    while (aux != NULL)
    {
        count = count +1;
        printf("///       %d. %s (%s)\n", count, aux->nome, aux->cpf);
        aux = aux->prox;
    }
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    free(aux);
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


void clientesOrdemAlfabeticaDecrescente(Cliente **lista)
{
    FILE *fp;
    Cliente *cl;
    
    apagarLista(&(*lista));
    *lista = NULL;
    fp = fopen("clientes.dat","rb");
    if (fp == NULL)
    {
        printf("Erro! O sistema não  conseguiu encontrar o arquivo de dados dos clientes\n!"); //criar tela de erro
        exit(1);
    }
    else{
        cl = (Cliente *) malloc(sizeof(Cliente));
        while (fread(cl, sizeof(Cliente), 1, fp)){
            if ((*lista == NULL) || (strcmp(cl->nome, (*lista)->nome) > 0)) {
                cl->prox = *lista;
                *lista = cl;
            }else{
                Cliente* ant = *lista;    
                Cliente* atu = (*lista)->prox;
                while ((atu != NULL) && (strcmp(atu->nome, cl->nome) > 0)) {
                    ant = atu;
                    atu = atu->prox;
                }
                ant->prox = cl;
                cl->prox = atu;
            }
            cl = (Cliente *) malloc(sizeof(Cliente));
        }
        free(cl);
    }   
    fclose(fp); 
}

void telaClientesOrdemAlfabeticaDecrescente(Cliente *aux)
{    
    int count = 0;

    system("clear||cls");
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
    printf("///       LISTA DE CLIENTES (N0ME E CPF) - ORDEM ALFABÉTICA DECRESCENTE     ///\n");
    printf("///                                                                         ///\n");
    while (aux != NULL)
    {
        count = count +1;
        printf("///       %d. %s (%s)\n", count, aux->nome, aux->cpf);
        aux = aux->prox;
    }
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    free(aux);
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}