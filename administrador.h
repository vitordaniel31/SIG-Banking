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
	char nome[101];
    char cpf[12];
    int conta; // a conta terá 5 digitos
    char email[101];
    int dia;
    int mes;
    int ano;
    char celular[12];
    char endereco[255];
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