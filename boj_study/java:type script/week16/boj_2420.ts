const fs = require('fs');

const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().split(' ');

//let input = fs.readFileSync(0, 'utf8').toString().split(' ');

let A = BigInt(input[0]);
let B = BigInt(input[1]);

if (A < B)
{
    console.log((B-A).toString());
}
else
{
    console.log((A-B).toString())
}
