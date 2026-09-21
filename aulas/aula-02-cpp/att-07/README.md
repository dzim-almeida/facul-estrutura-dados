# Atividade 07 — Deslocamento em uma grade

## Objetivo
Calcular e exibir a posição resultante de cada ponto após um deslocamento unitário em uma direção.

## Resolução passo a passo

1. Ler a quantidade `q`, a direção e a posição inicial.
2. Guardar a posição original em `aux_x` e `aux_y`.
3. Alterar uma coordenada conforme a direção: `U` diminui `y`, `D` aumenta `y`, `L` diminui `x` e `R` aumenta `x`.
4. Imprimir a posição calculada.
5. Restaurar a posição original para processar o próximo ponto.
6. Ler a próxima posição até completar `q` pontos.

## Funções

O algoritmo está em `main`. As variáveis auxiliares preservam a origem de cada ponto enquanto a posição deslocada é exibida.

## Compilação

```bash
g++ -std=c++17 -Wall -Wextra cobrinha.cpp -o app
./app
```
