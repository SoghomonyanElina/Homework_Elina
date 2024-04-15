#include <iostream>
class Vector_3 {
    private: 
      double x, y, z;
    public:
      Vector_3(double x, double y, double z) : x(x), y(y), z(z) {}
      friend Vector_3 operator-(const Vector_3& V1, const Vector_3& V2) {
        return Vector_3(V1.x - V2.x, V1.y - V2.y, V1.z - V2.z);
      }
      friend std::ostream& operator<<(std::ostream& os, const Vector_3& V) {
        os << '(' << V.x << ',' << V.y << ',' << V.z << ')';
        return os;
      }
};

int main() {
    Vector_3 V1(9, 8, 10);
    Vector_3 V2(9, 4, 0);
    Vector_3 V = V1 - V2;
    std::cout << V << std::endl;
}