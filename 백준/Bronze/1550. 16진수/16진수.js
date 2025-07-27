const readline = require("readline");
const rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout,
});

let input = "";
let chars = [];
const conv = [10, 11, 12, 13, 14, 15];

rl.on("line", (line) => {
	chars = line.split("");
	rl.close();
}).on("close", () => {
	const ans = solution();
	console.log(ans);
	process.exit();
});

const solution = () => {
	let mult = chars.length - 1;
	return chars.reduce((total, e) => {
		const dec = charToDec(e);
		// console.log(e, mult, total, dec);
		return total + Math.pow(16, mult--) * dec;
	}, 0);
};

const charToDec = (a) => {
	if (a >= "0" && a <= "9") return parseInt(a);
	else return conv[a.charCodeAt(0) - "A".charCodeAt(0)];
};
