const fs = require('fs');

// const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
//let input = fs.readFileSync(filePath).toString().split(' ');

let input = fs.readFileSync(0, 'utf8').toString().split(' ');

inputA = +input[0];
inputB = +input[1];

console.log(inputA - inputB);