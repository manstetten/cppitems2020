struct Base {
  int b;
  virtual ~Base() = default;
};
struct Widget : Base {
  int w;
};
struct WidgetOwns : Base {
  int *data;
  WidgetOwns() : data(new int) {}
  ~WidgetOwns() override { delete data; };
};

Base get_base() { return Widget{}; }
Base *get_base_ptr() { return new WidgetOwns{}; }

int main() {

  auto *ptr = get_base_ptr();
  delete ptr; // first action is not the override -> ~WidgetOwns() 
  // -> ~Base() is called though destruction mechanism
}