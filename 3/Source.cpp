//#include <iostream>
//#include <string>
//#include <sstream>
//
//using namespace std;
//
//struct node {
//	float heso = 0;
//	int mu = 0;
//	node *next = NULL;
//};
//
//node* ConvertToLinkedList(int *arr, int size) {
//	node *head = NULL;
//	node *pre = NULL;
//	for (int i = 0; i < size; i++) {
//		node *cur = new node;
//		cur->heso = arr[i];
//		if (i == 0) {
//			head = cur;
//			pre = head;
//		}
//
//		else {
//			pre->next = cur;
//			pre = cur;
//		}
//		if (i == size - 1)
//			cur->next = NULL;
//	}
//	return head;
//}
//
//void addNode(node *&head, float hesoIn, int muIn) {
//	node *temp = head;
//	node *pnew = new node;
//	if (head == NULL) {
//		pnew->next = NULL;
//		pnew->heso = hesoIn;
//		pnew->mu = muIn;
//		head = pnew;
//		return;
//	}
//	while (temp != NULL) {
//		if (temp->next == NULL) {
//			temp->next = pnew;
//			pnew->heso = hesoIn;
//			pnew->mu = muIn;
//			pnew->next = NULL;
//			return;
//		}
//		temp = temp->next;
//	}
//
//}
//
//
//void printPoly(node *llist) {
//	node *temp = llist;
//	if (temp == NULL)cout << "da thuc 0" << endl;
//	else {
//		while (temp != NULL) {
//			if (temp == llist) {
//				cout << temp->heso << "x^" << temp->mu;
//			}
//			else if (temp->mu == 1) {
//				cout << "+" << temp->heso << "x";
//			}
//			else if (temp->mu == 0) {
//				cout << "+" << temp->heso;
//			}
//			else
//				cout << "+" << temp->heso << "x^" << temp->mu;
//
//			temp = temp->next;
//		}
//	}
//	cout << endl;
//}
//
//node *addPoly(node *poly1, node *poly2) {
//	node *temp1 = poly1, *temp2 = poly2;
//	node *resHead = NULL, *pre = NULL;
//	int i = 0;
//	while (temp1 != NULL || temp2 != NULL) {
//		node *cur = new node;
//		int a = 0, b = 0;
//		if (temp1 == NULL) {//truong hop poly1 ngan hon
//			cur->heso = temp2->heso;
//			temp2 = temp2->next;
//		}
//		else if (temp2 == NULL) {//truong hop poly2 ngan hon
//			cur->heso = temp1->heso;
//			temp1 = temp1->next;
//		}
//		else {//poyly1+poyly2
//			cur->heso = temp1->heso + temp2->heso;
//			temp1 = temp1->next;
//			temp2 = temp2->next;
//		}
//		if (i == 0) {//cap phat cho poly ket qua
//			resHead = cur;
//			pre = resHead;
//		}
//		else {
//			pre->next = cur;
//			pre = cur;
//		}
//		i++;
//	}
//	return resHead;
//}
//
//node *mulPoly(node *poly1, node *poly2) {
//
//	node *temp1 = poly1, *temp2 = poly2;
//	int count1 = 0, count2 = 0, bac = 0;
//	while (temp1 != NULL) {
//		count1++;
//		temp1 = temp1->next;
//	}
//	while (temp2 != NULL) {
//		count2++;
//		temp2 = temp2->next;
//	}
//	bac = count1 + count2 - 2;
//	temp1 = poly1;
//	temp2 = poly2;
//	int *res = new int[bac + 1];//da thuc bac  0 1 2 3 ...
//	for (int i = 0; i < bac + 1; i++) res[i] = 0;//gan array = 0
//
//	for (int i = 0; i < count1; i++) {
//		for (int j = 0; j < count2; j++) {
//			res[i + j] += temp1->heso*temp2->heso;
//			temp2 = temp2->next;
//		}
//		temp2 = poly2;
//		temp1 = temp1->next;
//	}
//
//	return ConvertToLinkedList(res, bac + 1);
//}
//
//
//void inputPoly(node *&poly, string input1) {
//
//	char x, mu;
//	float hesoIn = 0;
//	int muIn = 0;
//	string token = "";
//	size_t pos = 0, prepos = 0;
//	for (int i = 1; i < input1.size(); i++) {
//
//		if (input1[i] == '+' || input1[i] == '-' ||
//			input1[i] == ' ' || i == input1.size() - 1) {
//			pos = i;
//			token = input1.substr(prepos, pos - prepos + 1);
//			stringstream scin(token);
//			scin >> hesoIn >> x >> mu >> muIn;
//			addNode(poly, hesoIn, muIn);
//			prepos = pos;
//		}
//
//	}
//
//}
//
//int main() {
//	string a, b;
//	int n;
//	cout << "  ...";
//	
//	getline(cin, a);
//
//	cout << " n ";
//	cin >> n;
//
//	cin.ignore(256, '\n');
//
//	cout << "b ";
//	getline(cin, b);
//	cout << "0000" << endl;
//	cout << a << endl << b;
//	system("pause");
//}