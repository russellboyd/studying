#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  vector<int> source {3,6,1,0,-2,5};
  vector<int> v2(source.size());

  copy(begin(source),end(source),begin(v2));

  auto v3 = source;

  auto position = find(begin(source), end(source), 1);
  vector<int> v4(source.size());
  copy(begin(source), position+1, begin(v4));

  vector<int> v5(source.size());
  copy_if(begin(source),end(source),begin(v5),[](int elem) {return elem % 2 == 0;});

  copy_n(begin(v5),3,begin(v2));

  copy(begin(source),position + 1, position + 1);

  copy_backward(begin(v3),end(v3),end(source));

  //copy(begin(source), end(source) - 1, begin(source) + 1);

  copy_backward(begin(source),end(source) - 1, end(source));

  auto newend = remove(begin(source), end(source), 3);
  int s = source.size();
  int logicalsize = newend - begin(source);
  source.erase(newend,end(source));

  source = v3;
  source.erase(remove(begin(source), end(source), 
}
