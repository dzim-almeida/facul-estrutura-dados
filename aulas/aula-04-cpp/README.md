# Aula 04 — Recursão em vetores

## Objetivos

- Aplicar recursão a uma estrutura linear.
- Dividir um intervalo do vetor em subproblemas menores.
- Comparar valores e propagar o resultado para a chamada anterior.

## Busca do maior valor

A atividade da aula calcula o maior valor de um vetor dentro de um intervalo definido por `init` e `end`.

O algoritmo segue estes passos:

1. Se o intervalo possui uma única posição, retorna o elemento daquela posição.
2. Compara os elementos nas duas extremidades do intervalo.
3. Chama a função recursivamente para o intervalo interno.
4. Compara o maior valor das extremidades com o maior valor encontrado no intervalo interno.
5. Retorna o maior dos dois resultados.

Essa abordagem mostra como uma função pode reduzir o tamanho do problema sem percorrer o vetor com um laço explícito. O intervalo precisa ser válido e os índices devem apontar para posições existentes.

## Função principal

A função `maximum` recebe o vetor, o índice inicial e o índice final. A função `main` cria o vetor, define o intervalo analisado e imprime o resultado.

## Complexidade

Em cada chamada, uma quantidade constante de comparações é feita e o intervalo é reduzido. Para um intervalo com `n` posições, o tempo é linear, $O(n)$, e o consumo adicional da pilha também é linear no pior caso.

## Atividade

- [Máximo recursivo de um vetor](att-01/max.cpp)

## Compilação

```bash
g++ -std=c++17 -Wall -Wextra att-01/max.cpp -o att-01/app
./att-01/app
```