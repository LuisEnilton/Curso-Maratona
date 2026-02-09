---
# try also 'default' to start simple
theme: seriph
# random image from a curated Unsplash collection by Anthony
# like them? see https://unsplash.com/collections/94734566/slidev
background: https://cover.sli.dev
# some information about your slides (markdown enabled)
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
transition: fade-out
---

# Objetivos do curso

<v-clicks>

- Incentivar vocês a participarem da maratona

- Dar um nivel básico de dominios sobre algoritmos e estrutura de dados

- Ter as habilidades básicas necessárias para resolver uma questão numa entrevista

</v-clicks>


<!--
You can have `style` tag in markdown to override the style for the current page.
Learn more: https://sli.dev/features/slide-scope-style
-->

<!--
Here is another comment.
-->

---
transition: slide-up
---

# Porque estudar para maratona me ajudaria em algo?

<v-clicks>

- É divertido (eu acho).

- Abre oportunidades em empresas boas.

- Ajuda a ter a habilidade de transformar ideias em código.

- Facilita muito sua vida em entrevistas.

</v-clicks>

---
layout: two-cols
layoutClass: gap-16
---

# Sumário da Aula

You can use the `Toc` component to generate a table of contents for your slides:

```html
<Toc minDepth="1" maxDepth="1" />
```

The title will be inferred from your slide content, or you can override it with `title` and `level` in your frontmatter.

::right::

<Toc text-sm minDepth="1" maxDepth="2" />

---
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
---

# Tipos de variáveis

## Inteiros
```cpp {*|1|2|*} 
int a = 2; // vai de -2^31 até 2^31 -1
long long b = 3;// vai de -2^63 até 
```

## Ponto flutuante

```cpp  {*|1|2|4} 
double a = 2.1; // vai de  1.7e−308 and 1.7e+308
long double b = 3.2;// vai de 1.18973e+4932 até 3.3621e-4932

// podem ter problemas de precisão na hora de imprimir

```

## Booleanos

```cpp  {*|1|2|4} 
bool a = true;
bool b = false;

// 0 tem valor false, e qualquer outro numero true
bool c = 0, d = 2;
```

<!--
Notes can also sync with clicks

[click] This will be highlighted after the first click

[click] Highlighted with `count = ref(0)`

[click:3] Last click (skip two clicks)
-->


---

# Entrada e saida
```cpp [lerInt.cpp] {*|2|3,4|*}
int x,y;
cin >> x >> y;
cout << x << " " << y << '\n';
cout << x << " " << y << endl;
// '\n' é
```
'\n' é apenas quebra de linha, endl libera o buffer.

Imprimir double pode causar erro de precisão.

````md magic-move {lines: true}
```cpp [lerDouble.cpp]
double x,y;
// ler double é mt lento, é melhor evitar
cin >> x >> y;

cout << x << " " << y << endl;
```

```cpp [lerDouble.cpp]
// Solução 
double x,y;
cin >> x >> y;

cout << setprecision(8) << fixed << x << " " << y << endl;
```
````

---

# Caracteres e String
```cpp [lerCarac.cpp] {*|1,2|4-7|*} 
char c; cin >> c; // ler somente um caractere
cout << c << endl;

// Caracteres também são o seu valor em ascii
// então você pode somar
char aux = 'a' + 2; // vai ser igual a 'c'
cout << aux << endl;
```

```cpp [lerString.cpp] {*|1|2|4|*} 
string s; // string é um array de caractere
cin >> s;
cout << s << endl;
char c = 'a';
s[0] = c; // uma posição dentro da string é um char
cout << s.size() << endl; // retorna o tamanho da string
s.push_back(c); // adiciona um caractere ao final da string
```
---
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
Como calcular o resto de uma divisão inteira sem precisar converter para double?
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
---
# Auto
Existe um tipo de variável que deduz automaticamente seu tipo com base no que lhe foi atribuido.

```cpp 
int a = 2;
auto x = a; // int
auto y = 2.2; // double
auto z = x + y;
auto str = "abcd";
```


---
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
```
````

---
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
---
# Condicionais

Falaremos apenas de if-else

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

---
class: px-20
---

# Curto circuito

````md magic-move {lines: true}
```cpp {*|1,2|4|*}
int a[3] ={1,2,3};
int i = 3;
// a expressão a[i] < 4 será avaliada?
if(i < 3 && a[i] < 4){

}
```

```cpp {*|2|*}
int a[3] ={1,2,3};
int i = 3;
// Não!!
// como o programa sabe que no && se uma condição for falsa, tudo já é falso, a expressão não é avaliada.
if(i < 3 && a[i] < 4){

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
Também existe um foreach em C++, entraremos em detalhes na aula de estrutura de dados.


---

# Array
Estrutura guarda elementos sequencias na memória. É 0 Indexado, os valores começam no indice 0;

```cpp {*|1|2|3-4|5-7|8-11|*}
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

# Vector
Faz tudo que array faz, mas tem métodos adicionais. Em comparação com o array pode ser um pouco mais lento por ter realocação.

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

# Funções

A função tem tem parâmetros, tipos de retorno e tipo dos parâmetros definidos. A função pode ser void.

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

## Swap

Troca o valor de duas variáveis de mesmo tipo.

```cpp 
int a = 3, b = 2;
swap(a,b);
// tomar cuidado com arrays
// se quiser trocar 2 arrays é preciso trocar as referências
int a[2],b[2];

swap(*a,*b);
```

## Max
Recebe 2 valores do mesmo tipo e retorna o maior deles.

```cpp 
int a = 3,b = 2;
cout << max(a,b) << endl;
```

---
foo: bar
dragPos:
  square: 691,32,167,_,-16
---

# Funções úteis de C++
## Min
Recebe 2 valores do mesmo tipo e retorna o menor deles.

```cpp 
int a = 3,b = 2;
cout << min(a,b) << endl;
```


---
src: ./pages/imported-slides.md
hide: false
---

---

# Monaco Editor

Slidev provides built-in Monaco Editor support.

Add `{monaco}` to the code block to turn it into an editor:

```ts {monaco}
import { ref } from 'vue'
import { emptyArray } from './external'

const arr = ref(emptyArray(10))
```

Use `{monaco-run}` to create an editor that can execute the code directly in the slide:

```ts {monaco-run}
import { version } from 'vue'
import { emptyArray, sayHello } from './external'

sayHello()
console.log(`vue ${version}`)
console.log(emptyArray<number>(10).reduce(fib => [...fib, fib.at(-1)! + fib.at(-2)!], [1, 1]))
```

---
layout: center
class: text-center
---

# Learn More

[Documentation](https://sli.dev) · [GitHub](https://github.com/slidevjs/slidev) · [Showcases](https://sli.dev/resources/showcases)

<PoweredBySlidev mt-10 />
