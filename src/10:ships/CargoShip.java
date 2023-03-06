/*
    Ernest Izdebski
    2023-03-06

    A CruiseShip class, which extends Ship, and has an attribute for
    the maximum number of passengers.
*/

public class CargoShip extends Ship {
    /* attributes */
    private int capacity;

    /* constructors */
    CargoShip(String name, String year, int tonnage) {
        super(name, year);
        this.capacity = tonnage;
    }

    /* accessors */
    public int getCapacity() { return this.capacity; }

    /* mutators */
    public void setCapacity(int tonnage) { this.capacity = tonnage; }

    /* methods */
    public String toString() {
        return "Ship(name='" + this.getName() + "', capacity=" + this.capacity + ")";
    }
}
