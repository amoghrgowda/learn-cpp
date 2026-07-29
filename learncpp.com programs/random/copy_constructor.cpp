#include <iostream>
#include <cstring>

class String{
    private:
        char* m_Buffer; 
        unsigned int m_Size;
    public:
        String(const char* string){
            m_Size = std::strlen(string);
            m_Buffer = new char[m_Size+1];
            memcpy(m_Buffer, string, m_Size);
            m_Buffer[m_Size] = 0; 
        } 
        
        char& operator[](unsigned int index){
            return m_Buffer[index];
        }

        String(const String& other): m_Size(other.m_Size){
            m_Buffer = new char[m_Size+1];
            memcpy(m_Buffer, other.m_Buffer, m_Size+1);
        }

        ~String(){
        delete[] m_Buffer;
        }

        friend std::ostream& operator<<(std::ostream& stream, const String& string);
};

std::ostream& operator<<(std::ostream& stream, const String& string){
    stream<< string.m_Buffer;
    return stream;
}


int main(){
    String name = "Hello World!";
    String other = name;
    std::cout<< name<<std::endl;
    other[11] = '?'; 
    std::cout<<other<<std::endl;
}