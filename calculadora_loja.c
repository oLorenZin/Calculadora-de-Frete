#include <stdio.h>
#include <string.h>
#include <time.h>
 
#define PRAZO_ENTREGA_DIAS 5 
 
typedef struct {
    int   codigo;
    char  nome[100];
    float peso;    
    float preco;    
} Produto;
 
/* Chama o nome da regiao a partir do codigo escolhido (numero de 1 a 4) */
const char *nomeRegiao(int regiao) {
    switch (regiao) {
        case 1: return "Sul";
        case 2: return "Sudeste";
        case 3: return "Norte";
        case 4: return "Nordeste";
        default: return "Regiao invalida";
    }
}
 
/* Calcula o frete de acordo com a regiao e o peso.
   Retorna -1.0 se a regiao informada for invalida. */
float calcularFrete(int regiao, float peso) {
    float fretePadrao[4] = {30.00, 25.00, 35.00, 40.00};
    float fretePesado[4] = {50.00, 45.00, 55.00, 60.00};
 
    if (regiao < 1 || regiao > 4) {
        return -1.0;
    }
 
    int idx = regiao - 1;
 
    if (peso > 2.0f) {
        return fretePesado[idx];
    } else {
        return fretePadrao[idx];
    }
}
 
int main(void) {
    Produto p;
    int regiao;
    float frete, total;
 
    printf("Codigo do produto: ");
    scanf("%d", &p.codigo);
 
    printf("Nome do produto: ");
    scanf(" %99[^\n]", p.nome);
 
    printf("Peso do produto (kg): ");
    scanf("%f", &p.peso);
 
    printf("Preco do produto (R$): ");
    scanf("%f", &p.preco);
 
    printf("\nLocal de entrega:\n");
    printf("  [1] Regiao Sul\n");
    printf("  [2] Regiao Sudeste\n");
    printf("  [3] Regiao Norte\n");
    printf("  [4] Regiao Nordeste\n");
 
    //loop para confirma a resposta certa
    int leituraValida;
    do {
        printf("Escolha (1-4): ");
        leituraValida = scanf("%d", &regiao);
 
        if (leituraValida != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            regiao = 0;
            printf("Entrada invalida! Digite apenas um numero de 1 a 4.\n");
        } else if (regiao < 1 || regiao > 4) {
            printf("Regiao invalida! Digite um numero de 1 a 4.\n");
        }
    } while (regiao < 1 || regiao > 4);
 
    frete = calcularFrete(regiao, p.peso);
    total = p.preco + frete;
 
    time_t agora = time(NULL);
    struct tm dataCompra = *localtime(&agora);
 
    time_t timestampEntrega = agora + (PRAZO_ENTREGA_DIAS * 24L * 60L * 60L);
    struct tm dataEntrega = *localtime(&timestampEntrega);
 
    printf("\n Resumo da Compra\n");
    printf("Codigo do produto ......: %d\n", p.codigo);
    printf("Nome do produto .........: %s\n", p.nome);
    printf("Peso do produto .........: %.2f kg\n", p.peso);
    printf("Preco do produto ........: R$ %.2f\n", p.preco);
    printf("Local de entrega ........: [%d] Regiao %s\n", regiao, nomeRegiao(regiao));
    printf("Preco do frete ...........: R$ %.2f\n", frete);
    printf("Preco total da compra ...: R$ %.2f\n", total);
    printf("Data e hora da compra ...: %02d/%02d/%04d %02d:%02d:%02d\n",
           dataCompra.tm_mday, dataCompra.tm_mon + 1, dataCompra.tm_year + 1900,
           dataCompra.tm_hour, dataCompra.tm_min, dataCompra.tm_sec);
    printf("Data prevista de entrega : %02d/%02d/%04d\n",
           dataEntrega.tm_mday, dataEntrega.tm_mon + 1, dataEntrega.tm_year + 1900);
 
    return 0;
}