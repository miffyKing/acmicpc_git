const fs = require('fs');

const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().split('\n');

//let input = fs.readFileSync(0, 'utf8').toString().split('\n');

let firstline = input[0].split(' ');

let a = firstline[0];
let b = firstline[1];

if (+a > +b)
    console.log('>');

else if (+a < +b)
    console.log('<');
else 
    console.log("==");