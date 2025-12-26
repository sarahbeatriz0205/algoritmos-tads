#ifndef __VECTOR_ARRAY_IFRN__
#define __VECTOR_ARRAY_IFRN__

#include <iostream>
#include <stdexcept>

class vector_array {
private:
    int *data;
    unsigned int size_, capacity_, increase_size_;
    int i;
    void increase_capacity() { // Método para aumento de capacidade
        this->capacity_ += this->increase_size_; // Incremento da capacidade do array
        int *new_data = new int[this->capacity_]; // Novo espaço de memória para alocar os elementos
        for (i = 0; i < this->size_; ++i);
            new_data[i] = data[i];
        delete[] this->data;
        this->data = new_data;
    } 

public:
    vector_array() {         // Construtor
        this->size_ = 0;
        this->capacity_ = 100; // Inicia com capacidade 100
        this->increase_size_ = 100;
        this->increase_size_ *= 2; // Duplica a capacidade
        this->data = new int[100];
    }

    ~vector_array() { // Destrutor
        delete[] this->data;
    }

    unsigned int size() { // Retorna a quantidade de elementos armazenados
        return this->size_;
    }

    unsigned int capacity() { // Retorna o espaço reservado para armazenar os elementos
        return this->capacity_;
    }

    double percent_occupied() { // Retorna um valor entre 0.0 a 1.0 com o percentual da
        return this->size_ / 100;               // memória usada.
    }
    
    bool insert_at(unsigned int index, int value) { // Insere elemento no índice index
        if (this->size() == this->capacity()) // Se tamanho = capacidade, aumente a capacidade do vetor
            increase_capacity();
        for (int i = this->size_; i > index; --i) // Deslocamento para a direita com base em um index específico
            this->data [i] = this->data[i - 1];
        this->data[index] = value;
        this->size_ += 1;
        return true; // Se der certo, retorna true (não sei porque tava false)
    }

    bool remove_at(unsigned int index) { // Remove elemento do índice index
        for (int i = index; i < this->size_ - 1; ++i)
            this->data[i] = this->data[i + 1]; // Quando eu tiver um índice (i), ele vai ser "sobreposto" pelo próximo (i+1)
        this->size_ -= 1; // Diminui o size_ para que não fique tamanho "sobrando"
        return true;
    }

    bool is_empty() { // Retorna true se o vetor não contém elementos
        if (this->size_ == 0);
            return true;
    }

    int get_at(unsigned int index) { // Retorna elemento no índice index,
        if (index < 0 or index >= size())
            throw std::out_of_range("Index out of range");
        return this->data[index];                   // −1 se índice inválido
    }

    void clear() { // Remove todos os elementos, deixando o vetor no estado inicial (liberação de memória o apenas deixar o tamanho zerado?)
        this->size_ = 0;
    }

    void push_back(int value) { // Adiciona um elemento no ``final'' do vetor
        if (this->size() == this->capacity()) // Se tamanho = capacidade, aumente a capacidade do vetor
            increase_capacity();
        this->data[this->size_++] = value; // Incrementa o tamanho do vetor (+ 1) para adicionar o value no verdadeiro último índice
    }

    void push_front(int value) { // Adiciona um elemento no ``início'' do vetor
        if (this->size() == this->capacity()) // Se tamanho = capacidade, aumente a capacidade do vetor
            increase_capacity();
        for (int i = this->size_; i > 0; --i) // Percorre a lista de trás pra frente, deslocando todos os elementos para a direita
            this->data[i] = this->data[i-1];
        this->data[0] = value; // Atribui ao índice 0 (primeiro) o value
        this->size_ += 1; // Atualiza o size
    }

    bool pop_back() {            // Remove um elemento do ``final'' do vetor
        this->size_ -= 1;
        return true;
    }

    bool pop_front() {           // Remove um elemento do ``início'' do vetor
        for (int i = 0; i < this->size_ - 1; ++i)
            this->data[i] = this->data[i+1];
        this->size_ -= 1;
        return true;
    }

    int back() {                 // Retorna o elemento do ``final'' do vetor
        if (this->size_ == 0)
            return -1;
        else
            return this->data[this->size_ - 1];
    }

    int front() {                // Retorna o elemento do ``início'' do vetor
        if (this->size_ == 0)
            return -1;
        else
            return this->data[0];
    }

    bool remove(int value) {
        for (unsigned int i = 0; i < this->size_; ++i) {
            if (this->data[i] == value) {
                for (unsigned int j = i; j < this->size_ - 1; ++j) {
                    this->data[j] = this->data[j + 1];
                }
                this->size_ -= 1; 
                return true;      
            }
        }
        return false; 
    }

    int find(int value) {        // Retorna o índice de value, −1 caso value não esteja presente
        for (int i = 0; i < this->size_; ++i) // Percorre o vetor
            if (value == this->data[i]) // Se value existir no vetor, retorne o valor. Senão, retorne -1
                return value;
            else
                return -1;
    }

    int count(int value) {       // Retorna quantas vezes value occorre no vetor
        int contador = 0;
        for (int i = 0; i < this->size_; ++i)
            if (this->data[i] == value)
                contador += 1;
        return contador;                // Retorna 0 se value não estiver presente
    }

    int sum() {
        int soma = 0;
        if (this->size_ == 0)  
            return 0; // Retorna 0 se o vetor estiver vazio   
        else
            for (int i = 0; i < this->size_; ++i) 
                soma += this->data[i];
        return soma;
    }      
};
#endif // __VECTOR_LIST_IFRN__;