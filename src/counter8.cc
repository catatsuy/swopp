class Counter : public Module {
 public:
  wire<uint> out;
  reg<uint> counter;
  void Init() {
    out = [=]() { return counter(); };
  }
  void Always() {
    counter <<= (counter() + 1) & 0xff;
  }
};
