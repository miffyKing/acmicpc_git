const fs = require('fs');

const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().split(' ');

//let input = fs.readFileSync(0, 'utf8').toString().split(' ');

//타입스크립트 배열 사용법
let array[5];


