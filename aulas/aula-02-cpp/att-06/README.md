# Atividade 06 — Figurinhas repetidas e faltantes

## Objetivo
Identificar as figurinhas repetidas na coleção de Baruel e as figurinhas que ainda faltam no livro.

## Resolução passo a passo

1. Ler a quantidade de figurinhas do livro e a quantidade recebida.
2. Inicializar `figsInBook` com `false`.
3. Para cada figurinha recebida, consultar a posição correspondente no livro.
4. Se for a primeira ocorrência, marcar a figurinha como presente e zerar a posição temporária.
5. Se já estiver marcada, mantê-la para ser exibida como repetida.
6. Percorrer a coleção e imprimir as repetidas, ou `N` quando não houver.
7. Percorrer o livro e imprimir as posições ainda falsas, ou `N` quando o álbum estiver completo.

## Estruturas principais

- `baruelFigs` armazena a coleção recebida.
- `figsInBook` funciona como tabela de presença indexada pelo número da figurinha.
- `haveRepeatedFigs` e `bookNotCompleted` controlam as mensagens finais.

A implementação pressupõe que os números das figurinhas estejam entre `1` e `bookFigures`.

## Compilação

```bash
g++ -std=c++17 -Wall -Wextra att-06.cpp -o app
./app
```
