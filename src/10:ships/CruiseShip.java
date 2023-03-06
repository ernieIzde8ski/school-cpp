/*
    Ernest Izdebski
    2023-03-03

    A CruiseShip class, which extends Ship, and has an attribute for
    the maximum number of passengers.
*/


public class CruiseShip extends Ship {
    /* attributes */
    private int maxPassengers;

    /* constructors */
    CruiseShip(String name, String year, int maxPassengers) {
        super(name, year);
        this.maxPassengers = maxPassengers;
    }

    /* mutators */
    public void setMaxPassengers(int max) { this.maxPassengers = max; }

    /* accessors */
    public int getMaxPassengers() { return this.maxPassengers; }

    /* methods */
    public String toString() {
        return "Ship(name='" + this.getName() + "', maxPassengers=" + this.maxPassengers + ")";
    }

    /* debugging */
    public static void main(String[] args) {
        System.out.println((new CruiseShip("USS Enterprise (NCC-1701-D)", "2363",
                                           1_014)).toString());
    }
}

