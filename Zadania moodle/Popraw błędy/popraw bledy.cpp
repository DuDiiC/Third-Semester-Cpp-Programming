#include <iostream>

using namespace std;

class user {
    protected:
        string name;
    public:
        virtual string introduce() const {
            return name;
        }
        friend ostream &operator<<(ostream &o, const user &u);
};

ostream &operator<<(ostream &o, const user &u) {
    o << u.introduce();
    return o;
}

class adm: public virtual user {
    public:
        string introduce() const {
            return user::introduce()+" (Administrator)";
        }
        adm(string s){name=s;}
};

class author: public virtual user{
    protected:
        int number;
    public:
        author(string s) { name=s; number=0; }
        void newArticle() { number++; cout << "New article added" << endl; }
        string introduce()const {
            return user::introduce()+" (Author)";
        }
};

class normal: public user {
    public:
        normal(string s) { name=s; }
};

class superadm: public adm, public author {
    public:
        superadm(string s):adm(s),author(s) {
            this->author::name=s;
            this->adm::name=s;
            this->author::number=0;
        }
        string introduce() const {
            return this->author::name+" (Super administrator)";
        }
        using author::newArticle;
};

ostream &operator<<(ostream &o, const adm &a) {
    o << a.introduce();
    return o;
}

ostream &operator<<(ostream &o, const author &a) {
    o << a.introduce();
    return o;
}


int main() {
    user* tab[5];
    normal user0("Arnold");
    normal user1("Alfred");
    adm user2("Anna");
    author user3("Waldemar");
    superadm user4("Juliusz");
    tab[0] = &user0;
    tab[1] = &user1;
    tab[2] = &user2;
    tab[3] = &user3;
    tab[4] = &user4;
    for(int i=0; i<5; ++i) {
        cout << tab[i]->introduce() << endl;
        cout << *tab[i] << endl;
    }
    user3.newArticle();
    user4.newArticle();
    return 0;
}
