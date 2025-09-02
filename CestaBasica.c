#include <stdio.h>

/* Declaração de funções. Implementações estão depois de main */
float calcular_variacao(float preco_anterior, float preco_atual);
void printar_item_de_cesta(char * nome, float preco_anterior, float preco_atual, float variacao, char * situacao);
char* avaliar_situacao_item_de_cesta(float variacao);

int main()  {
    // LER nome do item Arroz
    char* arroz_nome = "Arroz";

    // LER preço do mês anterior do item Arroz
    float arroz_preco_anterior = 20.0;

    // LER preço do mês atual do item Arroz
    float arroz_preco_atual = 22.5;

    // CALCULAR e armazenar variação de preços do item Arroz
    float arroz_variacao = calcular_variacao(arroz_preco_anterior, arroz_preco_atual); 

    // AVALIAR e armazenar situação do item Arroz
    char* arroz_situacao = avaliar_situacao_item_de_cesta(arroz_variacao);


    // LER nome do item Feijão
    char* feijao_nome = "Feijão";

    // LER preço do mês anterior do item Feijão
    float feijao_preco_anterior = 8.0;

    // LER preço do mês atual do item Feijão
    float feijao_preco_atual = 8.0;

    // CALCULAR e armazenar variação de preços do item Feijão
    float feijao_variacao = calcular_variacao(feijao_preco_anterior, feijao_preco_atual); 

    // AVALIAR e armazenar situação do item Feijão
    char* feijao_situacao = avaliar_situacao_item_de_cesta(feijao_variacao);


    // LER nome do item Óleo de soja
    char* oleo_nome = "Óleo de soja";

    // LER preço do mês anterior do item Óleo de soja
    float oleo_preco_anterior = 6.5;

    // LER preço do mês atual do item Óleo de soja
    float oleo_preco_atual = 6.0;

    // CALCULAR e armazenar variação de preços do item Óleo de soja
    float oleo_variacao = calcular_variacao(oleo_preco_anterior, oleo_preco_atual); 

    // AVALIAR e armazenar situação do item Óleo de soja
    char* oleo_situacao = avaliar_situacao_item_de_cesta(oleo_variacao);
  

    // EXIBIR encabeçado do relatorio
    printf("Resumo de variação de Preços:\n\n");

    // EXIBIR informações e avaliação do item Arroz
    printar_item_de_cesta(arroz_nome, arroz_preco_anterior, arroz_preco_atual, arroz_variacao, arroz_situacao);

    // EXIBIR informações e avaliação do item Feijão
    printar_item_de_cesta(feijao_nome, feijao_preco_anterior, feijao_preco_atual, feijao_variacao, feijao_situacao);
   
    // EXIBIR informações e avaliação do item Óleo de soja
    printar_item_de_cesta(oleo_nome, oleo_preco_anterior, oleo_preco_atual, oleo_variacao, oleo_situacao);
    
    // FIM
    return 0;
}

/* Calcula variação de preços */
float calcular_variacao(float preco_anterior, float preco_atual) {
    return (((preco_anterior - preco_atual) / preco_anterior) * 100);
}

/*  Avalia a situação de um item da cesta básica em função da variação de seu preço  */
char* avaliar_situacao_item_de_cesta(float variacao) {
    if(variacao < 0) {
        return "QUEDA";
    } else if(variacao > 0) {
        return "AUMENTO";
    } else {
        return "ESTÁVEL";
    }
} 

/* printa as informações de um produto da cesta no relatório */
void printar_item_de_cesta(char * nome, float preco_anterior, float preco_atual, float variacao, char * situacao) {
    printf("Produto: %s\n\tPreço Anterior: R$%.2f\n\tPreço Atual: R$%.2f\n\tVariação: %.2f%%\n\tSituação: %s\n\n", nome, preco_anterior, preco_atual, variacao, situacao);
}
