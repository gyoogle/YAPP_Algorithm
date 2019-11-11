require('fs').readFileSync('/dev/stdin').toString().split(' ');
console.log(parseInt(data[0]) * parseInt(data[1]) - 1)
