#include <iostream>
class Vector_3 {
    private:
      int x, y, z;
    public:
      Vector_3(int x, int y, int z) : x(x), y(y), z(z) {}
      friend Vector_3 operator*(const Vector_3& V1, const Vector_3& V2) {
        int x_ = V1.y * V2.z - V1.z * V2.y;
        int y_ = V1.z * V2.x - V1.x * V2.z;
        int z_ = V1.x * V2.y - V1.y * V2.x;
        return Vector_3(x_,y_,z_);
      }
      friend std::ostream& operator<<(std::ostream& os, const Vector_3& V) {
        os << '(' << V.x << ',' << V.y << ',' << V.z << ')';
        return os;
      }
};

int main() {
    Vector_3 V1(1,3,2);
    Vector_3 V2(0,1,2);
    Vector_3 V = V1 * V2;
    std::cout << V << std::endl;
} //Cross product