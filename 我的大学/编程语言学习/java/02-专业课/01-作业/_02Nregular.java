public class _02Nregular {
    public static void main(String[] args) {
        RegularPolygon RegularPolygon1 = new RegularPolygon();
        RegularPolygon RegularPolygon2 = new RegularPolygon(5, 3);
        RegularPolygon RegularPolygon3 = new RegularPolygon(10, 5, 3.6, 7.8);
        System.out.println("Polygon 1 perimeter: " + RegularPolygon1.getPerimeter());
        System.out.println("Polygon 1 area: " + String.format("%.2f", RegularPolygon1.getArea()));
        System.out.println("Polygon 2 perimeter: " + RegularPolygon2.getPerimeter());
        System.out.println("Polygon 2 area: " + String.format("%.2f", RegularPolygon2.getArea()));
        System.out.println("Polygon 3 perimeter: " + RegularPolygon3.getPerimeter());
        System.out.println("Polygon 3 area: " + String.format("%.2f", RegularPolygon3.getArea()));
    }

    public static class RegularPolygon {
        private int n = 3;
        private double side = 1.0;
        private double x = 0.0;
        private double y = 0.0;

        public RegularPolygon() {};
        public RegularPolygon(int _n, double _side) {
            this.n = _n;
            this.side = _side;
            this.x = 0.0;
            this.y = 0.0;
        }
        public RegularPolygon(int _n, double _side, double _x, double _y) {
            this.n = _n;
            this.side = _side;
            this.x = _x;
            this.y = _y;
        }

        public int getn() {return this.n;}
        public double getside() {return this.side;}
        public double getx() {return this.x;}
        public double gety() {return this.y;}

        public void setn(int _n) {
            if (_n >= 3)
                this.n = _n;
            else
                System.out.println("%d edges cannot constitute a polygon");
        }
        public void setside(double _side) {
            if (_side <= 0)
                System.out.println("A polygon cannot have a side less than 0");
            else
                this.side = _side;
        }
        public void setx(double _x) {
            this.x = _x;
        }
        public void sety(double _y) {
            this.y = _y;
        }

        public double getPerimeter() {
            return this.n * this.side;
        }

        public double getArea() {
            double area = 1.0;
            area *= (this.n * this.side * this.side);
            area /= (4 * Math.tan(Math.PI/this.n));
            return area;
        }
    }
}
