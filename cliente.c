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

typedef struct transferencia Transferencia; //struct inspirado no de @flgorgonio
typedef struct deposito Deposito; //struct inspirado no de @flgorgonio
typedef struct saque Saque; //struct inspirado no de @flgorgonio
typedef struct emprestimo Emprestimo; //struct inspirado no de @flgorgonio


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
            case '3':   telaClienteSaque();
                        break;
            case '4':   telaClienteDeposito();
                        break;
            case '5':   telaClienteTransferencia();
                        break;
            case '6':   telaClienteEmprestimo();
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
    printf("///            3. Solicitar saque                                           ///\n");
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

Deposito* telaClienteDeposito(void) {
    system("clear||cls");
    
    Deposito *dep;
    dep = (Deposito*) malloc(sizeof(Deposito));

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
    printf("///                                DEPÓSITO                                 ///\n");
    printf("///                                                                         ///\n");
    do{
        printf("///      Digite o valo do depósito (apenas números): ");
        scanf("%s", dep->valor );
        getchar();
    }while(integer(dep->valor)==0 || size(dep->valor, 10, 1)==0);
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return dep;
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

Emprestimo* telaClienteEmprestimo(void) {
    system("clear||cls");
    
    Emprestimo *emp;
    emp = (Emprestimo*) malloc(sizeof(Emprestimo));

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
    printf("///                            EMPRÉSTIMO                                   ///\n");
    printf("///                                                                         ///\n");
    do{
        printf("///      Digite o valor do empréstimo (apenas números): ");
        scanf("%s", emp->valor );
        getchar();
    }while(integer(emp->valor)==0);
    do{
        printf("///      Diga o motivo da solicitação:");
        scanf("%s", emp->motivo);
        getchar();
    }while(size(emp->motivo, 255, 1)==0);
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return emp;
}
