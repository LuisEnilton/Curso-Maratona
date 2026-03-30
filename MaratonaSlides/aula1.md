---
# try also 'default' to start simple
theme: dracula

title: Introdução a Maratona e a C++
info: |
  ## Slidev Starter Template
  Presentation slides for developers.

  Learn more at [Sli.dev](https://sli.dev)
# apply UnoCSS classes to the current slide
class: text-center
# https://sli.dev/features/drawing
drawings:
  persist: false
# slide transition: https://sli.dev/guide/animations.html#slide-transitions
transition: slide-left
# enable MDC Syntax: https://sli.dev/features/mdc
mdc: true
# duration of the presentation
duration: 35min
---

# Introdução a Maratona e a C++

<!--
The last comment block of each slide will be treated as slide notes. It will be visible and editable in Presenter Mode along with the slide. [Read more in the docs](https://sli.dev/guide/syntax.html#notes)
-->

---
layout: capa-aula
numero_aula: 1
---
---
layout: two-cols
layoutClass: gap-16
---

# Sumário da Aula

<Toc text-sm minDepth="1" maxDepth="2" columns=2  />
---

# Estrutura básica

```cpp {*|1|3|5|9|7} 
#include <bits/stdc++.h> // inclusão da biblioteca, que tem tudo que precisamos para rodar

using namespace std; // evita termos que escrever std:: em tudo

int main(){

    cout << "Hello world" << endl;

    return 0;
}
```

---

# Tipos de variáveis

## Inteiros
```cpp {*|1|2|*} 
int a = 2; // vai aproximadamente de -2 * 10e9 até 2 * 10e9
long long b = 3;// vai aproximadamente de -4 * 10e8 até 4 * 10e18
```

## Ponto flutuante

```cpp  {*|1|2|4} 
double a = 2.1; // vai de  1.7e−308 and 1.7e+308
long double b = 3.2;// vai de 1.18973e+4932 até 3.3621e-4932

// podem ter problemas de precisão na hora de imprimir

```

## Booleanos

```cpp  {*|1|2|4-5} 
bool a = true;
bool b = false;

// 0 tem valor false, e qualquer outro numero true
bool c = 0, d = 2;
```
---

# Entrada e Saida

```cpp [lerInt.cpp] {*|2|3,4|*}
int x,y;
cin >> x >> y;
cout << x << " " << y << '\n';
cout << x << " " << y << endl;
```
'\n' é apenas quebra de linha, endl libera o buffer.

Existem funções que aceleram a velocidade de entrada e saida do programa
```cpp [fastInpOut.cpp] {*|2|3,4|*}
#define endl '\n'
// Se usarmos endl ele vai liberar o buffer o que gasta muito tempo.
int main(){

  ios::sync_with_stdio(false); // Não é possivel misturar printf com cout depois de rodar essa linha
  cin.tie(NULL)
}
// Ele não limpa mais o buffer toda vez que vai ler um numero
```
---

# Entrada e saida em numeros reais

Imprimir double pode causar erro de precisão por causa de arredondamentos.

````md magic-move {lines: true}
```cpp [lerDouble.cpp]
double x,y;
cin >> x >> y;
double z = x * y;
cout << z << endl;
```

```cpp [lerDouble.cpp]
// Solução 
double x,y;
cin >> x >> y;

cout << setprecision(8) << fixed << z << endl;
```
````
[Questão Exemplo](https://codeforces.com/group/mzbGmMVMMp/contest/670834/problem/E)

OBS: Ler double é muito lento, se possível leia tudo como inteiro e depois converta.

---

# Caracteres
```cpp [lerCarac.cpp] {*|1,2|4-7|*} 
char c; cin >> c; // ler somente um caractere
cout << c << endl;

// Caracteres também são o seu valor em ascii
// então você pode somar
char aux = 'a' + 2; // vai ser igual a 'c'
cout << aux << endl;
```

[Tabela Ascii](https://www.ime.usp.br/~pf/algoritmos/apend/ascii.html)

---


# Operadores
## Operadores aritméticos
```cpp [numericOp.cpp] {*|1|2|3|4|5|6|*} 
int a = 2,b = 3;
int c = a + b;
int d= a - b;
int e = a * b;
int f = a/b; // divisão inteira (arredonda pra baixo)
int r = a % b; // resto da divisão
```

## Problema
Como calcular o teto de uma divisão inteira sem precisar converter para double?
````md magic-move {lines: true}

```cpp 
int a = 5,b = 2;
int teto = a/b;
cout << teto << endl; // isso printa 2

```

```cpp 
// Solução
int a = 5,b = 2;
int teto = (a + b - 1)/b;
cout << teto << endl; // 3

```
````
---

# Auto
Tipo de variável que deduz automaticamente seu tipo com base no que lhe foi atribuido.

```cpp 
int a = 2;
auto x = a; // int
auto y = 2.2; // double
auto z = x + y;
auto str = "abcd";
```

---

# Overflow

Ocorre quando o resultado de uma operação é maior (ou menor) do que o tamanho suportado pelo tipo

````md magic-move {lines: true}
```cpp {*|1-2|3|*}
int a = 1e9; //10^9
a = a * a; // resultado = 10e18
cout << a << endl;
```

```cpp {*|1-2|3|*}
long long a = 1e9; 
a = a * a;
cout << a << endl; //10 a 18 cabe no long long
```

```cpp {*|2|*}
int a = 1e9;
long long b = (1000) * a ;
cout << b << endl;
```
```cpp {*|2|*}
int a = 1e9;
long long b = (1000) * (long long)a ;
cout << b << endl;
// primeiro a operação é realizada e depois o valor é colocado na variável, então ele não converte. 
```
````

---

# Operadores lógicos
Operados utilizados na lógica boleana

```cpp {*|3|5|7|*}
bool a = true, b = false, c = true;

bool op_or = a || b; // retorna true se pelo menos 1 for true

bool op_and = a && b; // retorna true se os dois forem verdadeiros

a = !a; // inverte o valor da condição

```
---

# Condicionais

Utilizaremos apenas de if-else

```cpp {*|2|*}
int a,b; cin >> a >> b;

if(a > b){ 
  // se a for menor que b entra aq
}else if(a< b){ 
  // se a<b entra aq
}else{
  // se a == b entra aq
}

```

[Problema Motivador](https://codeforces.com/group/mzbGmMVMMp/contest/670834/problem/C)

---

# Curto circuito

Curto circuito ocorre quando o programa retorna o valor de uma expressão booleana sem avaliar todos os seus termos.

````md magic-move {lines: true}
```cpp {*|1,2|4|*}
int a[3] ={1,2,3};
int i = 3;
// a expressão a[i] < 4 será avaliada?
if(i < 3 && a[i] < 4){

}
```

```cpp {*|3-5|*}
int a[3] ={1,2,3};
int i = 3;
/* Não!! como o programa sabe que no && se uma condição for falsa, tudo já é falso,
então a expressão não precisa mais ser avaliada.
*/
if(i < 3 && a[i] < 4){

}
```

```cpp {*|5|3-4|*}
int a[3] ={1,2,3};
int i = 3;
// Isso também ocorre no ||
// Se um termo for verdadeiro, tudo já é verdade e a expressão não precisa mais ser avaliada.
if(1 == 1 || i > 5){

}
```
````

---

# Loops

## For
```cpp {*|3-5|*}
int n; cin >> n;
// for que roda n vezes, e executa o que está dentro
for(int i = 0;i < n;i++){

}

```

## While

````md magic-move {lines: true}
```cpp {*|3-5|*}
int n; cin >> n;
// while que roda n vezes, e executa o que está dentro
while(n--){ // enquanto n for > 0

}

```
```cpp {*|3-5|*}
int n; cin >> n;
// while que roda n vezes, e executa o que está dentro
while(n> 0){ // enquanto n for > 0
  n--;
}

```
````

## Extra
Também existe um foreach em C++, entraremos em detalhes posteriormente.


---

# Array
Estrutura guarda elementos de forma sequencial na memória. É 0 Indexado, os valores começam no indice 0;

```cpp {*|1|2|4-5|7-9|11-14|*} {lines:true}
int a[5] = {0,1,2,3,4};
int c[2]; // se criado vazio, é preenchido com lixo da memória

// pra acessar uma posição individualmente
int x = a[1];

// pode ser criado dinamicamente
int n; cin >> n;
int b[n];

// for que lê todas as posições de um array de tamanho n
for(int i = 0; i < n;i++){
  cin >> b[i];
}

```

---

# String

```cpp [lerString.cpp] {*|1|2-3|4-5|6-7|*} 
string s; // string é um array de caractere
cin >> s;
cout << s << endl;
char c = 'a';
s[0] = c; // uma posição dentro da string é um char
cout << s.size() << endl; // retorna o tamanho da string
s.push_back(c); // adiciona um caractere ao final da string
```

Mais métodos de string na [documentação](https://cplusplus.com/reference/string/string/).

---

# Vector
Faz tudo que array faz, mas tem métodos adicionais. Em comparação com o array pode ser um pouco mais lento por ter realocação de memória.

```cpp {*|1|3|5-6|7-9|11,12|13,14|*}
vector<int> a(5) = {1,2,3,4,5};

int x = a[1];

int n; cin >> n;
vector<int> b(n);
for(int i = 0; i < n;i++){
  cin >> b[i];
}

// posso adicionar elementos no final, pode causar realocação
b.push_back(5);
// posso retirar elementos do final
b.pop_back();
// .size() retorna o tamanho
cout << b.size() << endl;
```
---

# ForEach

Em C++ existe um for que pode ser utilizado em estruturas como vector e string, para iterar sobre os valores deles sem precisar de índice.

```cpp {*|1|3-5|7|9-11|*} {lines:true}
vector<int> a(5) = {1,2,3,4,5};

for(int valor: a){
  cout << valor << endl;
}

string s = "abcde";

for(char caractere : s){
  cout << caractere << endl;
}

```
---

# Funções

A função tem parâmetros, tipos de retorno e tipo dos parâmetros definidos. A função pode ser void.

Os parâmetros podem ser passados por cópia ou referência, caso sejam passados por referência, se forem alterados dentro da função também serão alterados onde foi chamado.


````md magic-move {lines: true}
```cpp {*|2|3-4|2-4|*}
// Passando a por cópia
int soma(int a,int b){
  int resposta = a+b;
  return resposta;
}


int main(){
  int a = 2,b = 3;
  a = soma(a,b);
  cout << a << endl;
  return 0;
}

```
```cpp {*|1-3|3-4|*}
// Passando a por referência
// é preciso colocar um &
void soma(int &a,int b){
    a += b;
}


int main(){
  int a = 2,b = 3;
  soma(a,b);
  cout << a << endl;
  return 0;
}

```
````
---

# Funções úteis de C++

## Min
Recebe 2 valores do mesmo tipo e retorna o menor deles.

```cpp 
int a = 3,b = 2;
cout << min(a,b) << endl;
```

## Max
Recebe 2 valores do mesmo tipo e retorna o maior deles.

```cpp 
int a = 3,b = 2;
cout << max(a,b) << endl;
```

---

# Algoritmos básicos

## Achar o maximo num array

````md magic-move {lines: true}
```cpp 
vector<int> arr = {2,4,5,3,1};
int maxi = 0;
for(auto x : arr){
  if(x > maxi) maxi = x;
}
```
```cpp 
vector<int> arr = {2,4,5,3,1};
int maxi = 0;
for(auto x : arr){
  maxi = max(maxi,x);
}
```

```cpp 
vector<int> arr = {2,4,5,3,1};
// pra achar o minimo é a mesma coisa, so que inicialmente tem valor infinito
int mini = INF;
for(auto x : arr){
  mini = min(mini,x);
}
```
````

---

# Algoritmos básicos

## Contar a frequencia de cada valor num array

````md magic-move {lines: true}
```cpp 
vector<int> arr = {2,4,5,3,1};
vector<int> cnt(maximo + 1);
for(auto x : arr){
  cnt[x]++;
}
```
```cpp 
string s = "abcd";
// contar a frequencia de cada caractere
vector<int> cnt(26); // a posição 0 guarda pra 'a''e a 25 pra 'z'
for(auto c : s){
  cnt[c - 'a']++;
}
```
````

---

# Problema

## Eu tenho duas strings s e t, como saber se uma é anagrama da outra?

[Problema](https://leetcode.com/problems/valid-anagram/description/)

---

# Referências

- [Documentação C++](https://cplusplus.com/)

- [CP Algorithms](https://cp-algorithms.com/index.html) :
Site com ótimas explicações para algoritmos mais complexos.

- [Curso UFMG](https://www.youtube.com/playlist?list=PLU2KWF7n4KZzvYwAk7h2LAx4Td0kadh-T) :
Várias ideias do nosso curso são baseadas nele.

- [MaratonUSP](https://www.youtube.com/@MaratonUSP) :
Canal no youtube com aulas muito boas.

- [Lista de questões por tópico](https://youkn0wwho.academy/topic-list):
Ótimo site (em inglês) que tem lista de questões para quase todos os assuntos.

---
src: ./pages/contatos.md
---

---
layout: end
---
# Obrigado por acompanhar a aula

 Por favor preencha o [formulário](https://codeforces.com/group/mzbGmMVMMp) de feedback com sugestões e críticas para a próxima aula 🙃.

<QRCode url="https://codeforces.com/group/mzbGmMVMMp" :size="150" />
