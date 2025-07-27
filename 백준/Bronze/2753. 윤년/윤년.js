const readline = require("readline");
const rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout,
});

rl.on("line", (line) => {
	const year = parseInt(line);
	// console.log(year % 400, year % 4, year % 100);
	if (year % 400 === 0) console.log(1);
	else if (year % 4 === 0 && year % 100 !== 0) console.log(1);
	else console.log(0);
	rl.close();
}).on("close", () => {
	process.exit();
});
