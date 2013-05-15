template <typename T>
class reg : public RegisterInterface {
 private:
  bool set_;
  T curr_;
  T next_;

  // copy constructor
  reg<T>(const reg<T>& other);
  reg<T>& operator=(const reg<T>& rhs);
 public:
  reg(): set_(false), curr_(0), next_(0) {
    ArchHDL::Singleton::GetInstance().AddRegister(this);
  }
  void Update() {
    if (set_) {
      curr_ = next_;
      set_ = false;
    }
  }
  void operator=(T val) {
    curr_ =  val;
  }
  void operator<<=(T val) {
    set_ = true;
    next_ = val;
  }
  T operator ()() {
    return curr_;
  }
};
