package Composite;

import java.util.List;

interface FileSystem {
  void ls();
}

class File implements FileSystem {
  public void ls() {
    System.out.println("file");
  }
}

class Directory implements FileSystem {
  List<FileSystem> fileSystems;

  public void ls() {
    System.out.println("folder");

    for (FileSystem fileSystem : fileSystems) {
      fileSystem.ls();
    }
  }

  public void add(FileSystem fileSystem) {
    fileSystems.add(fileSystem);
  }

}

class Main {
  void main() {
    Directory directory = new Directory();

    directory.add(new File());
    directory.add(new Directory());

    directory.ls();
  }
}
