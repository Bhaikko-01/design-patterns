package Iterator;

import java.util.List;

interface Iterateable<T> {
  boolean hasNext();

  T next();
}

interface Aggregator<T> {
  Iterateable<T> getIterator();
}

class Book {
  int id;
  String name;

  Book(int id, String name) {
    this.id = id;
    this.name = name;
  }
}

class BookIterator implements Iterateable<Book> {
  List<Book> books;
  int index;

  BookIterator(List<Book> books) {
    this.books = books;
    index = 0;
  }

  @Override
  public boolean hasNext() {
    return index == this.books.size();
  }

  @Override
  public Book next() {
    return this.books.get(index++);
  }
}

// * Library class is responsible for returning valid iterator since it is
// * maintaing collection. But this does not implement the functionality for
// * iterating objects. This is done in separate class BookIterator which will
// * have reference to all books
public class Library implements Aggregator<Book> {
  List<Book> books;

  @Override
  public Iterateable<Book> getIterator() {
    return new BookIterator(books);
  }

  public void addBook(Book book) {
    this.books.add(book);
  }
}

class Main {
  void main() {
    Book book1 = new Book(1, "A");
    Book book2 = new Book(1, "A");
    Book book3 = new Book(1, "A");
    Book book4 = new Book(1, "A");

    Library library = new Library();
    library.addBook(book1);
    library.addBook(book2);
    library.addBook(book3);
    library.addBook(book4);

    Iterateable<Book> bookIterator = library.getIterator();

    while (bookIterator.hasNext()) {
      Book book = bookIterator.next();

      System.out.println(book);
    }
  }
}
