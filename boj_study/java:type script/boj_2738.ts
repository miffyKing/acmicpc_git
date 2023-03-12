const fs = require('fs');

const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().split('\n');

//let input = fs.readFileSync(0, 'utf8').toString().split('\n');

let firstline = input[0].split(' ');

input.shift();

let a = +firstline[0];
let b = +firstline[1];

let arr1: number[] = [];
let arr2: number[] = [];

for (let i = 0; i < a; i++)
{
    let oneline = input[i].split(' ');
    for (let j = 0; j < b; j++)
    {
        arr1.push(oneline[j]);
    }
}
for (let i = a; i < a*2; i++)
{
    let oneline = input[i].split(' ');
    for (let j = 0; j < b; j++)
    {
        arr2.push(oneline[j]);
    }
}

let arr3: number[] = [];

for (let i = 0; i < a; i++)
{
    for (let j = 0; j < b; j++)
    {
        const sum = +arr1[i*b + j] + +arr2[i*b + j];
        process.stdout.write(sum.toString() + ' ');
    }
    if ( i != a-1)
    {
        console.log('');
    }
}





