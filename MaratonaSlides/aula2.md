---
# try also 'default' to start simple
theme: dracula

title: Introdução a Complexidade e algoritmos básicos
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

# Introdução a Complexidade e Algoritmos básicos

<!--
The last comment block of each slide will be treated as slide notes. It will be visible and editable in Presenter Mode along with the slide. [Read more in the docs](https://sli.dev/guide/syntax.html#notes)
-->

---
layout: capa-aula
numero_aula: 2
---

---
layout: two-cols
layoutClass: gap-16
---

# Sumário da Aula

<Toc text-sm minDepth="1" maxDepth="2" columns=2  />
---

# Busca Binária

Imagine buscar a palavra **"Laranja"** em um dicionário.

* Você não lê página por página desde a letra A.
* Você abre o livro no meio (ex: letra M).
* Como "L" vem antes de "M", você **descarta toda a segunda metade** do livro.
* Repete o processo na primeira metade até achar

---

# Exemplo (Adivinhe o numero)

Estou pensando em um número de **1 a 100**. A cada chute, eu digo: Maior, Menor ou Acertou.

<v-clicks>

- Abordagem 1: Pesquisa Simples (Linear)
  - Chuta 1, depois 2, depois 3...
  - Pior caso: 100 tentativas. 


- Abordagem 2: Busca Binária
  - Chuta o meio: **50**. *(Eu digo: "Maior")*
  - Metade das opções foram eliminadas. O número está entre 51 e 100.
  - Novo meio: **75**. *(Eu digo: "Menor")*
  - O número com certeza está entre 51 e 74. 

- A cada rodada, **eliminamos metade** das possibilidades. ![Quantidade de Chutes](/Buscabinaria.png)
</v-clicks>

---

# Quantidade de chutes

Na busca simples, vamos subtraindo as possibilidades de 1 em 1. Na busca binária, dividimos por 2 a quantidade de possibilidades a cada passo.
O número máximo de tentativas é quantas vezes podemos dividir $N$ por 2 até chegar a 1.

<v-clicks>

Isso é a definição de **Logaritmo na base 2**.

| Tamanho de $N$ | Busca Simples $O(N)$ | Busca Binária $O(\log N)$ |
| :--- | :--- | :--- |
| 100 elementos | 100 chutes | ~ 7 chutes |
| 1.000 elementos | 1.000 chutes | ~ 10 chutes |
| $10^6$ elementos | 1.000.000 chutes | ~ 20 chutes |
| $10^9$ elementos | 1.000.000.000 chutes | ~ 30 chutes |

<br>

</v-clicks>

---

# Problema

Dado um array com N elementos responda Q perguntas do tipo "Qual o indice do elemento V no array, se V não estiver no array imprima 'X' ".

[Link Problema]([Exercicio](https://neps.academy/br/exercise/2758))


---

# Por que estudar complexidade?

Nos problemas de maratona não nos importamos apenas se o algoritmo está correto, mas também com a velocidade que ele executa.

Essa motivação nos leva a estudar complexidade, que nos dá uma estimativa, com base na entrada do tempo que o algoritmo demora para rodar .

Motivos:
<v-clicks>

- Estimar o tempo de execução sem ter o código.

- Avaliar o pior caso para a solução proposta, em competições, os testes dos juizes são feitos para quebrar soluções ineficientes.

- Saber que estrutura de dados eu posso utilizar, sem estourar o limite de tempo.

</v-clicks>

---

# Notação Big O

O Big O ($O$) descreve como o número de operações do seu algoritmo cresce à medida que a entrada ($N$) aumenta.

## Definições

<v-clicks>

- **Não mede o tempo em segundos:** Segundos dependem do hardware, da linguagem e do compilador.
- **Mede a ordem de grandeza:** Se a entrada dobrar, o tempo dobra? Quadruplica?
- **Foca no Pior Caso:** Assumimos que o universo conspira contra nós. Se a busca pode ir até o final da lista, assumimos que ela vai até o final.
- **Ignora Constantes:** Para o Big O, $O(2N)$ e $O(50N)$ são apenas $O(N)$. O que importa é a curva de crescimento.

</v-clicks>
---

# Aplicação na Maratona

Via de regra, em competições usando C++, em 1 segundo o computador processa **$10^8$ operações.

Em cada problema é definido o tempo limite máximo e as restrições para o tamanho da entrada.

<img src="/TabelaComplexidade.png" class="w-2/5 mx-auto rounded-lg shadow-lg border border-gray-300" />
---

# Analisando código
 
## Loops aninhados

<v-clicks>

```cpp
int cnt = 0;
for(int i = 1; i <=n;i++){
  for(int j = 1;j <=m;j++){
    cnt++;
  }
}

```

- Em loops aninhados em cada voltar do loop exterior, você roda o loop interior completo, então você multiplica a complexidade dos dois.
- O(N * M)

</v-clicks>

---

# Analisando código

## Loops separados

<v-clicks>

```cpp
int cnt = 0;
for(int i = 1; i <=n;i++){
  
}

for(int j = 1;j <=m;j++){
    cnt++;
  }

```

- Em loops Separados, calculamos a complexidade separadamente e depois somamos.
- O(N + M)

</v-clicks>

---

# Exercicio Motivador

## Divisores de um número

<v-clicks>

Dado um numero N, encontre todos os divisores dele.

Restrições: N <= $10^9$.

Tempo limite: 1 segundo.
</v-clicks>

---

# Primeira Abordagem
Podemos iterar por todos os numeros <= a N e testar se ele divide N.

```cpp
vector<int> divisores;
for(int i = 1; i <=n;i++){
  if((n % i) == 0) divisores.push_back(i);
}

```

<v-clicks>

Qual a complexidade desse código?

$O(N)$

Efetuariamos $10^9$ operações o que é muito lento.

</v-clicks>

---

# Segunda abordagem

É impossivel que um numero maior do que a metade divida N, logo só precisamos testar até N/2

```cpp
for(int i = 1; i <=n/2;i++){
  if((n % i) == 0) divisores.push_back(i);
}
```
<v-clicks>

Qual a complexidade desse código?

$O(N/2)$ = $O(N)$ 

Efetuariamos $5 * 10^8$ operações o que ainda é muito lento.

</v-clicks>

---

# Observação

Todo número N tem uma quantidade finita de divisores, mas eles não estão distribuidos de forma aleatória.

Eles se organizam em pares ao redor do ponto central: $\sqrt{N}$.


<v-clicks>

$$d \times \left(\frac{N}{d}\right) = N$$

Se $d$ é um divisor, $\frac{N}{d}$ também é. Um "espelha" o outro.

Prova por contradição: Existir dois divisores a e b de N (a/N = b) tal que a > $\sqrt{N}$ e b > $\sqrt{N}$ $\Rightarrow$ $a * b > N$ , o que é uma contradição.

</v-clicks>

---
layout: two-cols
class: text-center
transition: slide-up
---

# Divisores de $N=36$
## Espelho em $\sqrt{36} = 6$

<div class="text-lg space-y-2 font-mono w-full px-4 mt-2">
  
  <span v-click class="block border border-opacity-20 py-0.5 rounded bg-opacity-10 bg-gray-500">Iteração $i=1$</span>
  
  <span v-click class="block border border-opacity-20 py-0.5 rounded bg-opacity-10 bg-gray-500">Iteração $i=2$</span>
  
  <span v-click class="block border border-opacity-20 py-0.5 rounded bg-opacity-10 bg-gray-500">Iteração $i=3$</span>
  
  <span v-click class="block border border-opacity-20 py-0.5 rounded bg-opacity-10 bg-gray-500">Iteração $i=4$</span>
  
  <span v-click class="block border border-opacity-20 py-0.5 rounded bg-opacity-10 bg-gray-500 leading-tight">Iteração $i=5$ <span class="text-red-400 text-xs block">Não divide (pula)</span></span>
  
  <span v-click class="block border border-primary py-0.5 rounded bg-opacity-20 bg-primary font-bold">Iteração $i=6 = \sqrt{36}$</span>

</div>

::right::

<div class="flex flex-col items-center h-full mt-2">

<h3 class="mb-4 text-sm opacity-80 uppercase tracking-widest">Pares Encontrados</h3>

<div class="grid grid-cols-2 gap-x-10 gap-y-2 font-bold text-3xl w-fit mx-auto">
  
  <div v-click="1" class="text-right text-green-300">1</div>
  <div v-click="1" class="text-left text-green-300">36</div>

  <div v-click="2" class="text-right text-cyan-300">2</div>
  <div v-click="2" class="text-left text-cyan-300">18</div>

  <div v-click="3" class="text-right text-purple-300">3</div>
  <div v-click="3" class="text-left text-purple-300">12</div>

  <div v-click="4" class="text-right text-amber-300">4</div>
  <div v-click="4" class="text-left text-amber-300">9</div>

  <div v-click="6" class="text-right text-blue-300">6</div>
  <div v-click="6" class="text-left text-blue-300">6</div>

</div>

<div v-click="7" class="mt-4 w-full pt-3 border-t border-dashed border-opacity-30 border-gray-400 text-center text-sm">
  <p class="font-bold text-green-400">Iterações: 6 (vs 36)</p>
  <p class="text-xs opacity-60 mt-1">Após a raiz, os pares apenas se repetem de trás pra frente.</p>
</div>

</div>

---

# Terceira abordagem

Com base na observação anterior, só precisamos testar os numeros até $\sqrt{N}$

```cpp
for(int i = 1; i * i <=n;i++){
  if((n % i) == 0) {
    divisores.push_back(i);
    if(i != n/i) divisores.push_back(n/i);
    // precisamos tratar o caso da raiz quadrada pra não ficar duplicado
  }
}
```
<v-clicks>

Qual a complexidade desse código?

$O(\sqrt{N})$

Efetuariamos $31 * 10^4$ operações o que passa com bastante folga no tempo limite.

</v-clicks>

---

# Problema

Descubrar se um numero N é primo.

N <= $10^{12}$

[Link do Problema](https://neps.academy/br/course/logica-de-programacao/lesson/e-primo)

---

# Solução

```cpp
bool eh_primo = true;
for(int i = 1; i * i <=n;i++){
  if((n % i) == 0) {
    eh_primo = false;
  }
}
```
---

# Hora do Quiz

Peguem o link do quiz no chat.

---

# Referências

- [Documentação C++](https://cplusplus.com/)
- [Livro Entendendo algoritmos](https://www.amazon.com.br/Entendendo-Algoritmos-Ilustrado-Programadores-Curiosos/dp/8575225634)
- [Aula UFMG](https://www.youtube.com/watch?v=cu3kKbkEZSw&list=PLU2KWF7n4KZzvYwAk7h2LAx4Td0kadh-T)
- [Quiz](https://create.kahoot.it/share/quiz-complexidade-algoritmos/d71a1c5e-f556-43f8-a0d1-2d855fa58579)
- [Série Harmônica](https://pt.wikipedia.org/wiki/S%C3%A9rie_harm%C3%B3nica_(matem%C3%A1tica))

---
src: ./pages/contatos.md
---

---
layout: end
---
# Obrigado por acompanhar a aula

 Por favor preencha o [formulário](https://codeforces.com/group/mzbGmMVMMp) de feedback com sugestões e críticas para a próxima aula 🙃.

<QRCode url="https://codeforces.com/group/mzbGmMVMMp" :size="150" />
