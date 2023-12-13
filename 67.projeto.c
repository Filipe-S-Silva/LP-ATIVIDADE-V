#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

struct informacoesFuncinarios
{

    char nome[200];
    int numeroCadastro;
    char CPF[200];
    char email[200];
    char endereco[200];
    char numeroDeTelefone[200];
    char dataDeNascimento[200];
    char idade[200];
    int horasDeTrabalho;
    float valorSalario;
};

void menu()
{
    printf("CÓDIGO  ===================== AÇÃO\n");
    printf("\n");
    printf("  1                CASDASTRAR FUNCIONÁRIO\n");
    printf("  2                     BATER O PONTO\n");
    printf("  3               DESLIGAMENTO FUNCIONÁRIO\n");
    printf("  4                  FOLHA DE PAGAMENTO\n");
    printf("  5                       SAIR DO MENU\n");
    printf("\n");
}

void limpatela()
{
    system("cls || clear");
}

int main()
{

    // variaveis
    setlocale(LC_ALL, "portuguese");
    int codigo;
    struct informacoesFuncinarios funcionarios[999];
    int posicao = 0;
    int cadastro;
    int horarioEntrada;
    int horarioSaida;
    int i;
    int valorHora = 5;
    float capitalTotalEmpresa = 500000;

    char loginCorreto[200] = "123456";
    char senhaCorreta[200] = "123";
    char loginInserido[200];
    char senhaInserida[200];

    // usuario

    do
    {
        printf("Digite seu login:");
        gets(loginInserido);
        printf("Digite sua senha:");
        gets(senhaInserida);

        if (strcmp(loginInserido, loginCorreto) == 0 && strcmp(senhaInserida, senhaCorreta) == 0)
        {
            printf("Entrando no sistema...");
            sleep(2);
            limpatela();
            do
            {
                menu();
                printf("Informe o código desejado: ");
                scanf("%d", &codigo);
                fflush(stdin);

                switch (codigo)
                {
                case 1:
                    sleep(2);
                    limpatela();
                    printf("CADASTRO FUNCIONÁRIO\n");

                    printf("\n");

                    printf("Informe o nome do funcionário:");
                    gets(funcionarios[posicao].nome);

                    funcionarios[posicao].numeroCadastro = posicao;

                    printf("Informe o CPF do funcionário:");
                    gets(funcionarios[posicao].CPF);

                    printf("Informe o email do funcionário:");
                    gets(funcionarios[posicao].email);

                    printf("Informe o endereço do funcionário:");
                    gets(funcionarios[posicao].endereco);

                    printf("Informe o numero de telefone do funcionário:");
                    gets(funcionarios[posicao].numeroDeTelefone);

                    printf("Informe a data de nascimento do funcionário:");
                    gets(funcionarios[posicao].dataDeNascimento);

                    printf("Informe a idade do funcionário:");
                    gets(funcionarios[posicao].idade);

                    printf("O CADASTRO DO FUNCIONÁRIO É %dº\n", funcionarios[posicao].numeroCadastro);

                    sleep(4);
                    printf("Cadastro realizado\n");
                    sleep(2);
                    limpatela();

                    posicao++;

                    fflush(stdin);

                    break;

                case 2:
                    sleep(2);
                    limpatela();
                    printf("BATER PONTO\n");
                    printf("\n");

                    printf("Informe o cadastro do funcionario: ");
                    scanf("%d", &cadastro);

                    for (i = 0; i < posicao; i++)
                    {
                        if (cadastro == funcionarios[i].numeroCadastro)
                        {

                            printf("Informe o horário de entrada: ");
                            scanf("%d", &horarioEntrada);

                            printf("Informe o horário de saida: ");
                            scanf("%d", &horarioSaida);

                            funcionarios[i].horasDeTrabalho += (horarioSaida - horarioEntrada);

                            sleep(2);
                            limpatela();
                            printf("Horas registradas.......");
                            sleep(2);
                            limpatela();
                        } /*else {                        
                            printf("Funcionario não encontrado.....\nTente novamente");
                            sleep(2);
                            limpatela();
                        }*/
                    }

                    break;

                case 3:
                    sleep(2);
                    limpatela();
                    printf("DEMISSÃO\n");

                    printf("\n");
                    printf("LISTA DE FUNCIONARIOS\n");

                    for (i = 0; i < posicao; i++)
                    {
                        printf("Cadastro e nome do funcionario: %d, %s\n", funcionarios[i].numeroCadastro, funcionarios[i].nome);
                        printf("\n");
                    }

                    printf("Informe o cadastro do funcionario: ");
                    scanf("%d", &cadastro);

                    for (i = 0; i < posicao; i++)
                    {
                        if (cadastro == i)
                        {
                            strcpy(funcionarios[i].nome, "Funcionario demitido");
                            strcpy(funcionarios[i].CPF, "Funcionario demitido");
                            strcpy(funcionarios[i].email, "Funcionario demitido");
                            strcpy(funcionarios[i].endereco, "Funcionario demitido");
                            strcpy(funcionarios[i].numeroDeTelefone, "Funcionario demitido");
                            strcpy(funcionarios[i].dataDeNascimento, "Funcionario demitido");
                            strcpy(funcionarios[i].idade, "Funcionario demitido");

                            funcionarios[i].horasDeTrabalho = 0;
                            funcionarios[i].valorSalario = 0;
                            funcionarios[i].numeroCadastro = 99999;
                        }
                    }
                    sleep(2);
                    limpatela();
                    break;

                case 4:

                    for (i = 0; i < posicao; i++)
                    {
                        funcionarios[i].valorSalario = valorHora * funcionarios[i].horasDeTrabalho;
                        printf("Valor do salario do funcionário %s: %.2f\n", funcionarios[i].nome, funcionarios[i].valorSalario);
                    }

                    sleep(7);
                    limpatela();

                    break;

                case 5:
                    sleep(2);
                    system("cls || clear");
                    printf("Saindo do programa.........\n");
                    sleep(2);
                    printf("Programa encerrado.........");
                    break;

                default:
                    printf("Código inválido\nTente novamente");
                    break;
                }

            } while (codigo != 5);
        }
        else
        {
            printf("Login ou senha incorreta.\n");
        }

    } while (strcmp(loginCorreto, loginInserido) != 0 || strcmp(senhaCorreta, senhaInserida) != 0);

    getchar();
    return 0;
}