# AULA 06 - Análise e Complexibilidade de Algoritmos (Continuação)

## Análise sintótica de Big-O
Enteder método de prova de complexibilidade. Exemplo:
**Prove que 3n² + 18 = O(n²)**

### 1- Use a definição de formal de limite assintótico superior (Notação Big-O)

Dizemos que $f(n) = O(g(n))$ se, e somente se, existem constantes reais positivas $c > 0$ e um valor inteiro $n_0 \ge 1$ tais que:

$$0 \le f(n) \le c \cdot g(n), \quad \forall n \ge n_0$$

## Nomeclaturas e consumo de tempo
$O(1)$: Tempo constante 

- não depende de $n$
- Ex: atribuição e leitura de uma variável

$O(lg)$: Logarítmo

- $lg$ é igual $log_2$
- quando dobre uma entrada x o tempo aumenta em uma constante
- Ex: Busca binária

$O(n)$: Linear

...

