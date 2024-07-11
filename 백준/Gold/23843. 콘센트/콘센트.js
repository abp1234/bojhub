const { reverse } = require('dns');
const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let input = [];
let N, M;

rl.on('line', function(line) {
    input.push(line);
    if (input.length === 2) {
        rl.close();
    }
}).on('close', function() {
    [N, M] = input[0].split(' ').map(Number);
    let chargingTimes = input[1].split(' ').map(Number);

    // Extract k values from 2^k times
    //let kValues = chargingTimes.map(t => Math.log2(t));
    chargingTimes.sort((a, b) => b - a);
    // MinHeap implementation
    class MinHeap {
        constructor() {
            this.heap = [];
        }

        insert(value) {
            this.heap.push(value);
            this.bubbleUp();
        }

        bubbleUp() {
            let index = this.heap.length - 1;
            while (index > 0) {
                let element = this.heap[index];
                let parentIndex = Math.floor((index - 1) / 2);
                let parent = this.heap[parentIndex];
                if (parent <= element) break;
                this.heap[index] = parent;
                this.heap[parentIndex] = element;
                index = parentIndex;
            }
        }

        extractMin() {
            const min = this.heap[0];
            const end = this.heap.pop();
            if (this.heap.length > 0) {
                this.heap[0] = end;
                this.sinkDown(0);
            }
            return min;
        }

        sinkDown(index) {
            let length = this.heap.length;
            let element = this.heap[index];
            while (true) {
                let leftChildIndex = 2 * index + 1;
                let rightChildIndex = 2 * index + 2;
                let leftChild, rightChild;
                let swap = null;

                if (leftChildIndex < length) {
                    leftChild = this.heap[leftChildIndex];
                    if (leftChild < element) {
                        swap = leftChildIndex;
                    }
                }
                if (rightChildIndex < length) {
                    rightChild = this.heap[rightChildIndex];
                    if (
                        (swap === null && rightChild < element) ||
                        (swap !== null && rightChild < leftChild)
                    ) {
                        swap = rightChildIndex;
                    }
                }
                if (swap === null) break;
                this.heap[index] = this.heap[swap];
                this.heap[swap] = element;
                index = swap;
            }
        }

        size() {
            return this.heap.length;
        }

        getMin() {
            return this.heap[0];
        }
    }

    // Priority queue to manage machine workloads
    let pq = new MinHeap();

    // Initialize machines with zero work
    for (let i = 0; i < M; i++) {
        pq.insert(0);
    }

    // Assign tasks to machines
    for (let i = 0; i < N; i++) {
        let currentK = chargingTimes[i];
        let currentMinWorkload = pq.extractMin();
        pq.insert(currentMinWorkload + currentK);
    }

    // Find the maximum workload
    let maxWorkload = 0;
    while (pq.size() > 0) {
        maxWorkload = Math.max(maxWorkload, pq.extractMin());
    }

    console.log(maxWorkload);
    process.exit();
});
