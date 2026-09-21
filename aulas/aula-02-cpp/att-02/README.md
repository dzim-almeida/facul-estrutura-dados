# Atividade 02 — Classificação por idade

## Objetivo
Ler o nome e a idade de uma pessoa e classificá-la em uma faixa etária.

## Resolução passo a passo

1. Ler `nome` e `idade`.
2. Testar as faixas em ordem crescente.
3. Atribuir a classificação correspondente.
4. Exibir o nome junto da classificação.

A cadeia `if`, `else if` e `else` garante que somente uma faixa seja escolhida. A primeira condição também impede que uma idade negativa seja classificada como criança.

## Faixas utilizadas

- `0` a `11`: criança.
- `12` a `17`: jovem.
- `18` a `64`: adulto.
- `65` a `999`: idoso.
- Valores a partir de `1000`: múmia.

## Funções

O processamento está em `main`; não há função auxiliar nesta atividade.

## Compilação

```bash
g++ -std=c++17 -Wall -Wextra att-02.cpp -o app
./app
```
