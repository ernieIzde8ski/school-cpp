/*
    Ernest Izdebski

    2023-03-02
    A Ship class, with attributes for name and year of construction.
*/


public class Ship {
    /* attributes */
    private String name;
    private String year;

    /* constructors */
    Ship(String name, String year) {
        this.name = name;
        this.year = year;
    }

    /* accessors */
    public String getName() { return this.name; }
    public String getYear() { return this.year; }

    /* mutators */
    public void setName(String name) { this.name = name; }
    public void setYear(String year) { this.year = year; }

    /* methods */
    public String toString() { return "Ship(name='" + this.name + "', year='" + this.year + "')"; }
}
