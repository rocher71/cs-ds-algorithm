const readline = require("readline");
const rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout,
});

const input = [];

rl.on("line", (line) => {
	input.push(Number(line));
	if (input.length === 2) rl.close();
}).on("close", () => {
	const quad = solution(input[0], input[1]);
	console.log(quad);
	process.exit();
});

const solution = (a, b) => {
	if (a > 0 && b > 0) return 1;
	else if (a < 0 && b > 0) return 2;
	else if (a < 0 && b < 0) return 3;
	else return 4;
};
