
const fs = require('fs');

const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().split('\n');

//let input = fs.readFileSync(0, 'utf8').toString().split('\n');


console.log('       _.-;;-._');
console.log("'-..-'|   ||   |");
console.log("'-..-'|_.-;;-._|");
console.log("'-..-'|   ||   |");
console.log("'-..-'|_.-''-._|");
