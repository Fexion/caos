int bitcount(STYPE value) {
    int count = 0;
    UTYPE uvalue = value;
    while (uvalue) {
        count += uvalue & 1;
        uvalue >>= 1;

    }
    return count;
}
