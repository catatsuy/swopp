class RegisterInterface {
 public:
  virtual void Update() = 0;
};

class ModuleInterface {
 public:
  virtual void Init() = 0;
  virtual void Always() = 0;
};

class WireInterface {};

namespace ArchHDL {

class Singleton {
 private:
  std::vector<RegisterInterface*> registers_;
  std::vector<ModuleInterface*> modules_;
  std::vector<WireInterface*> wires_;
 public:
  static Singleton& GetInstance(void) {
    static Singleton singleton;
    return singleton;
  }
  void AddRegister(RegisterInterface* ri) {
    registers_.push_back(ri);
  }
  void AddModule(ModuleInterface* mi) {
    modules_.push_back(mi);
  }
  void AddWire(WireInterface* wi) {
    wires_.push_back(wi);
  }
  void Init() {
    for (uint i = 0; i < modules_.size(); i++) {
      modules_[i]->Init();
    }
  }
  void Exec() {
    for (uint i = 0; i < modules_.size(); i++) {
      modules_[i]->Always();
    }
    for (uint i = 0; i < registers_.size(); i++) {
      registers_[i]->Update();
    }
  }
};

void Step() {
  static bool init = false;
  if (!init) {
    init = true;
    ArchHDL::Singleton::GetInstance().Init();
  }
  ArchHDL::Singleton::GetInstance().Exec();
}

}  // namespace ArchHDL
