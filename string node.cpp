#include <iostream>
#include <queue>
using namespace std;

struct Node {
    string data;
    Node* left;
    Node* right;
};

Node* root = nullptr, *n = nullptr, *temp = nullptr;
Node* createNode(string data) {
    n = new Node;
    n->data = data;
    n->left = nullptr;
    n->right = nullptr;
    return n;
}
void insert(Node*& root, string data) {
    if (root == nullptr) {
        root = createNode(data);
    } else if (data <= root->data) {
        insert(root->left, data);
    } else {
        insert(root->right, data);
    }
}
Node *cariMin(Node *root){ 
	if (root==NULL) 
		return NULL; 
	while(root->left != NULL) 
		root = root->left; 
	return root; 
}
bool pencarian(Node* root, string data) {
    if (root == nullptr)
        return false;
    else if (data < root->data)
        return pencarian(root->left, data);
    else if (data > root->data)
        return pencarian(root->right, data);
    else
        return true;
}
void hapus(Node*& root, string data) {
    if (root == nullptr)
        return;
    else if (data < root->data)
        hapus(root->left, data);
    else if (data > root->data)
        hapus(root->right, data);
    else {
        if (root->left == nullptr && root->right == nullptr) {
            delete(root);
            root = nullptr;
        }
        else if (root->left == nullptr) {
            temp = root;
            root = root->right;
            delete(temp);
            temp = nullptr;
        }
        else if (root->right == nullptr) {
            temp = root;
            root = root->left;
            delete(temp);
            temp = nullptr;
        }
        else {
            temp = cariMin(root->right);
            root->data = temp->data;
            hapus(root->right, temp->data);
        }
    }
}
void Order(Node* root) {
    if (root == nullptr) return;
    Order(root->left);
    cout << root->data << ", ";
    Order(root->right);
}
void OrderDsc(Node* root) {
    if (root == nullptr) return;
    OrderDsc(root->right);
    cout << root->data << ", ";
    OrderDsc(root->left);
}
void levelOrder(Node *root){ 
	if (root==NULL) return; 
		queue<Node*> q; 
	q.push(root); 
	while(!q.empty()){ 
		cout << q.front()->data << ", "; 
		if(q.front()->left != NULL) 
			q.push(q.front()->left); 
		if(q.front()->right != NULL) 
			q.push(q.front()->right); 
		q.pop(); 
	} 
}
void preOrder(Node *root){ 
	if (root==NULL) return; 
	cout << root->data << ", "; 
	preOrder(root->left); 
	preOrder(root->right); 
}
void postOrder(Node *root){ 
	if (root==NULL) return; 
	postOrder(root->left); 
	postOrder(root->right); 
	cout << root->data << ", "; 
}

void ui();
void subUi();
int main() {
	Node node;
	int choice,ops;
	string data;
	while(choice!=5){
		ops=0;
		ui();cin>>choice;
		cin.clear();
		cin.ignore();
		system("cls");
		switch(choice){
			case 1:{
				cout<<"Masukkan Nilai : ";getline(cin,data);
				insert(*&root, data);
				cout<<"Data dengan nilai "<<data<<" berhasil di tambahkan.\n";
				system("pause");
				break;
			}
			case 2:{
				if(root==NULL){
					cout<<"Node masi Kosong\n";
				}else{
					cout<<"Masukkan Data yang akan di hapus: ";getline(cin,data);
					if(pencarian(root,data)==true){
						hapus(root,data);
						cout<<"Data dengan nilai "<<data<<" berhasil dihapus\n";
					}else{
						cout<<"data dengan nilai "<<data<<" tidak ditemukan\n";
					}
				}
				system("pause");
				break;
			}
			case 3:{
				if(root==NULL){
					cout<<"Node masi Kosong\n";
				}else{
					cout<<"Masukkan Nilai yang akan dicari: ";getline(cin,data);
					if(pencarian(root,data)==true)
						cout<<"data dengan nilai "<<data<<" berhasil ditemukan\n";
					else
						cout<<"data dengan nilai "<<data<<" tidak ditemukan\n";
				}
				system("pause");
				break;
			}
			case 4:{
				if(root==NULL){
					system("cls");
					cout<<"Node masi Kosong\n";
					system("pause");
				}else{
					while(ops!=6){
						subUi();cin>>ops;
						cin.clear();
						cin.ignore();
						system("cls");
						switch(ops){
							case 1:{
								cout<<"Level Order Traversal\n";
								levelOrder(root);
								cout<<endl;
								system("pause");
								break;
							}
							case 2:{
								cout<<"PreOrder Traversal\n";
								preOrder(root);
								cout<<endl;
								system("pause");
								break;
							}
							case 3:{
								cout<<"InOrder Traversal (ASC)\n";
								Order(root);
								cout<<endl;
								system("pause");
								break;
							}
							case 4:{
								cout<<"InOrder Traversal (DSC)\n";
								OrderDsc(root);
								cout<<endl;
								system("pause");
								break;
							}
							case 5:{
								cout<<"PostOrder Traversal\n";
								postOrder(root);
								cout<<endl;
								system("pause");
								break;
							}
							case 6:
								cout<<"Keluar...\n";
							default:
								cout<<"Inputan tidak valid...\n";
								system("pause");
						}
					}			
				}
				break;
			}
			case 5:{
				cout<<"Keluar...\n";
				break;
			}
			default:
				cout<<"Inputan tidak valid...\n";
				system("pause");
		} 
	}  
}   
void ui(){
	system("cls");
	cout<<"Menu Binary Search Tree\n";
	cout<<"1. Insert Node\n";
	cout<<"2. Hapus Data\n";
	cout<<"3. Cari Data\n";
	cout<<"4. Traversal\n";
	cout<<"5. Keluar\n";
	cout<<"Masukkan Pilihan [1..5]: ";
}
void subUi(){
	system("cls");
	cout<<"pilih jenis traversal\n";
	cout<<"1. Level Order Traversal\n";
	cout<<"2. PreeOrder Traversal\n";
	cout<<"3. InOrder Traversal (ASC)\n";
	cout<<"4. InOrder Traversal (DSC)\n";
	cout<<"5. PostOrder Traversal\n";
	cout<<"6. Batal\n";
	cout<<"Masukkan Pilihan [1..6]: ";
}