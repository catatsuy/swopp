class TestTop : public Module {
 public:
  reg<uint> HALT;
  reg<uint> cycle;

  wire<uint> cnt_out;
  Counter cnt;
   
  void Init() {
    cnt_out = cnt.out;
  }
  void Always() {
    cycle <<= cycle() + 1;
    HALT  <<= (cycle() >= HALT_CYCLE);

    if (cycle() > (HALT_CYCLE - 10)) {
      printf("%d %u\n", cycle(), cnt_out());
    }
  }
};

int main() {
  TestTop testtop;
  while (!testtop.HALT()) {
    ArchHDL::Step();
  }
  return 0;
}
