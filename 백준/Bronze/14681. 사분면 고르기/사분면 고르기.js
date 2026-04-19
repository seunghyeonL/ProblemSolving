const readline = require('readline');

const rl = readline.createInterface(process.stdin)

const input = []
let cnt = 0

rl.on('line', (line) => {

    input.push(Number(line))

}).on('close', () => {

    let x = input[0]
    let y = input[1]

    if (x > 0 && y > 0) console.log(1)
    else if (x < 0 && y > 0) console.log(2)
    else if (x < 0 && y < 0) console.log(3)
    else console.log(4)

    process.exit();
})
