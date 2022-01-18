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
#include "validators.h"

typedef struct cliente Cliente; //struct inspirado no de @flgorgonio

////// Funções do Módulo do Administrador
void moduloAdministrador(void) {
    char opcao;
    do {
        opcao = telaAdministrador();
        switch(opcao) {
            case '1':   telaAdministradorClientes();
                        break;
            case '2':   telaAdministradorCadastroCliente();
                        break;
            case '3':   telaAdministradorPesquisaCliente();
                        break;
            case '4':   telaAdministradorAtualizaCliente();
                        break;
            case '5':   telaAdministradorTransacoes();
                        break;

        }       
    } while (opcao != '0');
}

char telaAdministrador(void) {
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
    printf("///            1. Lista de Clientes                                         ///\n");
    printf("///            2. Cadastrar Cliente                                         ///\n");
    printf("///            3. Pesquisar Dados de um Cliente                             ///\n");
    printf("///            4. Atualizar Cliente                                         ///\n");
    printf("///            5. Transações                                                ///\n");
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

void telaAdministradorClientes(void) {
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
    printf("///                        LISTA DE CLIENTES (N0ME E CPF)                   ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Vitor Daniel Lócio Medeiros (101.101.101-11)              ///\n");
    printf("///            2. Maria José Lócio Linhares Medeiros (101.101.101-11)       ///\n");
    printf("///            3. Jesca Gabrielly Medeiros (101.101.101-11)                 ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

Cliente* telaAdministradorCadastroCliente(void) {
    system("clear||cls");
    
    Cliente *cli;
    cli = (Cliente*) malloc(sizeof(Cliente));

    FILE* fp; //baseado nos slides apresentados nas aulas
    fp = fopen("clientes.txt","at");
    if (fp == NULL){ //se a função não retornar nada
      printf("Erro! O sistema não conseguiu criar o arquivo\n!");
      exit(1);
    }

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
    printf("///       = = = = = = = = = = Cadastro de Cliente = = = = = = = = = =       ///\n");
    do{
        printf("///           Nome completo (sem acento): ");
        scanf("%s", cli->nome);
        getchar();
    }while(letras(cli->nome)==0 || size(cli->nome, 100, 1)==0);
    fprintf(fp,"%s \n", cli->nome);

    do{
        printf("///           CPF (apenas números): ");
        scanf("%s", cli->cpf );
        getchar();  
    }while(cpfVerify(cli->cpf)==0);
    fprintf(fp,"%s \n", cli->cpf);

    do{
        printf("///           E-mail: ");
        scanf("%s", cli->email);
        getchar();
    }while(emailVerify(cli->email)==0 || size(cli->email, 100, 1)==0);
    fprintf(fp,"%s \n", cli->email);

    do{
        printf("///           Data de Nascimento (dd mm aaaa): ");
        scanf("%d %d %d", &cli->dia, &cli->mes, &cli->ano);
        getchar();
    }while(date(cli->dia, cli->mes, cli->ano)==0);
    fprintf(fp,"%d/%d/%d \n", cli->dia, cli->mes, cli->ano);

    do{
        printf("///           Celular  (apenas números): ");
        scanf("%s", cli->celular);
        getchar();
    }while(cell(cli->celular)==0 || size(cli->celular, 11, 1)==0);
    fprintf(fp,"%s \n", cli->celular);
    
    do{
        printf("///           Estado: ");
        scanf("%s", cli->estado);
        getchar();
    }while(letras(cli->estado)==0 || size(cli->estado, 100, 1)==0);
    fprintf(fp,"%s \n", cli->estado);
    
    do{
        printf("///           Cidade: ");
        scanf("%s", cli->cidade);
        getchar();
    }while(size(cli->cidade, 100, 1)==0);
    fprintf(fp,"%s \n", cli->cidade);
    
    do{
        printf("///           Logradouro / Número: ");
        scanf("%s", cli->logradouro);
        getchar();
    }while(size(cli->logradouro, 100, 1)==0);
    fprintf(fp,"%s \n", cli->logradouro);
    
    do{
        printf("///           Bairro: ");
        scanf("%s", cli->bairro);
        getchar();
    }while(size(cli->bairro, 100, 1)==0);
    fprintf(fp,"%s \n", cli->bairro);
    
    do{
        printf("///           CEP (apenas números): ");
        scanf("%s", cli->cep );
        getchar();
    }while(integer(cli->cep)==0 || size(cli->cep, 8, 1)==0);
    fprintf(fp,"%s \n", cli->cep);
    
    do{
        printf("///           Complemento: ");
        scanf("%s", cli->complemento);
        getchar();
    }while(size(cli->complemento, 100, 1)==0);
    fprintf(fp,"%s \n\n", cli->complemento);
    fclose(fp);
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    //fwrite(cli, sizeof(Cliente), 1, fp);
    return cli;
}

void telaAdministradorPesquisaCliente(void) {
    system("clear||cls");
    char cpf[11];
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
    printf("///       = = = = = = = = = = Pesquisa de Cliente = = = = = = = = = =       ///\n");
    printf("///                                                                         ///\n");
    do{
        printf("///           Informe o CPF (apenas números) do cliente: ");
        scanf("%s", cpf );
        getchar();
    }while(cpfVerify(cpf)==0);
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    telaAdministradorDadosCliente(cpf);
    getchar();
}

void telaAdministradorDadosCliente(char cpf[]) {
    /*FILE* fp;
    Cliente* cli;

    cli = (Cliente*) malloc(sizeof(Cliente));
    fp = fopen("clientes.txt", "rt");
    if (fp == NULL) {
        printf("Erro! O sistema não conseguiu encontrar os dados desse cliente no arquivo\n!");
        exit(1);
    }
    while(fread(cli, sizeof(Cliente), 1, fp)) {
        if ((strcmp(cli->cpf, cpf) == 0)) {
            fclose(fp);
        }
    }
    fclose(fp);
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
    printf("///       = = = = = = = = = = Cadastro de Cliente = = = = = = = = = =       ///\n");
    printf("///           Nome: %s \n", cli->nome);
    printf("///           CPF: %s \n ", cli->cpf);
    printf("///           E-mail: %s \n ", cli->email);
    printf("///           Celular: %s \n", cli->celular);
    printf("///           Estado: %s \n", cli->estado);
    printf("///           Cidade: %s \n", cli->cidade);
    printf("///           Logradouro / Número: %s \n", cli->logradouro);
    printf("///           Bairro: %s \n", cli->nome);
    printf("///           CEP: %s \n", cli->cep);
    printf("///           Complemento: %s \n", cli->complemento);
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    */
}

void telaAdministradorAtualizaCliente(void) {
    system("clear||cls");
    char cpf[11];
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
    printf("///       = = = = = = = =  Atualização de Cliente = = = = = = = = = =       ///\n");
    printf("///                                                                         ///\n");
    do{
        printf("///           Informe o CPF (apenas números) do cliente: ");
        scanf("%s", cpf );
        getchar();
    }while(cpfVerify(cpf)==0);
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void telaAdministradorTransacoes(void) {
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
    printf("///                            LISTA DE TRANSAÇÕES                          ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Saque - Vitor Daniel Lócio Medeiros - R$1000,00           ///\n");
    printf("///            2. Depósito - Maria José Lócio Linhares Medeiros - R$500,00  ///\n");
    printf("///            3. Solicitação de Empréstimo - Jesca Gabrielly Medeiros      ///\n");
    printf("///            - R$10000                                                    ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}