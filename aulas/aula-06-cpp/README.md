# Aula 06 — Análise assintótica e provas de Big-O

Esta aula dá continuidade à análise de algoritmos e formaliza a classificação iniciada na aula 05. O foco é provar que uma função pertence a uma classe assintótica, em vez de apenas observar seus termos dominantes.

## Objetivos

- Aplicar a definição formal de Big-O.
- Escolher constantes `c` e `n₀` que validem uma prova assintótica.
- Reconhecer as principais classes de crescimento.
- Entender por que constantes multiplicativas e parcelas de menor ordem não alteram a classe final.

## Definição formal

Dizemos que `f(n) = O(g(n))` quando existem constantes reais `c > 0` e `n₀ ≥ 1` tais que:

$$0 \le f(n) \le c \cdot g(n), \quad \forall n \ge n_0$$

Em outras palavras, a partir de uma entrada suficientemente grande, `f(n)` fica abaixo de um múltiplo constante de `g(n)`.

## Exemplo de prova

Vamos provar que `3n² + 18 = O(n²)`.

1. Considere `f(n) = 3n² + 18` e `g(n) = n²`.
2. Para `n ≥ 1`, vale `18 ≤ 18n²`.
3. Portanto:

   $$3n^2 + 18 \le 3n^2 + 18n^2 = 21n^2$$

4. Escolha `c = 21` e `n₀ = 1`.
5. Como a desigualdade vale para todo `n ≥ 1`, concluímos que `3n² + 18 = O(n²)`.

O objetivo da prova não é encontrar o menor `c`, mas apresentar constantes positivas que satisfaçam a definição.

## Classes de crescimento

### `O(1)` — constante

O custo não depende do tamanho da entrada. Acessar uma posição conhecida de um vetor ou atribuir um valor a uma variável são exemplos usuais.

### `O(log n)` — logarítmica

O problema diminui por um fator constante a cada etapa. Na busca binária, por exemplo, metade dos elementos é descartada a cada comparação. Neste contexto, `lg n` representa `log₂ n`.

### `O(n)` — linear

O custo cresce proporcionalmente ao tamanho da entrada. Percorrer um vetor uma vez é um exemplo.

### `O(n log n)`

Essa classe aparece em algoritmos que dividem o problema em partes e realizam trabalho linear por nível, como algoritmos eficientes de ordenação.

### `O(n²)` — quadrática

O custo cresce proporcionalmente ao quadrado da entrada. Dois laços aninhados que percorrem `n` elementos são um exemplo frequente.

### `O(2^n)` e `O(n!)`

São classes de crescimento exponencial e fatorial. O custo aumenta rapidamente e limita o tamanho das entradas que podem ser processadas.

## Como analisar uma função

1. Defina o que representa `n`.
2. Identifique a operação que mais se repete.
3. Conte laços, chamadas recursivas e operações por iteração.
4. Escreva uma função de custo, quando necessário.
5. Remova constantes multiplicativas e termos de menor ordem para obter a classe assintótica.
6. Quando for exigida uma prova formal, encontre `c` e `n₀` e verifique a desigualdade.

## Observações importantes

- Big-O descreve crescimento, não o tempo exato em segundos.
- A base do logaritmo altera apenas uma constante, pois `log₂ n` e `log₁₀ n` pertencem à mesma classe assintótica.
- A complexidade de memória também pode ser analisada com as mesmas ideias.
- Uma solução com menor Big-O nem sempre é mais rápida para entradas pequenas, pois constantes e custos de implementação ainda importam.

## Relação com a aula 05

A aula 05 introduziu a contagem de operações e a comparação de casos. Nesta continuação, a definição formal permite justificar matematicamente classificações como `O(n)`, `O(n²)` e `O(log n)`.

## Compilação

Esta pasta contém anotações teóricas. Para executar os exemplos práticos de análise, consulte os arquivos da [aula 05](../aula-05-cpp/README.md).

## Resumo

Uma prova de Big-O demonstra que uma função não cresce mais rapidamente que outra, a partir de uma entrada mínima. O método consiste em construir uma desigualdade válida e indicar as constantes que a tornam verdadeira.
