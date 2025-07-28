const readline = require("readline");
const rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout,
});

class Queue {
	constructor() {
		this.arr = [];
		this.size = 0;
	}
	push(element) {
		this.arr[this.size++] = element;
	}
	pop() {
		if (this.size === 0) return;
		const front = this.arr[0];
		this.arr = this.arr.slice(1);
		this.size--;
		return front;
	}
	getSize() {
		return this.size;
	}
	empty() {
		if (this.size === 0) return true;
		else return false;
	}
}

let input = [];
const result = [];
let q = new Queue();

rl.on("line", (line) => {
	input = line.split(" ").map((e) => parseInt(e));
	rl.close();
}).on("close", () => {
	for (let i = 1; i <= input[0]; i++) q.push(i);

	while (!q.empty()) {
		for (let i = 0; i < input[1] - 1; i++) q.push(q.pop());
		result.push(q.pop());
	}
	console.log("<" + result.join(", ") + ">");
	process.exit();
});
