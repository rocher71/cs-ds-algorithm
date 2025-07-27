const readline = require("readline");
const rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout,
});

let ans = 0;

rl.on("line", (line) => {
	ans = line.trim().split(" ").length;
	if (line === " ") ans = 0;
	rl.close();
}).on("close", () => {
	console.log(ans);
	process.exit();
});
