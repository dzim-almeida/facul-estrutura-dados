# Atividade 01 — Área de um triângulo

## Objetivo
Calcular a área de um triângulo a partir dos três lados usando a fórmula de Heron.

## Resolução passo a passo

1. Ler os lados `a`, `b` e `c`.
2. Calcular o semiperímetro `p = (a + b + c) / 2`.
3. Aplicar `area = sqrt(p * (p - a) * (p - b) * (p - c))`.
4. Exibir a área com duas casas decimais.

O programa usa `sqrt` de `<cmath>` e `setprecision` de `<iomanip>`. Para a fórmula representar um triângulo real, os lados devem respeitar a desigualdade triangular.

## Funções e recursos

A solução concentra o processamento em `main`. `fixed` e `setprecision(2)` controlam a formatação da saída.

## Compilação

```bash
g++ -std=c++17 -Wall -Wextra att-01.cpp -o app
./app
```
