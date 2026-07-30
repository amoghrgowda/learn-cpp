#include <iostream>

enum Color{
    black,
    blue,
    red,
    yellow
};

constexpr std::string_view getColorName(Color& color){
    switch(color){
        case black: return "black";
        case blue: return "blue";
        case red: return "red";
        case yellow: return "yellow";
        default: return "unknown color"; 
    }
}

std::ostream& operator<<(std::ostream& out, Color color){   // param Color is not a reference to allow rvalues also.
    out<< getColorName(color);
    return out;
}

int main(){
    Color shirt {red};
    std::cout<<"Your shirt is "<< shirt<<std::endl;
}