const readline = require("readline");
const rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout,
});

let n = 0;

rl.on("line", (line) => {
	n = parseInt(line);
	rl.close();
}).on("close", () => {
	let fiveCnt = 0;
	let twoCnt = 0;
	for (let i = 2; i <= n; i++) {
		let iFive = i,
			iTwo = i;
		while (iFive >= 1) {
			if (iFive % 5 !== 0) break;
			fiveCnt++;
			iFive /= 5;
		}
		while (iTwo >= 1) {
			if (iTwo % 2 !== 0) break;
			twoCnt++;
			iTwo /= 2;
		}
		twoCnt += Math.floor(i / 2);
		// console.log(i, fiveCnt, twoCnt);
	}
	const zeroCnt = Math.min(fiveCnt, twoCnt);
	console.log(zeroCnt);
	process.exit();
});
