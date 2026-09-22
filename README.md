# Calculadora de Compra — Loja Virtual (Linguagem C)

Programa em C que calcula o preço total de uma compra em uma loja virtual, somando o preço do produto ao preço do frete. O frete é calculado de acordo com a região de entrega e o peso do produto, seguindo uma tabela de valores fixa.

Projeto desenvolvido como Atividade Avaliativa (Aprendizagem Baseada em Problemas) da disciplina de Estruturas de Programação — UVA.

## Funcionalidades

- Cadastro dos dados do produto: código, nome, peso (kg) e preço (R$)
- Seleção da região de entrega: Sul, Sudeste, Norte ou Nordeste
- Cálculo automático do frete, com valor diferenciado para produtos com peso acima de 2 kg
- Cálculo do preço total da compra (produto + frete)
- Geração automática de data/hora da compra e data prevista de entrega
- Resumo final da compra com todas as informações exigidas

## Tabela de frete utilizada

| Região    | Frete padrão | Frete (peso > 2kg) |
|-----------|-------------:|--------------------:|
| Sul       | R$ 30,00     | R$ 50,00             |
| Sudeste   | R$ 25,00     | R$ 45,00             |
| Norte     | R$ 35,00     | R$ 55,00             |
| Nordeste  | R$ 40,00     | R$ 60,00             |

## Como compilar

Requer um compilador C (gcc, clang, etc.).

```bash
gcc -Wall -o calculadora_loja calculadora_loja.c
```

## Como executar

```bash
./calculadora_loja
```

O programa solicita, na ordem: código do produto, nome, peso (kg), preço (R$) e a região de entrega (opção de 1 a 4). Ao final, exibe o resumo completo da compra no terminal.

### Exemplo de execução

```
Codigo do produto: 101
Nome do produto: Livro Clean Code
Peso do produto (kg): 0.8
Preco do produto (R$): 89.90
Escolha (1-4): 2

================ RESUMO DA COMPRA ================
Codigo do produto ......: 101
Nome do produto .........: Livro Clean Code
Peso do produto .........: 0.80 kg
Preco do produto ........: R$ 89.90
Local de entrega ........: [2] Regiao Sudeste
Preco do frete ...........: R$ 25.00
Preco total da compra ...: R$ 114.90
Data e hora da compra ...: 22/09/2026 19:37:05
Data prevista de entrega : 27/09/2026
====================================================
```

## Estrutura do código

- `struct Produto` — armazena código, nome, peso e preço do produto
- `calcularFrete()` — aplica a regra de frete (padrão ou peso > 2kg) conforme a região
- `nomeRegiao()` — converte o código da região (1–4) no nome correspondente
- `main()` — controla o fluxo: leitura dos dados, cálculo do frete e do total, obtenção da data/hora e impressão do resumo

## Observações e limitações conhecidas

- O prazo de entrega (diferença entre data da compra e data prevista de entrega) **não é especificado no enunciado da atividade** — apenas que a data de entrega deve ser posterior à data da compra. Este projeto assume um prazo fixo de 5 dias corridos, definido na constante `PRAZO_ENTREGA_DIAS` no início do arquivo. Ajuste esse valor se o critério da disciplina for outro.
- O programa processa um produto por execução (não é um carrinho com múltiplos itens).
- Não há validação de tipos negativos (peso ou preço negativos não são bloqueados); é uma calculadora simples, sem tratamento de entrada malformada além da validação de região.

## Testes realizados

| Cenário | Entrada | Resultado esperado |
|---|---|---|
| Produto leve, Sudeste | peso 0.8kg, região 2 | Frete padrão R$ 25,00 |
| Produto pesado, Sul | peso 2.5kg, região 1 | Frete diferenciado R$ 50,00 |
| Produto leve, Nordeste | peso 0.1kg, região 4 | Frete padrão R$ 40,00 |

## Disciplina

Bases de Programação — Universidade Veiga de Almeida (UVA)
