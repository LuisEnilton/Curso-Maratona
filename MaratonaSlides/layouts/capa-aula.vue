<template>
  <div class="slidev-layout w-full h-full flex flex-col justify-center items-center text-center">
    
    <div class="flex-grow flex flex-col justify-center">
      <slot />
    </div>

    <div v-if="$frontmatter.numero_aula" class="mt-8 mb-4 flex flex-col items-center">
      <p class="text-sm opacity-75 mb-2">Escaneie para acessar o slide da Aula {{ $frontmatter.numero_aula }}</p>
      
      <QRCode 
        :url="`https://luisenilton.github.io/Curso-Maratona/aula${$frontmatter.numero_aula}/`" 
        :size="180" 
      />
      
      <a 
        :href="`https://luisenilton.github.io/Curso-Maratona/aula${$frontmatter.numero_aula}/`" 
        target="_blank"
        class="text-xs mt-2 text-primary hover:underline"
      >
        luisenilton.github.io/Curso-Maratona/aula{{ $frontmatter.numero_aula }}
      </a>
    </div>

  </div>
</template>