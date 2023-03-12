const fs = require('fs');

const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().split(' ');

//let input = fs.readFileSync(0, 'utf8').toString().split(' ');

let arr: number[] = [];
for (let i = 0; i < 5; i++)
{
    arr.push(input[i]);
}

let answer : number = 0;

for (let i = 0; i < 5; i++)
{
    answer += (arr[i]*arr[i]);
}
console.log(answer%10);