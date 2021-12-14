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
#include "cliente.h"
#include "validators.h"

////// Funções do Módulo do Cliente
void moduloCliente(void) {
    char opcao;
    do {
        opcao = telaCliente();
        switch(opcao) {
            case '1':   telaClienteExtrato();
                        break;
            case '2':   telaClienteComprovantes();
                        break;
            case '3':   telaClientePagar();
                        break;
            case '4':   telaClienteTransferencia();
                        break;
            case '5':   telaClienteEmprestimo();
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
    printf("///            2. Meus Comprovantes                                         ///\n");
    printf("///            3. Pagar Contas                                              ///\n");
    printf("///            4. Fazer Transferência                                       ///\n");
    printf("///            5. Solicitar Empréstimo                                      ///\n");
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
    printf("///                                 MEU EXTRATO                             ///\n");
    printf("///                                                                         ///\n");
    printf("///            Saque == (- R$1000,00)                         10/11/2021    ///\n");
    printf("///            Depósito == (+ R$500,00)                       12/11/2021    ///\n");
    printf("///            Transferência == (- R$300,00)                  14/11/2021    ///\n");
    printf("///                                                                         ///\n");
    printf("///            SALDO ATUAL = R$3500,00                        15/11/2021    ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void telaClienteComprovantes(void) {
    system("clear||cls");
    char comprovante[10];
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
    printf("///                            LISTA DE COMPROVANTES                        ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Saque - Vitor Daniel Lócio Medeiros - R$1000,00           ///\n");
    printf("///            2. Depósito - Maria José Lócio Linhares Medeiros - R$500,00  ///\n");
    printf("///            3. Transferência - Jesca Gabrielly Medeiros - R$500,00       ///\n");
    printf("///                                                                         ///\n");
    do{
        printf("///      Informe o número da transação que deseja emitir comprovante: ");
        scanf("%s", comprovante );
        getchar();
    }while(integer(comprovante)==0 || size(comprovante, 10, 1)==0);
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void telaClientePagar(void) {
    system("clear||cls");
    char codigo[100];
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
    printf("///                            PAGAMENTO DE BOLETO                          ///\n");
    printf("///                                                                         ///\n");
    do{
        printf("///      Digite o código de barras do boleto: (apenas números)");
        scanf("%s", codigo );
        getchar();
    }while(integer(codigo)==0 || size(codigo, 100, 1)==0);
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void telaClienteTransferencia(void) {
    system("clear||cls");
    char nome[100];
    char cpf[11];
    char agencia[5];
    char conta[20];
    char tipo[1];
    char valor[10];

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
        printf("///           Nome completo (sem acento): ");
        scanf("%s", nome);
        getchar();
    }while(letras(nome)==0 || size(nome, 100, 1)==0);
    do{
        printf("///           CPF (apenas números): ");
        scanf("%s", cpf );
        getchar();  
    }while(cpfVerify(cpf)==0);
    do{
        printf("///           Agência (apenas números): ");
        scanf("%s", agencia );
        getchar();
    }while(integer(agencia)==0);
    do{
        printf("///           Conta com dígito (apenas números): ");
        scanf("%s", conta );
        getchar();
    }while(integer(conta)==0);
    do{
        printf("///           Tipo da Conta (1-Corrente, 2-Poupança): ");
        scanf("%c", tipo );
        getchar();
    }while(integer(tipo)==0);
    do{
        printf("///      Digite o valor da transferêcia: (apenas números)");
        scanf("%s", valor );
        getchar();
    }while(integer(valor)==0);
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void telaClienteEmprestimo(void) {
    system("clear||cls");
    char valor[10];
    char motivo[255];
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
    printf("///                            PAGAMENTO DE BOLETO                          ///\n");
    printf("///                                                                         ///\n");
    do{
        printf("///      Digite o valor do empréstimo (apenas números): ");
        scanf("%s", valor );
        getchar();
    }while(integer(valor)==0);
    do{
        printf("///      Diga o motivo da solicitação:");
        scanf("%s", motivo);
        getchar();
    }while(size(motivo, 255, 1)==0);
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}
