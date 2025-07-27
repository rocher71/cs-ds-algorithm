const readline = require("readline");
const rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout,
});

let input = [];

rl.on("line", (line) => {
	input.push(line);
	if (line == "0") rl.close();
}).on("close", () => {
	input = input.slice(0, input.length - 1);
	input.forEach((e) => solution(e));
	process.exit();
});

const solution = (str) => {
	for (let i = 0; i < str.length; i++) {
		if (str[i] === str[str.length - i - 1]) continue;
		console.log("no");
		return;
	}
	console.log("yes");
};
