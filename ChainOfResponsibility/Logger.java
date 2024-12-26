package ChainOfResponsibility;

class LogProcessor {
  public static int INFO = 1;
  public static int DEBUG = 2;
  public static int ERROR = 3;

  LogProcessor nextLogProcessor;

  LogProcessor(LogProcessor nextLogProcessor) {
    this.nextLogProcessor = nextLogProcessor;
  }

  public void log(int logLevel, String message) {
    if (this.nextLogProcessor != null) {
      this.nextLogProcessor.log(logLevel, message);
    }

    // Request cannot be fullfilled
  }
}

class InfoLogProcessor extends LogProcessor {
  InfoLogProcessor(LogProcessor nextLogProcessor) {
    super(nextLogProcessor);
  }

  public void log(int logLevel, String message) {
    if (logLevel == LogProcessor.INFO) {
      System.out.println("INFO: " + message);
    } else {
      super.log(logLevel, message);
    }
  }
}

class DebugLogProcessor extends LogProcessor {
  DebugLogProcessor(LogProcessor nextLogProcessor) {
    super(nextLogProcessor);
  }

  public void log(int logLevel, String message) {
    if (logLevel == LogProcessor.INFO) {
      System.out.println("DEBUG: " + message);
    } else {
      super.log(logLevel, message);
    }
  }

}

class Main {
  void main() {
    LogProcessor mainLogger = new InfoLogProcessor(new DebugLogProcessor(null));

    mainLogger.log(LogProcessor.INFO, "hello");
    mainLogger.log(LogProcessor.DEBUG, "world");
  }
}
