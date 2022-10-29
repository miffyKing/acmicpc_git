abstract class Player {
  int body;
  int sex;
  abstract void attack();

  void run() {
    System.out.println("I run");
  }

}

class Football extends Player {

  void attack() {
    System.out.println("I kick balls");
  }
}

class Basketball extends Player {

  void attack() {
    System.out.println(" I throw balls");
  }
}

class Volleyball extends Player {
  void attack() {
    System.out.println("I hit balls");
  }
}

public class AbstrackClass {

  public static void main(String[] args) {

    Player bcho = new Basketball();
    bcho.attack();
  }

}
