---
# try also 'default' to start simple
theme: dracula

title: Aplicações de Busca Binária e Soma de Prefixos.
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

# Aplicações de Busca Binária e Soma de Prefixos

<!--
The last comment block of each slide will be treated as slide notes. It will be visible and editable in Presenter Mode along with the slide. [Read more in the docs](https://sli.dev/guide/syntax.html#notes)
-->

---
layout: capa-aula
numero_aula: 5
---

---
layout: two-cols
layoutClass: gap-16
---

# Sumário da Aula

<Toc text-sm minDepth="1" maxDepth="2" columns=2  />
---

# Função Monotônica

<v-clicks>

- A busca binária não é restrita a problemas de encontrar valores no array ou primeiro valor >= , na verdade ela pode ser aplicada em qualquer função definida como **monotônica** em $O( \log_2n )$, mas o que é uma função monotônica?

- Lembre que em cada passo da busca binária nós precisamos cortar uma das metades do espaço de busca, então temos que ter certeza que o valor que buscamos não está daquele lado.

- Uma função monotônica é aquela que mantém um único sentido de variação em todo o seu domínio. Isso significa que ela é sempre não crescente ou sempre não decrescente.

- Matematicamente nós temos 2 opções para uma função monotônica:
      
      - x2 > x1 && f(x2) >= f(x1) , não decrescente
      - x2 > x1 && f(x2) <= f(x1) , não crescente

- Perceba que dado que estamos procurando um valor y, se chutarmos um valor x nós podemos comparar o valor de y com f(x) e decidir para que lado ir.


</v-clicks>

---

# Questão motivadora

<v-clicks>

[Link](https://codeforces.com/group/mzbGmMVMMp/contest/693602/problem/A)

https://www.desmos.com/calculator?lang=pt-BR

```cpp
    double l = 1, r = 1e10;

    while((l - r) <= EPS){
      int x = (l + r)/2;
      // se o valor que chutamos está depois de C, temos que voltar
      if(f(x) > C){
        r = x;
      }else{
        l = x;
      }
    }
    cout << l << endl;
```

</v-clicks>

---

# Função Booleana

<v-clicks>

Uma função booleana retorna 'Verdadeiro' ou 'Falso' para qualquer valor X de entrada, vamos denotar Verdadeiro por 1 e Falso por 0 .

Exemplo de função: Consigo levantar esse peso no supino?

| Peso $X$ | 5 | 10 | 15 | **20** | 25 | 30 | 35 |
| :--- | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **Consigo? $f(X)$** | 1 | 1 | 1 | **0** | 0 | 0 | 0 |

Perceba que essa função é monotônica, se eu não consigo com um peso X, eu não conseguirei com X + 1. Logo, poderiámos fazer uma busca binária para determinar o maior peso que uma pessoa levanta no supino.


</v-clicks>

---

# Busca binária na resposta

<v-clicks>

Problema: Uma fábrica tem $n$ máquinas que podem ser usadas para fazer produtos. Seu objetivo é fazer um total de $m$ produtos.

Para cada máquina, você sabe o número de segundos que ela precisa para fazer um único produto. As máquinas podem trabalhar simultaneamente, e você pode decidir livremente o cronograma delas.

Qual é o tempo mais curto necessário para fazer $m$ produtos?
 
[Link](https://codeforces.com/group/mzbGmMVMMp/contest/693602/problem/B)

Ao analisarmos um problema de mínimo nós podemos fazer a seguinte pergunta, se eu consigo resolver o problema com X eu também consigo resolver com X + 1?

Se isso for verdade podemos modelar a função de resposta como uma função booleana que será monotônica com base na observação anterior, e aplicar busca binária.

</v-clicks>

---

# Solução

<v-clicks>

Dado que a função de resposta monotônica, nós precisamos apenas criar uma função **can(t)** que verifica se eu consigo resolver o problema com um tempo t, se for possível nós tentamos diminuir a resposta.

É importante definirmos com precisão qual o menor e o maior valor possível para a resposta.

```cpp
    int l = 0, r = 1e18;
    int ans;
    while(l <= r){
        int t = (l + r)/2;
        // se eu consigo com esse valor tento com menos
        if(can(t)){
            ans = t;
            r = t - 1;
        }else{
            l = t + 1;
        }
    }
```

Para checkar se é possivel com um tempo $t$, podemos calcular quantos produtos cada máquina produz em $t$ segundos e vemos se o total é maior do que $m$.

</v-clicks>

---

# Soma de prefixos

<v-clicks>

## Problema Motivador

Dado um array com $N (<= 10^5)$ inteiros, responda $Q (<= 10^5)$ consultas na forma:  
 
**"Qual a soma dos valores no intervalo incluso $[a, b]$?"**


### Exemplo prático

| Índice ($i$) | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |
| :--- | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **Valor** | 3 | 2 | 4 | 5 | 1 | 1 | 5 | 3 |



### Consultas
*   **$[2, 4] \rightarrow$** $2 + 4 + 5$ = **11**
*   **$[5, 6] \rightarrow$** $1 + 1$ = **2**

</v-clicks>

---

# Força bruta

<v-clicks>

A primeira abordagem a se pensar é, porque não fazer um loop de $[l,r]$ somando o valor de cada elemento de cada elemento.

```cpp
  while(q--){
    int l,r; cin >> l >> r;
    int sum = 0;
    for(int i = l; i <=r;i++) sum += a[i];
    cout << sum << endl;
  }
```

Perceba que se em cada consulta ele pedir um intervalo grande, perto do tamanho do array a complexidade de uma consulta fica $O(N)$ , como são Q consultas a complexidade final fica $O(NQ)$ que dá $4 * 10^{10}$ operações

</v-clicks>

---


# Problema Simplificado

<v-clicks>

Imagine que agora nas consultas, todo $l$ tem valor 1, ou seja queremos calcular valores do prefixo.

Nesse caso poderiamos precalcular o valor de cada soma de prefixo apenas com um loop.

```cpp
  vector<int> soma_pref(n + 1);
  for(int i = 1; i <=n;i++){
    soma_pref[i] = soma_pref[i - 1] + a[i - 1];
  }
```

Perceba que o array que guarda a soma está 1 indexado, isso é util porque agora na posição 0 nós guardamos o prefixo vazio.

Então para responder a $querie [l,r]$, nós já temos o valor salvo em $soma_pref[r]$, basta imprimir;

</v-clicks>

---

# Voltando ao problema original

<v-clicks>

A observação que precisamos ter aqui é que qualquer range [l,r] pode ser representado como a subtração de dois prefixos do array da soma de prefixos, mais especificamente:


soma de $[l,r] = somapref[r] - somapref[l - 1]$ .

A complexidade para acessar duas vezes um array é O(1) então conseguimos resolver o problema em $O(Q)$ ou melhor dizendo $O(N + Q)$.

Mas e se l for igual a 1? Nesse caso nós subtrairíamos $somapref[0]$ que é o prefixo vazio.

</v-clicks>

---

# Soma de prefixos e Busca binária

<v-clicks>

Se um array A é formado inteiros não negativos, então a soma de prefixos dele pode ser visualizada como uma função monotônica, logo, podemos fazer uma busca binária.

Aplicações:

- Qual o menor prefixo que tem soma >= K.
- Para uma posição $r$, qual o menor $l$ ($l < r$) tal que a soma $[l,r] <= X$
- Contar quantos subarrays tem soma $>= S$

[Questão](https://codeforces.com/group/mzbGmMVMMp/contest/693602/problem/E)

</v-clicks>

---

# Problema clássico

<v-clicks>

Dado um array A, quantos subarrays tem soma exatamente igual a K.

[Problema](https://leetcode.com/problems/subarray-sum-equals-k/description/)

A ideia principal desse problema vem a partir de uma manipulação matemática.

$somapref[r] - somapref[l - 1] = K$

$somapref[r] - K = somapref[l - 1]$

Para cada $r$ queremos achar quantos $l$'s existems tal que $somapref[r] - K = somapref[l - 1]$. 
A soma disso para todos os $r$'s será a resposta final , o algoritmo consiste em iterar o array de forma crescente e salvar quantas vezes um valor já apareceu antes.

```cpp
  for(int x : arr){
    int soma_r += x;
    resposta += cnt[soma_r - k] // quantas vezes apareceu um l com somapref[l - 1] = somapref[r] - K
    cnt[soma_r]++; // esse cara se torna uma opção para quem está na frente dele
  }
```

</v-clicks>

---

# Soma num Intervalo

<v-clicks>

## Problema Motivador

Dado um array com $N$ inteiros, Processe $Q$ consultas na forma:  
 
**" $[l, r,x] $ Some X em todos os elementos no intervalo $[l,r]$"**

No final imprima o array após todas as somas


### Exemplo prático

| Índice ($i$) | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |
| :--- | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **Valor** | 3 | 2 | 4 | 5 | 1 | 1 | 5 | 3 |



### Consultas
*   **$[2, 4, 2]$** 
*   **$[5, 6, 1]$** 

</v-clicks>

---

# Força bruta

<v-clicks>

A primeira abordagem a se pensar é, porque não fazer um loop de $[l,r]$ somando $x$ em todos os elementos

```cpp
  while(q--){
    int l,r,x; cin >> l >> r >> x;
    for(int i = l; i <=r;i++) a[i] += x;;
    cout << sum << endl;
  }
```

Perceba que se em cada querie ele pedir um intervalo grande, perto do tamanho do array a complexidade de uma consulta fica $O(N)$ , como são Q consultas a complexidade final fica $O(NQ)$ que dá $4 * 10^{10}$ operações

</v-clicks>

---

# Array de diferenças

<v-clicks>

Tentaremos calcular o array de diferenças (AD) que guarda para cada índice o quanto seu valor foi alterado juntando todas as consultas.

Considere um Array de tamanho 5 , inicialmente o AD está assim [0,0,0,0,0,0] , o array tem um índice a mais propositalmente.

Agora, pensando na soma de prefixos o que acontece quando somamos 1 do indice 2 até o indice 4.

$ [0,1,0,0,-1,0]$ , perceba que quando calcularmos a soma de prefixos todos os valores entre 2 e 4 vão ser somados em 1, essa soma se propaga. Porém ao chegarmos no indice 5 esse valor é subtraido o valor para de ser propagado.

$somapref = [0,1,1,1,0,0]$ , após calcularmos a soma de prefixos teremos o array final.

</v-clicks>

---

# Problema

<v-clicks>

[Link](https://olimpiada.ic.unicamp.br/pratique/pj/2018/f3/troca/)

```cpp
vector<int> ps(n + 1);
while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        ps[l]++;
        ps[r + 1]--;
    }

    for (int i = 1; i <= n; i++)
    {
        ps[i] += ps[i - 1];
    }
```

$ps$ guarda o array após todas as alterações.

</v-clicks>

---


# Referências

- [Documentação C++](https://cplusplus.com/)
- [Curso Busca Binária](https://codeforces.com/edu/course/2/lesson/6)
- [Aula Busca Binária Errichto](https://www.youtube.com/watch?v=GU7DpgHINWQ&list=PLl0KD3g-oDOHpWRyyGBUJ9jmul0lUOD80&index=4)
- [Aula Soma de Prefixos Errichto](https://www.youtube.com/watch?v=PhgtNY_-CiY)
- [Array de Diferenças](https://codeforces.com/blog/entry/78762)
- [Livro CPH](https://cses.fi/book/book.pdf)

---
src: ./pages/contatos.md
---

---
layout: end
---
# Obrigado por acompanhar a aula

 Por favor preencha o [formulário](https://forms.gle/Y7rXjvKZybMibntR6) de feedback com sugestões e críticas para a próxima aula 🙃.

<QRCode url="https://forms.gle/Y7rXjvKZybMibntR6" :size="150" />
