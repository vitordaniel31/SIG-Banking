///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Seridó                     ///
///               Departamento de Computação e Tecnologia                   ///
///                  Disciplina DCT1106 -- Programação                      ///
///                Projeto: Sistema de Controle de Contas Bancárias         ///
///     Copyright © 2021 Vitor Daniel - Todos os direitos reservados        ///
///////////////////////////////////////////////////////////////////////////////

typedef struct cli Cli;

struct cli {
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
  	struct cli *prox;
};

// Assinatura das funções do módulo de relatórios
void moduloRelatorios(void);
char telaRelatorios(void);
void clientesOrdemAlfabetica(Cli **);
void apagarLista(Cli**);
void telaClientesOrdemAlfabetica(Cli*);
