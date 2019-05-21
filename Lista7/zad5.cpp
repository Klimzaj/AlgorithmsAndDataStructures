#include <iostream>

class UnionFind
{
  private:
    size_t* _parent;
    size_t* _rank;
    
  public:
    UnionFind(const size_t& n) : _parent{new size_t[n]}, _rank{new size_t[n]}
    {
      for(size_t i = 0; i < n; ++i)
      {
          _parent[i] = i;
          _rank[i] = 0;
      }
    }
    ~UnionFind()
    {
      delete[] _rank;
      delete[] _parent;
    }
    void make_union(const size_t& i,const size_t& j)
    {
      size_t a = find(i);
      size_t b = find(j); 
      if(a!=b)
      {
        if(_rank[a] < _rank[b])
          _parent[a] = b;
        else if(_rank[b] < _rank[a])
          _parent[b] = a;
        else
        {
          _parent[a] = b;
          ++_rank[b];
        }
      }
    }
    size_t find(const size_t& i)
    {
      if(_parent[i] == i)
          return i;
      return _parent[i] = find(_parent[i]);
    }
};

int main()
{
  UnionFind myUnion(51);
}