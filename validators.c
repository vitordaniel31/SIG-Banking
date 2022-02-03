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
#include <string.h>
#include <ctype.h>
#include "validators.h"
#include "administrador.h"

////// Funções do Módulo Validator
int integer(char entrada[]) { //verifica se entrada é um inteiro
    int i;
    for(i = 0; i < strlen(entrada); i++)
    {
        if (!isdigit(entrada[i]))
        {
            return 0;
        }
    }
    return 1;
}

int letras(char entrada[]) { //verifica se entrada é um inteiro
    int i;
    for(i = 0; i < strlen(entrada); i++)
    {
        if (!isalpha(entrada[i]) && !isspace(entrada[i]))
        {
            return 0;
        }
    }
    return 1;
}

int cpfVerify(char entrada[]) { //verifica se o cpf digitado tem 11 digitos
    FILE* fp;
    Cliente* cliente;

    cliente = (Cliente*) malloc(sizeof(Cliente));
    fp = fopen("clientes.dat", "rb");
    while(fread(cliente, sizeof(Cliente), 1, fp)) {
        if ((strcmp(cliente->cpf, entrada) == 0)) {
            printf("///                 JÁ EXISTE UM CLIENTE COM ESSE CPF                       ///\n");
            fclose(fp);
            return 0;
        }
    }

    int i;
    for(i = 0; i < strlen(entrada); i++)
    {
        if (!isdigit(entrada[i]))
        {
            printf("///                 O CAMPO CPF SÓ PERMITE NÚMEROS                          ///\n");
            return 0;
        }
    }
    free(cliente);
    if(strlen(entrada)!=11) return 0; 
    return 1;
}

int cpfExtrato(char entrada[]) { //verifica se o cpf digitado tem 11 digitos
    FILE* fp;
    Cliente* cliente;

    cliente = (Cliente*) malloc(sizeof(Cliente));
    fp = fopen("clientes.dat", "rb");
    while(fread(cliente, sizeof(Cliente), 1, fp)) {
        if ((strcmp(cliente->cpf, entrada) == 0)) {
            fclose(fp);
            return 1;
        }
    }
    free(cliente);
    printf("///              ESSE CPF NÃO ESTÁ REGISTRADO A UMA CONTA                   ///\n");
    return 0;
}

int date(int dia, int mes, int ano){
    int validateDay = 0;
    if((mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12) && (dia>0 && dia<=31)) validateDay = 1;
    else if((mes==4 || mes==6 || mes==9 || mes==11) && (dia>0 && dia<=30)) validateDay = 1;
    else if((mes==2) && (dia>0 && dia<=29)){
        if(dia<=28) validateDay = 1;
        else if(dia==29 && ((ano % 4)==0 && ((ano % 100)!=0 || (ano % 400)==0))) validateDay = 1;
    }

    if(ano>=0 && (mes>=1 && mes<=12) && validateDay) return 1;
    else return 0;
}

int size(char entrada[], int tamanho, int required){
    if(strlen(entrada)>tamanho) return 0;
    if(required==1 && strlen(entrada)==0) return 0;

    return 1;
}

/*int emailVerify(char entrada[]){
    if(entrada[strlen(entrada)-4]!='.') return 0;
    if(entrada[strlen(entrada)-4]=='@') return 0;

    int arrobaPos = -1;
    int contArroba = 0;
    int i;
    for (i = 0; i < strlen(entrada); i++)
    {
        if(entrada[i]=='@'){
          arrobaPos = i;
          contArroba++;
        }
    }
    if(contArroba==0 || contArroba>1) return 0;

    
    char permitidos[28]={'.', 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y', 'z'};
    for (i = arrobaPos; i < strlen(entrada)-4; i++)
    {   
        int count = 0;
        int j;
        for (j = 0; j < 28; j++)
        {
            if(entrada[i+1]==permitidos[j]){
              count++;
            }
        }
        if(count==0) return 0; //tem algarismos sem ser permitidos entre o @ e o . do dominio
        count = 0;
    }
  
    return 1;
}*/

int cell(char entrada[]){
    if(strlen(entrada)!=11) return 0; //verifica se tem 11 digitos
    if(integer(entrada)==0) return 0; //verifica se tem apenas numeros

    return 1;
}