#ifndef __SET_LINKED_IFRN__
#define __SET_LINKED_IFRN__
class set_linked {
private:
    struct int_node { // Estrutura do nó
        int value;
        struct int_node *next, * prev; // Próximo nó e nó anterior
    };
    int_node *inicio, *fim;
    unsigned int size_;
public:
    // Construtor
    set_linked() {
        this->inicio = nullptr;
        this->fim = nullptr;
        this->size_ = 0;
    }

    // Destrutor
    ~set_linked() {
        int_node *current = this->inicio; // O ponteiro atual vai começar do início
        while (current != nullptr){ // Enquanto o ponteiro atual for diferente de vazio
            int_node *to_remove  = current; // Crie um ponteiro "extra" (to_remove) para remover o ponteiro atual (current)
            current = current->next; // O ponteiro atual vai ser o próximo nó
            delete to_remove; // Deleta o antigo ponteiro atual que está em to_remove
        }
        this->size_ = 0;
    }

    // Insere 'value' no conjunto caso ele não esteja presente
    // (não pode repetir elementos).
    // Retorna verdadeiro caso o elemento seja inserido,
    // falso caso contrário.
    bool insert(int value) {
        int_node *current  = this->inicio;
        // Me retorna se o valor dado já existe no set
        while (current != nullptr){
            if (current->value == value){
                return false;
            }
            current = current->next;
        }
        int_node* new_node = new int_node;
        new_node->value = value;
        new_node->next = nullptr;
        new_node->prev = this->fim;
        if (this->inicio == nullptr){
            this->inicio = new_node;
        } else{
            this->fim->next = new_node;
        }
        this->fim = new_node;
        this->size_++;
        return true;
    }

    // Remove 'value' do conjunto caso esteja presente.
    // Retorna verdadeiro se o elemento foi removido,
    // falso caso contrário.
    bool erase(int value) {
        int_node *current = this->inicio;
        while (current != nullptr){
        if (current->value == value){
            if (current == this->inicio && current == this->fim){
                this->inicio = nullptr;
                this->fim = nullptr;
            } else if (current == this->inicio){
                this->inicio = current->next; // o próximo
                this->inicio->prev = nullptr; // o anterior, que agora foi removido, aponta pra vazio
            } else if (current == this->fim){
                this->fim = current->prev; // o último se torna o anterior
                this->fim->next = nullptr; 
            }
            else{
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            delete current;
            this->size_--;
            return true;
        }
        current = current->next;
        }
        return false;
    }

    // Retorna verdadeiro se 'value' está
    // presente no conjunto, falso caso contrário.
    bool find(int value) {
        int_node *current = this->inicio;
        while (current != nullptr){
            if (current->value == value){
                return true;
            }
        current = current->next;
        }
        return false;
    }

    // Retorna a quantidade de elementos do conjunto.
    unsigned int size() {
        return this->size_; // Mudar size_ nas operações de insert e erase 
    }

    // Retorne o tamanho do espaço alocado para o conjunto
    unsigned int capacity() {
        return this->size_; // A capacidade é o tamanho
    }

    // Retorna verdadeiro se o conjunto estiver vazio,
    // falso caso contrário.
    bool empty() {
        if (this->size_ == 0){
            return true;
        }
        return false;
    }

    // Apaga todos os elementos do conjunto.
    void clear() {
        int_node *current = this->inicio;
        while (current != nullptr){
            int_node *next = current->next;
            delete current;
            current = next;
        }
        this->size_ = 0;
        this->inicio = nullptr;
        this->fim = nullptr;
    }
    
};

#endif // __SET_LINKED_IFRN__