#include <iostream>

using namespace std;

// FIFO

template <typename T>
class kolejkaPr{
private:
    T value;
    kolejkaPr* key;
public:
    kolejkaPr() :key(NULL), value(0){};
    kolejkaPr(T _val) :key(NULL), value(_val){};
    kolejkaPr(T _val, kolejkaPr* _key) :key(_key), value(_val){};

    ~kolejkaPr()
    {
        if(key)
        {
            delete key;
            key = NULL;
        }   
    }

    void Add(T _val, kolejkaPr * _a)  //poprawic dodawanie, aby sortowalo
    {
        //od najmniejszych do najwiekszych

        if(_val > this->value && this->key != NULL)
        {
            this->key->Add(_val, this);
        }
        else if(_val > this->value && this->key == NULL)
        {
            this->key = new kolejkaPr<T>(_val);
        }
        else if(_val <= this->value && this->key != NULL)
        {

            _a->key = new kolejkaPr<T>(_val,this);

        }
        else if(_val <= this->value && this->key == NULL)
        {
            // T temp = this->value;
            this->key = new kolejkaPr<T>(this->value);
            this->value = _val;
        }
    }
    void Get()
    {
        cout << this->value << endl; 
    }
    void Remove()
    {        
        if(this->key == NULL)
        {
            cout << "Kolejka jest pusta" << endl;
            delete this;
        }
        else
        {
            // kolejkaPr *a = this-> key;
            // wyciek pamieci??
          this->value = this->key->value;
            this->key = this->key->key;
        }
        
    }
    void WriteAll()
    {
        cout << value << endl;
        if(key)
        {
            key->WriteAll();
        }
    }
    int Size()
    {
        int x = 1;
        kolejkaPr* temp = this->key;
        while(temp)
        {
            x++;
            temp = temp->key;
        }
        return x;
    }
};

// FIFO

template <typename T>
class kolejka{
private:
    T value;
    kolejka* key;
public:
    kolejka() :key(NULL), value(0){};
    kolejka(T _val) :key(NULL), value(_val){};
    kolejka(T _val, kolejka* _key) :key(_key), value(_val){};

    ~kolejka()
    {
        if(key)
        {
            delete key;
            key = NULL;
        }   
    }

    void Add(T _val)
    {
        if(this->key != NULL)
        {
            this->key->Add(_val);
        }
        else
        {
            this->key = new kolejka<T>(_val);
        }
    }
    void Get()
    {
        cout << this->value << endl; 
    }
    void Remove()
    {        
        if(this->key == NULL)
        {
            cout << "Kolejka jest pusta" << endl;
            delete this;
        }
        else
        {
            this->value = this->key->value;
            this->key = this->key->key;
        }
        
    }
    void WriteAll()
    {
        cout << value << endl;
        if(key)
        {
            key->WriteAll();
        }
    }
    int Size()
    {
        int x = 1;
        kolejka* temp = this->key;
        while(temp)
        {
            x++;
            temp = temp->key;
        }
        return x;
    }
};

// LIFO
template <typename T> 
class stos{
private:
    T value;
    stos* key;
public:
    // stos() :key(NULL), value(NULL) {};
    stos(T _val) :key(NULL) , value(_val){};
    stos(T _val, stos* _key) :key(_key), value(_val){};

    void Add(T _val)
    {
        if(this->key != NULL)
        {
            this->key->Add(_val);
        }
        else
        {
            this->key = new stos<T>(_val);
        }
    };
    void Get()
    {
        if(this->key != NULL)
        {
            this->key->Get();
        }
        else
        {
            cout << this->value << endl; 
        }
        
    }
    void Remove(stos* _last)
    {
        if(this->key != NULL)
        {
            this->key->Remove(this);
        }
        else
        {
            cout<<"Usunieta wartosc: " << this->value << endl;
             delete this;
            _last->key = NULL;
        }
        
    }
    ~stos()
    {
        if(key)
        {
            delete key;
            key = NULL;
        }
        // cout<<"Zwolnienie pamieci"<<endl;
    };

    void WriteAll()
    {
        if(key)
        {
            key->WriteAll();
        }
        cout << value << endl;
    };

    int Size()
    {
        int s = 1;
        stos* st2 = key;
        while(st2)
        {
            s++;
            st2 = st2->key;
        }
        return s;
    };
};

int main()
{
    stos<int> myStos(0);

    for(int i = 1; i < 6; i++){
        myStos.Add(i);
    }

    cout<< "Stos" << endl<<endl;
    cout << "Ilosc elementow: " << myStos.Size() << endl;
    cout << "Ostatnia wartos: "; 
    myStos.Get();
    myStos.Remove(&myStos);
    cout << "Ostatnia wartos: "; 
    myStos.Get();
    cout << "Ilosc elementow: " <<myStos.Size() << endl;
    myStos.WriteAll();
 
    cout<<endl<<endl;
    cout<< "Kolejka" << endl<<endl;
    kolejka<int> myKolejka(0);

    for(int i = 1; i < 6; i++)
    {
        myKolejka.Add(i);
    }
    cout << "Ilosc elementow: " <<myKolejka.Size() << endl;
    cout << "Pierwsza wartos: "; 
    myKolejka.Get();
    myKolejka.Remove();
    cout << "Ilosc elementow: " << myKolejka.Size() << endl;
    cout << "Pierwsza wartos: "; 
    myKolejka.Get();
    cout << endl;
    myKolejka.WriteAll();

    cout<<endl<<endl;
    cout<< "Kolejka Priorytetowa" << endl<<endl;
    kolejkaPr<int> myKolejkaPr(0);

    for(int i = 6; i >= 1; i--)
    {
        myKolejkaPr.Add(i,&myKolejkaPr);
    }
    cout << "Ilosc elementow: " <<myKolejkaPr.Size() << endl;
    cout << "Pierwsza wartos: "; 
    myKolejkaPr.Get();
    myKolejkaPr.Remove();
    cout << "Ilosc elementow: " << myKolejkaPr.Size() << endl;
    cout << "Pierwsza wartos: "; 
    myKolejkaPr.Get();
    cout << endl;
    myKolejkaPr.WriteAll();


    return 0;
}