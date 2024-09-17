#include <iostream>
class Vector_3 {
    private:
      int x, y, z;
    public:
      Vector_3(int x, int y, int z) : x(x), y(y), z(z) {}
      friend Vector_3 operator++(Vector_3& V) {
        return Vector_3(++V.x, ++V.y, ++V.z);
      }
      friend Vector_3 operator++(Vector_3& V, int num) {
        return Vector_3(V.x++, V.y++, V.z++);
      }
      friend std::ostream& operator<<(std::ostream& os, Vector_3& V) {
        os << '(' << V.x << ',' << V.y << ',' << V.z << ')';
        return os;
      }
};
int main() {
    Vector_3 V(1,3,5);
    Vector_3 V_(1,4,0);
    Vector_3 V1 = ++V;
    Vector_3 V2 = V_++;
    std::cout << V1 << ' ' << V2 << std::endl;
}