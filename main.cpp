#include <iostream>
#include <cstddef>
using namespace std;
class Nod{
private:
    char info;
    Nod *next;
public:
    Nod *GetNext(){return next;}
    char GetInfo(){return info;}
    void setNext(Nod *next1){this->next=next1;}
    Nod()//constructor neparametrizat
    {
        this->info=0;
        this->next=nullptr;}
    Nod(char info1,Nod *urm);//constructor param
    ~Nod(){
        info = '\0';
        next = nullptr;
    }
    friend ostream &operator <<(ostream &out,const Nod &nod );
    friend void citire_n(int n);

};

Nod::Nod(char info1, Nod *urm) {
    this->info=info1;
    this->next=urm;

}

ostream & operator <<(ostream &out, const Nod &nod){
    out<<nod.info<<" ";
    return out;
}

class Coada_de_caractere{
private:
    Nod *first,*last;
    size_t sz = 0;
public:
    Coada_de_caractere();
    ~Coada_de_caractere();
    void push(char c);
    void pop();
    bool isEmpty();
    friend ostream &operator <<(ostream &out,const Coada_de_caractere &coada);
    friend istream &operator >> (istream &in,Coada_de_caractere &coada);
    Coada_de_caractere operator +(Coada_de_caractere &caractere);
    Nod *GetFirst(){return first;}
    Coada_de_caractere operator -(Coada_de_caractere &queue);
};

Coada_de_caractere::Coada_de_caractere() {
    sz = 0;
    this->first=nullptr;
    this->last=nullptr;
}

Coada_de_caractere::~Coada_de_caractere() {
    Nod *index=this->first;
    while(index!=nullptr)
    {
        Nod *urm=index->GetNext();
        delete index;
        index=urm;
    }
    sz = 0;
}

void Coada_de_caractere::push(char c) {
    if(this->last==nullptr)
        this->first=this->last=new Nod(c,nullptr);
    else
    {
        Nod *p=new Nod(c,nullptr);
        this->last->setNext(p);
        this->last = p;
    }
    sz++;
}

void Coada_de_caractere::pop() {
    if(first!=nullptr)
    {
        Nod *p=first;
        first=first->GetNext();
        delete p;
        sz--;
    }

}

bool Coada_de_caractere::isEmpty() {
    return sz == 0;
}

ostream &operator<<(ostream &out, const Coada_de_caractere &coada) {
    Nod *p=coada.first;
    while(p!=nullptr)
    {out<<p->GetInfo()<<" ";
        p=p->GetNext();}
    return out;
}

istream &operator>>(istream &in, Coada_de_caractere &coada) {
    size_t n;
    char p;
    cout<<"Dati nr de elemente pe care le veti citi de la tastatura "<<" ";
    in>>n;
    while(n)
    {in >> p;
        coada.push(p);
        n--;}
    return in;
}

Coada_de_caractere Coada_de_caractere::operator+(Coada_de_caractere  &caractere) {
    Nod *p=new Nod();
    p=first;
    Coada_de_caractere cd;
    while(p!=nullptr)
    {
        cd.push(p->GetInfo());
        p=p->GetNext();
    }
    p=caractere.GetFirst();
    while(p!=nullptr)
    {
        cd.push(p->GetInfo());
        p=p->GetNext();
    }


    return cd;
}

Coada_de_caractere Coada_de_caractere::operator-(Coada_de_caractere  &queue) {
    Nod *p=new Nod();
    Nod *q=new Nod();
    p=first;
    q=queue.GetFirst();
    static Coada_de_caractere cd;
    while(p!=nullptr && q!=nullptr)
    { if(p->GetInfo()>q->GetInfo())
        {cd.push(p->GetInfo());}
        else
        {cd.push(q->GetInfo());}
        p=p->GetNext();
        q=q->GetNext();}
    return cd;

}
void citire_n(int n)
{Coada_de_caractere x[100];
 for(int i=0;i<n;i++)
     cin>>x[i];
 for(int i=0;i<n;i++)
     cout<<x[i]<<endl;}
int main()
{
    Coada_de_caractere ob1;
    Coada_de_caractere ob2;
    cin >> ob1;
    cin>>ob2;
    ob1.push('c');
    ob1.push('b');
    ob2.push('a');
    ob2.push('z');
    ob1.pop(); ob2.pop();
    cout<<ob1.isEmpty()<<endl;
    cout <<ob1<<endl;
    cout<<ob2<<endl;
    cout<<ob1+ob2<<endl;
    cout<<ob1-ob2<<endl;
    int n;
    cin>>n;
    citire_n(n);

    return 0;
}
