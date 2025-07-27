const readline = require("readline");
const rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout,
});

const arr = [500, 100, 50, 10, 5, 1];

rl.on("line", (line) => {
	let num = parseInt(1000 - line);
	let ans = 0;
	arr.forEach((e) => {
		ans += Math.floor(num / e);
		num = num % e;
	});
	console.log(ans);
	rl.close();
}).on("close", () => process.exit());
