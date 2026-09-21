# Aula 07 — Ponteiros e passagem por endereço

## Objetivos

- Entender que um ponteiro armazena o endereço de outra variável.
- Usar os operadores de endereço (`&`) e desreferenciação (`*`).
- Alterar uma variável por meio do ponteiro que aponta para ela.
- Passar valores simples e estruturas para funções sem criar cópias desnecessárias.
- Reconhecer cuidados básicos com ponteiros inválidos e não inicializados.

## O que é um ponteiro

Um ponteiro é uma variável cujo valor representa um endereço de memória. O ponteiro não armazena diretamente o valor de `x`; ele armazena a localização onde `x` está guardado.

```cpp
int valor = 10;
int* ponteiro = &valor;
```

Nesse exemplo, `ponteiro` aponta para `valor`. O tipo `int*` indica que o endereço deve referenciar um `int`.

## Operador `&`: endereço

Aplicado a uma variável, `&` produz o endereço dela. Esse endereço pode ser atribuído a um ponteiro compatível:

```cpp
int valor = 10;
int* ponteiro = &valor;
```

A atribuição `int* outro = valor;` está errada porque tenta colocar um valor inteiro em uma variável que espera um endereço de `int`.

## Operador `*`: declaração e desreferenciação

O símbolo `*` aparece em dois contextos:

- na declaração, indica que a variável é um ponteiro, como em `int* ponteiro`;
- em uma expressão, acessa o valor armazenado no endereço apontado, como em `*ponteiro`.

```cpp
int valor = 10;
int* ponteiro = &valor;

std::cout << ponteiro << '\n';  // endereço de valor
std::cout << *ponteiro << '\n'; // valor armazenado nesse endereço

*ponteiro = 100;                 // altera valor para 100
```

Depois da atribuição `*ponteiro = 100`, a variável `valor` também passa a valer `100`, pois ambos acessam a mesma posição de memória.

## Ponteiros e funções

Ao passar o endereço de uma variável para uma função, a função pode alterar o objeto original por desreferenciação:

```cpp
void trocar(int* primeiro, int* segundo) {
    int temporario = *primeiro;
    *primeiro = *segundo;
    *segundo = temporario;
}
```

A chamada deve fornecer endereços:

```cpp
int x = 10;
int y = 20;
trocar(&x, &y);
```

O código da [troca de inteiros](swap.cpp) demonstra esse processo completo.

## Ponteiros para estruturas

Uma estrutura também pode ser acessada por ponteiro. A expressão `(*ponto).x` acessa o campo `x` do objeto apontado. A forma mais comum e legível é usar o operador `->`:

```cpp
struct Ponto {
    int x;
    int y;
};

void duplicar(Ponto* ponto) {
    ponto->x *= 2;
    ponto->y *= 2;
}
```

O exemplo [cartesian_swap.cpp](cartesian_swap.cpp) troca dois pontos e altera os campos de um ponto recebido por endereço.

## Cuidados

- Inicialize ponteiros antes de desreferenciá-los.
- Não use um ponteiro depois que o objeto apontado deixou de existir.
- Não confunda endereço (`ponteiro`) com valor apontado (`*ponteiro`).
- Um ponteiro nulo não aponta para um objeto válido e não pode ser desreferenciado.
- O tipo do ponteiro deve ser compatível com o tipo do objeto apontado.

## Atividades e exemplos

- [Ponteiro básico](pointers.cpp): mostra endereço, valor apontado e alteração indireta.
- [Troca de inteiros](swap.cpp): implementa uma troca usando dois ponteiros.
- [Troca e duplicação de pontos](cartesian_swap.cpp): aplica ponteiros a uma `struct`.

Também há executáveis previamente gerados na pasta [output](output/), mas a compilação deve ser feita a partir dos arquivos `.cpp` para refletir o código atual.

## Compilação

Na pasta desta aula, execute um comando por arquivo:

```bash
g++ -std=c++17 -Wall -Wextra -g pointers.cpp -o pointers
./pointers
```

Para os demais exemplos, substitua `pointers.cpp` e `pointers` por `swap.cpp`/`swap` ou `cartesian_swap.cpp`/`cartesian_swap`.

## Resumo

Ponteiros conectam uma variável ao endereço em que ela está armazenada. `&` obtém o endereço, enquanto `*` acessa ou altera o valor nesse endereço. Essa técnica fundamenta a passagem por endereço e prepara o estudo de referências, alocação dinâmica e estruturas de dados.
