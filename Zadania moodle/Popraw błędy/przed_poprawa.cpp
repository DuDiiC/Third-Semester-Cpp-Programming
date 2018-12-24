<span syntax="c++">
#include <iostream>

using namespace std;

class user{
    private:
        string name;
    public:
        string introduce(){
            return name;
        }
    ostream& operator<<(ostream &o, user &u);
}

ostream& operator<<(ostream &o, const user &u){
    o << (u.introduce());
    return o;
}

class adm: public virtual user{
    public:
        string introduce(){
            return user::introduce()+&quot; (Administrator)&quot;;
        }
};

class author: public user{
    protected:
        int number;
        author(string s){name=s; number=0;}
        void newArticle(){number++; cout<<"New article added"<<endl;}
        string introduce(){
            return user::introduce()+" (Author)";
        }
};

class normal: protected user{
    public:
        normal(string s){name=s;}
};

class superadm: public adm, protected author{
    public:
        superadm(string s):adm(s),author(s){}
        string introduce(){
            return name+" (Super administrator)";
        }
    private
        using author::newArticle;
};

int main(){
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
    for(int i=0; i&lt;5; ++i){
        cout << tab[i]->introduce() << endl;
        cout << *tab[i] << endl;
    }
    user3.newArticle();
    user4.newArticle();
    return 0;
}
</span>
