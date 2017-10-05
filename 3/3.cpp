#include <iostream>
#include <string>
#include <sstream>
#include <math.h>

using namespace std;

struct node {
	float heso = 0;
	int mu = 0;
	node *next = NULL;
};

struct polyNode {
	node *poly = NULL;
	polyNode *next = NULL;
};

int sizeNode(node* head) {
	int size = 0;
	while (1)
	{
		if (head == NULL) break;
		size++;
		head = head->next;
	}
	return size;
}

node* ConvertToLinkedList(float *arr, int size) {
	node *head = NULL;
	node *pre = NULL;
	for (int i = size - 1 ; i >= 0; i--) {
		node *cur = new node;
		cur->heso = arr[i];
		cur->mu = i;
		if (i == size - 1 ) {
			head = cur;
			pre = head;
		}

		else {
			pre->next = cur;
			pre = cur;
		}
		if (i == size - 1)
			cur->next = NULL;
	}
	return head;
}

void addNode(node *&head, float hesoIn, int muIn) {
	node *temp = head;
	node *pnew = new node;
	if (head == NULL) {
		pnew->next = NULL;
		pnew->heso = hesoIn;
		pnew->mu = muIn;
		head = pnew;
		return;
	}
	while (temp != NULL) {
		if (temp->next == NULL) {
			temp->next = pnew;
			pnew->heso = hesoIn;
			pnew->mu = muIn;
			pnew->next = NULL;
			return;
		}	
		temp = temp->next;
	}
	
}

void addPolyNode(polyNode *&head, polyNode *polyIn) {
	polyNode *temp = head;
	polyNode *pnew = new polyNode;
	if (head == NULL) {
		pnew->next = NULL;
		pnew->poly = polyIn->poly;
		
		head = pnew;
		return;
	}
	while (temp != NULL) {
		if (temp->next == NULL) {
			temp->next = pnew;
			pnew->poly = polyIn->poly;
			pnew->next = NULL;
			return;
		}
		temp = temp->next;
	}

}

void printPoly(node *llist) {
	cout << endl;
	node *temp = llist;
	if (temp == NULL)
		cout << "da thuc 0" << endl;
	else {
		while (temp != NULL) {	
			if (temp == llist) {// so hang dau tien cua da thuc
				if (temp->heso == 1) {
					cout << "x^" << temp->mu;
					if (temp->mu == 1)
						cout << temp->heso << "x";
					else if (temp->mu == 0)
						cout << temp->heso;
				}
				else if (temp->mu == 1)
					cout << temp->heso << "x";
				else
					cout << temp->heso << "x^" << temp->mu;
			}

			else if (temp->heso == 0);

			else if (temp->heso == 1) {
				
				if (temp->mu == 1) {
					cout << " + " << "x";
				}
				else if (temp->mu == 0) {
					cout << " + " << temp->heso;
				}
				else 
					cout << " + " << "x^" << temp->mu;
			}
			else if (temp->mu == 1) {
				cout << " + " << temp->heso << "x";
			}
			else if (temp->mu == 0) {
				cout << " + " << temp->heso;
			}
			else 
				cout << " + " << temp->heso << "x^" << temp->mu;
			
			temp = temp->next;
		}
	}
	cout << endl << endl;
}

node *addPoly(node *poly1, node *poly2) {
	node *temp1 = poly1, *temp2 = poly2;
	node *pre = NULL;
	int i = 0;
	node *headRes = new node;
	
	if (temp1->mu > temp2->mu ) {
		headRes->heso = temp1->heso;
		headRes->mu = temp1->mu;
	}
	else if (temp1->mu < temp2->mu) {
		headRes->heso = temp2->heso;
		headRes->mu = temp2->mu;
	}
	else {
		headRes->heso = temp2->heso + temp1->heso;
		headRes->mu = temp2->mu;
	}
	int maxMu = headRes->mu;
	for (int i = maxMu - 1; i >= 0; i--) {
		node *cur = new node;
		cur->mu = i;

		while (temp1 != NULL) { // duyet linkedList1 tim so hang co bac cua cur.
			if (temp1->mu == cur->mu) {
				cur->heso += temp1->heso;
				break;
			}
			temp1 = temp1->next;	
		}
		while (temp2 != NULL) { // duyet linkedList2 tim so hang co bac cua cur.
			if (temp2->mu == cur->mu) {
				cur->heso += temp2->heso;
				break;
			}
			temp2 = temp2->next;
		}
		temp1 = poly1; //khoi phuc vi tri con tro temp1 temp2
		temp2 = poly2;

		if (i == maxMu - 1) {
			headRes->next = cur;
			pre = cur;
		}
		else {
			pre->next = cur;
			pre = cur;
		}

	} 
	return headRes;
}


