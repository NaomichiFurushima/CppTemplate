
template <int N, class... Ts>
struct tuple_data;

template <int N>
struct tuple_data<N> {};

template <int N, class Thead, class... Tbody>
struct tuple_data<N, Thead, Tbody...>
: public tuple_data<N + 1, Tbody...>
{
  Thead value;
};

template <class... Ts>
struct tuple : public tuple_data<0, Ts...>{};

template <int N, class Thead, class... Tbody>
Thead& get_tuple_data(tuple_data<N, Thead, Tbody...>& t)
{
  return t.value;
}

template <int N, class... Ts>
auto get(tuple<Ts...>& t) -> decltype(get_tuple_data<N>(t))
{
  return get_tuple_data<N>(t);
}
