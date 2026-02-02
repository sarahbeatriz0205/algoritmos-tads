#ifndef __SET_ARRAY_IFRN__
#define __SET_ARRAY_IFRN__

class set_array{
private:
    int *data; // Aponta para o local que está alocado o array
    unsigned int size_, capacity_; // Declaração do tamanho e capacidade
    void increase_capacity() { // Método para aumento de capacidade
        this->capacity_ *= 2; // Incremento da capacidade do array
        int *new_data = new int[this->capacity_]; // Novo espaço de memória para alocar os elementos
        for (int i = 0; i < this->size_; ++i){
            new_data[i] = data[i];
        }
        delete[] this->data;
        this->data = new_data;
    } 
public:
    // Construtor
    set_array() {
        this->size_ = 0;
        this->capacity_ = 8;
        this->data = new int[capacity_];
    }

    // Destrutor
    ~set_array() {
        delete[] this->data;
    }

    // Insere 'value' no conjunto caso ele não esteja presente
    // (não pode repetir elementos).
    bool insert(int value) {
        if (this->size_ == this->capacity_){
            increase_capacity();
        }
        for (int i = 0; i < this->size_; i++){
            if (this->data[i] == value){
                return false;   // falso caso o valor seja igual.
            }
        }
        this->size_++;
        this->data[this->size_] = value;
        return true; // Retorna verdadeiro caso o elemento seja inserido.
    }

    // Remove 'value' do conjunto caso esteja presente.
    // Retorna verdadeiro se o elemento foi removido,
    // falso caso contrário.
    bool erase(int value) {
        for (int i = 0; i < this->size_; i++){
            if (this->data[i] == value){
                this->data[i] = this->data[this->size_ - 1]; // Ordem não importa
                this->size_--;
                return true;
            }
        }
        return false;
    }

    // Retorna verdadeiro se 'value' está presente no conjunto
    // falso caso contrário.
    bool find(int value){
        for (int i =0; i < this->size_; i++){
            if (this->data[i] == value){
                return true;
            }
        }
        return false;
    }

    // Retorna a quantidade de elementos do conjunto.
    unsigned int size() {
        return this->size_;
    }

    // Retorne o tamanho do espaço alocado para o conjunto.
    unsigned int capacity() {
        return this->capacity_;
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
    // Voltei o tamanho e capacidade ao seus valores iniciais, liberei a memória com delete
    void clear() {
        this->size_ = 0;
    }
};

#endif // __SET_ARRAY_IFRN__