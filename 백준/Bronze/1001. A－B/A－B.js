const readline = require("readline");
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let input = [];

rl.on("line", (line) => {
    input = line.split(' ').map(e => parseInt(e));
    rl.close();
}).on("close", () => {
    solution(input[0], input[1]);
    process.exit();
})

const solution = (a, b) => {
    console.log(a - b);
}