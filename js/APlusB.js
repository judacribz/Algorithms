var a = process.argv[2];
var b = process.argv[3];

if (a != null && b != null) {
    console.log("The sum of " + a + " and " + b  + " is "  + a + b);
} else {
    console.log("Error: Two numbers separated by a space required");
}