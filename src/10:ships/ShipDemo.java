/*
    Ernest Izdebski
    2023-03-06

    A demonstration of the Ship, CruiseShip, and CargoShip classes.
*/

class ShipDemo {
    public static void main(String[] args) {
        // create/populate ships array
        Ship[] ships = new Ship[3];
        ships[0] = new Ship("USS Defiant (NX-74205)", "2366");
        ships[1] = new CargoShip("USS Enterprise (NCC-1701-D)", "2363", 1014);
        ships[2] = new CruiseShip("USS Voyager (NCC-74656)", "2371", 5000);
        // iterate through ships and display
        for (Ship ship : ships)
            System.out.println(ship.toString());
    }
}