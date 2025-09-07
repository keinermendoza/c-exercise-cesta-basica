#include <stdio.h>
#include <string.h>

typedef struct 
{
    char* nome;
    float preco_anterior;
    float preco_atual;
    float variacao;
    char* situacao;
    int variacao_teve_abuso;
} ProdutoCestaBasica;

int main()  {
    int PRODUCT_NUMBER = 3;
    ProdutoCestaBasica cesta_basica[PRODUCT_NUMBER];

    // variáveis temporárias
    char nome[100];
    float preco_anterior;
    float preco_atual;
    float variacao;
    char* situacao;
    int variacao_teve_abuso = 0;
    int i = 0;
    int leitura_correta = 0;

    // apresenta o programa
    printf("Este programa avalia o aumento de preços em produtos alimentícios\n");
    
    while (i < PRODUCT_NUMBER) {
        // inicializando variável como falsa
        variacao_teve_abuso = 0;

        printf("\nAvaliando produto %d/%d...\n", i+1, PRODUCT_NUMBER);

        // perguntar nome do produto a avaliar
        printf("Introduza o nome do produto a avaliar: ");

        if (fgets(nome, sizeof(nome), stdin) != NULL) {
            nome[strcspn(nome, "\n")] = '\0'; // eliminar salto de linha

            // validar que não está vazio
            if (nome[0] == '\0') {
                printf("\nNão foi informado nenhum nome. Tente novamente.\n");
                printf("Reiniciando avaliação do produto...\n\n");
                continue;
            }

        } else {
            printf("\nNão foi possível ler sua resposta\n");
            printf("Reiniciando avaliação do produto...\n\n");
            while (getchar() != '\n'); // limpar buffer
            continue;
        }

        // perguntar preço do mês anterior
        printf("Introduza o preço do produto (%s) no mês anterior: ", nome);
        leitura_correta = scanf("%f", &preco_anterior);
        if (leitura_correta != 1) {
            printf("\nPor favor, introduza um número. Se tiver decimais, use ponto (.) em vez de vírgula (,)\n");
            printf("Reiniciando avaliação do produto...\n\n");
            while (getchar() != '\n'); // limpar buffer
            continue;
        }

        // perguntar preço do mês atual
        printf("Introduza o preço do produto (%s) no mês atual: ", nome);
        leitura_correta = scanf("%f", &preco_atual);
        if (leitura_correta != 1) {
            printf("\nPor favor, introduza um número. Se tiver decimais, use ponto (.) em vez de vírgula (,)\n");
            printf("Reiniciando avaliação do produto...\n\n");
            while (getchar() != '\n'); // limpar buffer
            continue;
        }

        // calcular situação do item
        variacao = ((preco_atual - preco_anterior) / preco_anterior) * 100;

        if (variacao < 0) {
            situacao = "QUEDA";
        } else if (variacao > 0) {
            situacao = "AUMENTO";
            
            // conferindo se houve abuso no aumento
            if (variacao > 10) {
                variacao_teve_abuso = 1;
            } 

        } else {
            situacao = "ESTÁVEL";
        }

        ProdutoCestaBasica temp = {
            nome,
            preco_anterior,
            preco_atual,
            variacao,
            situacao,
            variacao_teve_abuso
        };

        cesta_basica[i] = temp;
        i++;

        while (getchar() != '\n'); // limpar buffer
    }

    // exibir cabeçalho do resumo
    printf("\nResumo de variação de preços:\n\n");

    // imprimir resumo dos itens
    for (int i = 0; i < PRODUCT_NUMBER; i++) {
        printf("Produto: %s\n", cesta_basica[i].nome);
        printf("    Preço Anterior: R$%.2f\n", cesta_basica[i].preco_anterior);
        printf("    Preço Atual: R$%.2f\n", cesta_basica[i].preco_atual);
        printf("    Variação: %.2f%%\n", cesta_basica[i].variacao);
        printf("    Situação: %s\n", cesta_basica[i].situacao);
        if (cesta_basica[i].variacao_teve_abuso) {
            printf("    AUMENTO DE PREÇO ABUSIVO!!\n\n");
        } else {
            printf("\n");
        }
    }
}
