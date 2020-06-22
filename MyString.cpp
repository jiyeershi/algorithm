#include <iostream>
#include<stdio.h>
using namespace std;

class MyString
{
private:
    char* data;
    int length;

public:
    
    MyString(char* str)
    {
        if(str == nullptr){
            data = new char(1);
            data[0] = '\0';
            length = 0;
        }else{
            int len = strlen(str);
            data = new char(len + 1);
            length = len;
            memcpy(data, str, len + 1);
        }
    }
    

    MyString& operator=(MyString& str)
    {
        if(this == &str) return *this;
        delete[] data;
        int len = str.Len();
        data = new char(len + 1);
        memcpy(data, str.GetStr(), len + 1);
        this->length = len;
        return *this;
    }

    MyString& Concat(MyString& str)
    {
        int len = str.Len() + length;
        char* newData = new char(len + 1);
        memcpy(newData, data, length);
        memcpy(newData + length, str.GetStr(), str.Len()+1);
        delete[] data;
        data = newData;
        length = len;
        return *this;
    }

    //
    MyString& SubString(int pos, int len){
        if(pos < 0 || pos > length - 1 || len < 0 || len > length - pos){
            //异常处理
        }
        printf("substring begin 1 = %s   and len = %lu\n", data, strlen(data));
        
        for (int i = 0; i <= strlen(data); i++) {
            printf("begin 1 ch = %x\n", data + i);
            printf("begin 1 *ch = %x\n", data[i]);
        }
        
        MyString* str = new MyString(nullptr);
        printf("str->data 0 = %x\n", str->data);
        
        delete[] str->data;
        str->data =  (char*)malloc(len + 1);//new char(len + 1);
        str->data[0] = '\0';
        str->length = len;
        
        printf("str->data 1 = %x\n", str->data);
        printf("substring begin 2 = %s   and len = %lu\n", data, strlen(data));
        
        for (int i = 0; i <= strlen(data); i++) {
            printf("begin 2 ch = %x\n", data + i);
            printf("begin 2 *ch = %x\n", data[i]);
        }
        
        printf("\n\n\n");
        memcpy(str->data, data + pos-1, len);
        
        printf("substring end 2 = %s and len = %lu\n", data, strlen(data));
        for (int i = 0; i <= strlen(data); i++) {
            printf("end 2 ch = %x\n", data + i);
            printf("end 2 *ch = %x\n", data[i]);
        }
        
        printf("substring begin 3 = %s and len = %lu\n", data, strlen(data));
        str->data[len] = '\0';

        return *str;
    }
    
    int Len()
    {
        return length;
    }

    char* GetStr()
    {
        return data;
    }

    
    ~MyString()
    {
        length = 0;
        delete[]data;
        data = nullptr;
    }
    
};

void myPrint(MyString& str)
{
    printf("tag start: %s\n", str.GetStr());
    for (int i = 0; i <= strlen(str.GetStr()); i++) {
        printf(" ch = %x\n", str.GetStr() + i);
        printf(" *ch = %c\n", str.GetStr()[i]);
    }
    printf("tag end: %s\n\n", str.GetStr());
}

int main(int argc, char *argv[]) {
    MyString str1 = "xxxxmmmm";
    MyString str2 = "88880000";
    
    myPrint(str1);
    myPrint(str2);
    str2 = str2.Concat(str1);
    
    myPrint(str2);
    MyString str3 = str2.SubString(3, 4);
    
    myPrint(str2);
    myPrint(str3);
    return 0;
}
