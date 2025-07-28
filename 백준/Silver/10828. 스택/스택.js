class Stack {
	constructor() {
		this.arr = [];
		this.size = 0;
	}
	push(element) {
		this.arr[this.size++] = element;
	}
	pop() {
		if (this.size <= 0) result.push(-1);
		else result.push(this.arr[--this.size]);
	}
	getSize() {
		result.push(this.size);
	}
	top() {
		if (this.size <= 0) result.push(-1);
		else result.push(this.arr[this.size - 1]);
	}
	empty() {
		if (this.size == 0) result.push(1);
		else result.push(0);
	}
}

const readline = require("readline");
const rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout,
});

let n = 0;
let st = new Stack();
const result = [];

rl.on("line", (line) => {
	if (n == 0) n = line;
	else {
		n--;
		let cmd = line.split(" ");
		if (cmd[0] === "push") st.push(parseInt(cmd[1]));
		else if (cmd[0] === "top") st.top();
		else if (cmd[0] === "size") st.getSize();
		else if (cmd[0] === "empty") st.empty();
		else if (cmd[0] === "pop") st.pop();
	}
	if (n == 0) rl.close();
}).on("close", () => {
	console.log(result.join("\n"));
	process.exit();
});
