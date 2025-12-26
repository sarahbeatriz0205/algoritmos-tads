#ifndef __VECTOR_LINKED_IFRN__
#define __VECTOR_LINKED_IFRN__
class vector_linked {
private:
    struct int_node {
        int value;
        int_node *next, *prev;
    };
    int_node *head, *tail;
    unsigned int size_;

public:
    vector_linked() { // Construtor
        this->head = nullptr; // primeiro nó
        this->tail = nullptr; // último nó
        this->size_ = 0; // tamanho
    }

    // Percorre a lista, usa current como ponteiro para o próximo valor e to_remove para remover o valor que está sendo apontado por to_remove 
    ~vector_linked() { // Destrutor
        int_node* current = this->head; // current é um ponteiro para o primeiro nó da lista
        while (current != nullptr){
            int_node* to_remove = current; // to_remove se torna o valor de current antes da atualização abaixo
            current = current->next; // current só é atualizado aqui, indo para o next
            delete to_remove; // após avançar current, você ainda precisa ter a referência para deletar o nó anterior.
        }    

    }
    unsigned int size() { // Retorna a quantidade de elementos armazenados
        return this->size_;
    }
    unsigned int capacity() { // Retorna o espaço
        return this->size_;
    } // reservado para armazenar os elementos
    double percent_occupied() { // Retorna um valor entre 0.0 a 1.0
        return 1.0;           // com o percentual da memória usada. confesso que não entendi como fazer com lista duplamente ligada
    }

    void push_back(int value) { // Adiciona um elemento no ``final'' do vetor
        int_node* new_node = new int_node;
        new_node->value = value;
        new_node->next = nullptr;
        new_node->prev = this->tail;
        if (this->head == nullptr) // criação de novo nó se não existir?
            this->head = new_node;
        else
            this->tail->next = new_node;
        this->tail = new_node;
        this->size_++;
    }

    void push_front(int value) { // Adiciona um elemento no ``início'' do vetor
        int_node* new_node = new int_node;
        new_node->value = value; // novo nó aponta pra o valor?
        new_node->next = head; // aponta para o 1º nó = nullptr
        new_node->prev = nullptr;
        if (this->head == nullptr)
            this->tail = new_node;
        else
            this->head->prev = new_node;
        this->head = new_node;  
        this->size_++;
    }

    bool insert_at(unsigned int index, int value) { // Insere elemento no índice index (nó)
        int_node* current = this->head;
        if (index > this->size_) 
            return false;
        if (index == 0){ // inserir no início
            this->push_front(value);
            return true; // retornar true pra parar a execução das outras linhas quando essa condição for verdadeira
        }
        if (index == this->size_){ // inserir no fim
            this->push_back(value);
            return true;
        }
        int_node* new_node = new int_node; // nó recém criado, sem valores definidos
        new_node->value = value;
        for (unsigned int i = 0; i < index; ++i){
            current = current->next;
        }
        new_node->next = current;
        new_node->prev = current->prev;
        current->prev->next = new_node;
        current->prev = new_node;
        this->size_++;
        return true;
    }

    bool remove_at(unsigned int index) { // Remove elemento do índice index
        int_node *current = this->head;
        for (unsigned int i = 0; i < index; i++){
            current = current->next;
        }
        int_node *to_remove = current;
        if (to_remove != nullptr){
            to_remove->prev->next = to_remove->next;
        } else{
            this->head = to_remove->next;
        }
        if (to_remove->next != nullptr){
            to_remove->next->prev = to_remove->prev; 
        } else { 
            this->tail = to_remove->prev;
        }
        delete to_remove; 
        this->size_--; 
        return true;
    }

    bool is_empty() { // Retorna true se o vetor não contém elementos
        if (this->size_ == 0)
            return true;
        return false;
    }
    
    int get_at(unsigned int index) { // Retorna elemento no índice index,
        int_node* current = this->head; // current aponta para o ponteiro inicial
        if (index >= this->size_) // validação de index
            return -1;  // −1 se índice inválido
        for (unsigned int i = 0; i < index; ++i) // percorre lista até o índice
            current = current->next; // sempre passa para o próximo valor
        return current->value; // retorna o valor encontrado                 
    }

    void clear() { // Remove todos os elementos, deixando o vetor no estado inicial
        int_node *current = this->head;
        while (current != nullptr){ 
            int_node* to_remove = current;
            current = current->next;
            delete to_remove;
        }
        this->head = nullptr;
        this->tail = nullptr;
        this->size_ = 0;
    }

    bool pop_back() { // Remove um elemento do ``final'' do vetor
        if (this->tail == nullptr)
            return false;
        if (this->head == this->tail){
            delete this->head;
            this->head = nullptr;
            this->tail = nullptr;
            return true;
            this->size_--;
        }
        this->tail = this->tail->prev;
        delete this->tail->next;
        this->tail->next = nullptr;
        this->size_--;
        return true;
    }

    bool pop_front() { // Remove um elemento do ``início'' do vetor
        if (this->head == nullptr)
            return false;
        int_node* to_remove = this->head;
        this->head = this->head->next;
        
        if (this->head != nullptr){
             this->head->prev = nullptr; // novo primeiro nó não tem anterior
        } else {
        this->tail = nullptr; // lista ficou vazia
    }
        delete to_remove;
        this->size_--;
    return true;
}

    int back() { // Retorna o elemento do ``final'' do vetor
        if (this->size_ == 0){
            return -1;
        }
        return this->tail->value;
    }
    int front() { // Retorna o elemento do ``início'' do vetor
         if (this->size_ == 0){
            return -1;
        }
        return this->head->value;
    }
    bool remove(int value) { // Remove value do vetor caso esteja presente
        int_node *current = this->head;
        while (current != nullptr){
            if (current->value == value){
                int_node *to_remove = current;
            
            if (to_remove->prev != nullptr) { 
                to_remove->prev->next = to_remove->next; 
            }else { 
                this->head = to_remove->next;
            }
            if (to_remove->next != nullptr) { 
                to_remove->next->prev = to_remove->prev; 
            } else { 
                this->tail = to_remove->prev;
            }
            delete to_remove;
            this->size_--; 
            return true;
        }
        current = current->next;
    }
        return false;
    }
    int find(int value) { // Retorna o índice de value, −1 caso value não esteja presente
        int index = 0; // Vai servir para contar a quantidade de índices que andou, pra saber qual o "index"
        int_node *current = this->head;
        while (current != nullptr){
            if (current->value == value)
                return index;
            current = current->next;
            index++;
        }
            return -1;
    }
    int count(int value) { // Retorna quantas vezes value occorre no vetor
        int contador = 0;
        int_node *current = this->head;
        while (current != nullptr){
            if (current->value == value){
                contador += 1;
            }
            current = current->next;
        }
        return contador;
    }
    int sum() { // Retorna a soma dos elementos do vetor
        int soma = 0;
        int_node *current = this->head;
        while (current != nullptr){
            soma += current->value;
            current = current->next;
        }
        return soma;
    }
};
#endif // __VECTOR_LINKED_IFRN__