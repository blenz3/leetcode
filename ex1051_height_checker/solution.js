/**
 * @param {number[]} heights
 * @return {number}
 */
var heightChecker = function(heights) {
    // JavaScript default sort is terrible
    function sortNumber(a, b) {
        return a - b;
    }
    var sortedHeights = heights.slice().sort(sortNumber);

    var numStudents = 0;
    for (var i = 0; i < heights.length; ++i) {
        if (heights[i] !== sortedHeights[i]) {
            numStudents++;
        }
    }
    
    return numStudents;
};
