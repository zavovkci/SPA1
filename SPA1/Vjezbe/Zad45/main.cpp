#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node(int d, Node* N): data(d), next(N){}
};

class Lista{
protected:
    Node* head{};
public:
    Lista(){}
    void push_front(int);
    void display();
    Node* search(int);
    bool erase(int);
    int size();
    void reverse();
    void prune();
    ~Lista();
};

void Lista::prune()
{
    if (head == NULL)
        return;
    Node *prev = head;
    Node *node = head->next;

    while (prev != NULL && node != NULL)
    {
        prev->next = node->next;

        free(node);

        prev = prev->next;
        if (prev != NULL)
            node = prev->next;
    }
}

void Lista::reverse()
{
    Node* curr = head;
    Node* next= nullptr;
    Node* prev= nullptr;
    while(curr!=nullptr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

int Lista::size()
{
    int brojac=0;
    Node* iter = head;
    while(iter!=nullptr){
        brojac++;
        iter=iter->next;
    }
    return brojac;
}

bool Lista::erase(int x){
    Node* iter = head;
    Node* prev = head;
    while(iter!=nullptr){
        if(iter->data == x){
            if(iter==head){
                head=iter->next;
            }
            else{
                prev->next = iter->next;
            }
            delete iter;
            return true;
        }
        prev = iter;
        iter = iter->next;
    }
    return false;
}

Node* Lista::search(int s){
    Node* iter=head;
    while(iter!=nullptr){
        if(iter->data==s)
            return iter;
        iter = iter->next;
    }
    return nullptr;
}

void Lista::push_front(int x){
    Node *data = new Node(x, head);
    head=data;
}

void Lista::display(){
    Node* iter = head;
    while(iter != nullptr){
        cout << iter->data << "|" << iter->next << " --> ";
        iter = iter->next;
    }
    cout << " null " << endl;
}

Lista::~Lista(){
    cout << "~Lista() destroys the List object!" << endl;
    Node* iter = head;
    Node* forDelete;
    while(iter != nullptr){
        forDelete=iter;
        iter = iter->next;
        delete forDelete;
    }
}


int main()
{
    Lista L;
    L.push_front(5);
    L.push_front(8);
    L.push_front(3);
    L.push_front(4);
    L.push_front(7);
    L.push_front(2);
    L.display();
    if(L.search(-4) != nullptr)
        cout << "Data found" << endl;
    else
        cout << "Not found" << endl;

    cout << L.erase(2) << endl;
    L.display();
    cout << L.size() << endl;
    L.reverse();
    L.display();
    L.prune();
    L.display();

    return 0;
}
