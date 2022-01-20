<template>
  <v-app>
    <v-app-bar
      app
      color="primary"
      dark
    >

      <v-btn
        href="https://github.com/SheepSeb/mbw"
        target="_blank"
        text
      >
        <span class="ml-2">MBW Web app</span>
        <v-icon>mdi-open-in-new</v-icon>
      </v-btn>
    </v-app-bar>

    <v-main>
      <Table/>
    </v-main>
  </v-app>
</template>

<script>
import Table from './components/Table';

export default {
  name: 'App',

  components: {
    Table,
  },

  data: () => ({
    //
  }),
};
</script>
