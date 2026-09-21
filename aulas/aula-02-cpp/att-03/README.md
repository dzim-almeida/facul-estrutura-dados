# Atividade 03 — Perseguição circular

## Objetivo
Simular o deslocamento de um bandido em uma pista circular até alcançar o helicóptero ou encontrar o policial.

## Resolução passo a passo

1. Ler as posições do helicóptero, do policial, do bandido e a direção.
2. Enquanto o bandido não estiver na posição do helicóptero, avançar uma unidade na direção indicada.
3. Se ultrapassar `15`, voltar para `0`; se ficar abaixo de `0`, voltar para `15`.
4. Após cada movimento, verificar se o bandido encontrou o policial.
5. Imprimir `N` ao encontrar o policial ou `S` ao alcançar o helicóptero.

O `while` representa a repetição da simulação. A correção dos limites implementa o comportamento circular da pista.

## Funções

O algoritmo está em `main`; as posições são atualizadas diretamente no laço.

## Compilação

```bash
g++ -std=c++17 -Wall -Wextra att-03.cpp -o app
./app
```
