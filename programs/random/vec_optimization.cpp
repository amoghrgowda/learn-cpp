#include <iostream>
#include <vector>

struct Vertex{
public:
    float x{},y{},z{};

    Vertex(float x, float y, float z): x(x), y(y), z(z) {
        std::cout<<"Constructed!\n";
    };

    Vertex(const Vertex& other): x(other.x), y(other.y), z(other.z){
        std::cout<<"Copied!\n";
    };

    ~Vertex() = default;

};

void naiveApproach(){
    std::cout<<"Naive approach:\n";

    std::vector<Vertex> vertices;

    vertices.push_back(Vertex(1.0f,2.0f,3.0f));
    vertices.push_back(Vertex(4.0f,5.0f,6.0f));
    vertices.push_back(Vertex(7.0f,8.0f,9.0f));

    std::cout<<"---End Naive Approach---\n";
}

void optimizedApproach(){
    std::cout<<"Optimized approach:\n";

    std::vector<Vertex> vertices;

    vertices.reserve(3);

    vertices.emplace_back(1.0f,2.0f,3.0f);
    vertices.emplace_back(4.0f,5.0f,6.0f);
    vertices.emplace_back(7.0f,8.0f,9.0f);

    std::cout<<"---End Optimized Approach---\n";
}

int main(){
    naiveApproach();
    optimizedApproach();
    return 0;
}