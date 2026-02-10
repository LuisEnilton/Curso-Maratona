<script setup>
import QrcodeVue from 'qrcode.vue'

defineProps({
  url: { type: String, required: true },
  size: { type: Number, default: 150 }
})
</script>

<template>
  <div class="flex justify-center p-4">
    <qrcode-vue :value="url" :size="size" level="H" />
  </div>
</template>