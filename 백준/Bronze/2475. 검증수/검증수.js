const readline = require("readline");
const rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout,
});

let input = [];

rl.on("line", (line) => {
	input = line.split(" ").map((e) => parseInt(e));
	rl.close();
}).on("close", () => {
	solution();
	process.exit();
});

const solution = () => {
	let sum = input.reduce((total, e) => total + Math.pow(e, 2), 0);
	console.log(sum % 10);
};
