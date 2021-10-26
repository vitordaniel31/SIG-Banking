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
void telaCliente(void);
void telaRelatorios(void);

/////
// Programa principal
int main(void) {
    //Execução
    telaPrincipal();
    return 0;
}

/////
// Funções
void telaPrincipal(void) {
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
    printf("///            1. Módulo do Administrador                                   ///\n");
    printf("///            2. Módulo do Cliente                                         ///\n");
    printf("///            3. Módulo do Relatórios                                      ///\n");
    printf("///            4. Sobre o sistema                                           ///\n");
    printf("///            5. Equipe de Desenvolvedores                                 ///\n");
    printf("///            0. Encerrar                                                  ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");

    int escolha;
    printf("Digite o número referente ao módulo que deseja acessar: ");
    scanf("%d", &escolha);

    if(escolha==1) telaAdministrador();
    else if(escolha==2) telaCliente();
    else if(escolha==3) telaRelatorios(); 
    else if(escolha==4) telaSobre();
    else if(escolha==5) telaEquipe();  
    else exit(0);
}

void telaSobre(void) {
    system("clear||cls");
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
    
}

void telaEquipe(void) {
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
    printf("///            Este projeto foi desenvolvido por:                           ///\n");
    printf("///                                                                         ///\n");
    printf("///            Vitor Daniel Lócio Medeiros                                  ///\n");
    printf("///            E-mail: vitor.medeiros.709@ufrn.edu.br                       ///\n");
    printf("///            Redes sociais: @vitor.danielm                                ///\n");
    printf("///            Repositório: https://github.com/vitordaniel31/SIG-Banking    ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}

void telaAdministrador(void) {
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
    printf("///            1. Clientes                                                  ///\n");
    printf("///            2. Transações                                                ///\n");
    printf("///            0. Sair                                                      ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}

void telaCliente(void) {
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
    printf("///            1. Meu Extrato                                               ///\n");
    printf("///            2. Meus Comprovantes                                         ///\n");
    printf("///            3. Pagar Contas                                              ///\n");
    printf("///            4. Fazer Transferência                                       ///\n");
    printf("///            5. Solicitar Empréstimo                                      ///\n");
    printf("///            0. Sair                                                      ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}

void telaRelatorios(void) {
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
    printf("///            1. Logs do Sistema                                           ///\n");
    printf("///            0. Sair                                                      ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}