class Module : public ModuleInterface {
 private:
  // copy constructor
  Module(const Module& other);
  Module& operator=(const Module& rhs);
 public:
  Module() {
    ArchHDL::Singleton::GetInstance().AddModule(this);
  }
  virtual void Init() {}
  virtual void Always() {}
};
