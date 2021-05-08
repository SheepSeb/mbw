const path = require('path');

module.exports = {
  outputDir:path.resolve(__dirname,'./publicDeploy'),
  devServer:{
    proxy:{
      '/api':{
        target: 'http://localhost:8000'
      }
    }
  },
  transpileDependencies: [
    'vuetify'
  ]
}
