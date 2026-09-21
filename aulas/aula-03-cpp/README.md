# Aula 03 — Recursão

## Objetivos

- Identificar caso base e passo recursivo.
- Traduzir soluções iterativas simples para funções recursivas.
- Acompanhar a redução do problema até uma entrada menor.
- Reconhecer custos e limitações de chamadas recursivas.

## Como funciona a recursão

Uma função recursiva chama a si mesma com uma entrada menor ou mais próxima da condição de parada. Toda solução precisa de:

1. **Caso base**, que resolve diretamente o menor problema.
2. **Passo recursivo**, que reduz o problema e combina o resultado da chamada menor.

Sem um caso base ou sem redução da entrada, a função pode continuar chamando a si mesma indefinidamente.

## Exemplos trabalhados

- Soma dos inteiros de `1` até `n`.
- Impressão recursiva de uma quantidade de asteriscos.
- Fatorial de um número.
- Verificação recursiva de palíndromos, comparando as extremidades.
- Contagem de formas de percorrer uma escada usando passos de 1 ou 3 degraus.

Nos exemplos, cada chamada reduz o intervalo, o número ou a quantidade de degraus analisada. A pilha de execução guarda as chamadas pendentes até que o caso base seja atingido.

## Cuidados

- Validar entradas que não pertencem ao domínio esperado, como números negativos.
- Evitar recursão profunda quando uma solução iterativa for mais adequada.
- Considerar o consumo de memória da pilha além do número de operações.
- Garantir que os índices de strings e vetores permaneçam dentro dos limites.

## Atividades

- [Soma recursiva](att-02/soma.cpp)
- [Linha de asteriscos](att-03/asteristico.cpp)
- [Fatorial](att-04/fatorial.cpp)
- [Palíndromo](att-05/palindromo.cpp)
- [Escadas](att-06/stair.cpp)

## Compilação

```bash
g++ -std=c++17 -Wall -Wextra arquivo.cpp -o app
./app
```