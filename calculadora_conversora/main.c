#include <stdio.h> //biblioteca para usar funções de entrada e saída
#include <stdlib.h> // biblioteca para usar a função de limpar a tela
#include <windows.h> //biblioteca adicionada para configurar UTF-8, que não tinha funcionado de outras formas
#include<math.h> //biblioteca adicionada para poder usar funções matemáticas
#define MAX 50 //define o número máximo do vetor que irá construir o número binário

int main()
{
    system("chcp 65001 > nul"); //comando para conseguir usar UTF-8

    //declaração de variáveis
    int opcao, continuar; //armazenam as escolhas do usuario
    int dec, bin, binario, decimal; //variáveis para armazenar valor decimal e binario
    int vet_bin[MAX]; //vetor que vai armazenar o número binário final
    int i = 0, j; // variáveis de controle de loop

    //programa
    do {
            //menu inicial da calculadora
            printf ("=============CALCULADORA=============\n");
            printf ("Escolha uma opção e pressione Enter:\n\t");
            printf ("1 - binário para decimal\n\t");
            printf ("2 - decimal para binário\n");
            printf ("=====================================\n");
        scanf("%d", &opcao);

      switch ( opcao ) //estrutura para selecionar uma opção do menu
      {
        case 1 :
        printf("\nInforme um número binário:\n"); //solicita ao usuário um número binário a ser convertido
        scanf("%d", &binario);
        for(i = 0; binario > 0; i++) //estrutura de repetição para transformar o número binário em decimal
            {
            decimal = decimal + pow(2, i) * (binario % 10); //uso da função pow, que realiza potenciação
            binario = binario / 10;
            }
        printf("\nNúmero decimal: \t %d\n", decimal); //exibe o resultado
        decimal = 0; //zera a variável para evitar lixo nas próximas execuções da calculadora
        break; //estrutura obrigatória para impedir que os outros casos sejam executados

        case 2 :

        printf ("\nInforme um número decimal:\n");
        scanf ("%d", &dec);
        i = 0; //reseta a variável de controle
        // enquanto a variável dec for maior que 0
        while(dec > 0)
        {
            // obtém o resto da divisão de dec por 2
            vet_bin[i] = dec % 2;
            i++; //incremento de variável
            dec = dec / 2; //atribui o novo valor à variável
        }

        printf("\nResultado da conversão:\n");
        // percorre o vetor de trás pra frente para mostrar o número em binário
        for(j = i - 1; j >= 0; j--){
            printf("%d", vet_bin[j]); //exibe cada elemento na tela
            vet_bin[j] = NULL; //limpa o vetor para um próximo uso
        }

        break;

        default : //opção padrão no caso do usuário escolher uma opção inválida no menu
        printf ("OPS! Valor inválido! Tente novamente\n");
      }
        printf("\nDigite 1 para continuar ou 2 para sair\n"); //momento que o usuário decide fazer outra operação ou não
        scanf("%d", &continuar);
        system("cls"); //limpa a tela

    } while (continuar==1); //condição para o programa ser executado novamente
    return 0;
}
