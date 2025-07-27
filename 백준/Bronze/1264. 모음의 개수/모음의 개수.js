const readline = require("readline");
const rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout,
});

let input = [];

rl.on("line", (line) => {
	input.push(line);
	if (input[input.length - 1] === "#") rl.close();
}).on("close", () => {
	input = input.slice(0, input.length - 1);
	input.forEach((e) => solution(e));
	process.exit();
});

const solution = (str) => {
	let cnt = 0;
	for (let i = 0; i < str.length; i++) {
		const c = str.charAt(i);
		if (
			c == "a" ||
			c == "e" ||
			c == "i" ||
			c == "o" ||
			c == "u" ||
			c == "A" ||
			c == "E" ||
			c == "I" ||
			c == "O" ||
			c == "U"
		)
			cnt++;
	}
	console.log(cnt);
};
