/* Lorenzo Braiener da Cunha MA: 1230206908
   Mateus Ibirapitanga Teske Prado MA: 1260119308
   Felipe Celestrino Monteiro MA: 1230112049
   Ian Machado Ranel Calassara Pereira MA: 1260126459
   Miguel de Oliveira Azeredo MA: 1260208490*/

#include <stdio.h>
#include <locale.h>
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
        default: return "Região inválida";
    }
}
 
/* Calcula o frete de acordo com a regiao e o peso.
   Retorna -1.0 se a regiao informada for invalida. */
float calcularFrete(int regiao, float peso) {
 int adiocional - 0;
 if (peso > 2){
  adicional = 20;
 }
 switch(regiao) {
 case 1:
  return 30 + adicional;
 case 2:
  return 25 + adicional;
 case 3:
  return 35 + adicional;
 case 4:
  return 40 + adicional;
 default:
  return -1;
 }
}

int main(void) {
    setlocale(LC_ALL, ".utf8");

    Produto p;
    int regiao;
    float frete, total;

    printf("---------------CALCULADORA DE COMPRA - LOJA VIRTUAL---------------\n");
 
    printf("Código do produto: ");
    scanf("%d", &p.codigo);
 
    printf("Nome do produto: ");
    scanf(" %99[^\n]", p.nome);
 
    printf("Peso do produto (kg): ");
    scanf("%f", &p.peso);
 
    printf("Preço do produto (R$): ");
    scanf("%f", &p.preco);
 
    printf("\nLocal de entrega:\n");
    printf("[1] Região Sul\n");
    printf("[2] Região Sudeste\n");
    printf("[3] Região Norte\n");
    printf("[4] Região Nordeste\n");
 
    //loop para confirma a resposta certa
    int leituraValida;
    do {
        printf("Escolha (1-4): ");
        leituraValida = scanf("%d", &regiao);
 
        if (leituraValida != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            regiao = 0;
            printf("Entrada inválida! Digite apenas um número de 1 a 4.\n");
        } else if (regiao < 1 || regiao > 4) {
            printf("Região inválida! Digite um número de 1 a 4.\n");
        }
    } while (regiao < 1 || regiao > 4);
 
    frete = calcularFrete(regiao, p.peso);
    total = p.preco + frete;
 
    time_t agora = time(NULL);
    struct tm dataCompra = *localtime(&agora);
 
    time_t timestampEntrega = agora + (PRAZO_ENTREGA_DIAS * 24L * 60L * 60L);
    struct tm dataEntrega = *localtime(&timestampEntrega);
 
    printf("\n---------------RESUMO DA COMPRA---------------\n");
    printf("Código do produto.......: %d\n", p.codigo);
    printf("Nome do produto.........: %s\n", p.nome);
    printf("Peso do produto.........: %.2f kg\n", p.peso);
    printf("Preço do produto........: R$ %.2f\n", p.preco);
    printf("Local de entrega........: [%d] Região %s\n", regiao, nomeRegiao(regiao));
    printf("Preço do frete..........: R$ %.2f\n", frete);
    printf("Preço total da compra...: R$ %.2f\n", total);
    printf("Data e hora da compra...: %02d/%02d/%04d %02d:%02d:%02d\n",
           dataCompra.tm_mday, dataCompra.tm_mon + 1, dataCompra.tm_year + 1900,
           dataCompra.tm_hour, dataCompra.tm_min, dataCompra.tm_sec);
    printf("Data prevista de entrega: %02d/%02d/%04d\n",
           dataEntrega.tm_mday, dataEntrega.tm_mon + 1, dataEntrega.tm_year + 1900);
 
    return 0;
}
