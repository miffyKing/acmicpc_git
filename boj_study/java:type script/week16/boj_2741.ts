const fs = require('fs');

const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().split('\n');

//let input = fs.readFileSync(0, 'utf8').toString().split('\n');

let n = +input[0];

for (let i = 1; i <= n; i++)
{
    process.stdout.write(i + '\n');
}