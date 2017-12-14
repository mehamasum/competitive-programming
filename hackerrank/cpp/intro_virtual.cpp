int PROF = 1;
int STU = 1;
class Person {
    public:
        int id;
        string name;
        int age;
        virtual void getdata()=0;
        virtual void putdata()=0;
};

class Professor: public Person {
    public:
        int pub;
        Professor() {
            id = PROF++;   
        }
        void getdata() {
            cin >> name >> age >> pub;
        }

        void putdata() {
            cout << name <<" "<< age <<" "<< pub <<" "<< id << endl;
        }
};

class Student: public Person {
    public:
        int marks[6];
        Student() {
            id = STU++;   
        }
        void getdata() {
            cin >> name >> age;
            for(int i=0; i<6; i++) cin >> marks[i];
        }

        void putdata() {
            int sum = 0;
            for(int i=0; i<6; i++) sum+= marks[i];
            cout << name <<" "<< age <<" "<<sum<<" "<<id<<endl;
        }
};