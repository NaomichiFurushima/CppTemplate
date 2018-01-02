
template <template<class T, class A = std::allocator<T> > class Container>
//標準コンテナではAを忘れないのがポイント
class Phonebook
{
  struct Record
  {
    std::string name;
    std::string phone;

    Record(const std::string& n, const std::string& p)
      :name(n)
       ,phone(p)
    {}

    friend std::ostream& operator<<(std::ostream& stream, const Record& r)
    {
      return stream << r.name << ':' << r.phone;
    }
  };

  Container<Record> book;

public:
  void add(const std::string& name, const std::string& phone)
  {
    book.emplace_back(name, phone);//c++11〜
  }
  void print(std::ostream& stream) const
  {
    std::copy(begin(book), end(book),
        std::ostream_iterator<Record>(stream, "\n"));
  }
};
