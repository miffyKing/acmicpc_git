const fs = require('fs');

 const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
 let input = fs.readFileSync(filePath).toString().split(' ');

//let input = fs.readFileSync(0, 'utf8').toString().split(' ');

var inputA = +input[0];
var inputB = +input[1];

console.log(inputA + inputB);

//---------------

// const fs = require('fs');
// const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
// let input = fs.readFileSync(filePath).toString().split('\n');

// input = input.toString().split(' ').map((item) => +item);

// inputA = +input[0];
// inputB = +input[1];

// console.log(inputA + inputB);
