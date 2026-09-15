# AULA 05 - Análise e Complexibilidade de Algoritmos
Essa aula se consiste na analise temporal e de complexibidade empregada por diferente tipos de algorítmos.

## Big-O Notation
O Big O é a métrica universal dessa analise, categorizando diferentes tipos de algoritmos pela complexibilidade de tempo. 
Nessa classificação alguns pontos devem ser considerados como constantes e operações relativamentes proporcionais.

## Busca sequencial e consumo de tempo
Na análise sequencial e consumo de tempos temos que observar sempre a quantidade de passos que um algorítmo pode percorrer. No trecho de código abaixo o algoritmo tem uma complexibilidade de T(n) = 3n+4 passos, levando em consideração a pior hipótese.

```cpp
// Algorítmo com complexibilidade T(n) = 3n+4

int busca(int vet[], int n, int x) {
    int i; // Execuções -> 1
    for(i = 0; i < n; i++) { Execuções -> // Execuções -> N + 1
        if (v[i] == x) { // Execuções -> N
            return i; 
        }
    }
    return -1; // Execuções -> 1
}
```
Atividade extra -> <span style="background-color: red; color: white">Realizar a análise de uma soma de matrizes<span>.

## Transpondo a função no gráfico
Com a complexibilidade cálculada podemos tranpor a função final dentro de um gráfico, por exemplo o gráfico da opção acima seria:

![Gráfico função T(n) = 3n + 4](./img/image.png "Função T(n) = 3n + 4 em gráfico")

## Entendimento sobre melhor e pior caso de execução
Analisar algorítmos depende de uma análise absoluta que sempre abrange a situação real da execução de um programa, para isso não basta apenas olhar o melhor caso de uma execução, mas sempre deve se olhar o pior caso por abranger toda a situação possível.

## Crescimento assintótico de funções
Vamos abordar novamente o conceito sobre o que é Big-O, só que desta vez de forma mais aprofundada.
O Big-O analisa algorítmos conforme uma entrada n, e define funções em algo como 'CAIXAS' de desempenho, por exemplo temos algorítmos com complexibilidade n, n², n³, log(n) e !n. Como visto esses algorítmos possuem diferentes complexibilidades e isso tem impacto direto no tempo de execução de um programa