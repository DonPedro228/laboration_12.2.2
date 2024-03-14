#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

typedef int Info;
struct Elem
{
    Elem* link;
    Info info;
};

void push(Elem*& top, Info value);
Info pop(Elem*& top);
void Add(Elem*& top);
bool Not_Nezrustania(Elem* top);

int main() {
    Elem* top = NULL;

    cout << "Enter elements of the list in non-descending order (or -1 to end input):\n";
    Add(top);

    cout << "List elements: ";
    Elem* current = top;
    while (current != nullptr) {
        cout << current->info << " ";
        current = current->link;
    }
    cout << endl;

    if (Not_Nezrustania(top))
        cout << "The list is sorted in non-descending order.\n";
    else
        cout << "The list is not sorted in non-descending order.\n";

    return 0;
}

void Add(Elem*& top) {
    int value;
    cout << "Enter element (or -1 to end input): ";
    cin >> value;
    if (value != -1) {
        push(top, value);
        Add(top);
    }
}


void push(Elem*& top, Info value) {
    if (top == nullptr) {
        top = new Elem;
        top->info = value;
        top->link = nullptr;
    }
    else {
        push(top->link, value);
    }
}

Info pop(Elem*& top) {
    if (top == nullptr) {
        throw logic_error("Stack is empty");
    }
    Info value;
    if (top->link == nullptr) {
        value = top->info;
        delete top;
        top = nullptr;
    }
    else {
        value = pop(top->link);
    }
    return value;
}

bool Not_Nezrustania(Elem* top) {
    if (top == nullptr || top->link == nullptr) {
        return true;
    }
    else if (top->info > top->link->info) {
        return false;
    }
    else {
        return Not_Nezrustania(top->link);
    }
}