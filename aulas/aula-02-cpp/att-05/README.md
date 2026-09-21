# Atividade 05 — Pares de animais

## Objetivo
Contar quantos pares de animais com valores opostos podem ser formados.

## Resolução passo a passo

1. Ler a quantidade de animais e armazenar os valores no vetor.
2. Percorrer cada posição ainda disponível.
3. Procurar, nas posições seguintes, um valor cuja soma com o atual seja zero.
4. Ao encontrar o par, marcar o segundo animal como utilizado e incrementar `pairs`.
5. Exibir a quantidade de pares.

O valor `0` também é usado como marca de posição consumida. Por isso, essa representação pressupõe que o valor zero não seja um animal válido na entrada.

## Funções

O processamento está em `main` e usa dois laços: o externo escolhe o primeiro elemento e o interno procura seu par.

## Complexidade

No pior caso, a busca compara muitos pares de posições, resultando em tempo $O(n^2)$ e memória adicional $O(n)$ para o vetor.

## Compilação

```bash
g++ -std=c++17 -Wall -Wextra att-05.cpp -o app
./app
```
