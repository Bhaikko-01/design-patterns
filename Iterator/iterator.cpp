#include <iostream>
#include <vector>

template<class T>
class Iterator {
public:
  virtual void next() = 0;
  virtual T current() = 0;
  virtual bool hasMore() = 0;
};

template<class T>
class Aggregator {
public:
  virtual Iterator<T>* getIterator() = 0;
};

class NumIterator : public Iterator<int> {
private:
  std::vector<int>* collection;
  int index;

public:
  NumIterator(std::vector<int>* collection) {
    this->collection = collection;
    index = 0;
  }

  virtual void next() override {
    index++;
  }

  virtual bool hasMore() override {
    return index < collection->size();
  }

  virtual int current() override {
    return collection->at(index);
  }
};

class NumList : public Aggregator<int> {
private:
  std::vector<int>* list;

public:
  NumList() {
    this->list = new std::vector<int>();
  }

  void add(int num) {
    this->list->push_back(num);
  }

  virtual Iterator<int>* getIterator() override {
    return new NumIterator(this->list);
  }
};

int main()
{
  NumList numList;

  for (int i = 0; i < 10; i++) {
    numList.add(i);
  }

  Iterator<int>* it = numList.getIterator();

  while (it->hasMore()) {
    std::cout << it->current() << std::endl;

    it->next();
  }

  return 0;
}
