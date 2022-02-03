///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Seridó                     ///
///               Departamento de Computação e Tecnologia                   ///
///                  Disciplina DCT1106 -- Programação                      ///
///                Projeto: Sistema de Controle de Contas Bancárias         ///
///     Copyright © 2021 Vitor Daniel - Todos os direitos reservados        ///
///////////////////////////////////////////////////////////////////////////////

typedef struct extrato Extrato; //struct inspirado no de @flgorgonio


struct extrato {
    char tipo_movimentacao[20];
    int valor;
    char cpf[12];
};

// Assinatura das funções do módulo do cliente
void moduloCliente(void);
char telaCliente(void);
void telaClienteExtrato(void);
void telaClienteSaldo(void);

//funções para extrato
void clienteSalvarExtrato(Extrato*);

//funções para fazer depósito
void clienteDeposito(void);
Extrato* telaClienteDeposito(void);

//funções para fazer saque
void clienteSaque(void);
Extrato* telaClienteSaque(void);
