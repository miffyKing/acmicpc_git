const fs = require('fs');

const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().split('\n');

//let input = fs.readFileSync(0, 'utf8').toString().split('\n');

let isused : number[] = [];
let buffer : number[] = [];


function func(cur)
{
    return cur;
}

let anr = func(3);
console.log("!!!");