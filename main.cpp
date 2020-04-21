#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct record{
    string name;
    int count;
    record(string name){
        this->name=name;
        count=1;
    }
    bool operator==(const record & a){
        return (name==a.name);
    }
};

int  main(void){
    string str;
    while(cin>>str) {
        vector<string> name;
        vector<record> vec;
        int size = str.size();
        string tmp = "";
        for (int i = 0; i < size; i++) {
            if (str[i] == ',') {
                name.push_back(tmp);
                tmp = "";
            } else {
                tmp = tmp + str[i];
            }
        }
        name.push_back(tmp);
        sort(name.begin(), name.end());
//        for(int i=0;i<name.size();i++){
//            cout<<name[i]<<" ";
//        }
        cout<<endl;
        for(int i=0;i<name.size();i++){
            record tmp0(name[i]);
            auto tmp1=find(vec.begin(),vec.end(),tmp0);
            if(tmp1==vec.end()){
                vec.push_back(tmp0);
            }
            else{
                tmp1->count++;
            }
        }
        //需要使用冒泡排序
        bool flag=false;
        int n=vec.size();
        while(!flag){
            flag=true;
            for(int i=1;i<n;i++){
                if(vec[i].count>vec[i-1].count){
                    record tmp00=vec[i];
                    vec[i]=vec[i-1];
                    vec[i-1]=tmp00;
                    flag=false;
                }
            }
            n--;
        }
//        for(int i=0;i<vec.size();i++){
//            cout<<vec[i].name<<" "<<vec[i].count<<endl;
//        }
        cout<<"the elected person is "<<vec[0].name<<" and the number of people volted to him is "<<vec[0].count<<endl;
    }
}