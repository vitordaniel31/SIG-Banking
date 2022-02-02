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
///
void moduloAdministrador(void) {
    char opcao;
    do {
        opcao = telaAdministrador();
        switch(opcao) {
            case '1':   telaAdministradorClientes();
                        break;
            case '2':   telaAdministradorCadastroCliente();
                        break;
            case '3':   administradorPesquisarCliente();
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
    FILE* fp;
    Cliente* cli;

    cli = (Cliente*) malloc(sizeof(Cliente));
    fp = fopen("clientes.dat", "rb");
    if (fp == NULL) {
        printf("Erro! O sistema não  conseguiu encontrar o arquivo de dados dos clientes\n!"); //criar tela de erro
        exit(1);
    }
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
    printf("///                        LISTA DE CLIENTES (N0ME E CPF)                   ///\n");
    printf("///                                                                         ///\n");
    while(fread(cli, sizeof(Cliente), 1, fp)) {
        count = count +1;
        printf("///       %d. %s (%s)\n", count, cli->nome, cli->cpf);
        
    }
    fclose(fp);
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    free(cli);
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

Cliente* telaAdministradorCadastroCliente(void) {
    system("clear||cls");
    
    Cliente *cli;
    cli = (Cliente*) malloc(sizeof(Cliente));

    FILE* fp; //baseado nos slides apresentados nas aulas
    fp = fopen("clientes.dat","ab");
    if (fp == NULL){ //se a função não retornar nada
      printf("Erro! O sistema não conseguiu criar o arquivo\n!");
      exit(1);
    }
    int conta = 0;
    while(fread(cli, sizeof(Cliente), 1, fp)) {
        conta = conta + 1;
    }
    conta = conta + 1;
    

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
    //fprintf(fp,"%s \n", cli->nome);

    do{
        printf("///           CPF (apenas números): ");
        scanf("%s", cli->cpf);
        getchar();  
    }while(cpfVerify(cli->cpf)==0);
    //fprintf(fp,"%s \n", cli->cpf);

    do{
        printf("///           E-mail: ");
        scanf("%s", cli->email);
        getchar();
    }while(emailVerify(cli->email)==0 || size(cli->email, 100, 1)==0);
    //fprintf(fp,"%s \n", cli->email);

    do{
        printf("///           Data de Nascimento (dd mm aaaa): ");
        scanf("%d %d %d", &cli->dia, &cli->mes, &cli->ano);
        getchar();
    }while(date(cli->dia, cli->mes, cli->ano)==0);
    //fprintf(fp,"%d/%d/%d \n", cli->dia, cli->mes, cli->ano);

    do{
        printf("///           Celular  (apenas números): ");
        scanf("%s", cli->celular);
        getchar();
    }while(cell(cli->celular)==0 || size(cli->celular, 11, 1)==0);
    //fprintf(fp,"%s \n", cli->celular);
    
    do{
        printf("///           Endereço: ");
        scanf("%s", cli->endereco);
        getchar();
    }while(size(cli->endereco, 254, 1)==0);
    cli->conta = conta;
    //fprintf(fp,"%s \n", cli->endereco);
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    fwrite(cli, sizeof(Cliente), 1, fp);
    fclose(fp);
    free(cli);
    getchar();
    return cli;
}


//funções para pesquisar um cliente
void administradorPesquisarCliente(void) { //ESSA FUNÇÃO FOI INSPIRADA NO GITHUB DE @flgorgonio
    Cliente* cli;
    char* cpf;

    cpf = telaAdministradorPesquisaCliente();
    cli = administradorBuscarCliente(cpf);
    telaAdministradorExibeCliente(cli);
    free(cli); 
    free(cpf);
}

char* telaAdministradorPesquisaCliente(void) {
    system("clear||cls");
    char* cpf;
    cpf = (char*) malloc(12*sizeof(char));
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
    printf("///             #Digite 0 para voltar ao menu anterior#                     ///\n");
    printf("///                                                                         ///\n");
    printf("///           Informe o CPF (apenas números) do cliente: ");
    scanf("%s", cpf );
    getchar();
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    return cpf;
}

Cliente* administradorBuscarCliente(char* cpf){ //ESSA FUNÇÃO FOI INSPIRADA NO GITHUB DE @flgorgonio
    FILE* fp;
    Cliente* cli;

    cli = (Cliente*) malloc(sizeof(Cliente));
    fp = fopen("clientes.dat", "rb");
    if (fp == NULL) {
        printf("Erro! O sistema não  conseguiu encontrar o arquivo de dados dos clientes\n!"); //criar tela de erro
        exit(1);
    }
    while(fread(cli, sizeof(Cliente), 1, fp)) {
        if ((strcmp(cli->cpf, cpf) == 0)) { 
            fclose(fp);
            return cli;
        } 
    }
    fclose(fp);
    return NULL;
}

void telaAdministradorExibeCliente(Cliente* cli) {
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
    if(cli == NULL){
        printf("///       = = = = = = = = = =  Cliente Inexistente = = = = = = = = = = =    ///\n");
    }else{
        printf("///       = = = = = = = = = =  Dados do Cliente = = = = = = = = = = =       ///\n");
        printf("///           Nome: %s \n", cli->nome);
        printf("///           CPF: %s \n", cli->cpf);
        printf("///           Conta: %d \n", cli->conta);
        printf("///           E-mail: %s \n", cli->email);
        printf("///           Data de Nascimento: %d/%d/%d \n", cli->dia, cli->mes, cli->ano);
        printf("///           Celular: %s \n", cli->celular);
        printf("///           Endereço: %s \n", cli->endereco);
        printf("///                                                                         ///\n");
    }
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
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