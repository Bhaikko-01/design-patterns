package Prototype;

interface Clonable {
  Clonable clone();
}

class Student implements Clonable {
  int id;
  String name;

  Student(int id, String name) {
    this.id = id;
    this.name = name;
  }

  @Override
  public Student clone() {
    return new Student(this.id, this.name);
  }
}

class Main {
  void main() {
    Student student = new Student(1, "Hello");

    Student clonedStudent = student.clone();
  }
}
