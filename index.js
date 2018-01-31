const blackfriday = require('./src');

console.log(blackfriday);
console.log(
  blackfriday.markdown(`
# Hello world

1. one
2. two
3. three

`)
);
