package Proxy;

class Employee {
  public int id;
}

interface EmployeeDoa {
  Employee create(int id);
}

class EmployeeDoaImpl implements EmployeeDoa {
  public Employee create(int id) {
    // Creating logic

    return new Employee();
  }
}

class EmployeeDoaProxy implements EmployeeDoa {
  // ! Interface is used as reference here not Actual concrete class
  // as we avoid using Concrete classes in `has-a` relationship
  EmployeeDoa employeeDoa;

  public EmployeeDoaProxy(EmployeeDoa employeeDoa) {
    this.employeeDoa = employeeDoa;
  }

  public Employee create(int id) {
    // Proxy processing before moving forward with request

    return this.employeeDoa.create(id);
  }

}

class Main {
  void main() {
    EmployeeDoaProxy proxy = new EmployeeDoaProxy(new EmployeeDoaImpl());

    // This will call proxy first then actual class method will be called
    proxy.create(1);
  }
}
