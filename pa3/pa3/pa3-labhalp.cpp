//pa3 help
#include <iostream>
#include <vector>
class FakeStack
{
  private:
    int depth =0;

  public:

    void push()
    {
      ++depth;
    }
    int pop()
    {
      return depth--;
    }

    int depth()
    {
      return depth;
    }
}

class VectorStack{
  std::vector<std::string> vect;
public:
  void push(std::string data)
  {
    vect.push_back(data);
  }
  std::string pop()
  {
    std::string data = vect.back();
    vect.pop_back();
    return data;
  }

  int depth()
  {
    return vect.size();
  }


}
int main()
{
    
}
