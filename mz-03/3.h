
#include <inttypes.h>
union Data {
    void *p;
    float f;
};
int cmpf(const void *p1, const void *p2) {
    union Data data1, data2;
    
    data1.p = &p1;
    data2.p = &p2;
    if ( data1.f < data2.f ) {
        return (1);
    } else if ( data1.f > data2.f) {
        return (-1);
    } else {
        return 0;
    }
}
