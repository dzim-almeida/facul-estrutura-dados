# Aula 08 - TIPOS ABSTRATOS DE DADOS

## Valores por Ref (&)
Variáveis pode ser apontadas por **referência** utilizando a tag *&*;

### Diferença de ponteiro para referência
Um ponteiro é uma variável independente que guarda um endereço de memória.

Uma referência é um "apelido" (alias) inseparável para uma variável que já existe.

### Uso em código
```cpp
int x = 10;
int &ref = x; // Guarda a própria variável x em ref
```