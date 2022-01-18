///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Seridó                     ///
///               Departamento de Computação e Tecnologia                   ///
///                  Disciplina DCT1106 -- Programação                      ///
///                Projeto: Sistema de Controle de Contas Bancárias         ///
///     Copyright © 2021 Vitor Daniel - Todos os direitos reservados        ///
///////////////////////////////////////////////////////////////////////////////

typedef struct cliente Cliente; //struct inspirado no de @flgorgonio

struct cliente {
	char nome[100];
    char cpf[11];
    char email[100];
    int dia;
    int mes;
    int ano;
    char celular[12];
    char estado[100];
    char cidade[100];
    char logradouro[100];
    char bairro[100];
    char cep[8];
    char complemento[100];
};


// Assinatura das funções do módulo do administrador
void moduloAdministrador(void);
char telaAdministrador(void);
void telaAdministradorClientes(void);
Cliente* telaAdministradorCadastroCliente(void);
void telaAdministradorPesquisaCliente(void);
void telaAdministradorDadosCliente(char[]);
void telaAdministradorAtualizaCliente(void);
void telaAdministradorTransacoes(void);