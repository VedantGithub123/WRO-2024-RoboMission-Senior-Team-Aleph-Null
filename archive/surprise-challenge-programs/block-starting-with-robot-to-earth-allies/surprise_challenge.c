void surpriseChallenge()
{
    // Add this program at the very beginning of the program before the arm resets
    moveSimple(100, 100, 400);
    moveSimple(-100, -100, 400);
}