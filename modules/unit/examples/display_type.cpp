#include <vector>
#include <nt2/sdk/meta/type_id.hpp>

int main()
{
  std::vector<long*> vx;

  nt2::display_type<char[21]>();
  nt2::display_type(3.141592f);
  nt2::display_type(vx);
}
