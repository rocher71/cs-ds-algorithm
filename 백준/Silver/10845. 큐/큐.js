class Queue {
	constructor() {
		this.arr = [];
		this.size = 0;
	}
	push(element) {
		this.arr[this.size++] = element;
	}
	pop() {
		if (this.size === 0) {
			result.push(-1);
			return;
		}
		result.push(this.arr[0]);
		this.arr = this.arr.slice(1);
		this.size--;
	}
	getSize() {
		result.push(this.size);
	}
	empty() {
		if (this.size === 0) result.push(1);
		else result.push(0);
	}
	front() {
		if (this.size === 0) result.push(-1);
		else result.push(this.arr[0]);
	}
	back() {
		if (this.size === 0) result.push(-1);
		else result.push(this.arr[this.size - 1]);
	}
}

const readline = require("readline");
const rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout,
});

let n = 0;
const result = [];
let q = new Queue();

rl.on("line", (line) => {
	if (n === 0) n = line;
	else {
		const cmd = line.split(" ");
		if (cmd[0] === "push") q.push(parseInt(cmd[1]));
		else if (cmd[0] === "pop") q.pop();
		else if (cmd[0] === "size") q.getSize();
		else if (cmd[0] === "empty") q.empty();
		else if (cmd[0] === "front") q.front();
		else if (cmd[0] === "back") q.back();
		n--;
	}
	if (n === 0) rl.close();
}).on("close", () => {
	console.log(result.join("\n"));
	process.exit();
});
