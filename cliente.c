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
#include "cliente.h"
#include "administrador.h"
#include "validators.h"

typedef struct extrato Extrato; //struct inspirado no de @flgorgonio
typedef struct cliente Cliente; //struct inspirado no de @flgorgonio

char* cpf_cliente;
Cliente* cliente_logado;

////// Funções do Módulo do Cliente
void moduloCliente(void) {
    cpf_cliente = telaAdministradorPesquisaCliente();
    cliente_logado  = administradorBuscarCliente(cpf_cliente);
    char opcao;
    do {
        opcao = telaCliente();
        switch(opcao) {
            case '1':   telaClienteExtrato();
                        break;
            case '2':   telaClienteSaldo();
                        break;
            case '3':   telaClienteSaque();
                        break;
            case '4':   clienteDeposito();
                        break;
            case '5':   telaClienteTransferencia();
                        break;
        }       
    } while (opcao != '0');
}

char telaCliente(void) {
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
    printf("///            1. Meu Extrato                                               ///\n");
    printf("///            2. Meu Saldo                                                 ///\n");
    printf("///            3. Solicitar saque                                           ///\n");
    printf("///            4. Fazer Depósito                                            ///\n");
    printf("///            5. Fazer Transferência                                       ///\n");
    printf("///            0. Voltar ao menu anterior                                   ///\n");
    printf("///                                                                         ///\n");
    printf("///            Escolha a opção desejada: ");                                
    scanf("%c", &escolha);
    getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    return escolha;
}

void telaClienteExtrato(void) {
    FILE* fp;
    Extrato* extrato;

    extrato = (Extrato*) malloc(sizeof(Extrato));
    fp = fopen("extratos.dat", "rb");
    if (fp == NULL) {
        printf("Erro! O sistema não  conseguiu encontrar o arquivo de dados dos clientes\n!"); //criar tela de erro
        exit(1);
    }

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
    printf("///                                 Meu Extrato                             ///\n");
    printf("///                                                                         ///\n");
    while(fread(extrato, sizeof(Extrato), 1, fp)) {
        if ((strcmp(extrato->cpf, cpf_cliente) == 0)) { 
            printf("///            %s == (R$%d) \n", extrato->tipo_movimentacao, extrato->valor);
        } 
    }
    printf("///                                                                         ///\n");
    printf("///            SALDO ATUAL = R$%d \n", cliente_logado->saldo);
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    fclose(fp);
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void telaClienteSaldo(void) {
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
    printf("///                                 Meu Saldo                               ///\n");
    printf("///                                                                         ///\n");
    printf("///            O seu saldo é de: R$ %d                                     ///\n", cliente_logado->saldo);
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

//funções para fazer um deposito
void clienteDeposito(void) {
    Extrato *deposito;
    Cliente* cliente;

    deposito = telaClienteDeposito();
    clienteSalvarExtrato(deposito);
    cliente = administradorBuscarCliente(deposito->cpf);
    cliente->saldo = deposito->valor + cliente->saldo;
    administradorRegravarCliente(cliente);
    free(deposito);
}

Extrato* telaClienteDeposito(void) {
    system("clear||cls");
    Extrato *deposito;
    deposito = (Extrato*) malloc(sizeof(Extrato));

    Cliente* titular;

    sprintf(deposito->tipo_movimentacao, "%s", "Depósito");

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
    printf("///       = = = = = = = = = = = = = Depósito  = = = = = = = = = = = =       ///\n");
    do{
        printf("///            CPF (apenas números) do titular da conta: ");
        scanf("%[0-9]", deposito->cpf);
        getchar();  
    }while(cpfExtrato(deposito->cpf)==0);
    titular = administradorBuscarCliente(deposito->cpf);
    printf("///            Titular: %s \n", titular->nome);
    do{
        printf("///            Valor do depósito (apenas inteiros): ");
        scanf("%d", &deposito->valor);
        getchar();     
    }while(deposito->valor<=0);
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return deposito;
}

void clienteSalvarExtrato(Extrato* extrato) { 
    FILE* fp;

    fp = fopen("extratos.dat", "ab");
    if (fp == NULL) {
        printf("Erro! O sistema não  conseguiu encontrar o arquivo de dados dos extratos\n!"); //criar tela de erro
        exit(1);
    }
    fwrite(extrato, sizeof(Extrato), 1, fp);
    fclose(fp);
}

Saque* telaClienteSaque(void) {
    system("clear||cls");

    Saque *saq;
    saq = (Saque*) malloc(sizeof(Saque));

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
    printf("///                                 SAQUE                                   ///\n");
    printf("///                                                                         ///\n");
    do{
        printf("///      Digite o valo do saque (apenas números): ");
        scanf("%s", saq->valor );
        getchar();
    }while(integer(saq->valor)==0 || size(saq->valor, 10, 1)==0);
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return saq;
}


Transferencia* telaClienteTransferencia(void) {
    system("clear||cls");
    
    Transferencia *tra;
    tra = (Transferencia*) malloc(sizeof(Transferencia));

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
    printf("///                             TRANSFERÊNCIA BANCÁRIA                      ///\n");
    printf("///                                                                         ///\n");
    do{
        printf("///           CPF (apenas números): ");
        scanf("%s", tra->cpf );
        getchar();  
    }while(cpfVerify(tra->cpf)==0);
    do{
        printf("///           Agência (apenas números): ");
        scanf("%s", tra->agencia );
        getchar();
    }while(integer(tra->agencia)==0);
    do{
        printf("///           Conta com dígito (apenas números): ");
        scanf("%s", tra->conta );
        getchar();
    }while(integer(tra->conta)==0);
    do{
        printf("///           Tipo da Conta (1-Corrente, 2-Poupança): ");
        scanf("%c", tra->tipo );
        getchar();
    }while(integer(tra->tipo)==0);
    do{
        printf("///      Digite o valor da transferêcia (apenas números): ");
        scanf("%s", tra->valor );
        getchar();
    }while(integer(tra->valor)==0);
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return tra;
}
