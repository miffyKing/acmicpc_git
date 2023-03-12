const fs = require('fs');

const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().split('\n');

//let input = fs.readFileSync(0, 'utf8').toString().split('\n');

let words : string = input[0];

//console.log(words);
for (let i = 0; i < words.length; i++)
{
    if (words.charAt(i) >= 'a' && words.charAt(i) <= 'z')
    {
        process.stdout.write(words.charAt(i).toUpperCase());
    } else 
    {
        process.stdout.write(words.charAt(i).toLowerCase());
    }
}