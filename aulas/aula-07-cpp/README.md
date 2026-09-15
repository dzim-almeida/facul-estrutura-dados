# AULA DE ESTRUTURA - PONTEIROS

## O que são ponteiros?
-> Explique o fundamento

## Para que servem?
-> Explique as funcionalidades

## Como declarar um ponteiro
```cpp
int *p; // Assim declaramos um ponteiro válido
int *q;
```

## Operador '&'
Aplicando o operador '&' em uma variável faz com que o programa passe o endereço de memória daquele valor.
```cpp
int x;
int *p = &x; // 'p' agora guarda apenas o endereço de x
int *q = x; // Erro pois o programa tenta passar o valor da variável para um ponteiro de endereço 
```

## Operador '*'
Serve para declarar um ponteiro, como já demonstrado acima. Serve também para mostrar o valor da variável apontada.
```cpp
int x {10};
int *p = &x;

cout << p; // Imprime o endereço da memória de 'x';
cout << *p; // Imprime o valor '10'

*p = 100 // Também altera o valor da variável diretamente em 'x';
```