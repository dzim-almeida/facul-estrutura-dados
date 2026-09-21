# Aula 05 — Análise e complexidade de algoritmos

## Objetivos

- Medir o custo de um algoritmo em função do tamanho da entrada.
- Contar operações e representar esse custo por uma função `T(n)`.
- Diferenciar melhor caso, pior caso e caso médio.
- Classificar o crescimento de algoritmos usando a notação Big-O.
- Comparar algoritmos pelo crescimento assintótico.

## O que é complexidade

A complexidade permite estimar como o consumo de tempo ou memória de um algoritmo cresce conforme aumenta o tamanho da entrada. Em vez de medir o tempo em segundos, contamos operações relevantes e descrevemos esse comportamento com uma função, como `T(n) = 3n + 4`.

Essa análise não depende de uma máquina específica. Ela ajuda a comparar soluções mesmo quando os tempos absolutos de execução são diferentes.

## Contagem de operações: busca sequencial

Na busca sequencial, o vetor é percorrido da primeira posição até o elemento procurado ou até o fim:

```cpp
int busca(int vetor[], int tamanho, int valor) {
    for (int indice = 0; indice < tamanho; indice++) {
        if (vetor[indice] == valor) {
            return indice;
        }
    }

    return -1;
}
```

O resultado `-1` indica que o valor não foi encontrado. No pior caso, a função compara todas as `n` posições, portanto seu custo é linear: `O(n)`. A contagem exata pode ser escrita como uma função `T(n)`; a notação Big-O mantém apenas o termo dominante e descarta constantes e parcelas menores.

## Melhor, pior e caso médio

- **Melhor caso:** o valor está na primeira posição; a busca termina após uma comparação.
- **Pior caso:** o valor está na última posição ou não está no vetor; todas as posições são verificadas.
- **Caso médio:** depende da distribuição das posições possíveis e das hipóteses adotadas.

Para garantir um limite de desempenho, é comum analisar o pior caso. Isso não significa que toda execução terá esse custo, mas que o algoritmo não ultrapassará esse crescimento dentro do modelo analisado.

## Notação Big-O

A notação Big-O descreve um limite superior assintótico e concentra a análise no comportamento para entradas grandes:

- `O(1)`: tempo constante;
- `O(log n)`: crescimento logarítmico, típico de uma busca binária em dados ordenados;
- `O(n)`: crescimento linear, como a busca sequencial;
- `O(n log n)`: comum em algoritmos eficientes de ordenação;
- `O(n²)`: comum quando há dois laços aninhados sobre a entrada;
- `O(2^n)` e `O(n!)`: crescimentos muito elevados, geralmente inviáveis para entradas grandes.

Ao simplificar `3n + 4`, o termo dominante é `n`, então a classificação é `O(n)`. Da mesma forma, `5n² + 2n + 10` é `O(n²)`.

## Crescimento e visualização

Comparar os gráficos das funções ajuda a perceber que pequenas diferenças em entradas pequenas podem se tornar grandes diferenças em entradas maiores. O gráfico abaixo representa a função usada como exemplo na aula:

![Gráfico da função T(n) = 3n + 4](img/image.png "Crescimento da função T(n) = 3n + 4")

O gráfico deve ser interpretado como uma ferramenta de comparação de crescimento, e não como uma medição universal de segundos de execução.

## Atividade complementar

Na análise de uma soma de matrizes, conte quantas vezes cada dimensão é percorrida. Para uma matriz `n x n`, dois laços aninhados normalmente produzem um custo proporcional a `n²`, ou seja, `O(n²)`. A quantidade de operações internas pode alterar a função exata `T(n)`, mas não a classe assintótica.

## Atividades da aula

- [Atividade 01](att-01/01.cpp)
- [Atividade 02](att-02/02.cpp)
- [Atividade 03](att-03/03.cpp)
- [Atividade 04](att-04/04.cpp)
- [Atividade 05](att-05/05.cpp)
- [Atividade 06](att-06/06.cpp)

## Compilação

Na pasta da atividade, execute:

```bash
g++ -std=c++17 -Wall -Wextra -g 01.cpp -o app
./app
```

Substitua `01.cpp` pelo nome do arquivo da atividade que estiver sendo estudada.

## Resumo

A análise de complexidade transforma o comportamento de um algoritmo em uma descrição comparável. O procedimento básico é identificar o tamanho da entrada, contar as operações relevantes, observar os casos de execução e simplificar a função pelo termo dominante.
