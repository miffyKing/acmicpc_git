const fs = require('fs');

const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().trim().split(' ');

//let input = fs.readFileSync(0, 'utf8').toString().split(' ');

const m = BigInt(parseInt(input[0]));
const n = BigInt(parseInt(input[1]));


console.log((m/n).toString());
console.log((m%n).toString());