node *subPoly(node *poly1, node *poly2) {
	node* temp = NULL, *result = NULL;
	while (1)
	{
		if (poly2 == NULL) break;
		addNode(temp, poly2->heso *(-1), poly2->mu);
		poly2 = poly2->next;
	}
	temp = addPoly(poly1, temp);
	while (1)
	{
		if (temp == NULL) break;
		if (temp->heso == 0) {
			temp = temp->next;
			continue;
		}
		addNode(result, temp->heso, temp->mu);
		temp = temp->next;
	}
	return result;
}

node *mulPoly(node *poly1, node *poly2) {

	node *temp1 = poly1, *temp2 = poly2;

	int bac = poly1->mu + poly2->mu;

	float *res = new float[bac + 1];//da thuc bac  0 1 2 3 ...
	for (int i = 0; i < bac + 1; i++) res[i] = 0;//gan array = 0
	
	for (int i = poly1->mu; i >= 0; i--) {
		for (int j = poly2->mu; j >= 0; j--) {
			float tich1 = 0, tich2 = 0;

			while (temp1 != NULL) {
				if (temp1->mu == i) {
					tich1 = temp1->heso;
					break;
				}
				temp1 = temp1->next;
			}
			while (temp2 != NULL) {
				if (temp2->mu == j) {
					tich2 = temp2->heso;
					break;
				}
				temp2 = temp2->next;
			}
			temp1 = poly1;//khoi phuc vi tri con tro
			temp2 = poly2;

			res[i + j] += tich1 * tich2;
			
		}
	}
	return ConvertToLinkedList(res, bac + 1);
}

node *divPoly(node *poly1, node *poly2) {
	node *result = NULL, *temp1 = poly1, *temp2 = poly2;

	if (sizeNode(temp1) < 2) {
		if (temp1->mu >= temp2->mu) {
			addNode(result, temp1->heso / poly2->heso, temp1->mu - poly2->mu);
			temp1 = subPoly(temp1, mulPoly(result, temp2));
		}
		else {
			addNode(result, 0, 0);
		}
	}
	else {
		while (true)
		{
			if (temp1->mu >= poly2->mu) {
				addNode(result, temp1->heso / poly2->heso, temp1->mu - poly2->mu);
				if (sizeNode(result) < 2)
					temp2 = result;
				else {
					temp2 = result;
					for (int k = 1; k != sizeNode(result); k++)
					{
						temp2 = temp2->next;

					}
				}
				//printPoly(temp1);
				//printPoly(mulPoly(temp2, poly2));
				temp1 = subPoly(temp1, mulPoly(poly2, temp2));
				//printPoly(temp1);
				if (temp1 == NULL) break;
			}
			else break;
		}

	}
	return result;
}

// scan input1 from console (string) to the polynomial 
void inputPoly(node *&poly, string input1) {
	
	char x, mu;
	float hesoIn = 0;
	int muIn = 0;
	string token = "";
	size_t pos = 0, prepos = 0;
	for (int i = 0; i < input1.size(); i++) {

		if (input1[i] == '+' || input1[i] == '-' ||
			input1[i] == ' ' || i == input1.size() - 1) {
			pos = i;
			if (i == input1.size() - 1) {
				pos++;
			}
			token = input1.substr(prepos, pos - prepos );
			stringstream scin(token);

			if (token.substr(0, 1) == "x" || token.find("+x") < 999 ||
				token.find("-x") < 999) {//truong hop k co he so truoc x

				if (token.find('^') > 999) {
					muIn = 1;
					hesoIn = 1;
				}
				
				else if (token.find("+x") < 999 || token.find("-x") < 999) {
					token = token.substr(1, token.size() - 1);
					stringstream scin1(token);
					hesoIn = 1;
					scin1 >> x >> mu >> muIn;
				}
				else {
					hesoIn = 1;
					scin >> x >> mu >> muIn;
				}
			}
			else if (token.find('^') > 999) {
				if (token.find('x') > 999) {
					scin >> hesoIn;
					muIn = 0;
				}
				else {
					scin >> hesoIn;
					muIn = 1;
				}
				
			}
			
			else
				scin >> hesoIn >> x >> mu >> muIn;
			//cin.ignore(256, '\n'); x^4+3x^3+1
		
			addNode(poly, hesoIn, muIn);
			prepos = pos;
		}

	}
	
}

