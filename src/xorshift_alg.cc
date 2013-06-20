unsigned int xor() {
  static unsigned int y = 2463534242;
  y ^= (y << 13);
  y ^= (y >> 17);
  return (y ^= (y << 5));
}
