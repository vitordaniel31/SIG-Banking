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
	char nome[256];
    char cpf[12];
    char conta[6]; // a conta terá 5 digitos
    char email[256];
    int dia;
    int mes;
    int ano;
    char celular[12];
    char endereco[256];
    int saldo;
};


// Assinatura das funções do módulo do administrador
void moduloAdministrador(void);
char telaAdministrador(void);
void telaAdministradorClientes(void);

//funções para cadastrar um cliente
void administradorCadastrarCliente(void);
Cliente* telaAdministradorCadastroCliente(void);
void administradorSalvarCliente(Cliente*);

//funções para pesquisar um cliente
void administradorPesquisarCliente(void);
char* telaAdministradorPesquisaCliente(void);
Cliente* administradorBuscarCliente(char*);
void telaAdministradorExibeCliente(Cliente*);

//funções para atualizar um cliente
void administradorAtualizarCliente(void);
Cliente* telaAdministradorAtualizarCliente(void);
void administradorRegravarCliente(Cliente*);


void telaAdministradorAtualizaCliente(void);
void telaAdministradorTransacoes(void);