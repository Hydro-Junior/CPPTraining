#include <iostream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <climits>
using namespace std;
/**
	�����value�ľ���ֵ�ظ��˵Ľڵ㹹�����������������ڵ㹹����һ������
*/
struct Node {
	int addr;
	int val;
	int next_addr;
	Node *next;
	Node(int _address, int _val) :addr(_address), val(_val), next_addr(-1), next(NULL) {}
};
int main()
{
	//������
	unordered_map<int, Node*> addr_map;
	unordered_set<int> vals;
	int head_addr;
	int n;
	scanf("%d%d", &head_addr, &n);
	Node *head = NULL;
	Node *out = new Node(INT_MIN, INT_MAX);//DUMMY
	//�������ݲ�����address->node ��ӳ��
	for (int i = 0; i < n; i++) {
		int address;
		int value;
		int next_address;
		scanf("%d%d%d", &address, &value, &next_address);
		Node *nNode = new Node(address, value);
		nNode->next_addr = next_address;
		if (address == head_addr)head = nNode;
		addr_map.insert({ address, nNode});
	}
	//��������
	Node *cur = head, *inCur = head, *outCur = out;
	vals.insert(abs(cur->val));
	do {
        if(!cur) break;
		Node *next = addr_map[cur->next_addr];
		if(!next) break;
		if (vals.find(abs(next->val)) == vals.end()) {//������
			vals.insert(abs(next->val));
			inCur->next = next;
			inCur = inCur->next;
			cur = inCur;
		}
		else {
			outCur->next = next;
			outCur = outCur->next;
			cur = outCur;
		}
	} while (cur->next_addr != -1);
	while (head && head->next) {
		printf("%05d %d %05d\n", head->addr, head->val, head->next->addr);
		head = head->next;
	}
	if(head) printf("%05d %d %d\n", head->addr, head->val, -1);
	out = out->next;
	while (out && out->next) {
		printf("%05d %d %05d\n", out->addr, out->val, out->next->addr);
		out = out->next;
	}
	if(out)printf("%05d %d %d\n", out->addr, out->val, -1);
	return 0;
}
