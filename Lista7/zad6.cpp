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

bool PathA(const size_t& n,const bool t[][4])
{
    if(!t[0][0])
      return 0;
    UnionFind obj(n*n); 
    for(size_t i = 0; i < n; ++i)
      for(size_t j = 0; j < n; ++j)
      {
        if(t[i][j])
        {
          if(i+1 < n && t[i+1][j]) //right
            obj.make_union(i*n+j,(i+1)*n+j);
          if(j+1 < n && t[i][j+1]) //down
            obj.make_union(i*n+j,i*n+j+1);
        }
      }
    return obj.find(0) == obj.find(n*n-1) ? 1 : 0;
}
bool PathB(const size_t& n,const bool t[][4])
{
  UnionFind obj(n*n); 
  for(size_t i = 0; i < n; ++i)
  {
    for(size_t j = 0; j < n; ++j)
    {
      if(t[i][j])
      {
        if(i+1 < n && t[i+1][j]) //right
          obj.make_union(i*n+j,(i+1)*n+j);
        if(i-1 >= 0 && t[i-1][j]) //left
          obj.make_union(i*n+j,(i-1)*n+j);
        if(j+1 < n && t[i][j+1]) //down
          obj.make_union(i*n+j,i*n+j+1);
        }
      }
    }
    for(size_t i = 0; i < n; ++i)
      if(t[0][i])
        for(size_t j = 0; j < n; ++j)
          if(t[n-1][j])
            if(obj.find(i) == obj.find((n-1)*n+j))
              return 1;
    return 0;
}

int main()
{
    constexpr size_t n = 4;

    constexpr bool t[n][n] = {{1,1,0,0},
                              {1,0,0,0},
                              {1,1,0,0},
                              {1,1,1,1}};

    std::cout << "A: " << PathA(n,t) << std::endl;
    std::cout << "B: " << PathB(n,t) << std::endl;
}