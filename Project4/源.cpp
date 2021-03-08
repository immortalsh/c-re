#include<iostream>
using namespace std;


template<class elemType>
class linkQueue {
private:
	struct node {
		node* next;
		elemType data;
		node(const elemType& x, node* N = NULL) {
			data = x;
			next = N;
		}
		node() {
			next = NULL;
		}
		~node() {}
	};
	node* front, * rear;
public:
	linkQueue() {
		front = rear = NULL;
	};
	~linkQueue() {
		node* tmp;
		while (front != NULL) {
			tmp = front;
			front = tmp->next;
			delete tmp;
		}
	};
	bool isEmpty()const {
		return front == NULL;
	}
	void enQueue(const elemType& x) {
		if (rear == NULL)
			front = rear = new node(x);
		else {
			rear = rear->next = new node(x);
		}
	}
	elemType deQueue() {
		node* tmp = front;
		front = front->next;
		elemType elem = tmp->data;
		if (front == NULL)rear = NULL;
		delete tmp;
		return elem;
	}
};


class childLine {
private:
	struct Node {
		int P;
		int Q;
		int V;
		Node(int p = 0, int q = 0, int v = 0) {
			P = p;
			Q = q;
			V = v;
		}
		~Node() {}
	};
	int root;
	Node* line;
	int N = 100000;
	void preOrder(int i) {
		cout << line[i].V << ' ';              //输出根节点
		int tmp = line[i].P - 1;
		while (tmp >= 0) {                 //输出所有的孩子节点
			preOrder(tmp);
			tmp = line[tmp].Q - 1;
		}
	}
	void postOrder(int i) {
		int tmp = line[i].P - 1;
		while (tmp >= 0) {                 //输出所有的孩子节点
			postOrder(tmp);
			tmp = line[tmp].Q - 1;
		}
		cout << line[i].V << ' ';              //输出根节点
	}
public:
	childLine(int n = 0) {
		if (n < 100000)
			if (n > -1) {
				line = new Node[n];
				N = n;
			}
	}
	~childLine() {
		delete[] line;
	};
	void creatTree() {
		int i = 0;
		int* test = new int[N];
		for (int i = 1; i <= N; i++)
			test[i - 1] = i;
		while (i < N) {
			int p, q, v, m = 2147483648;
			cin >> p >> q >> v;
			if ((q <= N) && (p <= N) && (v <= 2147483647))
				if ((q >= 0) && (p >= 0) && (v >= -m)) {
					line[i] = Node(p, q, v);
					i++;
					for (int j = 0; j < N; ++j)
						if (test[j] == p || test[j] == q)
							test[j] = 0;
				}
		}
		for (int j = 0; j < N; ++j)
			if (test[j] != 0)
				root = j;
	}
	void preOrder() {
		preOrder(root);
		cout << endl;
	}
	void postOrder() {
		postOrder(root);
		cout << endl;
	}
	void levelOrder() {
		linkQueue<int>que;
		int tmp, a;
		que.enQueue(root);

		while (!que.isEmpty()) {
			a = que.deQueue();
			tmp = line[a].V;
			cout << tmp << ' ';
			if (line[a].P >= 1) {
				a = line[a].P - 1;
				que.enQueue(a);
				int temp;
				while (line[a].Q > 1) {
					temp = line[a].Q - 1;
					que.enQueue(temp);
					a = temp;
				}
			}
		}

	}
};

int main() {
	int n;
	cin >> n;
	childLine line(n);
	line.creatTree();
	line.preOrder();
	line.postOrder();
	line.levelOrder();
	return 0;
}