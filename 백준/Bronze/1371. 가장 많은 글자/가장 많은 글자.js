const readline = require("readline");
const rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout,
});

const cntMap = new Map();
for (let i = 0; i < 26; i++) {
	cntMap.set(String.fromCharCode(i + "a".charCodeAt(0)), 0);
}

rl.on("line", (line) => {
	solution(line);
}).on("close", () => {
	let maxCnt = Math.max(...cntMap.values());
	const ans = [...cntMap.entries()]
		.filter(([_, count]) => count === maxCnt)
		.map(([char]) => char)
		.sort()
		.join("");
	console.log(ans);
});

const solution = (str) => {
	str = str.toLowerCase();
	for (const c of str) {
		if (c < "a" || c > "z") continue;
		cntMap.set(c, (cntMap.get(c) || 0) + 1);
	}
};
