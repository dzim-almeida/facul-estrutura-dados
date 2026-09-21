# Atividade 04 — Seleção do vencedor

## Objetivo
Encontrar o jogador elegível cuja diferença entre duas medidas seja a menor.

## Resolução passo a passo

1. Ler a quantidade de jogadores.
2. Para cada jogador, ler as medidas `a` e `b`.
3. Ignorar o jogador se alguma medida for menor que `10`.
4. Calcular a diferença absoluta entre as medidas.
5. Atualizar a menor diferença e o índice do vencedor quando necessário.
6. Informar `sem ganhador` se nenhum jogador for elegível; caso contrário, imprimir seu índice.

## Função `calDiff`

`calDiff(int a, int b)` calcula `a - b` e troca o sinal quando o resultado é negativo, retornando a diferença absoluta.

O valor `bestDiff` funciona como sentinela inicial. O índice é atualizado somente quando a diferença encontrada é estritamente menor, preservando o primeiro vencedor em caso de empate.

## Compilação

```bash
g++ -std=c++17 -Wall -Wextra att-04.cpp -o app
./app
```