//search the poly correspond to the num which is inputed
node *findNumPoly(polyNode *polyHead, int num) {
	polyNode *temp = polyHead;
	int i = 1;
	while (temp != NULL) {
		if (num == i)
			return temp->poly;
		temp = temp->next;
		i++;
	}
}

int main() {
	polyNode *poly = NULL;
	string input1 = "", input2 = "";
	char ans;
	cout << "\t Start to input polynomial \n" << endl;
	int i = 0;
	do {
		polyNode *newPolyNode = new polyNode;
		cout << "input polynomial P" << ++i << " (no space): ";
		
		cin >> input1;
		//cin.ignore(256, '\n');
		
		inputPoly(newPolyNode->poly, input1);//set data for newPolyNode
		addPolyNode(poly, newPolyNode);//concate newPolyNode in polyNode linkedList

		cout << "continue input polynomial or not? (Y / N) ";
		cin >> ans;
		cin.ignore(256, '\n');
		if (ans == 'n' || ans == 'N') break;
	} while (ans == 'y' || ans == 'Y');

	cout << endl;
	cout << "\t Stop input polynomial \n" << endl << endl;
	
	do {
		char P1 = '\0', P2 = '\0';
		int numPolyA = -1, numPolyB = -1;
		string operatorIn;
		cout << "Perform math operations: (Pi add/sub/mul/div Pj)" << endl;
		getline(cin, input2);
		stringstream ss(input2);
		ss >> P1 >> numPolyA >> operatorIn >> P2 >> numPolyB;
		//cin.ignore(256, '\n');

		if (operatorIn == "add" || operatorIn == "Add" || operatorIn == "ADD" || operatorIn == "+") {
			if (P2 != 'P' && P2 != 'p') {
				node *polyA = findNumPoly(poly, numPolyA);
				int num = P2 - 48;

				if (numPolyB != - 1) {
					int f = log10(numPolyB) ;//so chu so cua numPolyB
					int x = 10;
					for (int i = 0; i < f; i++) x *= 10;
					num *= x;
					num += numPolyB;
				}
					
				node *polyNew = new node;
				polyNew->heso = num;
				polyNew->mu = 0;
				polyNew->next = NULL;
				printPoly(addPoly(polyA, polyNew));
			}

			else if (P1 != 'P' && P1 != 'p') {
				node *polyB = findNumPoly(poly, numPolyB);
				int num = P1 - 48;

				if (numPolyA != -1) {
					int f = log10(numPolyA);//so chu so cua numPolyB
					int x = 10;
					for (int i = 0; i < f; i++) x *= 10;
					num *= x;
					num += numPolyA;
				}

				node *polyNew = new node;
				polyNew->heso = num;
				polyNew->mu = 0;
				polyNew->next = NULL;
				printPoly(addPoly(polyNew, polyB));
			}
			else {
				node *polyA = findNumPoly(poly, numPolyA);
				node *polyB = findNumPoly(poly, numPolyB);
				printPoly(addPoly(polyA, polyB));
			}

		}

		else if (operatorIn == "sub" || operatorIn == "Sub" || operatorIn == "SUB" || operatorIn == "-") {
			if (P2 != 'P' && P2 != 'p') {
				node *polyA = findNumPoly(poly, numPolyA);
				int num = P2 - 48;

				if (numPolyB != -1) {
					int f = log10(numPolyB);//so chu so cua numPolyB
					int x = 10;
					for (int i = 0; i < f; i++) x *= 10;
					num *= x;
					num += numPolyB;
				}

				node *polyNew = new node;
				polyNew->heso = num;
				polyNew->mu = 0;
				polyNew->next = NULL;
				printPoly(subPoly(polyA, polyNew));
			}

			else if (P1 != 'P' && P1 != 'p') {
				node *polyB = findNumPoly(poly, numPolyB);
				int num = P1 - 48;

				if (numPolyA != -1) {
					int f = log10(numPolyA);//so chu so cua numPolyB
					int x = 10;
					for (int i = 0; i < f; i++) x *= 10;
					num *= x;
					num += numPolyA;
				}

				node *polyNew = new node;
				polyNew->heso = num;
				polyNew->mu = 0;
				polyNew->next = NULL;
				printPoly(subPoly(polyNew, polyB));
			}
			else {
				node *polyA = findNumPoly(poly, numPolyA);
				node *polyB = findNumPoly(poly, numPolyB);
				printPoly(subPoly(polyA, polyB));
			}
		}

		else if (operatorIn == "mul" || operatorIn == "Mul" || operatorIn == "MUL" || operatorIn == "*") {
			if (P2 != 'P' && P2 != 'p') {
				node *polyA = findNumPoly(poly, numPolyA);
				int num = P2 - 48;

				if (numPolyB != -1) {
					int f = log10(numPolyB);//so chu so cua numPolyB
					int x = 10;
					for (int i = 0; i < f; i++) x *= 10;
					num *= x;
					num += numPolyB;
				}

				node *polyNew = new node;
				polyNew->heso = num;
				polyNew->mu = 0;
				polyNew->next = NULL;
				printPoly(mulPoly(polyA, polyNew));
			}

			else if (P1 != 'P' && P1 != 'p') {
				node *polyB = findNumPoly(poly, numPolyB);
				int num = P1 - 48;

				if (numPolyA != -1) {
					int f = log10(numPolyA);//so chu so cua numPolyB
					int x = 10;
					for (int i = 0; i < f; i++) x *= 10;
					num *= x;
					num += numPolyA;
				}

				node *polyNew = new node;
				polyNew->heso = num;
				polyNew->mu = 0;
				polyNew->next = NULL;
				printPoly(mulPoly(polyNew, polyB));
			}
			else {
				node *polyA = findNumPoly(poly, numPolyA);
				node *polyB = findNumPoly(poly, numPolyB);
				printPoly(mulPoly(polyA, polyB));
			}	
		}

		else if (operatorIn == "div" || operatorIn == "Div" || operatorIn == "DIV" || operatorIn == "/") {
			if (P2 != 'P' && P2 != 'p') {
				node *polyA = findNumPoly(poly, numPolyA);
				int num = P2 - 48;

				if (numPolyB != -1) {
					int f = log10(numPolyB);//so chu so cua numPolyB
					int x = 10;
					for (int i = 0; i < f; i++) x *= 10;
					num *= x;
					num += numPolyB;
				}

				node *polyNew = new node;
				polyNew->heso = num;
				polyNew->mu = 0;
				polyNew->next = NULL;
				printPoly(divPoly(polyA, polyNew));
			}

			else if (P1 != 'P' && P1 != 'p') {
				node *polyB = findNumPoly(poly, numPolyB);
				int num = P1 - 48;

				if (numPolyA != -1) {
					int f = log10(numPolyA);//so chu so cua numPolyB
					int x = 10;
					for (int i = 0; i < f; i++) x *= 10;
					num *= x;
					num += numPolyA;
				}

				node *polyNew = new node;
				polyNew->heso = num;
				polyNew->mu = 0;
				polyNew->next = NULL;
				printPoly(divPoly(polyNew, polyB));
			}
			else {
				node *polyA = findNumPoly(poly, numPolyA);
				node *polyB = findNumPoly(poly, numPolyB);
				printPoly(divPoly(polyA, polyB));
			}
		}

		cout << "continue or not? ";
		cin >> ans;
		cin.ignore(256, '\n');
	} while (ans == 'y' || ans == 'Y');

	system("pause");
}