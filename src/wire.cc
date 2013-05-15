template <typename T>
class wire : public WireInterface {
 private:
  std::function<T ()> lambda_;

  // copy constructor
  wire<T>(const wire<T>& other);
  wire<T>& operator=(const wire<T>& rhs);
 public:
  wire(): lambda_(nullptr) {
    ArchHDL::Singleton::GetInstance().AddWire(this);
  }
  void operator=(std::function<T ()> lambda) {
    lambda_ = lambda;
  }
  T operator()() {
    return lambda_();
  }
};
