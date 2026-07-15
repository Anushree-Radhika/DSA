int push(int x){
                if (isFull()) {
                        if(cap < maxcap){
                                digit = inflate();

                        }
                        else{
                                cout << "No elements can be pushed in the stack" << "\n";
                                return 0;
                        }
                }
                digit[idx] =  x;
                (s)->idx += 1;
                cout << "Successful insertion" << "\n";
                return 1;
        }
        template<typename T>
        T pop(mystack<T> *s){
                if(isEmpty(s)){
                        cout << "No elements to pop" << "\n";
                        return 0;
                }
                else{
                        T t = s->digit[s->idx - 1];
                        s->idx --;
                        cout << "The popped element is:" << t << "\n";
                        return t;
                }
        }
        template<typename T>
        T getMaxSize(mystack<T> *s){
                return s->maxcap;
        }
        template<typename T>
        T currentSize(mystack<T> *s){
                return s->idx;
        }
        template<typename T>
        void stack3(mystack<T> *s1,mystack<T> *s2,mystack<T> *s3){
                while( (!isEmpty(s1)) && (!isEmpty(s2))){
                        mynamespace ::push(s3,mynamespace ::pop(s1));
                        mynamespace ::push(s3,mynamespace ::pop(s2));
                }
                while((!isEmpty(s1))){
                        mynamespace ::push(s3,mynamespace ::pop(s1));
                }
                while((!isEmpty(s2))){
                        mynamespace ::push(s3,mynamespace ::pop(s2));
                }
        }