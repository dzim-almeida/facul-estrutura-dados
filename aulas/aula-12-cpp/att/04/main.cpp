// nome: <SEU NOME>
// matrícula: <SUA MATRÍCULA>
// file: main.cpp
// desc: Interface via terminal para testar todas as operações de List
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stdexcept>
#include "list.cpp"
using namespace std;

int main()
{
    vector<List> listas; // um vector de listas

    while(true) {
        string comando, token;
        if(!getline(cin, comando)) break; // fim da entrada (ex.: arquivo redirecionado)
        stringstream ss{ comando };
        ss >> token;

        cout << "$" << ss.str() << endl;

        // listas.at(l) é usado no lugar de listas[l] para acusar índice de lista inexistente
        try {
            // exit
            if(token == "exit") {
                listas.clear();
                break;
            }
            // help
            else if(token == "help") {
                cout << "create | clone l | assign l1 l2 | pushback x l | addBack l a1 ... an" << endl;
                cout << "popback l | insertafter x k l | remove x l | removeall x l | concat l1 l2" << endl;
                cout << "clear l | size l | empty l | print l | printreverse l" << endl;
                cout << "equals l1 l2 | different l1 l2 | show | exit" << endl;
            }
            // create
            else if(token == "create") {
                listas.push_back(List());
            }
            // clone l
            else if(token == "clone") {
                int l;
                ss >> l;
                listas.at(l); // valida o índice antes de criar a nova lista
                listas.push_back(List());
                listas.back() = listas[l];
            }
            // assign l1 l2
            else if(token == "assign") {
                int l1, l2;
                ss >> l1 >> l2;
                listas.at(l1) = listas.at(l2);
            }
            // pushback x l
            else if(token == "pushback") {
                int x, l;
                ss >> x >> l;
                listas.at(l).push_back(x);
            }
            // addBack l a1 ... an
            else if(token == "addBack") {
                int l;
                ss >> l;
                int value;
                while(ss >> value) {
                    listas.at(l).push_back(value);
                }
            }
            // popback l
            else if(token == "popback") {
                int l;
                ss >> l;
                int value = listas.at(l).pop_back(); // remove antes de imprimir, caso dê erro
                cout << "popback: " << value << endl;
            }
            // insertafter x k l
            else if(token == "insertafter") {
                int x, k, l;
                ss >> x >> k >> l;
                listas.at(l).insertAfter(x, k);
            }
            // remove x l
            else if(token == "remove") {
                int x, l;
                ss >> x >> l;
                listas.at(l).remove(x);
            }
            // removeall x l
            else if(token == "removeall") {
                int x, l;
                ss >> x >> l;
                listas.at(l).removeAll(x);
            }
            // concat l1 l2
            else if(token == "concat") {
                int l1, l2;
                ss >> l1 >> l2;
                listas.at(l1).concat(listas.at(l2));
            }
            // clear l
            else if(token == "clear") {
                int l;
                ss >> l;
                listas.at(l).clear();
            }
            // size l
            else if(token == "size") {
                int l;
                ss >> l;
                int size = listas.at(l).size();
                cout << "size list " << l << ": " << size << endl;
            }
            // empty l
            else if(token == "empty") {
                int l;
                ss >> l;
                if(listas.at(l).empty()) cout << "lista " << l << " vazia" << endl;
                else cout << "lista " << l << " nao vazia" << endl;
            }
            // print l
            else if(token == "print") {
                int l;
                ss >> l;
                List& lst = listas.at(l);
                cout << "lista " << l << ": ";
                lst.print();
            }
            // printreverse l
            else if(token == "printreverse") {
                int l;
                ss >> l;
                List& lst = listas.at(l);
                cout << "lista " << l << " (reversa): ";
                lst.printReverse();
            }
            // equals l1 l2
            else if(token == "equals") {
                int l1, l2;
                ss >> l1 >> l2;
                if(listas.at(l1) == listas.at(l2)) cout << "listas iguais" << endl;
                else cout << "listas diferentes" << endl;
            }
            // different l1 l2
            else if(token == "different") {
                int l1, l2;
                ss >> l1 >> l2;
                if(listas.at(l1) != listas.at(l2)) cout << "listas diferentes" << endl;
                else cout << "listas iguais" << endl;
            }
            // show
            else if(token == "show") {
                for(unsigned i = 0; i < listas.size(); ++i) {
                    cout << "lista " << i << ": ";
                    listas[i].print();
                }
            }
            else {
                cout << "comando inexistente" << endl;
            }
        }
        catch(const out_of_range& e) {
            cout << "lista inexistente" << endl;
        }
        catch(const invalid_argument& e) {
            cout << "erro: " << e.what() << endl;
        }
    }
    return 0;
}
