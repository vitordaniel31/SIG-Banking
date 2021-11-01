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

/////
// Assinatura das funções
void telaSobre(void);
void telaPrincipal(void);
void telaEquipe(void);
void telaAdministrador(void);
void telaAdministradorClientes(void);
void telaAdministradorCadastroCliente(void);
void telaAdministradorPesquisaCliente(void);
void telaAdministradorTransacoes(void);
void telaCliente(void);
void telaRelatorios(void);

/////
// Programa principal
int main(void) {
    //Execução
    telaPrincipal();
    telaSobre();
    telaEquipe();
    telaAdministrador();
    telaAdministradorClientes();
    telaAdministradorCadastroCliente();
    telaAdministradorPesquisaCliente();
    telaAdministradorTransacoes();
    telaCliente();
    telaRelatorios();
    return 0;
}

/////
// Funções
void telaPrincipal(void) {
    //system("clear||cls");
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
    printf("///            1. Módulo do Administrador                                   ///\n");
    printf("///            2. Módulo do Cliente                                         ///\n");
    printf("///            3. Módulo do Relatórios                                      ///\n");
    printf("///            4. Sobre o sistema                                           ///\n");
    printf("///            5. Equipe de Desenvolvedores                                 ///\n");
    printf("///            0. Encerrar                                                  ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

    /*int escolha;
    printf("Digite o número referente ao módulo que deseja acessar: ");
    scanf("%d", &escolha);

    if(escolha==1) telaAdministrador();
    else if(escolha==2) telaCliente();
    else if(escolha==3) telaRelatorios(); 
    else if(escolha==4) telaSobre();
    else if(escolha==5) telaEquipe();  
    else exit(0);*/
}

void telaSobre(void) {
    //system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Universidade Federal do Rio Grande do Norte                 ///\n");
    printf("///                 Centro de Ensino Superior do Seridó                     ///\n");
    printf("///               Departamento de Computação e Tecnologia                   ///\n");
    printf("///                  Disciplina DCT1106 -- Programação                      ///\n");
    printf("///               Projeto: Sistema de Controle de Contas Bancárias          ///\n");
    printf("///     Copyright © 2021 Vitor Daniel - Todos os direitos reservados        ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///       = = = = = Sistema de Controle de Contas Bancárias = = = = =       ///\n");
    printf("///                                                                         ///\n");
    printf("///  Programa utilizado na disciplina DCT1106 - Programação, para fins      ///\n");
    printf("///  didáticos. O programa contém os principais módulos e funcionalidades   ///\n");
    printf("///  de um banco: cadastro de clientes, consulta de saldo, extrato, cartões,///\n");
    printf("///  empréstimos e a parte administrativa para controle da instituição      ///\n");
    printf("///  bancária.                                                              ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    
}

void telaEquipe(void) {
    //system("clear||cls");
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
    printf("///            Este projeto foi desenvolvido por:                           ///\n");
    printf("///                                                                         ///\n");
    printf("///            Vitor Daniel Lócio Medeiros                                  ///\n");
    printf("///            E-mail: vitor.medeiros.709@ufrn.edu.br                       ///\n");
    printf("///            Redes sociais: @vitor.danielm                                ///\n");
    printf("///            Repositório: https://github.com/vitordaniel31/SIG-Banking    ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

//telas do módulo 1-Administrador
void telaAdministrador(void) {
    //system("clear||cls");
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
    printf("///           Escolha a opção desejada:                                     ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void telaAdministradorClientes(void) {
    //system("clear||cls");
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
    printf("///            1. Vitor Daniel Lócio Medeiros (101.101.101-11)              ///\n");
    printf("///            2. Maria José Lócio Linhares Medeiros (101.101.101-11)       ///\n");
    printf("///            3. Jesca Gabrielly Medeiros (101.101.101-11)                 ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void telaAdministradorCadastroCliente(void) {
    //system("clear||cls");
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
    printf("///           Nome completo:                                                ///\n");
    printf("///           CPF (apenas números):                                         ///\n");
    printf("///           E-mail:                                                       ///\n");
    printf("///           Data de Nascimento (dd/mm/aaaa):                              ///\n");
    printf("///           Celular  (apenas números):                                    ///\n");
    printf("///           Cidade:                                                       ///\n");
    printf("///           Logradouro / Número:                                          ///\n");
    printf("///           Bairro:                                                       ///\n");
    printf("///           CEP:                                                          ///\n");
    printf("///           Complemento:                                                  ///\n");
    printf("///                                                                         ///\n");
    printf("///           Escolha a opção desejada:                                     ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void telaAdministradorPesquisarCliente(void) {
    //system("clear||cls");
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
    printf("///           Informe o CPF (apenas números) do cliente:                    ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void telaAdministradorTransacoes(void) {
    //system("clear||cls");
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

//fim das telas do módulo 1-Administrador

void telaCliente(void) {
    //system("clear||cls");
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
    printf("///            0. Sair                                                      ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void telaRelatorios(void) {
    //system("clear||cls");
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
    printf("///            1. Logs do Sistema                                           ///\n");
    printf("///            0. Sair                                                      ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}