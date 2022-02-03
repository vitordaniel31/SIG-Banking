///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Seridó                     ///
///               Departamento de Computação e Tecnologia                   ///
///                  Disciplina DCT1106 -- Programação                      ///
///                Projeto: Sistema de Controle de Contas Bancárias         ///
///     Copyright © 2021 Vitor Daniel - Todos os direitos reservados        ///
///////////////////////////////////////////////////////////////////////////////

typedef struct transferencia Transferencia; //struct inspirado no de @flgorgonio
typedef struct deposito Deposito; //struct inspirado no de @flgorgonio
typedef struct saque Saque; //struct inspirado no de @flgorgonio
typedef struct emprestimo Extrato; //struct inspirado no de @flgorgonio

struct extrato {
    char tipo_movimentacao[20];
    double valor;
    char cpf[12];
};

struct transferencia {
	char cpf[11];
    char agencia[5];
    char conta[20];
    char tipo[1];
    char valor[10];
};

struct deposito {
    char valor[10]; 
};

struct saque {
    char valor[10];
};


// Assinatura das funções do módulo do cliente
void moduloCliente(void);
char telaCliente(void);
void telaClienteExtrato(void);
void telaClienteSaldo(void);
Saque* telaClienteSaque(void);
Deposito* telaClienteDeposito(void);
Transferencia* telaClienteTransferencia(void);
