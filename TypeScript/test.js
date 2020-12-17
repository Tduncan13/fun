class Vector2 {
    constructor(_x, _y) {
        this._x = _x;
        this._y = _y;
    }
    set x(value) {
        this._x = value;
    }
    set y(value) {
        this._y = value;
    }
    get x() {
        return this._x;
    }
    get y() {
        return this._y;
    }
    draw() {
        console.log(`X: ${this._x} Y: ${this._y}`);
    }
    add(other) {
        return new Vector2(this._x + other.x, this._y + other.y);
    }
    subtract(other) {
        return new Vector2(this._x - other.x, this._y - other.y);
    }
    multiply(other) {
        return new Vector2(this._x * other.x, this._y * other.y);
    }
    divide(other) {
        return new Vector2(this._x / other, this._y / other);
    }
    dot(other) {
        return this._x * other.x + this._y * other.y;
    }
    cross(other) {
        return (this._x * other.y) - (this._y * other.x);
    }
}
let v1 = new Vector2(1, 2);
let v2 = new Vector2(2, 3);
console.log(v1.add(v2));
console.log(v1.dot(v2));
console.log(v1.cross(v2));
