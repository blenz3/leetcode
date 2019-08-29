/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
    return s.trim()
        .split(' ')
        .filter(word => word.length !== 0)
        .reverse()
        .join(' ');
};
