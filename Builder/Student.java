package Builder;

abstract class StudentBuilder {
  int rollno;
  String name;
  String course;

  public StudentBuilder addRollno(int rollno) {
    this.rollno = rollno;
    return this;
  }

  public StudentBuilder addName(String name) {
    this.name = name;
    return this;
  }

  public StudentBuilder addCourse(String course) {
    this.course = course;
    return this;
  }

  public Student build() {
    return new Student(this);
  }
}

class EngineeringStudentBuilder extends StudentBuilder {
  public Student getEngineeringStudent() {
    return addRollno(1).addName("Eng Student").addCourse("B.Tech").build();
  }
}

class MedicalStudentBuilder extends StudentBuilder {
  public Student getEngineeringStudent() {
    return addRollno(1).addName("Medical Student").addCourse("MBBS").build();
  }
}

class Student {
  int rollno;
  String name;
  String course;

  Student(StudentBuilder builder) {
    this.rollno = builder.rollno;
    this.name = builder.name;
    this.course = builder.course;
  }
}

class Main {
  void main() {
    Student engStudent = new EngineeringStudentBuilder().getEngineeringStudent();
    Student medStudent = new MedicalStudentBuilder().getEngineeringStudent();
  }
}
