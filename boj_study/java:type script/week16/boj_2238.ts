const fs = require('fs');

const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().split('\n');

//let input = fs.readFileSync(0, 'utf8').toString().split('\n');

let a = BigInt(input[0]);
let b = BigInt(input[1]);

console.log((a+b).toString());
console.log((a-b).toString());
console.log((a*b).toString());
