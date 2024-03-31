




- 未使用 enable_shared_from_this(來源：https://zhuanlan.zhihu.com/p/638029004)
A *pa = new A();
auto spa1 = std::shared_ptr<A>(pa);
auto spa2 = std::shared_ptr<A>(pa);

![](https://pic3.zhimg.com/80/v2-0e01cfa018a87e0367fa27ff3a8b28b6_720w.webp)


- 使用 enable_shared_from_this(來源：https://zhuanlan.zhihu.com/p/638029004)
![](https://pic3.zhimg.com/80/v2-5c66bd5b80155a3122deaab4064026e6_720w.webp)


- enable_shared_from_this 源碼

// CLASS TEMPLATE enable_shared_from_this

template<class _Ty>

class enable_shared_from_this

{  // provide member functions that create shared_ptr to this

public:

using _Esft_type = enable_shared_from_this;

 

_NODISCARD shared_ptr<_Ty> shared_from_this()

  { // return shared_ptr

  return (shared_ptr<_Ty>(_Wptr));

  }

 

_NODISCARD shared_ptr<const _Ty> shared_from_this() const

  { // return shared_ptr

  return (shared_ptr<const _Ty>(_Wptr));

  }

 

_NODISCARD weak_ptr<_Ty> weak_from_this() noexcept

  { // return weak_ptr

  return (_Wptr);

  }

 

_NODISCARD weak_ptr<const _Ty> weak_from_this() const noexcept

  { // return weak_ptr

  return (_Wptr);

  }

 

protected:

constexpr enable_shared_from_this() noexcept

  : _Wptr()

  { // construct

  }

 

enable_shared_from_this(const enable_shared_from_this&) noexcept

  : _Wptr()

  { // construct (must value-initialize _Wptr)

  }

 

enable_shared_from_this& operator=(const enable_shared_from_this&) noexcept

  { // assign (must not change _Wptr)

  return (*this);

  }

 

~enable_shared_from_this() = default;

 

private:

template<class _Other,

  class _Yty>

  friend void _Enable_shared_from_this1(const shared_ptr<_Other>& _This, _Yty * _Ptr, true_type);

 

mutable weak_ptr<_Ty> _Wptr;

};