
const fs = require('fs');

const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().split('\n');

//let input = fs.readFileSync(0, 'utf8').toString().split('\n');

for (let i = 0; i < input.length; i++)
{
    
    let oneline : string = input[i];
    let a : number = +oneline.split(' ')[0];
    let b : number = +oneline.split(' ')[1];
    if (a == 0 && b == 0)
    {
        break;
    }
    if (a > b)
    {
        console.log('Yes');
    } 
    else 
    {
        console.log('No');
    }
}