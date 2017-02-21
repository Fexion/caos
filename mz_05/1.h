unsigned extract(unsigned value, int bit, int length) {

    if (bit == 0 && length == 32) {
        return value;
    }
    value >>= bit;
    return value - ((value>>length)<<length);
}
