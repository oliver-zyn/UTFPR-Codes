const fs = require('fs');
const cardData = require('./cardData');

let content = ""

for(let i = 0; i < cardData.length; i++) {
  content += `${cardData[i].code}`
}

fs.writeFile('tudo.h', content, (err) => {
  if (err) {
    console.error('Ocorreu um erro ao escrever o arquivo:', err);
    return;
  }
  console.log('Arquivo gerado com sucesso!');
});
