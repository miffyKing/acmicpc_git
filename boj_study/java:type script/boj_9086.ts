
const fs = require('fs');

const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().split('\n');

//let input = fs.readFileSync(0, 'utf8').toString().split('\n');

var t :number = +input[0];
input.shift();

for (let i = 0; i < t; i++)
{
    var str :string = input[i];
    var front :string = str[0];
    var end :string = str[str.length-1];
    console.log(front + end);
}