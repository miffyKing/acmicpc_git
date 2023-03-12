const fs = require('fs');

const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().split('\n');

//let input = fs.readFileSync(0, 'utf8').toString().split('\n');

let firstline = input[0].split(' ');

for (let i = 1; i <= 9; i++)
{
    console.log(firstline + ' * ' + i + ' = ' + +firstline*i);
}